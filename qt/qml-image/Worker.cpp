#include "Worker.h"

#include <QDebug>
#include <QThread>
#include <QImage>


Worker::Worker(QObject * parent) : QObject{parent}, m_stop(false)
{
    qDebug() << __PRETTY_FUNCTION__ ;
}


Worker::~Worker()
{
    qDebug() << __PRETTY_FUNCTION__ ;
}


void Worker::process()
{
    // Process.
    // Start processing data.
    // (allocate resources using new here)

    qDebug() << __PRETTY_FUNCTION__ ;

    emit started();

    for ( int i = 0 ; i < 500 && ! m_stop ; ++i)
    {
        qDebug() << __PRETTY_FUNCTION__ << std::rand();

        QImage image(400, 400, QImage::Format_RGB888);

        QColor c;
        QList<Qt::GlobalColor> cl { Qt::white,
                                    Qt::black,
                                    Qt::red,
                                    Qt::darkRed,
                                    Qt::green,
                                    Qt::darkGreen,
                                    Qt::blue,
                                    Qt::darkBlue,
                                    Qt::cyan,
                                    Qt::darkCyan,
                                    Qt::magenta,
                                    Qt::darkMagenta,
                                    Qt::yellow,
                                    Qt::darkYellow,
                                    Qt::gray,
                                    Qt::darkGray,
                                    Qt::lightGray };

        int ci = cl.size() * std::rand() / RAND_MAX;
        c = cl.at(ci);
        image.fill(c);

        emit new_result_available(image);
        QThread::msleep(30);
    }

    emit finished();
}


void Worker::stop()
{
    qDebug() << __PRETTY_FUNCTION__ ;
    m_stop = true;
}
