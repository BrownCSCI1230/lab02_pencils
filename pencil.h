#ifndef PENCIL_H
#define PENCIL_H

class Canvas2D;

class pencil
{
public:
    void brushDown(int x, int y, Canvas2D *canvas);
    void brushDragged(int x, int y, Canvas2D *canvas);
    void brushUp(int x, int y, Canvas2D *canvas);

};

#endif // PENCIL_H
