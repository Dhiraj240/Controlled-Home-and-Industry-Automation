
float val;
float tempPin = A0;
float temp;
byte redPin=8, bluePin=13; // swap numbers for words
int x ;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
Serial.begin(9600);
  pinMode (13, OUTPUT); //red LED 
  pinMode (8, OUTPUT); //Green LED
  
  pinMode (tempPin, INPUT);  
}

  void loop() {
    x = analogRead(A0);
  Serial.println(x);
  delay(2000);
     temp = analogRead(tempPin);
     temp = temp * 0.48828125;

  delay(1000);
  if (temp < 34) //when temp is between 0-35 degrees
  {
  digitalWrite(13, LOW);//red led is off
  digitalWrite(8, HIGH);  //green led is on
  }
else if (temp > 34) //when temp is above 40 degrees
{
  digitalWrite(13, HIGH); //red led is off
  digitalWrite(8, LOW); //right red led is on
  
}
  
     val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(100);
  

    }
