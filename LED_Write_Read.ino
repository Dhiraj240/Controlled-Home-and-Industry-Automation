char command;
String string;
boolean ledon = false;
#define led 5
/*
temp lights LM35 and leds
*/
/*
temp lights LM35 and leds
*/
float val;
float tempPin = A0;
float temp;
byte redPin=8, bluePin=13; // swap numbers for words
int x ;

  void setup()
  {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
     pinMode(A0,INPUT);
  Serial.begin(9600);
Serial.begin(9600);
  pinMode (13, OUTPUT); //red LED symbolising Cold and Not Fit for Consumption
  pinMode (8, OUTPUT); //Green LED symbolising Lukewarm and Read for Consumption
  
  pinMode (tempPin, INPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(1);
    }
    
    if(string == "TO")
    {
        ledOn();
        ledon = true;
    }
    
    if(string =="TF")
    {
        ledOff();
        ledon = false;
        Serial.println(string);
    }
    
    if ((string.toInt()>=0)&&(string.toInt()<=255))
    {
      if (ledon==true)
      {
        analogWrite(led, string.toInt());
        Serial.println(string);
        delay(10);
      }
    }
     if (temp < 32) //when temp is between 0-35 degrees
  {
  digitalWrite(13, LOW);//red led is off
  digitalWrite(8, HIGH);  //green led is on
  }
else if (temp > 32) //when temp is above 40 degrees
{
  digitalWrite(13, HIGH); //red led is on
  digitalWrite(8, LOW); //green led is off
  
}
   
     val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
  
 }
 
void ledOn()
   {
      analogWrite(led, 255);
      delay(10);
    }
 
 void ledOff()
 {
      analogWrite(led, 0);
      delay(10);
 }
 

    
