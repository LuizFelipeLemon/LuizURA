
int led = 2;    //Led conectado ao pino 2

void setup() {
  pinMode(led, OUTPUT);     //Define o pino 2 como saída
}

void loop() {
  digitalWrite(led, HIGH);   //Escreve no pino 2 o valor alto
  delay(1000);               //Delay de 1 segundo
  digitalWrite(led, LOW);    //Escreve no pino 2 o valor baixo
  delay(1000);               //Delay de 1 segundo
}
