#include "threadfacecapture.h"
#include <iostream>

ThreadFaceCapture::ThreadFaceCapture(QObject *parent) : QThread (parent)
{
    std::cout << ' ';
    std::cout << ' ';
}

void ThreadFaceCapture::run()
{
    cv::Mat frame_mat, frame_gray;
    QImage frame_qimage;
    QRect rect;
    std::vector<cv::Rect> detections_cvrect;
    std::vector<cv::Rect>::iterator it;
    std::vector<QRect> detections_qrect;

    cap.open(0);
//    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
//    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
//    cap.set(cv::CAP_PROP_FPS, 60);
    faceCascade.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");

    while (1) {
        cap.read(frame_mat);
        cv::flip(frame_mat, frame_mat, 1);
        cv::cvtColor(frame_mat, frame_gray, CV_BGR2GRAY);
        faceCascade.detectMultiScale(frame_gray, detections_cvrect, 1.2, 5, 0, cv::Size(40, 40));

        for (it=detections_cvrect.begin();it!=detections_cvrect.end();it++) {
            rect.setX(it->x);
            rect.setY(it->y);
            rect.setWidth(it->width);
            rect.setHeight(it->height);
            detections_qrect.push_back(rect);
        }

        frame_qimage = Mat2QImage(frame_mat);
        emit imageInformation(frame_qimage, detections_qrect);

//        if(detections.size() != 0){
//            std::cerr << typeid(detections[0]).name() << std::endl;
//        }
//        cv::imshow("ha", frame_mat);
//        int k = cv::waitKey(30) & 0xff;
//        if(k == 27){
//            cap.release();
//            break;
//        }
    }
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
