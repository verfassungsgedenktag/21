#include "fractals.h"

void carpet(double left, double top, double right, double bottom, int rec) {
    if (rec--) {
        double in_left = left + (right - left) / 3,
               in_top = top - (top - bottom) / 3,
               in_right = right - (right - left) / 3,
               in_bottom = bottom + (top - bottom) / 3;

        bar(in_left, in_top, in_right, in_bottom);

        carpet(left, top, in_left, in_top, rec);
        carpet(in_left, top, in_right, in_top, rec);
        carpet(in_right, top, right, in_top, rec);
        carpet(left, in_top, in_left, in_bottom, rec);
        carpet(in_right, in_top, right, in_bottom, rec);
        carpet(left, in_bottom, in_left, bottom, rec);
        carpet(in_left, in_bottom, in_right, bottom, rec);
        carpet(in_right, in_bottom, right, bottom, rec);
    }
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int rec) {
    if (rec--) {
        int poly[6] = {floor((x1 + x2 + 1) / 2), floor((y1 + y2 + 1) / 2),
                       floor((x2 + x3 + 1) / 2), floor((y2 + y3 + 1) / 2),
                       floor((x1 + x3 + 1) / 2), floor((y1 + y3 + 1) / 2)};

        fillpoly(3, poly);

        triangle(x1, y1, (x1 + x2)/2, (y1 + y2)/2, (x1 + x3)/2, (y1 + y3)/2, rec);
        triangle((x1 + x2)/2, (y1 + y2)/2, x2, y2, (x2 + x3)/2, (y2 + y3)/2, rec);
        triangle((x1 + x3)/2, (y1 + y3)/2, (x2 + x3)/2, (y2 + y3)/2, x3, y3, rec);
    }
}

void curve(double x1, double y1, double x2, double y2, int rec) {
    if (!(rec--)) {
       line(floor(x1 + 0.5), floor(y1 + 0.5), floor(x2 + 0.5), floor(y2 + 0.5));
       return;

    }
    double x3 = x1 + (x2 - x1) / 3,
           y3 = y1 + (y2 - y1) / 3,
           x4 = x2 - (x2 - x1) / 3,
           y4 = y2 - (y2 - y1) / 3,
           x5 = x3 + ((x4 - x3) / 2 + (y4 - y3) * sin(M_PI / 3)),
           y5 = y3 + ((y4 - y3) / 2 - (x4 - x3) * sin(M_PI / 3));

    curve(x1, y1, x3, y3, rec);
    curve(x3, y3, x5, y5, rec);
    curve(x5, y5, x4, y4, rec);
    curve(x4, y4, x2, y2, rec);
}
