#include <QCoreApplication>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>
#include <QDateTime>

#include "nlohmann/json.hpp"
#include <iostream>


int main(int, char **)
{
    qDebug() << __PRETTY_FUNCTION__ << __cplusplus << "COUCOU!" ;

    using cppjson_obj = nlohmann::json;

    cppjson_obj tab_json;

    cppjson_obj v1;
    v1["index"] = 2520450028;
    v1["value"] = 3.0;

    //qDebug() << QString::fromStdString(std::string(v1.dump()));
    std::cout << v1.dump() << std::endl;

    tab_json += v1;

    cppjson_obj v2;
    v2["index"] = 2035;
    v2["value"] = 3.1415;

    //qDebug() << QString::fromStdString(std::string(v2.dump()));
    std::cout << v2.dump() << std::endl;

    tab_json += v2;

    //qDebug() << QString::fromStdString(std::string(tab_json.dump()));
    std::cout << tab_json.dump() << std::endl;

    qDebug() << "FINI." ;
}
