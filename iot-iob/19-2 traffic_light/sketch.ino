/*
Exemplo 1:
Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.

Exemplo 2:
Os LEDs vermelho e verde deverão piscar alternadamente e em intervalos de 400ms.

Exemplo 3:
Crie um código para simular um semáforo:
Verde --> 4 segundos
Amarelo --> 1 segundo
Vermelho --> 6 segundos
*/

// Atribuição de nomes aos pinos de LEDs
#define ledRED 4 //Cada número na frente do nome é a posição na qual estão conectados na placa
#define ledYEL 6
#define ledGRE 12

void setup(){
  //Configuração dos pinos dos LEDs como saída
  pinMode(ledRED, OUTPUT);
  pinMode(ledYEL, OUTPUT);
  pinMode(ledGRE, OUTPUT);
}

void loop(){
  //ex1();
  //ex2();
  ex3();
}

void ex1(){
  //Exemplo 1: Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.
  digitalWrite(ledRED, HIGH);
  digitalWrite(ledYEL, HIGH);
  digitalWrite(ledGRE, HIGH);
  delay(300);
  digitalWrite(ledRED, LOW);
  digitalWrite(ledYEL, LOW);
  digitalWrite(ledGRE, LOW);
  delay(300);
}

void ex2(){
  //Exemplo 2: Os LEDs vermelho e verde deverão piscar alternadamente e em intervalos de 400ms.
  digitalWrite(ledRED, HIGH);
  delay(400);
  digitalWrite(ledRED, LOW);
  delay(400);
  digitalWrite(ledGRE, HIGH);
  delay(400);
  digitalWrite(ledGRE, LOW);
  delay(400);
}

void ex3(){
  /*Exemplo 3:
  Crie um código para simular um semáforo:
  Verde --> 4 segundos
  Amarelo --> 1 segundo
  Vermelho --> 6 segundos*/

  digitalWrite(ledGRE, HIGH);
  delay(4000);
  digitalWrite(ledGRE, LOW);
  digitalWrite(ledYEL, HIGH);
  delay(1000);
  digitalWrite(ledYEL, LOW);
  digitalWrite(ledRED, HIGH);
  delay(6000);
  digitalWrite(ledRED, LOW);
}