/* 
  ******************************************************
  * zigzag.ino                                         *
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

Programa que enciende los led's de 1/4 parte de la matriz uno por uno durante un
tiempo determinado. Objetivo: saber como viajan los datos dentro de la matriz.
*/

#include <FastLED.h>

#define NUM_LEDS 1024 // 16x32 = 512 LEDs
#define DATA_PIN 4   // Pin de datos donde está conectado el LED strip

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // Tiempo total para recorrer todos los LEDs
  unsigned long totalTime = 2000; // 2 segundos
  unsigned long delayTime = totalTime / NUM_LEDS; // Tiempo de espera por LED

  for (int i = 0; i < NUM_LEDS; i++) {
    // Encender el LED actual
    leds[i] = (i%0xFF); // Cambia el color si lo deseas
  }
  delay(10); // Esperar el tiempo correspondiente
  FastLED.show();
}
