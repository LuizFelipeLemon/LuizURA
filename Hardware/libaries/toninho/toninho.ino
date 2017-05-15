#include "toninho.h"

Ultrassom luiz;
float dist;

#define TRIG 11
#define ECHO 12

void setup(){
  Serial.begin(9600); 
  pinMode(11,OUTPUT);
  pinMode(12,INPUT); 
  Serial.println("BEFORE");
}

void loop(){
  
  float distance, duration;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ECHO, HIGH);    //Emite um pulso 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);    //Calcula o tempo ate que o pulso retorne ao sensor
  Serial.println(pulseIn(ECHO, HIGH));
  Serial.println( duration / 58.2);
 
}

