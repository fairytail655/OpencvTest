#include "threadfacecapture.h"
#include <qdebug.h>

ThreadFaceCapture::ThreadFaceCapture(QObject *parent) : QThread (parent)
{
    stop_flag = false;
}

ThreadFaceCapture::~ThreadFaceCapture()
{

}

void ThreadFaceCapture::run()
{
    QString msg = QString("%1 -> %2 threadid:[%3]")
                .arg(__FILE__)
                .arg(__FUNCTION__)
                .arg((int)currentThreadId());
    qDebug() << msg;

    cv::Mat frame_mat, frame_gray;
    QImage frame_qimage;
    QRect rect;
    std::vector<cv::Rect> detections_cvrect;
    std::vector<cv::Rect>::iterator it;

    cap.open(0);
//    qDebug() << cap.get(cv::CAP_PROP_FPS);
//    qDebug() << cap.get(cv::CAP_PROP_FRAME_WIDTH);
//    qDebug() << cap.get(cv::CAP_PROP_FRAME_HEIGHT);
//    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
//    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FPS, 50);
    faceCascade.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");

    while (!stop_flag) {
        cap.read(frame_mat);
        cv::flip(frame_mat, frame_mat, 1);
        cv::cvtColor(frame_mat, frame_gray, CV_BGR2GRAY);
        faceCascade.detectMultiScale(frame_gray, detections_cvrect, 1.2, 5, 0, cv::Size(100, 100));

        std::vector<QRect> detections_qrect;
        for (it=detections_cvrect.begin();it!=detections_cvrect.end();it++) {
            rect.setX(it->x);
            rect.setY(it->y);
            rect.setWidth(it->width);
            rect.setHeight(it->height);
            detections_qrect.push_back(rect);
            cv::rectangle(frame_mat, *it, cv::Scalar(255,0,0), 2);
        }

        frame_qimage = Mat2QImage(frame_mat);
        emit imageInformation(frame_qimage, detections_qrect);
    }

    cap.release();
}

void ThreadFaceCapture::stop()
{
    stop_flag = true;
    QString msg = QString("%1 -> %2 threadid:[%3]")
                .arg(__FILE__)
                .arg(__FUNCTION__)
                .arg((int)currentThreadId());
    qDebug() << msg;
}

QImage ThreadFaceCapture::Mat2QImage(cv::Mat cvImg)
{
    QImage qImg;
    if(cvImg.channels()==3)                             //3 channels color image
    {
        cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg =QImage(const_cast<unsigned char*>(cvImg.data),
                    cvImg.cols, cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1)                    //grayscale image
    {
        qImg =QImage(const_cast<unsigned char*>(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage(const_cast<unsigned char*>(cvImg.data),
                     cvImg.cols,cvImg.rows,
                     cvImg.cols*cvImg.channels(),
                     QImage::Format_RGB888);
    }

    return qImg;
}
