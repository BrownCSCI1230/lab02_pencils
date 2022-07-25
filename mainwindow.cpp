#include "mainwindow.h"
#include "QtGui/qevent.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::canvasSetup(std::string canvasType)
{
    m_supportcanvas = new SupportCanvas2D(canvasType);
    this->setMouseTracking(true);

    QImage myImage;
    myImage.load("/Users/angelax/angela/cs1230dev/lab02_pencils/test.jpg");
    myImage = myImage.convertToFormat(QImage::Format_RGBX8888);

    QImage other;
    other.load("/Users/angelax/angela/cs1230dev/lab02_pencils/canvas.jpg");

    std::cout<<myImage.width()<<myImage.height()<<std::endl;
    QByteArray arr = QByteArray::fromRawData((const char*)myImage.bits(), myImage.sizeInBytes());



    std::cout<<arr.size()<<std::endl;
    std::cout<<int(uint8_t (arr.data()[1673]))<<" "<< int(uint8_t (arr.data()[167]))<<std::endl;
    ui->label->setPixmap(QPixmap::fromImage(other));

    //option 1:directly edit raw data, by passing a std::vector
    //exp:
    std::vector<uint8_t> buf;
    for (int i = 0; i < arr.size()/4 ; i++ ) {
        buf.push_back(123);
        buf.push_back(0);
        buf.push_back(123);
        buf.push_back(0);
    }
    m_canvas = &buf;
    drawImage();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (x >= 250 && x <= 750 && y >= 50 && y <= 550)
    {
        x -= 250;
        y -= 50;

        m_supportcanvas->mouseDown(x, y);
        drawImage();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (x >= 250 && x <= 750 && y >= 50 && y <= 550)
    {
        x -= 250;
        y -= 50;

        m_supportcanvas->mouseDrag(x, y);
        drawImage();

    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if (x >= 250 && x <= 750 && y >= 50 && y <= 550)
    {
        x -= 250;
        y -= 50;

        m_supportcanvas->mouseUp(x, y);
        drawImage();
    }
}

void MainWindow::drawImage()
{
    m_canvas= m_supportcanvas->getImage();

    QByteArray* img = new QByteArray(reinterpret_cast<const char*>(m_canvas->data()), m_canvas->size());

    QImage now = QImage((const uchar*)img->data(), 500, 500, QImage::Format_RGBX8888);
    ui->label->setPixmap(QPixmap::fromImage(now));
    ui->label->setMouseTracking(true);
    ui->label->show();

    delete img;
}

MainWindow::~MainWindow()
{
    delete ui;
}

