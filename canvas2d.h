#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <QWidget>
#include "RGBA.h"

class Canvas2D {
public:
    Canvas2D(std::string canvasType);

    void settingsChanged();

    void mouseDown(int x, int y);
    void mouseDragged(int x, int y);
    void mouseUp(int x, int y);

    void paint(int x, int y, std::vector<float> mask, bool smudge);

    void filterImage();

    // Return an array containing the rows of the image one after another, starting from the top.
    // Each row is width() wide and there are height() rows, so this array will have
    // width() * height() elements.
    std::vector<uint8_t> *DisplayCanvas();
    std::vector<RGBA> *DisplayColor();


    // used by support code to provide access to canvas data
    void setImage();
    std::vector<uint8_t> m_canvasData;
    //Task 6:create your colorful canvas
    //eg:
    std::vector<RGBA> m_colorCanvasData;
};

#endif // CANVAS2D_H
