#include "canvas2d.h"
#include <vector>

Canvas2D::Canvas2D(std::string canvasType)
{
    if (canvasType == "grayscale"){//IF CLI input is grayscale
        //TASK 3:Initialize your canvas
        //eg:
        for (int i = 0; i < 100; i++) {
            if (i % 2 == 0) {
                m_canvasData.push_back(0);
            } else {
                m_canvasData.push_back(255);
            }
        }
//        m_canvasData.assign(100,123);
        //Task 5: modify your pixel data to create a heart
        //eg:
//        m_canvasData.at(2)=255;
    }
    if (canvasType == "color"){//IF CLI input is colorful
        //task 7: enable a colorful canvas
        RGBA gray = RGBA(123,123,123,255);
        m_colorCanvasData.assign(500, gray);
        //task 9: modify the pixel data to create a flowser

    }
}

void Canvas2D::settingsChanged() {

}

std::vector<uint8_t> *Canvas2D::DisplayCanvas(){
    //Task 4:Return the pointer to the vector you just created
        return &m_canvasData;
}

//std::vector<RGBA> *Canvas2D::DisplayColor(){
//    //Task 8:Return the pointer to the colorcanvasdata you just created
//    //eg:
//    return &m_colorCanvasData
//}


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
