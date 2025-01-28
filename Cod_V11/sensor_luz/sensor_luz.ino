/* 
  ******************************************************
  * sensor_luz.ino                                    *
  * Proyecto: Señal LED - V0.1                         *
  * Autores:                                           *
  *   - David Jándula Sánchez                          *
  *   - Pedro Velasco Santana                          *
  *                                                    *
  * Granada - 2025                                     *
  ******************************************************
*/

#include <FastLED.h>
#include <DHT.h>

//Config LED's
#define NUM_LEDS 256
#define LED_PIN 2

CRGB leds[NUM_LEDS];

// Config Frame

// Source : Rows
// Line   : Row
// Bits   : LSB at right
// Order  : Top to bottom
// Scan   : Left to right
// Size   : 32 bits
// 
// Colour Format: RGB
// Brightness   : 100%
// Colour Space : 32 bits
const uint32_t ledarray0[] PROGMEM = {
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00FF00FF, 0x00FF80FF, 0x00FF80FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF80FF, 0x00FF80FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00FF80FF, 0x00FF80FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF80FF, 0x00FF80FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00FF00FF, 0x00FF80FF, 0x00FF80FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF80FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00FF00FF, 0x00FF0080, 0x00FF0080, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF0080, 0x00FF0080, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00FF0080, 0x00FF0080, 0x00FF0080, 0x00FF00FF, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF0080, 0x00FF0080, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00FF00FF, 0x00FF0080, 0x00FF0080, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x00FF0080, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00FF00FF, 0x008000FF, 0x008000FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x008000FF, 0x008000FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x008000FF, 0x008000FF, 0x008000FF, 0x00FF00FF, 0x00000000, 
0x00000000, 0x00FF00FF, 0x008000FF, 0x008000FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 
0x00FF00FF, 0x008000FF, 0x008000FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00FF00FF, 0x008000FF, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
};

// dimensiones imagen
#define WIDTH           8
#define HEIGHT          32

// dimensiones paneles
#define PANEL_WIDTH     8
#define PANEL_HEIGHT    32

int width = WIDTH;
int height = HEIGHT;
int panel_width = PANEL_WIDTH;
int panel_height = PANEL_HEIGHT;

int transform(int i, int j) {
    int x = 0;

    // columnas impares
    if ((j/panel_width)%2) x = (panel_width*height*(j/panel_width)+1)+panel_width*i+panel_width-2;

    // columnas pares
    else x = (panel_width*height*(j/panel_width+1)-1)-panel_width*i;

    // filas impares
    if (i%2) x += (j%panel_width)-panel_width+1;

    // filas pares
    else x += -(j%panel_width);

    return x;
}

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    FastLED.clear();

    //Calibrar el fotoresistor durante los primeros 5 segundos
    while (millis() < 1000){
      sensorValue = analogRead(A0);
      if (sensorValue > sensorHigh)
        sensorHigh = sensorValue;
      if (sensorValue < sensorLow)
        sensorLow = sensorValue;
    }
}

void loop() {

     //Leer el valor del fotoresistor
     sensorValue = analogRead(A0);

     for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            leds[transform(i, j)] = pgm_read_dword(&ledarray0[i * WIDTH + j]);
        }
        FastLED.show();
    }

    FastLED.setBrightness(map(sensorValue, sensorLow, sensorHigh, 0, 255));

    delay(500);
}
