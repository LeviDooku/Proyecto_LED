#include "Matrix.h"

/* dimensiones de los paneles y la imagen */
int panel_width = PANEL_WIDTH;
int panel_height = PANEL_HEIGHT;
int width = WIDTH;
int height = HEIGHT;
int num_leds = WIDTH * HEIGHT;

/* matriz de LEDs */
CRGB leds[NUM_LEDS];

// adapta la matriz a la disposición de los paneles
int transform(int i, int j) {
    int x = 0;

    // columnas impares
    if ((j/panel_width)%2) {
        x = (panel_width*height*(j/panel_width)+1)
          +  panel_width*i+panel_width-2;
    }

    // columnas pares
    else {
        x = (panel_width*height*(j/panel_width+1)-1)
          -  panel_width*i;
    }

    // filas impares
    if (i%2) {
        x += (j%panel_width)-panel_width+1;
    }

    // filas pares
    else {
        x += -(j%panel_width);
    }

    return x;
}

// inicializa la matriz de LEDs
void matrix_init() {
    // inicializa la biblioteca FastLED
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, num_leds);
    FastLED.clear();
}

// renderiza el frame elegido en la matriz de LEDs
void matrix_render(uint32_t *array) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            leds[transform(i, j)] = pgm_read_dword(&(array[i * width + j]));
        }
    }

    FastLED.show();
}

// apaga todos los LEDs
void matrix_clear(void) {
    FastLED.clear();
}

// ajusta el brillo de los LEDs
void matrix_set_brightness(unsigned int brightness) {
    if (0 <= brightness && brightness <= 100)
        FastLED.setBrightness(brightness);
}
