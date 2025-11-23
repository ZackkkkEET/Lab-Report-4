/* MAIN THEME: Using servo motor + LDR
MAIN GOAL: The main goal of this code and activity is to use a LDR sensor to control 
the servo motor
*/  
#include <Servo.h> 
Servo myservo;  // create Servo object to control a servo 
int LDRPIN = A0;  // 
int LDRval;    // variable to read the value from the analog pin 
float angle; 
void setup() { 
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object 
  Serial.begin(9600); 
} 

void loop() { 
  val = analogRead(LDRPIN);            // reads the value of the potentiometer (value between 0 and 1023) 
  angle = map(LDRval, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180) 
  myservo.write(angle);                  // sets the servo position according to the scaled value 
  delay(15);                          //wait 15ms
  Serial.print("LDR Reading = ");            
  Serial.print(LDRval);
  Serial.print(" | Servo Angle = ");
  Serial.println(angle);
}
 