
//Funçao para a opcao Manual Continua

void manualContinua(){

  digitalWrite(6, HIGH);    //Emite um sinal sonoro
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  
  bool fast = true;
  char aux;
  Serial.println("Voce escolheu a opcao Manual Continua: f= para frente, t= tras, d= direita, e= esquerda, p= parar. ");
  
  while (comando != 's')
  { 
    if (Serial.available()) {
      comando = 0; 
      comando = Serial.read();

      if (aux != comando) {
        motor1.detach();
        motor2.detach();
        if (!fast) {
          if (Serial.available()) {
            comando = Serial.read();
            break;
          }
          delay(600);
        }
      }
      aux = comando;
    }
    int seg = 0, but = 0;
    seg = 11;

    if (comando == 'y') {
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(180);
      motor2.write(0);
    }

    if (comando == 'f' && seg > 10) {
      fast = false;
      seg = dist();
      Serial.println(seg);
      if (seg > 0 && seg <= 10 || seg < 0) {
        motor1.detach();
        motor2.detach();
      }
      else {
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
      }
      motor1.write(180);
      motor2.write(0);
    }
    but = 0;
    if (comando == 't' && but == 0 ) {
      fast = false;
      but = digitalRead(BOTAO);
      Serial.println(but);
      if (but == 0) {
        motor1.detach();
        motor2.detach();
      }
      else {
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
      }
      motor1.write(0);
      motor2.write(180);
    }
    if (comando == 'b') {
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(0);
      motor2.write(180);
    }
    if (comando == 'e') {
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(0);
      motor2.write(0);
    }
    if (comando == 'd') {
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(180);
      motor2.write(180);
    }
    if (comando == 'p') {
      fast = true;
      motor1.detach();
      motor2.detach();
    }

  }
  Serial.println("Trocar opcao");
}
