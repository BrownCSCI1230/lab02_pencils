#include "pencil.h"
#include "canvas2d.h"
#include <iostream>

void pencil::brushDown(int x, int y, Canvas2D *canvas)
{
    x = x / 50;
    y = y / 50;
    int index = y * 10 + x;
    canvas->updateColorData(index, RGBA(100, 0, 50, 255));
}

void pencil::brushDragged(int x, int y, Canvas2D *canvas)
{
    x = x / 50;
    y = y / 50;
    int index = y * 10 + x;
    canvas->updateColorData(index, RGBA(100, 0, 50, 255));
}

void pencil::brushUp(int x, int y, Canvas2D *canvas)
{

}
