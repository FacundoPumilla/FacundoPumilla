//#####DEBUGGING#####
#define DEBUG_ENABLE
#ifdef DEBUG_ENABLE
#define PTN(x) Serial.println(x)
#define PT(x) Serial.print(x)
#else
#define PTN(x)
#define PT(x)
#endif
//#####DEBUGGING#####

#include <Arduino.h>

#include "var.h"
#include "OneButton.h"
#include "temperatura.h"
#include "function.h"

OneButton btnD3(InputD3, true, false);
OneButton btnD4(InputD4, true, false);
OneButton btnD5(InputD5, true, false);
OneButton btnD6(InputD6, true, false);

void btnD3Click(){
  LedBlink(LedRed, 4);
}
void btnD4Click(){
  LedBlink(LedGreen, 6);
}
void btnD5Click(){
  LedBlink(LedRed, 8);
}
void btnD6Click(){
  LedBlink(LedGreen, 10);
}

void setup() {
  Serial.begin(9600);

  sensorTemp.begin();

  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  
  pinMode(InputD3, INPUT);
  pinMode(InputD4, INPUT);
  pinMode(InputD5, INPUT);
  pinMode(InputD6, INPUT);

  btnD3.attachClick(btnD3Click);
  btnD4.attachClick(btnD4Click);
  btnD5.attachClick(btnD5Click);
  btnD6.attachClick(btnD6Click);

  #ifdef DEBUG_ENABLE
  while(!Serial);
  PTN("## Sensor de temperatura iniciado ##");
  PT("Sensores encontrados en setup: ");
  static int numDev = sensorTemp.getDeviceCount();
  Serial.println(numDev, DEC);
  //discoverOneWireDevices();
  PT("Temperatura actual: ");
  PTN(sensorTemp.getTempCByIndex(0));
  #endif
}

void loop() {
  btnD3.tick();
  btnD4.tick();
  btnD5.tick();
  btnD6.tick();
}