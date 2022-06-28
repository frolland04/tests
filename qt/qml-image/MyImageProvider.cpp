#include "MyImageProvider.h"

#include <QThread>


MyImageProvider::MyImageProvider(QObject * parent) :
    QQuickImageProvider{ QQmlImageProviderBase::Image },
    m_last_image()
{
    qDebug() << __PRETTY_FUNCTION__ ;

    setParent(parent);

    QThread* thread = new QThread();
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    connect( thread, &QThread::started, worker, &Worker::process);
    connect( worker,
            &Worker::new_result_available,
            [=]( const QImage & qi )
            {
                m_last_image = qi;
                emit new_result_available();
            }
    );

    connect( worker, &Worker::finished,  thread, &QThread::quit);
    connect( worker, &Worker::finished,  worker, &Worker::deleteLater);
    connect( thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}


MyImageProvider::~MyImageProvider()
{
    qDebug() << __PRETTY_FUNCTION__ ;
}


QImage MyImageProvider::requestImage(const QString & id, QSize * size, const QSize & requestedSize)
{
    qDebug() << __PRETTY_FUNCTION__ << id << requestedSize ;

    return m_last_image;
}
