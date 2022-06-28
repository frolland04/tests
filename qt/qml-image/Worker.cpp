#include "Worker.h"

#include <QDebug>
#include <QThread>


Worker::Worker(QObject * parent) : QObject{parent}
{
}


Worker::~Worker()
{
}


void Worker::process()
{
    // Process.
    // Start processing data.
    // (allocate resources using new here)

    qDebug() << __PRETTY_FUNCTION__ ;

    emit started();

    for ( int i = 0 ; i < 100 ; ++i)
    {
        emit new_result_available();
        QThread::msleep(50);
    }

    emit finished();
}
