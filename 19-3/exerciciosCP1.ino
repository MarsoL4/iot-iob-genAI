//Questão 2
//Atribuindo nome aos pinos dos LEDs
#define ledVC 2
#define ledAC 3
#define ledVdC 4
#define ledVP 5
#define ledVdP 6

//Atribuindo nome aos pinos dos Botões
#define BT1 8
#define BT2 9
#define BT3 10

//Questão 3
int valor;



void setup() {
  Serial.begin(9600);
  Serial.println("Enzo Marsola 556310, Cauan da Cruz 558238");
  
  //Configuração dos LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  //Configuração dos Botões
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

}

void loop() {
  /*
  //Questão 2:
  //Fase 1: Verde para veículos. Vermelho para pedestres
  digitalWrite(ledVdC, HIGH);
  digitalWrite(ledVP, HIGH);
  delay(5000);
  //Fase 2: Amarelo para veículos. Vermelho para pedestres.
  digitalWrite(ledVdC, LOW);
  digitalWrite(ledAC, HIGH);
  delay(2000);
  //Fase 3:  Vermelho para veículos. Verde para pedestres.
  digitalWrite(ledAC, LOW);
  digitalWrite(ledVP, LOW);
  digitalWrite(ledVC, HIGH);
  digitalWrite(ledVdP, HIGH);
  delay(5000);
  //Fase 4: Vermelho para veículos. Vermelho piscante para pedestres
  digitalWrite(ledVdP, LOW);
  piscarVPed();
  digitalWrite(ledVC, LOW);
  */
  
  /*
  //Questão 3:
  valor = analogRead(A2);

  if (valor < 300) {
    Serial.print("valor: ");
    Serial.println(valor);
    digitalWrite(ledVdP, HIGH);
    digitalWrite(ledAC, LOW);
    digitalWrite(ledVP, LOW);
    digitalWrite(ledVC, LOW);
    digitalWrite(ledVdC, LOW);
  }

  else if (valor >= 300 && valor < 600) {
    Serial.print("valor: ");
    Serial.println(valor);
    digitalWrite(ledAC, HIGH);
    digitalWrite(ledVdP, LOW);
    digitalWrite(ledVP, LOW);
    digitalWrite(ledVC, LOW);
    digitalWrite(ledVdC, LOW);
  }

  else if (valor >= 600 && valor < 900) {
    Serial.print("valor: ");
    Serial.println(valor);
    digitalWrite(ledVP, HIGH);
    digitalWrite(ledVdP, LOW);
    digitalWrite(ledAC, LOW);
    digitalWrite(ledVC, LOW);
    digitalWrite(ledVdC, LOW);
  }

  else if (valor >= 900 && valor < 1000) {
    Serial.print("valor: ");
    Serial.println(valor);

    digitalWrite(ledVC, HIGH);
    digitalWrite(ledAC, HIGH);
    digitalWrite(ledVdC, HIGH);
    delay(400);
    digitalWrite(ledVC, LOW);
    digitalWrite(ledAC, LOW);
    digitalWrite(ledVdC, LOW);
    delay(400);
  }


  else if (valor >= 1000) {
    Serial.print("valor: ");
    Serial.println(valor);
    Serial.println("Alarme!");

    digitalWrite(ledVC, HIGH);
    digitalWrite(ledVP, HIGH);
    delay(400);
    digitalWrite(ledVC, LOW);
    digitalWrite(ledVP, LOW);
    delay(400);
  }
  */

  //Questão 4:


  //Questão 5:

}

//Questão 2
void piscarVPed() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledVP, HIGH);
    delay(250);
    digitalWrite(ledVP, LOW);
    delay(250);
  }
}