#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

#include "sqlite_backend.h"


class Logger
{
public:

    Logger();
    ~Logger();

    void init();

    void release();

    void log_item(const std::string & p_text);

private:

    SqliteBackend m_backend;

};


#endif // __LOGGER_H__
