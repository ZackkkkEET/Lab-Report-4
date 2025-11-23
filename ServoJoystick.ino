/* MAIN THEME: Using Joysticks 
MAIN GOAL: The main goal of this code and activity is to use a joystick and read x/y axis location and  
then to display that X/Y position value on the Serial Monitor   
*/ 
int xPin = A0; //x-axis joystick set as Pin A0
int yPin = A1;  //x-axis joystick set as Pin A1
int ButtonPin = 2; //joystick set as pin 2
int xVal;       //variable stores reading x
int yVal;       //variable stores reading y
int buttonState;     //variable stores reading Button

void setup() { 
  Serial.begin(9600);   //starts communication with serial board @9600bit/seconds
pinMode(xPin, INPUT);    //X pin set as INPUT
pinMode(yPin, INPUT);     //Y pin set as INPUT
pinMode(2, INPUT_PULLUP);     //pin 2 set as INPUT_PullUP (Press =0, not =1)
} 

void loop() { 
 xVal = analogRead (xPin);   //read bit value X
 yVal = analogRead (yPin);   //read bit value Y
buttonState = digitalRead (2);     //read button state Pin 2
Serial.print("X: ");             //print "x: "
Serial.print(xVal);             //print X value
Serial.print(" | Y: ");         //seperate and print "Y: " on same line
Serial.print(yVal);             //print Y value
Serial.print(" | Button: ");     //seperate again and print "Button: " on same line
Serial.println(buttonState);      //print button state 
delay(100);                       //wait 1ms
} 