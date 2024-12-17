/* 
  ******************************************************
  * led_test.ino                                       *
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

Recurso útil sobre el struct CRGB:

https://fastled.io/docs/group___pixel_types.html#ggaeb40a08b7cb90c1e21bd408261558b99ab35114af96aa24d28e7901b1318cc43a
*/

#include <FastLED.h>

#define DATA_PIN 4          //Data pin
#define NUM_LEDS 10        //Número total LED's
#define ANCHO 5
#define ALTO 2
#define NIVELES_BRILLO 3 //Niveles de brillo: 15%, 50%, 100%
#define DURACION 10000      //Duración en ms por nivel de brillo (10 segundos)

CRGB leds[NUM_LEDS];

const uint8_t niveles_brillo[NIVELES_BRILLO] = {38, 128, 255};

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.clear();
}

void loop() {
    testeo(CRGB::Red);
    testeo(CRGB::Green);
    testeo(CRGB::Blue);

    testeo(CRGB::DeepPink); //Para comprobar que la documentación está actualizada
}

//Función para hacer más claro el loop
void testeo(const CRGB &color){
    for(int i = 0; i < NIVELES_BRILLO; i++){ //Recorremos el array de niveles_brillo
        FastLED.setBrightness(niveles_brillo[i]);
        flujo_leds(color); //Encendemos los leds correspondientes con el brillo que toca
        delay(DURACION);
    }
    FastLED.clear();
    FastLED.show();
}

//Función para encender los LED's correspondientes
void flujo_leds(const CRGB &color){
  int ledindex = 0;
  for(int y = 0; y < ALTO; y++){
    for(int x = 0; x < ANCHO; x++){
      if(ledindex < NUM_LEDS){
        leds[ledindex] = color;
        ledindex++;
      }
    }
  }
  FastLED.show();
}
