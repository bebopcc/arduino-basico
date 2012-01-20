#include <Servo.h>

Servo meuServo;

void setup() {
  meuServo.attach(10);
  pinMode(A0, INPUT);
}

void loop() {
  int posicaoPot = analogRead(A0);
  int posicaoServo = 
    map(posicaoPot, 0, 1023, 0, 180);
  meuServo.write(posicaoServo);
  delay(10);
}
