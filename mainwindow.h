#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "supportcanvas2d.h"
#include "canvas2d.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void canvasSetup(std::string canvasType);

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    std::vector<uint8_t> *m_canvas;
    SupportCanvas2D *m_supportcanvas;

    void drawImage();
};
#endif // MAINWINDOW_H
