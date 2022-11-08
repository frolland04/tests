#include "backend.hpp"
#include <QDebug>


Backend::Backend(QObject * parent) : QObject{parent}
{
    qDebug() << __PRETTY_FUNCTION__ ;

    m_refresh_timer.setInterval (500);
    QObject::connect(&m_refresh_timer, &QTimer::timeout, [this](){
        qDebug() << "REFRESH";
        set_a(rand () % 10000);
        set_b(rand () / 123456.789);
        set_c((rand () < (RAND_MAX / 2)) ? QStringLiteral ("YES") : QStringLiteral("NO"));
        set_d(rand () < (RAND_MAX / 2));
    });
    m_refresh_timer.start ();
}


Backend::~Backend()
{
    qDebug() << __PRETTY_FUNCTION__ ;
    m_refresh_timer.stop ();
}


int Backend::get_a()
{
    qDebug() << __PRETTY_FUNCTION__ << m_a;
    return m_a;
}


void Backend::set_a(int p_a)
{
    qDebug() << __PRETTY_FUNCTION__ << p_a << m_a;
    if (p_a != m_a)
    {
        m_a = p_a;
        emit a_changed();
    }
}


double Backend::get_b()
{
    qDebug() << __PRETTY_FUNCTION__ << m_b;
    return m_b;
}


void Backend::set_b(double p_b)
{
    qDebug() << __PRETTY_FUNCTION__ << p_b << m_b;
    if (p_b != m_b)
    {
        m_b = p_b;
        emit b_changed();
    }
}


QString Backend::get_c()
{
    qDebug() << __PRETTY_FUNCTION__ << m_c;
    return m_c;
}


void Backend::set_c(QString p_c)
{
    qDebug() << __PRETTY_FUNCTION__ << p_c << m_c;
    if (p_c != m_c)
    {
        m_c = p_c;
        emit c_changed();
    }
}


bool Backend::get_d()
{
    qDebug() << __PRETTY_FUNCTION__ << m_d;
    return m_d;
}


void Backend::set_d(bool p_d)
{
    qDebug() << __PRETTY_FUNCTION__ << p_d << m_d;
    if (p_d != m_d)
    {
        m_d = p_d;
        emit d_changed();
    }
}



