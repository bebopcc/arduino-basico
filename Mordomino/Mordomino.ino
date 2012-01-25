void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    char caracter = Serial.read();
    if(caracter == ‘1’) {
      digitalWrite(2, HIGH);
    } else if(caracter == ‘0’) {
      digitalWrite(2, LOW);
    }
    delay(25);
  }
}
