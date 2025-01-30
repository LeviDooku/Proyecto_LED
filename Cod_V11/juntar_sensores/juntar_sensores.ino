/* 
  ******************************************************
  * sensor_temp.ino                                    *
  * Proyecto: Señal LED - V0.1                         *
  * Autores:                                           *
  *   - David Jándula Sánchez                          *
  *   - Pedro Velasco Santana                          *
  *                                                    *
  * Granada - 2025                                     *
  ******************************************************
*/

/*
Resumen de funcionamiento:

Programa que junta un recibidor de infrarrojos, sensor DHT11 y 
una pantalla para no depender del monitor serial (aunque también se puede consultar)

FUTURO:

Programa esqueleto para ampliar mapeando imágenes y monitoreando brillo.

Falta parte LEDs y photoresistor
*/

#include <FastLED.h>
#include <DHT.h>
#include <IRremote.h>
#include <LiquidCrystal.h>

//Config DHT11
#define DHT_PIN 13    
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

//Config IR 1838
#define IR_PIN 12

IRrecv irrecv(IR_PIN);
decode_results results;

//Config pantalla LCD
#define RS 7 
#define E 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void imprimeMensaje(String mensaje, int col, int row){

  lcd.setCursor(col,row);
    lcd.print(mensaje);
}

void setup(){
  //Inicialización LCD
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("[+] INICIANDO");
  lcd.setCursor(0,1);
  lcd.print("[+] SISTEMA");

  Serial.begin(115200);

  //Inicialización DHT11
  dht.begin();

  //Inicialización IR 1838
  irrecv.enableIRIn();

  delay(1000);
  lcd.clear();
}

typedef struct{
  int brightness;
  float temperature;
  int frame;
} sensor_data;

void loop(){
    sensor_data sensores = {0, 0, 0};
    sensores.temperature = dht.readTemperature();   

    if (isnan(sensores.temperature)){
      lcd.home();
      lcd.print("[-] ERROR DHT11");
      return;
    }

    imprimeMensaje("[+] Temp: "+String(sensores.temperature)+"C", 0, 0);
    
    delay(2000);
    lcd.clear();

    Serial.write((uint8_t*)(&sensores), sizeof(sensor_data));
    
 }
