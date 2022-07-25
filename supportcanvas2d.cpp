#include "supportcanvas2d.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QMouseEvent>
#include "iostream"

SupportCanvas2D::SupportCanvas2D(std::string canvasType) :
    m_canvasType(canvasType)
{
    for (int i=0; i<250000; i++) {
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(255);
    }
    m_canvas2d = new Canvas2D(canvasType);
    colorCanvas();
}

SupportCanvas2D::SupportCanvas2D(QWidget* widget) {
    this->setParent(widget);
}

void SupportCanvas2D::colorCanvas() {
    // for each pixel in the 10x10 canvas
    for (int i = 0; i < 100; i++) {
        // calculates the (x and y) start and end indices in a 500x500 canvas
        int xStart = (i % 10) * 50;
        int xEnd = xStart + 50;
        int yStart = (i / 10) * 50;
        int yEnd = yStart + 50;

        for (int currY = yStart; currY < yEnd; currY++) {
            for (int currX = xStart; currX < xEnd; currX++) {
                // calculates the index in m_image (2000 indices make up a row bc of the RGBA channels)
                int index = currY * 2000 + currX * 4;

                if (m_canvasType == "grayscale") {
                    // changes the rgba values for the current pixel to a single value (aka grayscale)
                    m_image[index] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+1] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+2] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+3] = m_canvas2d->DisplayCanvas()->at(i);
                }
                if (m_canvasType == "color") {
                    // changes the rgba values for the current pixel to the given RGBA values
                    m_image[index] = m_canvas2d->DisplayColor()->at(i).r;
                    m_image[index+1] = m_canvas2d->DisplayColor()->at(i).g;
                    m_image[index+2] = m_canvas2d->DisplayColor()->at(i).b;
                    m_image[index+3] = m_canvas2d->DisplayColor()->at(i).a;
                }
            }
        }
    }
}


SupportCanvas2D::~SupportCanvas2D() {
}


bool SupportCanvas2D::saveImageFile(const QString &file) {
}

void SupportCanvas2D::newImage() {
    // Load a black 500x500 image.
}

void SupportCanvas2D::mouseDown(int x, int y)
{
    m_canvas2d->mouseDown(x, y);
    colorCanvas();
}

void SupportCanvas2D::mouseDrag(int x, int y)
{
    m_canvas2d->mouseDragged(x, y);
    colorCanvas();
}

void SupportCanvas2D::mouseUp(int x, int y)
{
    m_canvas2d->mouseUp(x, y);
    colorCanvas();
}

//void SupportCanvas2D::mousePressEvent(QMouseEvent *event) {
//    //TODO:
//    m_canvas2d = new Canvas2D(m_canvasType);
//    int x = event->x() / 50;
//    int y = event->y() / 50;
//    m_canvas2d->mouseDown(x, y);
//    colorCanvas();
//}

//void SupportCanvas2D::mouseMoveEvent(QMouseEvent *event) {
//    //TODO:
//    std::cout << "move" << std::endl;
//    int x = event->x() / 50;
//    int y = event->y() / 50;
//    m_canvas2d->mouseDragged(x, y);
//    colorCanvas();
//}

//void SupportCanvas2D::mouseReleaseEvent(QMouseEvent *event) {
//    // Move the mouse again in case this event is at a different position then the last event.
//    //TODO:
//    int x = event->x() / 50;
//    int y = event->y() / 50;
//    m_canvas2d->mouseUp(x, y);
//}

void SupportCanvas2D::settingsChanged() {
}


