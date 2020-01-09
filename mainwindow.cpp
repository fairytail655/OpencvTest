#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaType>
#include <QPixmap>
#include <QDebug>

#include <iostream>

void MainWindow::processImageInformation(const QImage image, const std::vector<QRect> rects)
{
    QImage face_image;
    if(rects.size() != 0){
         face_image = image.copy(rects[0]);
         ui->label_show_face->setPixmap(QPixmap::fromImage(face_image));
    }
    ui->label_show_video->setPixmap(QPixmap::fromImage(image));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    threadFaceCapture = new ThreadFaceCapture(this);
    qRegisterMetaType<std::vector<QRect>>("QRectVector");
    connect(threadFaceCapture, SIGNAL(imageInformation(const QImage, const QRectVector)), this, SLOT(processImageInformation(const QImage, const QRectVector)));
    threadFaceCapture->start();

    threadBaiduAPI = new ThreadBaiduAPI(this);
    threadBaiduAPI->start();
}

MainWindow::~MainWindow()
{
    delete threadFaceCapture;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    threadFaceCapture->stop();
    threadFaceCapture->wait();
    event->accept();
}
