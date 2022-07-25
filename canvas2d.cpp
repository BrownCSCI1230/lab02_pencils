#include "canvas2d.h"
#include "pencil.h"
#include <vector>
#include <iostream>

Canvas2D::Canvas2D(std::string canvasType) :
    m_pencil(new pencil())
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
        RGBA black = RGBA(0, 0, 0,255);
        m_colorCanvasData.assign(100, black);
        //task 9: modify the pixel data to create a flower
//        drawFlower(5, 5);
//        drawFlower(2, 3);
    }
}

Canvas2D::~Canvas2D()
{
    delete m_pencil;
}

void Canvas2D::settingsChanged() {

}

void Canvas2D::drawFlower(int x, int y) {
    // task 9: modify the pixel data to create a flower
    int centerIndex = y * 10 + x;
    int top = centerIndex - 10;
    int bottom = centerIndex + 10;
    int left = centerIndex - 1;
    int right = centerIndex + 1;
    m_colorCanvasData.at(centerIndex) = RGBA(255, 255, 255, 255);
    m_colorCanvasData.at(top) = RGBA(100, 0, 50, 255);
    m_colorCanvasData.at(bottom) = RGBA(100, 0, 50, 255);
    m_colorCanvasData.at(left) = RGBA(100, 0, 50, 255);
    m_colorCanvasData.at(right) = RGBA(100, 0, 50, 255);
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
    m_pencil->brushDown(x, y, this);
//    int index = y * 10 + x;
//    canvas2d->m_colorCanvasData.at(index) = RGBA(100, 0, 50, 255);
}

void Canvas2D::mouseDragged(int x, int y) {
    // Brush TODO: handle mouse events
//    int index = y * 10 + x;
//    m_colorCanvasData.at(index) = RGBA(100, 0, 50, 255);
    m_pencil->brushDown(x, y, this);
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

void Canvas2D::updateColorData(int index, RGBA color)
{
    m_colorCanvasData.at(index) = color;
}
