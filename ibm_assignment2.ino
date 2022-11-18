int t=2;
int e=3;
void setup()
{
  pinMode(t,OUTPUT);
  pinMode(e,INPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}
void loop()
{
  /* The Ultrasonic sensors can be used in water tanks at home
  and this sensor plays a buzzer sound when the water is about 
  to overflow and this inturn will reduce the wastage of water*/
  digitalWrite(t,9); 
  digitalWrite(t,1);
  delayMicroseconds(10);
  digitalWrite(t,0);
  float dur = pulseIn(e,HIGH);
  float dis = (dur*0.0343)/2;
  Serial.print("Distance in cm is: ");
  Serial.println(dis);
  if(dis<15)
  {
  tone(12,30);
  delay(1000);
  }
  else
  {
    noTone(12);
    delay(1000);
  }
  /* The PIR sensor can be fitted in the doors of houses 
  and if motion is detected the led will glow and this 
  will be an automatic notification */ 
  digitalWrite(11,LOW);
  int a = digitalRead(4);
  if(a==1)
  {
    Serial.println("Motion Detected");
    digitalWrite(11,HIGH);
  }
}
