/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "/Users/mbackus/Desktop/WasteSensor/src/WasteSensor.ino"
/**************************************************************************/
/*!
    @author   K. Townsend (Adafruit Industries)
    @license  BSD (see license.txt)
    This is an example for the Adafruit MMA8451 Accel breakout board
    ----> https://www.adafruit.com/products/2019
    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!
    @section  HISTORY
    v1.0  - First release
*/
/**************************************************************************/

#include <Wire.h>
#include <../lib/Adafruit_MMA8451/src/Adafruit_MMA8451.h>
#include <../lib/Adafruit_Sensor/src/Adafruit_Sensor.h>

void setup(void);
void loop();
bool verifyDumpsterUpsideDown(Adafruit_MMA8451 accelerometer);

#line 19 "/Users/mbackus/Desktop/WasteSensor/src/WasteSensor.ino"
Adafruit_MMA8451 mma = Adafruit_MMA8451();

// TODO Write Code
// ATM: return true;
bool verifyDumpsterUpsideDown(Adafruit_MMA8451 accelerometer) {
  // Read the 'raw' data in 14-bit counts
  // mma.read();
  // Serial.print("X:\t"); Serial.print(mma.x); 
  // Serial.print("\tY:\t"); Serial.print(mma.y); 
  // Serial.print("\tZ:\t"); Serial.print(mma.z); 
  // Serial.println();

  // /* Get a new sensor event */ 
  // sensors_event_t event; 
  // mma.getEvent(&event);

  // /* Display the results (acceleration is measured in m/s^2) */
  // Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  // Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  // Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  // Serial.println("m/s^2 ");
  
  // /* Get the orientation of the sensor */
  // uint8_t o = mma.getOrientation();
  
  // switch (o) {
  //   case MMA8451_PL_PUF: 
  //     Serial.println("Portrait Up Front");
  //     break;
  //   case MMA8451_PL_PUB: 
  //     Serial.println("Portrait Up Back");
  //     break;    
  //   case MMA8451_PL_PDF: 
  //     Serial.println("Portrait Down Front");
  //     break;
  //   case MMA8451_PL_PDB: 
  //     Serial.println("Portrait Down Back");
  //     break;
  //   case MMA8451_PL_LRF: 
  //     Serial.println("Landscape Right Front");
  //     break;
  //   case MMA8451_PL_LRB: 
  //     Serial.println("Landscape Right Back");
  //     break;
  //   case MMA8451_PL_LLF: 
  //     Serial.println("Landscape Left Front");
  //     break;
  //   case MMA8451_PL_LLB: 
  //     Serial.println("Landscape Left Back");
  //     break;
  //   }
  // Serial.println();
  // delay(500);
  return true;
}

// EEPROM

void setup(void) {
  Serial.begin(9600);

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
  
}

void loop() {

  mma.read();

  bool dumpster_upside_down = verifyDumpsterUpsideDown(mma);

  String data = "dumpster service event confirmed";
  if (dumpster_upside_down) {
    Particle.publish("dumpster-flipped", data, PRIVATE);
    delay(3000);
  }
  else {}

  System.sleep(D8, RISING);



  
}