#ifndef THREADBAIDUAPI_H
#define THREADBAIDUAPI_H

#include <QThread>
#include <curl/curl.h>

class ThreadBaiduAPI : public QThread
{
    Q_OBJECT

public:
    explicit ThreadBaiduAPI(QObject *parent = nullptr);
    ~ThreadBaiduAPI();

protected:
    void run();

};

#endif // THREADBAIDUAPI_H
