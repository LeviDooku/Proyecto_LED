#include <iostream>
#include <cstring>
#include "font.h"
extern "C" {
#include "bitmap.h"
}

using namespace std;

#define WIDTH               64
#define HEIGHT              64
#define FONT_WIDTH          7
#define FONT_HEIGHT         8

char leds[WIDTH * HEIGHT];
bmp_t bitmap;

void print_leds() {
    for (int i = 0; i <= WIDTH; i++) cout << "-";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        cout << "|";
        for (int j = 0; j < WIDTH; j++) cout << leds[i*WIDTH+j];
        cout << "|" << endl;
    }

    for (int i = 0; i <= WIDTH; i++) cout << "-";
    cout << endl;
}

void fill_leds(char fill) {
    for (int i = 0; i < WIDTH*HEIGHT; i++)
        leds[i] = fill;
}

void print_char(char c, int posx, int posy) {
    for (int i = 0; i < FONT_HEIGHT; i++) {
        unsigned char byte = font8x8_basic[c][i];
        for (int j = 0; j < FONT_WIDTH; j++) {
            char value = ((byte >> j) & 1);
            if (value)
                leds[(posy + i)*WIDTH + (posx + j)] = 'X';
        }
    }
}

void print_string(char *str, int line) {
    for (int i = 0; i < strlen(str) && i < WIDTH/FONT_WIDTH; i++) {
        print_char(str[i], 1+i*FONT_WIDTH, line*FONT_HEIGHT);
    }
}


int main(void) {
    bitmap = bmp_create(WIDTH, HEIGHT);
    fill_leds(' ');
    print_string(" REDUZCA  ", 3);
    print_string("VELOCIDAD ", 4);
    print_leds();
    
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            uint32_t color = (leds[j*WIDTH+i] != ' ') ? 0xFFFFFF : 0x000000;
            bmp_set_pixel(bitmap, i, j, color);
        }
    }

    bmp_write(bitmap, "result.bmp");

    // imprimir asignaciones de cada pixel en el array
    // for (int i = 0; i < WIDTH*HEIGHT; i++) {
    //     unsigned int val = 0xFFFFFF;
    //     if (leds[i] == ' ') val = 0x000000;
    //     printf("leds[%d] = 0x%06X\n", i, val);
    // }

    bmp_free(bitmap);
    return 0;
}
