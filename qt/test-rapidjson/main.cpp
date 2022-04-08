#include <QCoreApplication>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>
#include <QDateTime>

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"


int main(int, char **)
{
    qDebug() << __PRETTY_FUNCTION__ << __cplusplus << "COUCOU!" ;

    rapidjson::Document d;
    rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

    d.SetArray();

    rapidjson::Value obj;
    obj.SetObject();
    obj.AddMember("index", 25528004, allocator);
    obj.AddMember("data", 450.0, allocator);
    obj.AddMember("other", 28.12340, allocator);

    d.PushBack(obj, allocator);

    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    d.Accept(writer);
    std::cout << sb.GetString();

    qDebug() << "FINI." ;
}
