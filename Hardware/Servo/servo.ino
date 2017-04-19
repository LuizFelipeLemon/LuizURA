#define pot A5		//Potenciometro ligado no pino analógico 5
int servo = 3;		//Servo motor conectado ao pino 3

void setup(){
	
  Serial.begin(9600);		//Inicia a Serial
  pinMode(pot,INPUT);		//Define o Pino analógico 5 como entrada
  pinMode(servo,OUTPUT);	//Define pino 3 como saída
}

void loop(){
	
  int val = map(analogRead(pot),0,1023,0,255);	//Transforma os valores lidos no pino analógico de 0 a 1023 para seu 
						//correspondente de 0 a 255.
  	
  analogWrite(servo,val);	//Escreve no pino 3 a leitura a variavel val
	
  // Serial.println(map(analogRead(pot),0,1023,0,255));
  
}
