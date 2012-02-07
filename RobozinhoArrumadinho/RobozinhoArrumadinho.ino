const int MOTOR_DH = 3;
const int MOTOR_DA = 5;
const int MOTOR_EH = 6;
const int MOTOR_EA = 9;
const int VELO = 200;
void setup()
{
  pinMode(MOTOR_DH,OUTPUT);//motor 1
  pinMode(MOTOR_DA,OUTPUT);
  pinMode(MOTOR_EH,OUTPUT);  // motor 2
  pinMode(MOTOR_EA,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(11,INPUT);
  pinMode(2,INPUT);
  pinMode(A3,INPUT);
  Serial.begin(9600);
}

void loop(){
  int sensor = analogRead(A1);//0-1023
  
  //Verifica se tem obstaculo...
  if( sensor >=150 || digitalRead(11)==HIGH || digitalRead(2) == HIGH){ 
    parar();
    delay(400);

    //Se bateu do lado esquerdo, gira para a direita
    if(digitalRead(11)==HIGH) {
      girarPraDireita();
    }
    //Se bateu do lado direito, gira para a esquerda
    else if(digitalRead(2)==HIGH) {
      girarPraEsquerda();
    }
    //Se nao, gira pra qualquer lado...
    else {
      girarPraDireita();
    }
    int pot = analogRead(A3);
    delay(pot);
    
    parar();
  }
  //Se nao tiver obstaculo...
  else{
    andarPraFrente();
  }
}

void girarPraEsquerda(){
  analogWrite(MOTOR_DH,VELO);
  analogWrite(MOTOR_DA,0);
  //motor 2
  analogWrite(MOTOR_EH,0);
  analogWrite(MOTOR_EA,0);
}

void girarPraDireita(){
  analogWrite(MOTOR_DH,0);
  analogWrite(MOTOR_DA,0);
  //motor 2
  analogWrite(MOTOR_EH,0);
  analogWrite(MOTOR_EA,VELO);
}

void parar() {
  //motor 1
  analogWrite(MOTOR_DH,0);
  analogWrite(MOTOR_DA,0);

  //motor 2
  analogWrite(MOTOR_EH,0);
  analogWrite(MOTOR_EA,0); 
}

void andarPraFrente(){
  analogWrite(MOTOR_DH,0);
  analogWrite(MOTOR_DA,VELO);
  //motor 2
  analogWrite(MOTOR_EH,VELO);
  analogWrite(MOTOR_EA,0);
}

void andarPraTras(){
  analogWrite(MOTOR_DH,VELO);
  analogWrite(MOTOR_DA,0);
  //motor 2
  analogWrite(MOTOR_EH,0);
  analogWrite(MOTOR_EA,VELO);
}

