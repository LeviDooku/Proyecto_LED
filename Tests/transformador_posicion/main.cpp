#include <iostream>
using namespace std;

// dimensiones imagen
#define WIDTH           16
#define HEIGHT          64

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
    
int main(void) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << transform(i, j) << "\t";
        }
        cout << endl;
    }
}
