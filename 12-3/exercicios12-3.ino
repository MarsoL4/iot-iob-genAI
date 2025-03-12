// Atribuir nomes aos pinos
// LEDs 
#define ledB 2
#define ledW 3
#define ledR 4

void setup(){
	pinMode(ledB, OUTPUT);
	pinMode(ledW, OUTPUT);
	pinMode(ledR, OUTPUT);

  // Exercício 3
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, HIGH);
  delay(3000);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);
  
  delay(3000);


}

void loop() {
  //ex4();
  //ex5();
}

void ex4(){
  digitalWrite(ledR, HIGH);
  delay(1000);
  digitalWrite(ledW, HIGH);
  delay(1000);
  digitalWrite(ledB, HIGH);

  delay(3000);

  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);

  delay(2000)
}

void ex5(){
  digitalWrite(ledB, HIGH);
  delay(1000);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, HIGH);
  delay(1000);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, HIGH);
  delay(1000)
  digitalWrite(ledR, LOW);

  delay(3000)
}

void ex6(){
  
}









