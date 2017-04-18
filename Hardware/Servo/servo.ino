#define pot A5
int servo = 3;

void setup(){
	
  Serial.begin(9600);
  pinMode(pot,INPUT);
  pinMode(servo,OUTPUT);
}

void loop(){
  	
  analogWrite(servo,map(analogRead(pot),0,1023,127,255));
  Serial.println(map(analogRead(pot),0,1023,0,255));
  
}
