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

private:
    Ui::MainWindow *ui;
    std::vector<uint8_t> *m_canvas;
    SupportCanvas2D *m_supportcanvas;
};
#endif // MAINWINDOW_H
