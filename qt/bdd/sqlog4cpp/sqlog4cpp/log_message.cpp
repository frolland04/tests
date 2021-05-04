#include "log_message.h"

#include <QDebug>


LogMessage::LogMessage(std::time_t         p_timestamp,
                       const std::string & p_text     ,
                       const std::string & p_filename ,
                       int                 p_line_nb
                       ) :
    m_timestamp (p_timestamp),
    m_text      (p_text     ),
    m_filename  (p_filename ),
    m_line_nb   (p_line_nb  )
{
    qDebug() << __PRETTY_FUNCTION__ << QString::fromStdString(p_text);
}


LogMessage::~LogMessage()
{
    qDebug() << __PRETTY_FUNCTION__ << QString::fromStdString(m_text);
}


const std::string & LogMessage::text() const
{
    return m_text;
}

std::time_t LogMessage::timestamp() const
{
    return m_timestamp;
}

const std::string & LogMessage::filename() const
{
    return m_filename;
}

int LogMessage::line_nb() const
{
    return m_line_nb;
}
