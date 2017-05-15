// Biblioteca para o Toninho
// ECT - UFRN 2017
// Luiz Felipe Santana


#ifndef toninho_h
#define toninho_h

#include "Arduino.h"

class Ultrassom{
  
  public:
    Ultrassom();
    float dist();
    
  private:

    
};

class sensor{
  
  public:
    sensor();
    int valor();
  private:

    
};

class buzzer{
  
  public:
    buzzer();
    void tocar(int melodia[], int duracao[], int pausa[]);
  private:

    
};

#endif
