#include "canvas2d.h"
#include <vector>

Canvas2D::Canvas2D(std::string canvasType)
{
    if (canvasType == "grayscale"){//IF CLI input is grayscale
        //TASK 3:Initialize your canvas
        //eg:
        m_canvasData.assign(100,0);
        //Task 5: modify your pixel data to create a heart
        //eg:
        m_canvasData.at(23)=255;
        m_canvasData.at(24)=255;
        m_canvasData.at(26)=255;
        m_canvasData.at(27)=255;
        m_canvasData.at(32)=255;
        m_canvasData.at(35)=255;
        m_canvasData.at(38)=255;
        m_canvasData.at(42)=255;
        m_canvasData.at(48)=255;
        m_canvasData.at(53)=255;
        m_canvasData.at(57)=255;
        m_canvasData.at(64)=255;
        m_canvasData.at(66)=255;
        m_canvasData.at(75)=255;
    }
    if (canvasType == "color") { //IF CLI input is colorful
        //task 7: enable a colorful canvas
        RGBA magenta = RGBA(50, 0, 123,255);
        m_colorCanvasData.assign(100, magenta);
        //task 9: modify the pixel data to create a flower

    }
}

void Canvas2D::settingsChanged() {

}

std::vector<uint8_t> *Canvas2D::DisplayCanvas(){
    //Task 4:Return the pointer to the vector you just created
        return &m_canvasData;
}

std::vector<RGBA> *Canvas2D::DisplayColor(){
    //Task 8:Return the pointer to the colorcanvasdata you just created
    //eg:
    return &m_colorCanvasData;
}


void Canvas2D::mouseDown(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::mouseDragged(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::mouseUp(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::paint(int x, int y, std::vector<float> mask, bool smudge) {
    // Brush TODO: paint canvas using mask
}

void Canvas2D::filterImage() {
    // Filter TODO: filter the image on canvas using the selected filter
}

void Canvas2D::setImage() {
}
