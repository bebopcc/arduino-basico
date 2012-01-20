#include "notas.h"

const int SPEAKER = 12;

const int LED_AZUL = 9;    //4
const int LED_AMARELO = 5; //3
const int LED_VERMELHO = 7; //2
const int LED_VERDE = 3;    //1

const int BTN_AZUL = 8;
const int BTN_AMARELO = 4;
const int BTN_VERMELHO = 6;
const int BTN_VERDE = 2;

const int NOTA_AZUL = NOTE_B3;
const int NOTA_AMARELO = NOTE_G3;
const int NOTA_VERMELHO = NOTE_E3;
const int NOTA_VERDE = NOTE_C3;

int LEDS[4] = {LED_VERDE, LED_VERMELHO, LED_AMARELO, LED_AZUL};
int BTNS[4] = {BTN_VERDE, BTN_VERMELHO, BTN_AMARELO, BTN_AZUL};
int NOTAS[4] = {NOTA_VERDE, NOTA_VERMELHO, NOTA_AMARELO, NOTA_AZUL};

boolean vezDoGenius = true;

int sequencia[30];
int indiceAtual = 0;

long inicioTempoJogador = 0;

void setup() {
  pinMode(SPEAKER, OUTPUT);

  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  
  pinMode(BTN_AZUL, INPUT);
  pinMode(BTN_AMARELO, INPUT);
  pinMode(BTN_VERMELHO, INPUT);
  pinMode(BTN_VERDE, INPUT);

  reiniciar();
  delay(500);

  Serial.begin(9600);
}

void loop() {
  //Se for a vez do jogo...
  if(vezDoGenius) {
    Serial.println("vez do genius");
    
    //Gera o proximo sequencial
    int atual = (int)random(0, 4); //0 - 3
    sequencia[indiceAtual] = atual;
    indiceAtual++;
    delay(100);

    //Para cada valor na sequencia, toca/acende
    for(int i = 0; i < indiceAtual; i++) {
      Serial.println("tocar genius");
      tocar(sequencia[i]);
    }

    //Passa a vez para o jogador
    vezDoGenius = false;
    inicioTempoJogador = millis();
  } else {
    Serial.println("vez do jogador");
    for(int i = 0; i < indiceAtual; i++) {
      int jogada = lerJogada();
     
      //Validar se a jogada foi valida:
      //Se for invalida, game over!
      if(jogada != sequencia[i]) {
        gameOver();
      }

      //Renova o tempo do jogador
      inicioTempoJogador = millis();
    }

    delay(1000);
    vezDoGenius = true;
  }
  
  delay(25);
}

int lerJogada() {
  //Verifica se o tempo do jogador responder expirou
  while(millis() - inicioTempoJogador < 5000) {
    //Verifica se tem algum botao apertado
    int qtdBotoes = sizeof(BTNS)/sizeof(int);
    for(int i = 0; i < qtdBotoes; i++) {
      if(digitalRead(BTNS[i])) {
        Serial.println("tocar jogador");
        tocar(i);
        return i;
      }
    }
  }

  gameOver();
}

void gameOver() {
  tocar(0);
  tocar(1);
  tocar(2);
  tocar(3);
  reiniciar();
  delay(2500);
}

void reiniciar() {
  indiceAtual = 0;   
  vezDoGenius = true;
  inicioTempoJogador = millis();
}

void tocar(int indice) {
  //ACENDE
  digitalWrite(LEDS[indice], HIGH);
  //TOCA A NOTA
  tone(SPEAKER, NOTAS[indice]);
  
  //ESPERA
  delay(350);
  
  //APAGA O LED
  digitalWrite(LEDS[indice], LOW);
  //DESLIGA A NOTA
  noTone(SPEAKER);
  
  //ESPERA
  delay(350);  
}
