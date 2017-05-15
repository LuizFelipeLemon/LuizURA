#include"toninho.h"
#include "Arduino.h"

#define TRIG 11
#define ECHO 12

Ultrassom::Ultrassom(){
  
}

float Ultrassom::dist(){  // Retorna a distância medida pelo Sensor Ultrassônico
  float distance, duration;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ECHO, HIGH);    //Emite um pulso 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);    //Calcula o tempo ate que o pulso retorne ao sensor
  Serial.println(pulseIn(ECHO, HIGH));
  return distance = duration / 58.2;

}

