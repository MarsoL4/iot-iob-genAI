#include <WiFi.h>
 
const char* ssid = "13:50";
const char* password = "1234567891";
 
WiFiServer server(80);
String header;
 
String ledState = "off";
 
const int ledPin = 2; // LED onboard do ESP32 (normalmente no GPIO 2)
 
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;
 
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("Wi-Fi conectado.");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
 
void loop(){
  WiFiClient client = server.available();   
 
  if (client) {
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("Novo cliente.");
    String currentLine = "";
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
 
            if (header.indexOf("GET /led/on") >= 0) {
              Serial.println("LED ONBOARD ligado");
              ledState = "on";
              digitalWrite(ledPin, HIGH);
            } else if (header.indexOf("GET /led/off") >= 0) {
              Serial.println("LED ONBOARD desligado");
              ledState = "off";
              digitalWrite(ledPin, LOW);
            } else if (header.indexOf("GET /led/blink") >= 0) {
              Serial.println("LED ONBOARD piscando");
              ledState = "blink";
              for (int i = 0; i < 5; i++) {
                digitalWrite(ledPin, HIGH);
                delay(300);
                digitalWrite(ledPin, LOW);
                delay(300);
              }
            }
 
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #007BFF; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
 
            client.println("<body><h1>Controle do LED Onboard ESP32</h1>");
            client.println("<p>LED - Estado: " + ledState + "</p>");
            if (ledState == "off") {
              client.println("<p><a href=\"/led/on\"><button class=\"button\">LIGAR</button></a></p>");
            } else {
              client.println("<p><a href=\"/led/off\"><button class=\"button button2\">DESLIGAR</button></a></p>");
            }
            client.println("<p><a href=\"/led/blink\"><button class=\"button\">PISCAR</button></a></p>");
 
            client.println("</body></html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }
}