/* MAIN THEME: Using the Ultrasonic sensor   
MAIN GOAL: The main goal of this code and activity is to read The distnace if an object with the Ultrasonic sensor and 
displays that distance value on the Serial Monitor  
*/
#define trigPin 10  //trigger pin of ultrasonic sensor sat as pin 10
#define echoPin 13  //echo pin of ultrasonic sensor set as pin 13
#define MAX_DISTANCE 400  //max distance the sensor can measure
#include <LiquidCrystal.h>   //Library for controlling the LCD
float duration, distance;     //var for storing time and calculated distance
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //LCD pin connections: RS,EN,D4,D5,D6,D7
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    //start LCD object

void setup() { 
Serial.begin (9600);  //starts communication with serial board @9600bit/seconds
pinMode(trigPin, OUTPUT);  //trigger pin set as OUTPUT
pinMode(echoPin, INPUT);    //echo pin set as INPUT
lcd.begin(16, 2);       //initialize LCD with 16 columns and 2 rows
 lcd.print("Distance = ");  //print Distance = on first row
} 

void loop() { 
 digitalWrite(trigPin, LOW); //trigger pin set as LOW
 delay(2);                  //wait 2 ms
 digitalWrite(trigPin, HIGH);  //trigger HIGH (ON)
 delay(1);                    //wait 1 ms
 digitalWrite(trigPin, LOW);    //trigger pin LOW (OFF)
 duration = pulseIn(echoPin, HIGH);  //measures time for echo when HIGH
 distance = (duration / 2) * 0.0343;  //convert time to distance (cm)
 Serial.print("Distance = ");           //print Distance = 
 if (distance >=400 || distance <=2) {  //check if distance is outside sensor range
  Serial.println("Out of Range");       //if true print out of range
 } 
 else { 
  Serial.print(distance); //print distance value
  Serial.println(" cm");  //print unit in cm
  lcd.print(distance); //print distance on LCD
  lcd.print(" cm");   //print unit
    delay(500);       //wait 0.5Seconds
 }
 delay(500); 
} 
 
