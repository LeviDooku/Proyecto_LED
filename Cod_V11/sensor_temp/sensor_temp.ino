/* 
  ******************************************************
  * sensor_temp.ino                                    *
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

Programa que implementa la programación necesaria para 
monitorear la temperatura mediante umbrales
*/

#include <FastLED.h>

//Config LED's
#define NUM_LEDS 256
#define LED_PIN 4

//Config KY - 028 
#define TEMP_PIN A0 //Sensor análogico para respuesta rápida

//Umbrales brillo y temp
int ky028_temp = 0;
int brillo = 0;

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


void setup() {
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    FastLED.clear();
}

void loop() {
  
    //Leer valor del KY-028
    ky028_temp = analogRead(TEMP_PIN);
    
    //Calcular el brillo basado en los umbrales del KY-028
    if (ky028_temp < 400) {
        brillo = 255; //Brillo alto aprox 25 Cº
    } else if (ky028_temp < 600) {
        brillo = 128; //Brillo medio
    } else {
        brillo = 50; //Brillo bajo
    }

    FastLED.setBrightness(brillo);
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            leds[transform(i, j)] = pgm_read_dword(&ledarray0[i * WIDTH + j]);
        }
        FastLED.show();
    }
    
    Serial.print("Valor KY-028: ");
    Serial.println(ky028_temp);

    Serial.print("Brillo LEDs: ");
    Serial.println(brillo);
    Serial.println("----------------------");

    delay(1000); // Pausa de 1 segundo
}
