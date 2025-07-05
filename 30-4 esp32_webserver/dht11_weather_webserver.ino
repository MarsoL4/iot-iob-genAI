// Importar bibliotecas necessárias
#include <WiFi.h>


// Instalar a biblioteca e todas as dependências
#include <ESPAsyncWebServer.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> // Dependência da DHT

// Substitua pelas credenciais da sua rede
const char* ssid = "13:50";
const char* password = "1234567891";

#define DHTPIN 27     // Pino digital conectado ao sensor DHT

// Tipo de sensor em uso:
#define DHTTYPE DHT11  

// Instanciação do objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Criação do objeto AsyncWebServer na porta 80
AsyncWebServer server(80);

// Função para ler a temperatura do sensor DHT
String readDHTTemperature() {
  // As leituras do sensor podem ter até 2 segundos de atraso (sensor muito lento)
  // Ler temperatura em Celsius (padrão)
  float t = 23;
  // Ler temperatura em Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Verifica se a leitura falhou
  if (isnan(t)) {    
    Serial.println("Falha ao ler do sensor DHT!");
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

// Função para ler a umidade do sensor DHT
String readDHTHumidity() {
  // As leituras do sensor podem ter até 2 segundos de atraso (sensor muito lento)
  // float h = dht.readHumidity();
  float h = 53;

  if (isnan(h)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return "--";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

String temperatureMessage(){
  float tm = 23;

  if (isnan(tm)){
    return "--";
  }
  else {
    if(tm >= 25 && tm <= 45){
      return "Calor de rachar!";
    }
    else if (tm >= -10 && tm <= 20){
      return "Friozinho bom!";
    }
    else if (tm > 20 && tm < 25){
      return "Nem frio, nem calor!";
    }
    else {
      return "";
    }
  }
}

// Página HTML principal armazenada na memória flash
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align: middle;
      padding-bottom: 15px;
    }
    #temp_message{
      font-size: 1rem;
    }
  </style>
</head>
<body>
  <h2>Servidor ESP32 DHT</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="dht-labels">Temperatura</span> 
    <span id="temperature">%TEMPERATURE%</span>
    <sup class="units">&deg;C</sup><br>
    <p id="temp_message">%TEMP_MESSAGE%</p>
  </p>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i> 
    <span class="dht-labels">Umidade</span>
    <span id="humidity">%HUMIDITY%</span>
    <sup class="units">&percnt;</sup>
  </p>
</body>
<script>

setInterval(function () {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temp_message").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/tempmessage", true);
  xhttp.send();
}, 10000);

setInterval(function () {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000);

setInterval(function () {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000);
</script>
</html>)rawliteral";

// Função para substituir os espaços reservados por valores do DHT
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return readDHTTemperature();
  }
  else if(var == "HUMIDITY"){
    return readDHTHumidity();
  }
  else if(var == "TEMP_MESSAGE"){
    return temperatureMessage();
  }

  return String();
}

void setup(){
  // Porta serial para fins de depuração
  Serial.begin(115200);

  dht.begin();
  
  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi..");
  }

  // Exibir o endereço IP local do ESP32
  Serial.println(WiFi.localIP());

  // Rota para a página inicial
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Rota para retornar a temperatura
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });

  // Rota para retornar a umidade
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });

  //Rota para retornar uma mensagem específica de acordo com o nível de temperatura
  server.on("/tempmessage", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", temperatureMessage());
  });


  // Iniciar o servidor
  server.begin();
}
 
void loop(){
  
}
