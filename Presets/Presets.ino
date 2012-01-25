void setup() { 
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);

  Serial.begin(9600);
}

void loop() { 
  if(Serial.available()) {
    char comando = Serial.read(); 
    if(comando == 'a') {
      digitalWrite(2, HIGH); 
      digitalWrite(3, LOW);
    } 
    else if(comando == 'b') {
      digitalWrite(2, LOW); 
      digitalWrite(3, HIGH);
    } 
    else if(comando == 'c') {
      digitalWrite(2, HIGH); 
      digitalWrite(3, HIGH);
    } 
    else if(comando == 'd') {
      digitalWrite(2, LOW); 
      digitalWrite(3, LOW);
    }
  }
}
