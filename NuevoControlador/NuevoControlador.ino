/* 
  ******************************************************
  * Controlador.ino                                    *
  * Proyecto: Señal LED -                              *
  * Autores:                                           *
  *   - David Jándula Sánchez                          *
  *   - Pedro Velasco Santana                          *
  *                                                    *
  * Granada - 2025                                     *
  ******************************************************
*/

uint32_t ledarray0[] PROGMEM = {
0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 
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


/* librerías */
#include <LiquidCrystal.h>
#include <IRremoteESP8266.h>
#include <IRtimer.h>
#include <IRrecv.h>
#include "DHT.h"

/* módulos */
#include "ESP8266.h"
#include "Matrix.h"

/* pines de los sensores/actuadores */
#define LED_PIN D4
#define IR_PIN D3
#define DHT_PIN D2
#define DHTTYPE DHT11 // DHT 11

// datos del sensor IR
IRrecv irrecv(IR_PIN);
decode_results results;

// datos del sensor DHT11
DHT dht(DHT_PIN, DHTTYPE);
float temperature;

// datos de la pantalla LCD
LiquidCrystal lcd(D0,D1,D5,D6,D7,D8);

/* TODO: eliminar el uso de esta variable */
int numLeds = 1;
int var = 8;

/* funciones del sensor */
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

/* imprime un mensaje en la pantalla LCD */
void imprimeMensaje(String mensaje, int col, int row){
    lcd.setCursor(col,row);
    lcd.print(mensaje);
}

void setup() {
    Serial.begin(115200);
    matrix_init();
    
    // LCD
    lcd.begin(16, 2);
    lcd.home();
    lcd.print("[+] INICIANDO");
    lcd.setCursor(0,1);
    lcd.print("[+] SISTEMA");
    
    // IR
    irrecv.enableIRIn();

    // DHT11
    pinMode(DHT_PIN, INPUT);   
    dht.begin();

    delay(1000);
}

typedef struct {
    int brightness;
    float temperature;
    int frame;
} sensor_data;

sensor_data sensors = {25, 0, 0};

void loop() {
    // leer mando
    if (irrecv.decode(&results)) {
      Serial.print("Código recibido: ");
      Serial.println(results.value, HEX); // Imprime el código en formato hexadecimal
      irrecv.resume(); // Prepara el receptor para el siguiente valor
      if (results.value == 0xFFA25D) sensors.frame = 0;
      if (results.value == 0xFF629D) sensors.frame = 1;
      if (results.value == 0xFFE21D) sensors.frame = 2;
      if (results.value == 0xFF22DD) sensors.frame = 3;      
      if (results.value == 0xFFE01F) sensors.brightness = 25;
      if (results.value == 0xFFA857) sensors.brightness = 50;
      if (results.value == 0xFF906F) sensors.brightness = 100;
      if (results.value == 0xFF18E7) numLeds = numLeds+var;
      if (results.value == 0xFF4AB5) numLeds = numLeds-var;
      if (results.value == 0xFF5AA5) if (var < 100) var += 1;
      if (results.value == 0xFF10EF) if (var > 0) var -= 1;
    }

    // leer temperatura
    sensors.temperature = dht.readTemperature();

    // leer iluminación
    // TO-DO

    // mostrar datos en puerto serie
    Serial.print("[+] frame: ");
    Serial.print(sensors.frame);
    Serial.print(" temperature: ");
    Serial.print(sensors.temperature);
    Serial.print(" brightness: ");
    Serial.println(sensors.brightness);
    Serial.print(" var: ");
    Serial.println(var);    
    Serial.print(" numLeds: ");
    Serial.println(numLeds);

    // mostrar datos en LCD
    lcd.clear();
    imprimeMensaje("[+] Temp: "  + String(sensors.temperature)+"C", 0, 0);
    imprimeMensaje("Foto " + String(sensors.frame) + " Luz " + String(sensors.brightness), 0, 1);

    // representar imagen
    matrix_render(ledarray0);
    matrix_set_brightness(sensors.brightness);
    delay(250);
}
