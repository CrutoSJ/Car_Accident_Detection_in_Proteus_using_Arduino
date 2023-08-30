#include <LiquidCrystal.h>
#include <TinyGPS.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
const int relay_Pin = 2;
int triggerPin =10;
int echoPin = 11;
const int vibration_Sensor = 12;
TinyGPS gps;
long lat,lon;
bool vibration_Status = LOW;
long duration, distance;
void setup() {
  pinMode(relay_Pin, OUTPUT);
  pinMode(vibration_Sensor, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("ACCIDENT DETECTION");
  lcd.setCursor(3,2);
  lcd.print("SYSTEM");
  delay(500);  
}
void loop() {   
       digitalWrite(relay_Pin, HIGH);   
        delay(200);  
        lcd.clear();
        lcd.print("Vehicle Started");
        delay(500);     
        while(1)
        {   
          vibration_Status = digitalRead(vibration_Sensor);
          delay(100);   
          ultrasonic();
          delay(100); 
          if((vibration_Status == HIGH )  && (distance < 5))
          {
           delay(100);
           digitalWrite(relay_Pin, LOW);  
           delay(100);
           lcd.clear();
           lcd.print("Accident Detected");
           lcd.setCursor(3,2);
           lcd.print("Sending Msg");
           delay(500);    
           Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
           delay(100);  // Delay of 1000 milli seconds or 1 second
           Serial.println("AT+CMGS=\"+919922512017\"\r"); // Replace x with mobile number
           delay(100);
           Serial.println("Accident Detected ");// The SMS text you want to send
           Serial.println("please check location");// The SMS text you want to send
           while(1)
           {
            gps_read();

           }
          }
}
}

void gps_read()
{ 
 byte a;
  
  if(Serial.available())  
  {
    a=Serial.read();
   
   //Serial.write(a);
   
    while(gps.encode(a))   // encode gps data 
    { 
      gps.get_position(&lat,&lon); // get latitude and longitude
    
      Serial.println("Position: ");
      Serial.print("lat:");
      Serial.println((lat*0.000001),8);
      Serial.print("log:");
      Serial.println((lon*0.000001),8);
    }
  }
}

void ultrasonic()
{ // variable to hold the duration and distance value for HC-SR04
  digitalWrite(triggerPin, LOW); // Write trigger pin is as low
  delayMicroseconds(2); // Delay for 2microseconds
  digitalWrite(triggerPin, HIGH); //Write trigger pin is as high
  delayMicroseconds(10);// Delay for 10microseconds
  digitalWrite(triggerPin, LOW); //Write trigger pin is as low
  duration = pulseIn(echoPin, HIGH);//Read the echo pin
  distance = (duration / 2) / 29.1; // calculate the distance
}
