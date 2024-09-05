#include "HX711.h"

#define calibration_factor 441800.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2

HX711 scale;
long long start;
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  Serial.println("Readings:");
  while(!Serial.available());
  start = millis();
  digitalWrite(9, LOW);
}

void loop() {
  if (start+ 1000 <= millis()) digitalWrite(9, HIGH);
  Serial.print(scale.get_units(), 3); //scale.get_units() returns a float
  Serial.println();
}