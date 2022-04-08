#ifndef __SQLITE_BACKEND_H__
#define __SQLITE_BACKEND_H__

#include "log_message.h"
#include "global.h"


class SqliteBackend
{
public:

    SqliteBackend();
    ~SqliteBackend();

    void init();

    void release();

    void process_new_message(const LogMessage & p_msg);

private:

    return_t setup_tables();

    bool is_backend_ready()  { return m_is_ready; }
    void set_backend_ready() { m_is_ready = true; }

    bool m_is_ready;

};


#endif // __SQLITE_BACKEND_H__
