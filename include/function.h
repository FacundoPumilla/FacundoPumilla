#pragma once
#include <Arduino.h>

void LedBlink(int colorLed, int x){
    int cont=0;
    bool stateLed = true;
    do{
        if(millis() - newMillis >= intervalo){
            digitalWrite(colorLed, stateLed);
            newMillis = millis();
            cont++;
            stateLed = !stateLed;
        }
    }while(cont < x*2);
}

void discoverOneWireDevices(void) {
  byte addr[8];
  
  Serial.println("Buscando dispositivos 1-Wire");
  while (oneWire.search(addr)) 
  {  
  Serial.print("Address = ");
  for( int i = 0; i < 8; i++) {
    Serial.print(" 0x");
    Serial.print(addr[i], HEX);
  }
  Serial.println();
}

Serial.println();
oneWire.reset_search();
delay(2000);
}