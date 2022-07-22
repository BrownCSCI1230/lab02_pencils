#include "supportcanvas2d.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QMouseEvent>
#include "iostream"

SupportCanvas2D::SupportCanvas2D(std::string canvasType)
{
    for (int i=0; i<250000; i++) {
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(255);
    }
    m_canvas2d = new Canvas2D(canvasType);

    if (canvasType == "grayscale") {
        for (int i = 0 ; i < m_canvas2d->DisplayCanvas()->size(); i++) {
            int xStart = (i % 10) * 50;
            int xEnd = xStart + 50;
            int yStart = (i / 10) * 50;
            int yEnd = yStart + 50;

            for (int currY = yStart; currY < yEnd; currY++) {
                for (int currX = xStart; currX < xEnd; currX++) {
                    int index = currY * 2000 + currX * 4;
                    m_image[index] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+1] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+2] = m_canvas2d->DisplayCanvas()->at(i);
                    m_image[index+3] = m_canvas2d->DisplayCanvas()->at(i);
                }
            }
        }
    } else if (canvasType == "color") {

    }

}

SupportCanvas2D::~SupportCanvas2D() {
}


bool SupportCanvas2D::saveImageFile(const QString &file) {
}

void SupportCanvas2D::newImage() {
    // Load a black 500x500 image.
}

void SupportCanvas2D::mousePressEvent(QMouseEvent *event) {
    //TODO:
}

void SupportCanvas2D::mouseMoveEvent(QMouseEvent *event) {
    //TODO:
}

void SupportCanvas2D::mouseReleaseEvent(QMouseEvent *event) {
    // Move the mouse again in case this event is at a different position then the last event.
    //TODO:

}

void SupportCanvas2D::settingsChanged() {
}


