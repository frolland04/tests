#include "backend.hpp"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


Backend::Backend(QObject * parent) : QObject{parent}
{
    qDebug() << __PRETTY_FUNCTION__ ;

    m_refresh_timer.setInterval (500);
    QObject::connect(&m_refresh_timer, &QTimer::timeout, [this](){
        qDebug() << "REFRESH";
        m_a = rand () % 10000;
        m_b = rand () / 123456.789;
        m_c = rand () < (RAND_MAX / 2) ? QStringLiteral ("YES") : QStringLiteral("NO");
        m_d = rand () < (RAND_MAX / 2);
    });
    m_refresh_timer.start ();
}


Backend::~Backend()
{
    qDebug() << __PRETTY_FUNCTION__ ;
    m_refresh_timer.stop ();
}


QString Backend::get_json()
{
    qDebug() << __PRETTY_FUNCTION__ ;

    QJsonArray a;
    a += QJsonObject{{"prop_name", "a"}, {"prop_value", m_a}};
    a += QJsonObject{{"prop_name", "b"}, {"prop_value", m_b}};
    a += QJsonObject{{"prop_name", "c"}, {"prop_value", m_c}};
    a += QJsonObject{{"prop_name", "d"}, {"prop_value", m_d}};
    return QJsonDocument(a).toJson ();
}

