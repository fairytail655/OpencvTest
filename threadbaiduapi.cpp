#include "threadbaiduapi.h"

#include <QDebug>

ThreadBaiduAPI::ThreadBaiduAPI(QObject *parent): QThread (parent)
{

}

ThreadBaiduAPI::~ThreadBaiduAPI()
{

}

void ThreadBaiduAPI::run()
{
    CURL *curl_handle;
//    curl_handle = curl_easy_init();

    qDebug() << "haha";
}
