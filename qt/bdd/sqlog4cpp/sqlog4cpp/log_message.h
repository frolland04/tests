#ifndef __LOGMESSAGE_H__
#define __LOGMESSAGE_H__

#include <string>
#include <ctime>


class LogMessage
{
public:

    LogMessage(std::time_t         p_timestamp,
               const std::string & p_text     ,
               const std::string & p_filename ,
               int                 p_line_nb
               );

    ~LogMessage();

    const std::string & text     () const;
    std::time_t         timestamp() const;
    const std::string & filename () const;
    int                 line_nb  () const;

private:

    std::time_t m_timestamp;
    std::string m_text     ;
    std::string m_filename ;
    int         m_line_nb  ;

};


#endif // __LOGMESSAGE_H__
