/* 
  ******************************************************
  * mando.ino                                          *
  * Proyecto: Señal LED - V0.1                         *
  * Autores:                                           *
  *   - David Jándula Sánchez                          *
  *   - Pedro Velasco Santana                          *
  *                                                    *
  * Granada - 2025                                     *
  ******************************************************
*/

#include <IRremote.h>

// Configuración del pin del receptor IR
const int IR_PIN = 12; // Cambia a un pin digital disponible

IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn(); // Habilita el receptor IR
  Serial.println("Receptor IR listo");
}

void loop() {
  if (irrecv.decode(&results)) {
    // Verifica cuál botón se presionó y muestra un mensaje
    switch (results.value) {
      case 0xFFA25D:
        Serial.println("Se ha presionado botón 1");
        break;
      case 0xFF629D:
        Serial.println("Se ha presionado botón 2");
        break;
      case 0xFFE21D:
        Serial.println("Se ha presionado botón 3");
        break;
      case 0xFF22DD:
        Serial.println("Se ha presionado botón 4");
        break;
      case 0xFF02FD:
        Serial.println("Se ha presionado botón 5");
        break;
      case 0xFFC23D:
        Serial.println("Se ha presionado botón 6");
        break;
      case 0xFFE01F:
        Serial.println("Se ha presionado botón 7");
        break;
      case 0xFFA857:
        Serial.println("Se ha presionado botón 8");
        break;
      case 0xFF906F:
        Serial.println("Se ha presionado botón 9");
        break;
      case -1:
        Serial.println(" ");
        break;
      default:
        Serial.println("Se ha presionado un botón desconocido");
        break;
    }

    irrecv.resume(); // Recibir el siguiente código
  }
}
