// code for analysis of RC circiut
float v1=0;
void setup() {
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Computer Time,Time (Milli Sec.),Volt");

}

void loop() {
  v1=(float)5.0*analogRead(A0)/1024.0;
  Serial.print("DATA,TIME,");
  Serial.print(millis());
  Serial.print(",");
  Serial.println(v1);
  delay(100);
}
