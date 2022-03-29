#pragma once
#include <Arduino.h>

const int LedRed = 13;          //Led rojo, indica errores
const int LedGreen = 15;        //Led verde, indica estados.
// ##### INPUT #####
const int InputD3 = 0;          //Entrada digital D3+Gnd
const int InputD4 = 2;          //Entrada digital D4+Gnd
const int InputD5 = 14;         //Entrada digital Rele #2 220v
const int InputD6 = 12;         //Entrada digital Rele #1 220v

// ##### FUNCTION.H #####
unsigned long newMillis = 0;    //Almacena altualizacion de millis()
unsigned long intervalo = 250;  //Intervalo entre señales

// ##### Temperatura #####
#define ONE_WIRE_BUS 4          //D2 en el ESP8266