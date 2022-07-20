#include "supportcanvas2d.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QMouseEvent>
#include "iostream"

SupportCanvas2D::SupportCanvas2D()
{
    for(int i=0; i<250000; i++){
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(0);
        m_image.push_back(0);
    }
    m_canvas2d = new Canvas2D();
    for(int i=0 ; i<m_canvas2d->DisplayCanvas()->size(); i++){
        for (int j = 0; j<50; j++){
            m_image[4*50*i+4*j]=m_canvas2d->DisplayCanvas()->at(i);
            m_image[4*50*i+4*j+1]=m_canvas2d->DisplayCanvas()->at(i);

            m_image[4*50*i+4*j+2]=m_canvas2d->DisplayCanvas()->at(i);

            m_image[4*50*i+4*j+3]=m_canvas2d->DisplayCanvas()->at(i);

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


