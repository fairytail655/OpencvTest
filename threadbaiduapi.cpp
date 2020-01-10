#include "threadbaiduapi.h"

#include <QDebug>

ThreadBaiduAPI::ThreadBaiduAPI(QObject *parent): QThread (parent)
{
    // 设置APPID/AK/SK
    std::string app_id = "18174994";
    std::string api_key = "CPK3UVxCWFnTOL0BkyxSGWGy";
    std::string secret_key = "23uyGD9Tu4cgfC779tjjKPdenWYGgu2O";

    aip::Face client(app_id, api_key, secret_key);
}

ThreadBaiduAPI::~ThreadBaiduAPI()
{

}

void ThreadBaiduAPI::run()
{

}
