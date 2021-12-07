/*Criado por Leônidas Gomes Borges
Plataforma Arduino - Linguagem C*/

//inclui bibliotecas
#include <Servo.h>
#include <LiquidCrystal.h>

//indica quais portas serão usadas no LCD
LiquidCrystal lcd(7,8,10,11,12,13);

//declara as variaveis
int celsius = 0;
int Temp = 40;
const int motor = 2;
const int ledPinRed = 3;
const int ledPinBlue = 5;
const int ledPinGreen = 6;
const int sensorTemp = A0;
const int buzzer = A1;
const int ldrPin = A2;
//nomeia o servo
Servo servo;
//angulos de giro do motor
int pos = 0;
void setup()
{
  Serial.begin(9600);//para ler o retorno numeral de alguma variavel
  servo.attach(motor);
  pinMode(sensorTemp, INPUT);//entradas e saidas no arduino
  pinMode(ldrPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
}

void loop()
{
  celsius = map(((analogRead(sensorTemp) - 20) * 3.04), 0, 1023, -40, 125); //seta o menor/maior bit para a menor/maior temperatura
  Serial.println(celsius);
  //como estado inicial, o controle deslizante do sensor de temperatura marca -15 ºC,
  //então é feita o cálculo para converter o estado inicial
  //sendo, ((sensorTemp) - 20) * 3.04), para iniciar em 25 ºC.
  lcd.begin(16,2);
  lcd.print("Temp:");// Temperatura
  lcd.print(celsius);
  lcd.print(" C");// Celsius
  lcd.setCursor(0,1);
  lcd.print("Luz Am: ");// Luz Ambiente
  lcd.setCursor(11,0);
  lcd.print("M: ");// Motor
  lcd.setCursor(11,1);
  lcd.print("A: ");// Alarme
  int ldrStatus = analogRead(ldrPin);
  
  if (ldrStatus <= 54) // essa condição funciona, o led muda de cor e muda no lcd
  {
    digitalWrite(ledPinRed, HIGH);//acende led branco
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    lcd.setCursor(7,1);
    lcd.print("Nao");
  }
  else // essa condição funciona, o led muda de cor e muda no lcd
  {
    digitalWrite(ledPinRed, LOW);//acende led verde
    digitalWrite(ledPinBlue, LOW);
    digitalWrite(ledPinGreen, HIGH);
    lcd.setCursor(7,1);
    lcd.print("Sim");
  }
  
   if (celsius >= Temp)//essa condição funciona, o led muda de cor e o servo gira
  {
    digitalWrite(ledPinRed, HIGH);//acende led vermelho
    digitalWrite(ledPinBlue, LOW);
    digitalWrite(ledPinGreen, LOW);
    analogWrite(buzzer, 255);//aciona o buzzer
    delay(850);
    analogWrite(buzzer, 0);//para o buzzer
    delay(850);
    lcd.setCursor(13,0);
    lcd.print("ON");
    lcd.setCursor(13,1);
    lcd.print("ON");
    for(pos = 0; pos <= 180; pos += 1)//gira até a metade do motor
  	{
    	servo.write(pos);
    	delay(15);
 	 }
    for(pos = 0; pos >= 180; pos -= 1)//gira a outra metade do motor até a posição inicial
    {
    	servo.write(pos);
    	delay(15);
    }
   }
  else
    lcd.setCursor(13,0);
    lcd.print("OFF");
    lcd.setCursor(13,1);
    lcd.print("OFF");
}
