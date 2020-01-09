#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QRect>
#include <threadfacecapture.h>
#include <opencv2/core/types.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void processImageInformation(const QImage image, const std::vector<QRect> rects);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ThreadFaceCapture *threadFaceCapture;

};

#endif // MAINWINDOW_H
