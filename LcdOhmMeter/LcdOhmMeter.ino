/* MAIN THEME: Using the Arduino as a ohm meter + LCD display.  
MAIN GOAL: The main goal of this code and activity is to read an analog value from pin A0, to convert 
it into a real voltage value (0–5V), To calulate the current, and then to find the "unknow" resistor value
and to display that resistor value on both the Serial Monitor and LCD screen.            
*/ 
#include <LiquidCrystal.h>   // include the library code:  
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   
// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to   
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
byte OHM[8] = {        //creates Ohm symbole
  B00000, 
  B00000, 
  B01110, 
  B10001, 
  B10001, 
  B01010, 
  B11011, 
}; 

void setup() {    
lcd.begin(16, 2);     // set up the LCD's number of columns and rows:  
Serial.begin (9600);   //starts communication with serial board @9600bit/seconds
lcd.createChar (12, OHM);  //stores and creates the ohm symbole
lcd.setCursor (9,0);         //sets the symbole at coordinates
lcd.write(12);               //display symbole
}   

void loop() {   
  lcd.clear9);           //clears lcd screen of all numbers
  lcd.setCursor(0,0);   // set the cursor to column 0, line 
  int sensorValue = analogRead(A0); //read the input on analog pin 0:    

 Serial.print("  Va Bitvalue = ");  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):      
 Serial.print(sensorValue);  // print out the value you read:    
Serial.print ("\t");  //tab creates space 
float voltage = sensorValue * (5.0/1023.0);   //converts bit to voltage
Serial.print ("Voltage = ");      //prints Bitvalue =    
Serial.print(voltage);         // prints the actual sensor value (0-1023  
Serial.print ("\t");             //tab creates space
float current = (5.0 - voltage) / 10000.0 *1000.0;  //calculates current  
Serial.print("Current = ");           //prints "Current ="
Serial.print(current);                //prints current value of float current
float resistor = voltage / current;      //calculates unknown resistor value
Serial.print ("\t");                    //tab creates space
Serial.print (" Resistor = ");            //prints "Resistor = "
Serial.println (resistor);               //prints actual resistor value
lcd.print("R = ");                        //prints "R = " on LCD screen
lcd.print(resistor);                       //prints resistor value on LCD screen
delay(500);                                //wait 0.5 seconds
}   

 