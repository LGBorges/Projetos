//DECLARA PORTAS DO MOTOR 1
#define velm1 3
#define m1a 2
#define m1b 4
//DECLARA PORTAS DO MOTOR 2
#define velm2 11
#define m2a 12
#define m2b 13
//DECLARA PORTAS DO MOTOR 3
#define velm3 6
#define m3a 7
#define m3b 8
//DECLARA PORTAS DO LED RGB 1
#define ledR1 5
#define ledG1 9
#define ledB1 10
//DECLARA PORTAS DO LED RGB 2
#define ledR2 A0
#define ledG2 A1
#define ledB2 A2
//DECLARA PORTAS DO LED RGB 3
#define ledR3 A3
#define ledG3 A4
#define ledB3 A5
//DECLARA RPM INICIAL
int RPM400 = 6.8;
int RPM800 = 12.6;
int RPM1200 = 19;
//DECLARA RPM FINAL
int RPM600 = 9;
int RPM1000 = 16;
int RPM2000 = 31;

void setup(){
  //SAÍDA MOTOR 1
  pinMode(velm1, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  //SAÍDA MOTOR 2
  pinMode(velm2, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  //SAÍDA MOTOR 3
  pinMode(velm3, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  //SAÍDA LED RGB 1
  pinMode(ledR1, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledB1, OUTPUT);
  //SAÍDA LED RGB 2
  pinMode(ledR2, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledB2, OUTPUT);
  //SAÍDA LED RGB 3
  pinMode(ledR3, OUTPUT);
  pinMode(ledG3, OUTPUT);
  pinMode(ledB3, OUTPUT);
  //ESCRITA DO MOTOR 1
  analogWrite(velm1, 0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  //ESCRITA DO MOTOR 2
  analogWrite(velm2, 0);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  //ESCRITA DO MOTOR 3
  analogWrite(velm3, 0);
  digitalWrite(m3a, LOW);
  digitalWrite(m3b, LOW);
}

void loop(){
  motor1_led_Laranja();
  motor2_led_Vermelho();
  motor3_led_Vermelho();
  parado();
}

void motor1_led_Laranja(){
  //M1 + led laranja
  analogWrite(ledR1, 255);
  analogWrite(ledG1, 110);
  analogWrite(ledB1, 20);
  
  analogWrite(velm1, RPM400);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  delay(3000);
  analogWrite(velm1, RPM600);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  delay(3000);
}

void motor2_led_Vermelho(){
  //M2 + led vermelho
  analogWrite(ledR2, 255);
  analogWrite(ledG2, 0);
  analogWrite(ledB2, 0);
  
  analogWrite(velm2, RPM800);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  delay(3000);
  analogWrite(velm2, RPM1000);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  delay(3000);
}

void motor3_led_Vermelho(){
  //M3 + led vermelho
  analogWrite(ledR3, 255);
  analogWrite(ledG3, 0);
  analogWrite(ledB3, 0);
  
  analogWrite(velm3, RPM1200);
  digitalWrite(m3a, HIGH);
  digitalWrite(m3b, LOW);
  delay(4000);
  
  analogWrite(velm3, RPM2000);
  digitalWrite(m3a, HIGH);
  digitalWrite(m3b, LOW);
  delay(4000);
}

void parado(){
  //LED VERDE
  analogWrite(ledR1, 0);
  analogWrite(ledG1, 255);
  analogWrite(ledB1, 0);
  
  analogWrite(ledR2, 0);
  analogWrite(ledG2, 255);
  analogWrite(ledB2, 0);
  
  analogWrite(ledR3, 0);
  analogWrite(ledG3, 255);
  analogWrite(ledB3, 0);
  
  //PARA MOTORES
  analogWrite(velm1, 0);
  digitalWrite(m1a, 0);
  digitalWrite(m1b, 0);
  
  analogWrite(velm2, 0);
  digitalWrite(m2a, 0);
  digitalWrite(m2b, 0);
  
  analogWrite(velm3, 0);
  digitalWrite(m3a, 0);
  digitalWrite(m3b, 0);
  
  delay(3000);
  
  //APAGA LEDS
  analogWrite(ledR1, 0);
  analogWrite(ledG1, 0);
  analogWrite(ledB1, 0);
  
  analogWrite(ledR2, 0);
  analogWrite(ledG2, 0);
  analogWrite(ledB2, 0);
  
  analogWrite(ledR3, 0);
  analogWrite(ledG3, 0);
  analogWrite(ledB3, 0);
  
  delay(500);
}
