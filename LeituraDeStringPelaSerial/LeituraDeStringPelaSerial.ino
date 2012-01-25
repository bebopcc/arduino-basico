void setup() {
  Serial.begin(9600);
}

void loop() {
  String mensagemCompleta = "";
  while(Serial.available()) {//Enquanto tiver algo para ler...
    char caracter = Serial.read();//Leia o proximo
    mensagemCompleta += caracter;

    if(mensagemCompleta.endsWith("\n")) {
      Serial.println(mensagemCompleta);
    }
    
    delay(25);
  }
}
