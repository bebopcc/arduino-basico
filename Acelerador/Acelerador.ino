int velocidade = 0;

void setup() { 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);

  digitalWrite(7, HIGH); 
  digitalWrite(8, LOW);
}

void loop() { 
  if(digitalRead(2) == HIGH) {
    if(velocidade > 0) { 
      velocidade--;
    }
  }
  else {
    if(velocidade < 255) { 
      velocidade++;
    }
  }
  analogWrite(9, velocidade);
  delay(20);
}
