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
monitorear la temperatura mediante un mapeo en base a las señales
obtenidas con un sensor de temperatura DHT11.

FUTURO: 

Implementar un sistema con sensores DS18B20, los cuales pueden controlar
varios sensores con un pin analógico. Con un rango de unos -55 a 125 grados (DHT11 hasta 50).
Como es analógico es ideal para crear umbrales de brillo.

DHT11 permite monitorear humedad, es esto útil? Valorar

Controlar el brillo con fotoresistores
*/

#include <FastLED.h>
#include <DHT.h>

//Config LED's
#define NUM_LEDS 256
#define LED_PIN 2

//Config DHT11 
#define DHT_PIN 4   
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

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
    dht.begin();
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    FastLED.clear();
}

void loop() {
    float temperature = dht.readTemperature();   

    if (isnan(temperature)) {
      Serial.println("Error leyendo el sensor DHT");
      return;
    }

    int brillo = map(temperature, 20, 40, 255, 0);
    brillo = constrain(brillo, 0, 255);

    FastLED.setBrightness(brillo);
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            leds[transform(i, j)] = pgm_read_dword(&ledarray0[i * WIDTH + j]);
        }
        FastLED.show();
    }

    Serial.print("Temperatura: ");
    Serial.println(temperature);

    Serial.println("-------------");
    
    Serial.print("Brillo :");
    Serial.println(brillo); 
    
    delay(1000); //Pausa de 1 segundo (Recomendado por el fabricante)
}
