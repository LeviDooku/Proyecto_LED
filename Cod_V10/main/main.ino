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
