// Atribuir nomes aos pinos
// Botões 1, 2 e 3
#define BT1 8
#define BT2 9
#define BT3 10
// LEDs 
#define ledB 2
#define ledW 3
#define ledR 4

// Inicialização das variáveis de status de cada de botão
bool statusBT1;
bool statusBT2;
bool statusBT3;

bool flag1;
bool flag2;
bool flag3;

//Rotina Principal
void setup(){
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

  // Configura os LEDs
	pinMode(ledB, OUTPUT);
	pinMode(ledW, OUTPUT);
	pinMode(ledR, OUTPUT);

  // Exercício 3
  /*
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, HIGH);
  delay(3000);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);*/

  // Exercício 6
  for (int i = 0; i <= 6; i++) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledR, HIGH);
    delay(500);
    digitalWrite(ledB, LOW);
    digitalWrite(ledR, LOW);
    delay(500);
  }


  delay(3000);
  Serial.println("Fim da Inicialização");
}

void loop() {
  //ex4();
  //ex5();
  ex7();
}

void piscarRB(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, HIGH);
  delay(250);
  digitalWrite(ledB, LOW);
  digitalWrite(ledR, LOW);
  delay(250);  
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

  delay(2000);
};

void ex5(){
  digitalWrite(ledB, HIGH);
  delay(1000);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, HIGH);
  delay(1000);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, HIGH);
  delay(1000);
  digitalWrite(ledR, LOW);

  delay(3000);
};

void ex7(){
  statusBT3 = digitalRead(BT3);
  delay(100); //Minimizar o efeito debounce

  while (statusBT3){
    if (statusBT3 == 1 && flag3 == 0){
      // Foi detectada a borda de subida
      flag3 = 1;
      Serial.println("O botão foi pressionado");
      piscarRB();
    }
    
    if (statusBT3 == 0 && flag3 == 1) {
      Serial.println("O botão foi desligado");
      flag3 = 0;
      // Foi detectada a borda de descida
    }
    //TO DO!!!!
    
  }
}










