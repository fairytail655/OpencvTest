#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QRect>
#include <QCloseEvent>
#include <opencv2/core/types.hpp>

#include <threadfacecapture.h>
#include <threadbaiduapi.h>

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
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    ThreadFaceCapture *threadFaceCapture;
    ThreadBaiduAPI *threadBaiduAPI;
};

#endif // MAINWINDOW_H
