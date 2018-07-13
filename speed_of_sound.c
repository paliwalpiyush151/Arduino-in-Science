// code to find speed of sound using ultrasonic sensor and it's activation using clap switch
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int sensorValue = 0,sensorValue1=0;
int trigPin=13,echoPin=7;
int distance=60;   // fixed distance in my case is 60cm. 
int p=0,time;

void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Setup is ready");
  pinMode(6,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}
void loop() 
{
 sensorValue = analogRead(0); 
 if(sensorValue>50)  // when microphone sense sound of high intensity 
  {
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
  delay(1000);
  p++;
  }
  if(p==1) // when clap switch becomes active then sensor becomes active 
  {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2000);
    digitalWrite(trigPin,HIGH);
    digitalWrite(trigPin,LOW);
    time=pulseIn(echoPin,HIGH);
    p=(double)time/1000000;
   Serial.print("Speed of sound is :");
   Serial.print((float)(distance*2)/(p*100));
   Serial.println("m/s");
   lcd.setCursor(0,0);
   lcd.println("Velocity of sound");
   lcd.setCursor(0,1);
   lcd.print((float)(distance*2)/(p*100));
   lcd.print(" ");
   lcd.print("m/s");
   delay(4000);
   lcd.setCursor(0,0);
   lcd.println("-setup is ready-");
   lcd.setCursor(0,1);
   lcd.println("               ");
   p=0;
  }
}
