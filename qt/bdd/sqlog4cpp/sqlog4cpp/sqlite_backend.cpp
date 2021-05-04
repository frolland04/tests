#include "sqlite_backend.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QDateTime>


const QString DB_FILE    = QLatin1String("test.sqlite");
const QString TBL_NAME   = QLatin1String("T_LOGS");
const QString TBL_ROWIDS = QLatin1String("test INTEGER NOT NULL");
const QString TBL_KEYIDS = QLatin1String("PRIMARY KEY (test)");
const QString TBL_CONSTR = QLatin1String("WITHOUT ROWID");

QSqlDatabase qdb ;


SqliteBackend::SqliteBackend()
{
    qDebug() << __PRETTY_FUNCTION__;
}


SqliteBackend::~SqliteBackend()
{
    qDebug() << __PRETTY_FUNCTION__;
    release();
}


void SqliteBackend::init()
{
    qDebug() << __PRETTY_FUNCTION__;

    return_t res = RT_KO;

    if (QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        qDebug() << "Connection to Sqlite DB...";

        qdb = QSqlDatabase::addDatabase("QSQLITE");
        qdb.setDatabaseName(DB_FILE);

        if (!qdb.open())
        {
            qDebug() << "DB KO!" << qdb.lastError().text();
        }
        else
        {
            qDebug() << "DB OK...";

            if (qdb.tables().contains(TBL_NAME))
            {
                qDebug() << "TBL OK...";
                res = RT_OK;
            }
            else
            {
                qDebug() << "No existing required tables";
                res = setup_tables();
            }
        }
    }

    if (res) set_backend_ready();
}


void SqliteBackend::release()
{
    qDebug() << __PRETTY_FUNCTION__;

    if (qdb.isOpen() && qdb.isValid())
        qdb.close();

    m_is_ready = false;
}


void SqliteBackend::process_new_message(const LogMessage & p_msg)
{
    qDebug() << __PRETTY_FUNCTION__
             << p_msg.timestamp()
             << QString::fromStdString(p_msg.text())
             << QString::fromStdString(p_msg.filename())
             << p_msg.line_nb()
             << is_backend_ready();

    if (is_backend_ready())
    {
        QString sql_text = QString("INSERT INTO %1 VALUES (%2);").arg(TBL_NAME, QString::number(QDateTime::currentMSecsSinceEpoch()));
        qDebug() << __PRETTY_FUNCTION__ << sql_text;

        QSqlQuery sql = qdb.exec(sql_text);
        qDebug() << sql.lastError();
    }
}


return_t SqliteBackend::setup_tables()
{
    qDebug() << __PRETTY_FUNCTION__;

    return_t res = RT_KO;

    if (qdb.isOpen() && qdb.isValid())
    {
        QString sql_text = QString("CREATE TABLE IF NOT EXISTS %1 (%2, %3) %4;").arg(TBL_NAME, TBL_ROWIDS, TBL_KEYIDS, TBL_CONSTR);
        qDebug() << __PRETTY_FUNCTION__ << sql_text;

        QSqlQuery sql = qdb.exec(sql_text);
        if (qdb.tables().contains(TBL_NAME))
        {
            qDebug() << "TBL OK...";
            res = RT_OK; // success
        }
        else
        {
            qDebug() << "TBL KO!" << qdb.lastError().text();
        }
    }

    return res;
}
