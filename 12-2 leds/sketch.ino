/*
Arduino UNO

Linguagem Wiring (C++ adaptado customizado para microcontroladores)

Portas digitais:
(pinos de 0 a 13)
INPUT (entrada) ---> botão, sensor digital...
OUTPUT (saída) ---> LED, display, relé, buzzer...
0 Volts ----> 0 -----> LOW ------> false
    ou
5 Volts ----> 1 -----> HIGH -----> true

Exemplo:
O LED ligado ao pino 5 deverá piscar em intervalos de meio segundo. 
*/

#define LED 5 //atribui o nome LED ao pino 5
// ou
// const int LED = 5
// ou
// int LED = 5



void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT); //Configura o pino 5 como output
  // ou pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly;
  digitalWrite(5, HIGH); //Acende o LED em 5V
  // ou digitalWrite(LED, HIGH);

  delay(500); //espera de 500ms ou 0,5s

  digitalWrite(5, LOW);//Apaga o LED (0V)
  // ou digitalWrite(LED, LOW);

  delay(500); //espera de 500ms ou 0,5s
}