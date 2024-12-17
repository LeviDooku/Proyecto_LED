/* 
  ******************************************************
  * led_test.ino                                        *
  * Proyecto: Señal LED - V0.1                         *
  * Autores:                                           *
  *   - David Jándula Sánchez                          *
  *   - Pedro Velasco Santana                          *
  *                                                    *
  * Granada - 2024                                     *
  ******************************************************
*/

/*
Resumen de funcionamiento:

Programa que alterna Rojo, Verde y Azul en 10 led's de la matriz con 
tres niveles de intensidad para cada color. Objetivo: medir consumo
eléctrico de los led's a distintas intensidades.
*/

#include <FastLED.h>

#define DATA_PIN 4          //Data pin
#define NUM_LEDS 10        //Número total LED's
#define BRIGHTNESS_LEVELS 3 //Niveles de brillo: 15%, 50%, 100%
#define DURATION 10000      //Duración en ms por nivel de brillo (10 segundos)
