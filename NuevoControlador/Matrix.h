#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <FastLED.h>

// dimensiones de los paneles
#define PANEL_WIDTH     8
#define PANEL_HEIGHT    32
#define WIDTH           8
#define HEIGHT          32
#define NUM_LEDS        WIDTH * HEIGHT

void matrix_init();
void matrix_render(uint32_t *pixel);
void matrix_clear(void);
void matrix_set_brightness(unsigned int brightness);

#endif /* _MATRIX_H_ */
