#ifndef SUPPORTCANVAS2D_H
#define SUPPORTCANVAS2D_H

#include <QWidget>
#include "RGBA.h"
#include "canvas2d.h"

class SupportCanvas2D : public QWidget{
    Q_OBJECT
public:
    SupportCanvas2D();
    ~SupportCanvas2D();

    // Resize the canvas (this will resize the window too and set the image to black)
    void resize(int width, int height);

    // Load or save the canvas given a specific file path.  Return true on success.
    bool loadImage(const QString &file);
    bool saveImageFile(const QString &file);

    // Load a black 500x500 image
    void newImage();

    // Show a file dialog and perform the save action if the user picks a file.  Return true on
    // success.
    bool saveImage();

    std::vector<uint8_t> *getImage(){return &m_image;}


protected:
    // Overridden from QWidget
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    // This will be called when the size of the canvas has been changed

    // This will be called when the settings have changed
    virtual void settingsChanged();

    std::vector<uint8_t> m_image;
    Canvas2D *m_canvas2d;
};

#endif // SUPPORTCANVAS2D_H
