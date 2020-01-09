#ifndef THREADFACECAPTURE_H
#define THREADFACECAPTURE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <QThread>
#include <QImage>
#include <QRect>

class ThreadFaceCapture : public QThread
{
    Q_OBJECT

signals:
    void imageInformation(const QImage image, const std::vector<QRect> rects);

public:
    explicit ThreadFaceCapture(QObject *parent = nullptr);

private:
    cv::VideoCapture cap;
    cv::CascadeClassifier faceCascade;

protected:
    void run();
    QImage Mat2QImage(cv::Mat cvImg);
};

#endif // THREADFACECAPTURE_H
