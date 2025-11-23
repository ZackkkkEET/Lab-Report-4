/* MAIN THEME: Using Joysticks + Stepper Motor
MAIN GOAL: The main goal of this code and activity is to use a Joystick to control  
the Stepper motors speedY and directionX
*/   
#include <Stepper.h> 
// --- Stepper settings --- 
const int stepsPerRevolution = 2048;     // 28BYJ-48 motor 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); 
// --- Joystick pins --- 
int xPin = A0;   // left/right = direction 
int yPin = A1;   // up/down = speed 
int xVal, yVal; 
int stepSpeed; 

void setup() { 
  Serial.begin(9600);    //starts communication with serail board @9600bit/seconds
  myStepper.setSpeed(0);   // start with motor stopped 
} 
 
void loop() { 
  // Read joystick values 
  xVal = analogRead(xPin);   // 0–1023 
  yVal = analogRead(yPin);   // 0–1023 
  // --- Direction control --- 
  // Center is ~512 
  // Move left = CCW 
  // Move right = CW 
  int direction = 0; 
  if (xVal < 400) { 
    direction = -1;  // CCW 
  }  
  else if (xVal > 600) { 
    direction = 1;   // CW 
  }  
else { 
direction = 0;   // joystick centered 
  } 
  // --- Speed control --- 
  // Push joystick up = faster 
  // Push down = slower 
  // Map 0–1023 → 0–15 RPM 
  stepSpeed = map(yVal, 0, 1023, 0, 15); 
  myStepper.setSpeed(stepSpeed);
  // --- Move motor --- 
  if (direction == 1) { 
    myStepper.step(5);     // small forward step 
  }  
  else if (direction == -1) { 
    myStepper.step(-5);    // small backward step 
  }  
  // Debug info 
  Serial.print("X: ");       //print X:
  Serial.print(xVal);          //print x value
  Serial.print(" | Y: ");       //seperate and print Y:
  Serial.print(yVal);           //print Y value
  Serial.print(" | Speed: ");      //seperate and print Speed:
  Serial.print(stepSpeed);          //print speed value
  Serial.print(" | Direction: ");    //seperate and print Direction:
  Serial.println(direction);            //print direction value
} 