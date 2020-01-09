#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMetaType>
#include <QPixmap>

void MainWindow::processImageInformation(const QImage image, const std::vector<QRect> rects)
{
    std::cerr << "processImageInformation\n";
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
