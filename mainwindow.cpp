#include "mainwindow.h"
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

    QImage myImage;
    myImage.load("C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\test.jpg");
    myImage = myImage.convertToFormat(QImage::Format_RGBX8888);

    QImage other;
    other.load("C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\canvas.jpg");

    std::cout<<myImage.width()<<myImage.height()<<std::endl;
    QByteArray arr = QByteArray::fromRawData((const char*)myImage.bits(), myImage.sizeInBytes());



    std::cout<<arr.size()<<std::endl;
    std::cout<<int(uint8_t (arr.data()[1673]))<<" "<<int(uint8_t (arr.data()[167]))<<std::endl;
    ui->label->setPixmap(QPixmap::fromImage(other));

    //option 1:directly edit raw data, by passing a std::vector
    //exp:
    std::vector<uint8_t> buf;
    for (int i = 0; i < arr.size()/4 ; i++ ){
//        std::cout<<int(uint8_t(arr.data()[3*i]))<<" "<<int(uint8_t(arr.data()[3*i+1]))<<" "<<int(uint8_t(arr.data()[3*i+2]))<<std::endl;

        buf.push_back(123);
        buf.push_back(0);
        buf.push_back(0);
        buf.push_back(0);
    }
    m_canvas = &buf;
    m_canvas= m_supportcanvas->getImage();


    QByteArray* img = new QByteArray(reinterpret_cast<const char*>(m_canvas->data()), m_canvas->size());




    QImage now = QImage((const uchar*)img->data(), 500, 500, QImage::Format_RGBX8888);
    ui->label->setPixmap(QPixmap::fromImage(now));
    ui->label->show();
    std::cout<<"got to Qimage show"<<std::endl;


}

MainWindow::~MainWindow()
{
    delete ui;
}

