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


}

void loop() {
  
}

void ex4(){

}