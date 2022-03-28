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