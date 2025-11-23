/* MAIN THEME: Using the DHT11 sensor  
MAIN GOAL: The main goal of this code and activity is to read The room temperature 
and Humidity with the DHT11 sensor and displays that voltage on both the Serial Monitor           
*/ 
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library 
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor 
#include <Adafruit_Sensor.h> 
#include <DHT.h> 
#include <DHT_U.h> 
#define DHTPIN 6     // Digital pin connected to the DHT sensor  
#define DHTTYPE    DHT11     //#define DHTTYPE as DHT11   
DHT_Unified dht(DHTPIN, DHTTYPE); 
uint32_t delayMS; 

void setup() { 
  Serial.begin(9600); //starts communication with serial board @9600bit/seconds
  dht.begin();         //initialize the DHT sensor
  Serial.println(F("DHTxx Unified Sensor Example"));   
  // Print temperature sensor details
  sensor_t sensor; 
  dht.temperature().getSensor(&sensor); 
  Serial.println(F("------------------------------------")); 
  Serial.println(F("Temperature Sensor")); 
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name); 
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version); 
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id); 
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C")); 
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C")); 
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C")); 
  Serial.println(F("------------------------------------")); 
  dht.humidity().getSensor(&sensor); 
  Serial.println(F("Humidity Sensor")); 
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name); 
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version); 
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id); 
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%")); 
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%")); 
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%")); 
  Serial.println(F("------------------------------------")); 
  delayMS = sensor.min_delay / 1000;   // Set delay between sensor readings based on sensor details. 
} 

void loop() { 
  delay(1000); //Delay between measurements. 
  sensors_event_t event; 
   // ---- Read Temperature ----
  dht.temperature().getEvent(&event); 
  if (isnan(event.temperature)) { 
    Serial.println(F("Error reading temperature!")); 
  } 
  else { 
    Serial.print(F("Temperature: ")); 
    Serial.print(event.temperature); 
    Serial.println(F("°C")); 
  } 
  dht.humidity().getEvent(&event); 
  // ---- Read Humidity ----
  if (isnan(event.relative_humidity)) { 
    Serial.println(F("Error reading humidity!")); 
  } 
  else { 
    Serial.print(F("Humidity: ")); 
    Serial.print(event.relative_humidity); 
    Serial.println(F("%")); 
  } 
} 