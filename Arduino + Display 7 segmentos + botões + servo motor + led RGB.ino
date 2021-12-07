/*Criado por Leônidas Gomes Borges
15/04/2021*/

//Inclui biblioteca do servo motor
#include <Servo.h>

/*
Resistores do display = 220 ohms
Resistores dos botões = 10k ohms
Resistor do led RGB = 220 ohms
Fonte de alimentação do circuito = 5V
Fonte de alimentação do motor = 9V
*/

//Declarando variáveis nas portas para o Display de 7 segementos
const int pin_DP = 1;
const int pin_a = 2;
const int pin_b = 3;
const int pin_c = 4;
const int pin_d = 5;
const int pin_e = 6;
const int pin_f = 7;
const int pin_g = 8;
//Declarando variáveis para os botões
const int btn1 = 9;
const int btn2 = 10;
const int btn3 = 11;
const int btn4 = 12;
//Declarando o estado dos botões
int estadoBtn1 = 0;
int estadoBtn2 = 0;
int estadoBtn3 = 0;
int estadoBtn4 = 0;
//Declarando os pinos do led RGB
const int led_R = A0;
const int led_G = A1;
const int led_B = A2;
//Declarando servo/motor
const int motor = A3;
Servo servo;
int pos = 0;

void setup()
{
  //Seta os botões como entrada
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  //Seta o display como saída
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(pin_DP, OUTPUT);
  //Seta o led RGB como saída
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  //Seta motor como saída
  pinMode(motor, OUTPUT);
}

void loop()
{
  //Leitura dos estados dos botões
  estadoBtn1 = digitalRead(btn1);
  estadoBtn2 = digitalRead(btn2);
  estadoBtn3 = digitalRead(btn3);
  estadoBtn4 = digitalRead(btn4);

  if(estadoBtn1 == HIGH){
    //Mostra numero ZERO
    displayZero();
    //Acende led R + G
    ledRG();
    //Motor
    velMot1();
  }
  else if(estadoBtn2 == HIGH){
    //Mostra numero UM
    displayUm();
    //Acende led R + B
    ledRB();
    //Motor
    velMot2();
  }
  else if(estadoBtn3 == HIGH){
    //Mostra numero DOIS
    displayDois();
    //Acende led G + B
    ledGB();
    //Motor
    velMot3();
  }
  else if(estadoBtn4 == HIGH){
    //Mostra numero TRÊS
    displayTres();
    //Acende led R + G + B
    ledRGB();
    //Motor
    velMot4();
  }
  else{
    desligaCircuito();
  }
}

void displayZero(){
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, HIGH);
    digitalWrite(pin_c, HIGH);
    digitalWrite(pin_d, HIGH);
    digitalWrite(pin_e, HIGH);
    digitalWrite(pin_f, HIGH);
    digitalWrite(pin_g, LOW);
    digitalWrite(pin_DP, LOW);
}

void displayUm(){
    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, HIGH);
    digitalWrite(pin_c, HIGH);
    digitalWrite(pin_d, LOW);
    digitalWrite(pin_e, LOW);
    digitalWrite(pin_f, LOW);
    digitalWrite(pin_g, LOW);
    digitalWrite(pin_DP, LOW);
}

void displayDois(){
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, HIGH);
    digitalWrite(pin_c, LOW);
    digitalWrite(pin_d, HIGH);
    digitalWrite(pin_e, HIGH);
    digitalWrite(pin_f, LOW);
    digitalWrite(pin_g, HIGH);
    digitalWrite(pin_DP, LOW);
}

void displayTres(){
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, HIGH);
    digitalWrite(pin_c, HIGH);
    digitalWrite(pin_d, HIGH);
    digitalWrite(pin_e, LOW);
    digitalWrite(pin_f, LOW);
    digitalWrite(pin_g, HIGH);
    digitalWrite(pin_DP, LOW);
}

void ledRG(){
    digitalWrite(led_R, HIGH);
    digitalWrite(led_G, HIGH);
    digitalWrite(led_B, LOW);
}

void ledRB(){
    digitalWrite(led_R, HIGH);
    digitalWrite(led_G, LOW);
    digitalWrite(led_B, HIGH);
}

void ledGB(){
    digitalWrite(led_R, LOW);
    digitalWrite(led_G, HIGH);
    digitalWrite(led_B, HIGH);
}

void ledRGB(){
    digitalWrite(led_R, HIGH);
    digitalWrite(led_G, HIGH);
    digitalWrite(led_B, HIGH);
}

void velMot1(){
    servo.attach(motor);
    for(pos = 0; pos <= 180; pos+=3){
      servo.write(pos);
      delay(225);
    }
    for(pos = 180; pos >= 0; pos-=6){
      servo.write(pos);
      delay(225);
    }
}

void velMot2(){
    servo.attach(motor);
    for(pos = 0; pos <= 180; pos+=9){
      servo.write(pos);
      delay(225);
    }
    for(pos = 180; pos >= 0; pos-=12){
      servo.write(pos);
      delay(225);
    }
}

void velMot3(){
    servo.attach(motor);
    for(pos = 0; pos <= 180; pos+=15){
      servo.write(pos);
      delay(225);
    }
    for(pos = 180; pos >= 0; pos-=18){
      servo.write(pos);
      delay(225);
    }
}

void velMot4(){
    servo.attach(motor);
    for(pos = 0; pos <= 180; pos+=20){
      servo.write(pos);
      delay(225);
    }
    for(pos = 180; pos >= 0; pos-=20){
      servo.write(pos);
      delay(225);
    }
}

void desligaCircuito(){
    //Apaga o display e deixa o ponto aceso
    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, LOW);
    digitalWrite(pin_c, LOW);
    digitalWrite(pin_d, LOW);
    digitalWrite(pin_e, LOW);
    digitalWrite(pin_f, LOW);
    digitalWrite(pin_g, LOW);
    digitalWrite(pin_DP, HIGH);
    //Apaga o led
    digitalWrite(led_R, LOW);
    digitalWrite(led_G, LOW);
    digitalWrite(led_B, LOW);
    //Desliga o motor
    servo.detach();
}
