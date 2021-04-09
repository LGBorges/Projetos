#include <LiquidCrystal.h>

/*
-- RESISTOR DO LED = 150 OHMS
-- RESISTOR DO LCD = 200 OHMS
-- RESISTORES DOS BOTÕES = 10K OHMS
-- POTENCIOMETRO = 10 K OHMS
*/

LiquidCrystal lcd(7,8,13,12,10,9);
//Em ordem: rs,e,db4,db5,db6,db7

/*INICIANDO PORTAS E ESTADOS*/
const int led_alto_brilho = 11;
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPotenciometro = A0;
int EstadoBotao1 = LOW;
int EstadoBotao2 = LOW;
int EstadoPotenciometro = LOW;
int velocidade = 0;

void setup(){
  pinMode(led_alto_brilho, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPotenciometro, INPUT);
  Serial.begin(9600);
}

void loop(){
  lcd.begin(16,2);//LIGA LCD
  
  EstadoBotao1 = digitalRead(buttonPin1);
  EstadoBotao2 = digitalRead(buttonPin2);
  /*CONDICAO DOS BOTOES CASO AMBOS ESTEJAM APERTADOS OU NAO*/
  if(EstadoBotao1 == LOW && EstadoBotao2 == LOW){
    lcd.setCursor(2,0);
    lcd.print("Nenhum botao");
    lcd.setCursor(0,1);
    lcd.print("****--****--****");
    delay(1000);
  }
  else if(EstadoBotao1 == HIGH && EstadoBotao2 == HIGH){
    lcd.setCursor(4,0);
    lcd.print("ATENCAO!");
    lcd.setCursor(1,1);
    lcd.print("APENAS 1 BOTAO");
    delay(1000);
  }
  /*CONDICAO DOS BOTOES PARA LIGAR/DESLIGAR O LED
  	E VELOCIDADE DE ACORDO COM O POTENCIOMETRO*/
  if(EstadoBotao1 == HIGH && EstadoBotao2 == LOW){
    btn1LCD();
    potenciometroIniciaDesligado();
    analogWrite(led_alto_brilho, LOW);
  }
  else if(EstadoBotao2 == HIGH && EstadoBotao1 == LOW){
    btn2LCD();
    potenciometroIniciaLigado();
  }
}
/*FUNCAO DO POTENCIOMETRO COM LED DESLIGADO*/
void potenciometroIniciaDesligado(){
  velocidade = analogRead(buttonPotenciometro);
  analogWrite(led_alto_brilho,velocidade/4);
    if(velocidade<164){
      for(velocidade = 0; velocidade <=255 ; velocidade += 1){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    } 
    if(velocidade>165 && velocidade<348){
      for(velocidade = 0; velocidade <=255 ; velocidade += 10){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
   } 
   if(velocidade>349 && velocidade<511){
      for(velocidade = 0; velocidade <=255 ; velocidade += 15){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
   } 
   if(velocidade>512 && velocidade< 675){
      for(velocidade = 0; velocidade <=255 ; velocidade += 20){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
  }
   if(velocidade>676 && velocidade< 859){
      for(velocidade = 0; velocidade <=255 ; velocidade += 25){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
  }
   if(velocidade>860 && velocidade< 1023){
      for(velocidade = 0; velocidade <=255 ; velocidade += 30){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
  }
}
/*FUNCAO DO POTENCIOMETRO COM LED LIGADO*/
void potenciometroIniciaLigado(){
  velocidade = analogRead(buttonPotenciometro);
  analogWrite(led_alto_brilho,velocidade/4);
    if(velocidade<164){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 1){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    } 
    if(velocidade>165 && velocidade<348){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 10){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    analogWrite(led_alto_brilho, LOW);
   } 
   if(velocidade>349 && velocidade<511){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 15){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
   } 
   if(velocidade>511 && velocidade< 675){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 20){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    analogWrite(led_alto_brilho, LOW);
  }
   if(velocidade>676 && velocidade< 859){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 25){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    analogWrite(led_alto_brilho, LOW);
  }
   if(velocidade>860 && velocidade< 1023){
      for(velocidade = 255; velocidade >=0 ; velocidade -= 30){
        analogWrite(led_alto_brilho, velocidade);
        delay(100);
      }
    analogWrite(led_alto_brilho, LOW);
  }
}
/*FUNCOES DOS BOTOES PARA INDICAR NO LCD
	CASO UM BOTAO FOI ACIONADO*/
void btn1LCD(){
  if(EstadoBotao1 == HIGH){
    lcd.print("Botao 1 acionado");
    lcd.print(EstadoBotao1);
    lcd.setCursor(1,0);
    delay(1000);
  }
}

void btn2LCD(){
  if(EstadoBotao2 == HIGH){
    lcd.print("Botao 2 acionado");
    lcd.print(EstadoBotao2);
    lcd.setCursor(1,0);
    delay(1000);
  }
}
