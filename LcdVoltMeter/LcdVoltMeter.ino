/* MAIN THEME: Using the Arduino as a voltmeter + LCD display. 
MAIN GOAL: The main goal of this code and activity is to read an analog value from pin A0, to convert it into a real voltage value (0–5V), 
and displays that voltage on both the Serial Monitor and LCD screen.
*/
#include <LiquidCrystal.h>   // include the library code:   
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   
// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to   
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   

void setup() {   
lcd.begin(16, 2);   // set up the LCD's number of columns and rows:   
Serial.begin (9600);    //starts communication with serial board @9600bit/seconds
 }   

void loop() {   
  lcd.setCursor(0,0);    // set the cursor to column 0, line  
  int sensorValue = analogRead(A0);  // store value of analog pin A0  
Serial.print("  Va Bitvalue = ");      //Print "Va Bitvalue ="  
Serial.print(sensorValue);             //Print sensor value  
Serial.print ("\t");                     //creates a TAB  
float voltage = sensorValue * (5.0/1023.0);    //turns the bit value (0–1023) into voltage (0–5V) by calculating  
Serial.print ("Voltage = ");      //prints "Voltage =" 
Serial.print(voltage);            //prints actual voltage calculation results  
lcd.print("V = ");               //Prints 'V =" on " LCD screen
lcd.print(voltage);                //Prints voltage value on " LCD screen
delay (2000);                      //wait 2000 milliseconds 
}   