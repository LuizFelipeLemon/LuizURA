

int red = 2, blue = 3, green = 4;   //1° pino do led RGB no pino 2 do Arduino, 2° do led no pino 3 e 3° pino do led no pino 4
int bt1 = 8, bt2 = 9, bt3 = 10;     //Botão 1 conectado ao pino 8, Botão 2 no pino 9 e Botão 3 no pino 10

void setup() {

  pinMode(red, OUTPUT);       //Definindo o pino 2 como saída
  pinMode(green, OUTPUT);     //Definindo o pino 3 como saída
  pinMode(blue, OUTPUT);      //Definindo o pino 4 como saída
  
  pinMode(bt1, INPUT);        //Definindo o pino 8 como entrada
  pinMode(bt2, INPUT);        //Definindo o pino 9 como entrada
  pinMode(bt3, INPUT);        //Definindo o pino 10 como entrada

}


void loop() {

  digitalWrite(red, digitalRead(bt1));        // Escreve no pino 2 a leitura do pino 8
  digitalWrite(blue, digitalRead(bt2));       // Escreve no pino 3 a leitura do pino 9
  digitalWrite(green, digitalRead(bt3));      // Escreve no pino 4 a leitura do pino 10
  
}
