// code to find time travel by freely falling object using piezo electric sensors and photo interrupter
const int ledPin= 13;
const int threshold=1;
long int endTime=0,startTime=0;
double Time;
float d=0.9;  //hight of photointerrupter from piezosensors
int count=0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop()
{
  int val= analogRead(A0);   //analogpin connected to piezosensor-1
  int val2=analogRead(A1);   //piezosensor-2
  int val3=analogRead(A2);   //piezosensor-3
  int val4=analogRead(A3);   //piezosensor-4
  int val5=analogRead(A4);   //analogpin connected to photointerrupter
  Serial.print(val);	           // printing  values of each sensor on serial monitor
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.println(val5);

  if(val5>1000)   //when some object come in between interrupter analog pin becomes high
  {
    startTime=millis();
  }
  if (val>=threshold||val2>=threshold||val3>=threshold||val4>=threshold)
  {
   endTime=millis();
   Serial.print("EndTime : ");
   Serial.print((float)endTime/1000);
   Serial.print(" ");
   Serial.print("StartTime : ");
   Serial.println((float)startTime/1000);
   Serial.print("Time Of Flight : ");
   Time=(float)(endTime-startTime)/1000;
   Serial.println(Time);
   Serial.print("Acceleration of particle : ");
   Serial.println((d*2.0)/(Time*Time));
  
  digitalWrite(ledPin, HIGH);  // LED glowing
  delay(3000);
  digitalWrite(ledPin, LOW);
  delay(5000);
  }
  else
  {
  digitalWrite(ledPin, LOW);
  }
  delay(1);
}
