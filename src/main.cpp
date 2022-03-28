#include <Arduino.h>

#include "OneButton.h"
#include "var.h"
#include "function.h"

OneButton btnD3(InputD3, true, false);
OneButton btnD4(InputD4, true, false);
OneButton btnS2(InputS2, true, false);
OneButton btnS3(InputS3, true, false);

void btnD3Click(){
  LedBlink(LedRed, 4);
}
void btnD4Click(){
  LedBlink(LedGreen, 6);
}
void btnS2Click(){
  LedBlink(LedRed, 8);
}
void btnS3Click(){
  LedBlink(LedGreen, 10);
}

void setup() {
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  
  pinMode(InputD3, INPUT);
  pinMode(InputD4, INPUT);
  pinMode(InputS2, INPUT);
  pinMode(InputS3, INPUT);

  btnD3.attachClick(btnD3Click);
  btnD4.attachClick(btnD4Click);
  btnS2.attachClick(btnS2Click);
  btnS3.attachClick(btnS3Click);
}

void loop() {
  btnD3.tick();
  btnD4.tick();
  btnS2.tick();
  btnS3.tick();
}