#include "logger.h"
#include "log_message.h"

#include <QDebug>


Logger::Logger()
{
    qDebug() << __PRETTY_FUNCTION__;
}


Logger::~Logger()
{
    qDebug() << __PRETTY_FUNCTION__;
    release();
}


void Logger::init()
{
    qDebug() << __PRETTY_FUNCTION__;
    m_backend.init();
}


void Logger::release()
{
    qDebug() << __PRETTY_FUNCTION__;
    m_backend.release();
}


void Logger::log_item(const std::string & p_text)
{
    qDebug() << __PRETTY_FUNCTION__ << QString::fromStdString(p_text);

    LogMessage m(0, p_text, "", 0);
    m_backend.process_new_message(m);
}
