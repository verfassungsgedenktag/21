#include <stdio.h>
#include <stdlib.h>

#include "fractals.h"

int main() {
    int fractal = 3, rec = 1, gd = DETECT, gm = DETECT;

    initgraph(&gd, &gm, "");

    switch (fractal) {
        case 1:
            carpet(90, 10, 550, 470, rec);
            break;
        case 2:
            triangle(10, 470, 320, 10, 630, 470, rec);
            break;
        case 3:
            curve(10, 330, 630, 330, rec);
            break;
        default:
            printf ("Wrong number");
            return 1;
    }

    while (1) {
        int c = readkey();

        if (c == 72 && rec < 5) {
            clearviewport();

            switch (fractal) {
                case 1:
                    carpet(90, 10, 550, 470, ++rec);
                    break;
                case 2:
                    triangle(10, 470, 320, 10, 630, 470, ++rec);
                    break;
                case 3:
                    curve(10, 330, 630, 330, ++rec);
                    break;
            }
        }
        if (c == 80 && rec) {
            clearviewport();

            switch (fractal) {
                case 1:
                    carpet(90, 10, 550, 470, --rec);
                    break;
                case 2:
                    triangle(10, 470, 320, 10, 630, 470, --rec);
                    break;
                case 3:
                    curve(10, 330, 630, 330, --rec);
                    break;
            }
        }
    }

    return 0;
}
