void setup() { 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  for(int vel = 0; vel <= 255; vel++) {
    analogWrite(9, vel);
    delay(10);
  }
  
  for(int vel = 255; vel >= 0; vel--) {
    analogWrite(9, vel);
    delay(10);
  }
  
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW);
}

void loop() { 
}

