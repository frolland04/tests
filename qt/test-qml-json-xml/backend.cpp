#include "backend.hpp"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QDomDocument>


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

    QDomDocument doc;
    QDomElement data = doc.createElement("data");
    doc.appendChild(data);

    QDomElement list = doc.createElement("list");
    data.appendChild(list);

    QDomElement a = doc.createElement("item");
    list.appendChild(a);
    a.setAttribute ("prop_name", "a");
    a.setAttribute ("prop_value", QString::number (m_a));

    QDomElement b = doc.createElement("item");
    list.appendChild(b);
    b.setAttribute ("prop_name", "b");
    b.setAttribute ("prop_value", QString::number (m_b));

    QDomElement c = doc.createElement("item");
    list.appendChild(c);
    c.setAttribute ("prop_name", "c");
    c.setAttribute ("prop_value", m_c);

    QDomElement d = doc.createElement("item");
    list.appendChild(d);
    d.setAttribute ("prop_name", "d");
    d.setAttribute ("prop_value", m_d ? "True" : "False");

    return (doc.toString());
}

