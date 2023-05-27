#ifndef FRACTALS_H_INCLUDED
#define FRACTALS_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <graphics.h>

/* ���� ����������� */
void carpet(double left, double top, double right, double bottom, int rec);

/* ����������� ����������� */
void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int rec);

/* ������ ���� */
void curve(double x1, double y1, double x2, double y2, int rec);


#endif // FRACTALS_H_INCLUDED
