//Atribue nome aos Pinos
//Botões 1 e 2
#define BT1 8
#define BT2 9

//LEDs
#define ledB 2
#define ledW 3
#define ledR 4

int contador; //variável do tipo inteiro ---> 2^16 = 65.536 (64k)

void setup() {
  //Habilitar a porta serial
  //Baud Rate(9600 bits/s) padrão UNO
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);

  pinMode(ledB, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledR, OUTPUT);

}

void loop() {
  bool statusBT1 = digitalRead(BT1);
  bool statusBT2 = digitalRead(BT2);
  
  // if(statusBT1 == HIGH) piscaRB();
  // OU
  if(statusBT1 == HIGH){ //Aqui o HIGH poderia ser substituído por 1/0 ou true/false e funcionaria da mesma forma
    Serial.println("BT1 LIGADO!!! :D");
    piscaRB();
  }
  if(statusBT2 == HIGH){
    Serial.println("BT2 LIGADO!!! :D");
    contador++;
  	piscaTD();
    Serial.print("Contador: ");
    Serial.println(contador);
    delay(200);
  }
  else{
    piscaW();
  }

}

void piscaRB(){ // Pisca o LED vermelho e azul
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  delay(250);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  delay(250);
  digitalWrite(ledR, LOW);
}

void piscaW(){ //Pisca o LED Branco
  digitalWrite(ledW, HIGH);
  delay(350);
  digitalWrite(ledW, LOW);
  delay(350);
}

void piscaTD(){
  digitalWrite(ledW, LOW);
  delay(250);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, HIGH);
  delay(250);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW); 
}
