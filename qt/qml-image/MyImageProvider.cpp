#include "MyImageProvider.h"

#include <QThread>


MyImageProvider::MyImageProvider(QObject * parent)
    : QQuickImageProvider{ QQmlImageProviderBase::Image }
{
    setParent(parent);

    QThread* thread = new QThread();
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    connect( thread, &QThread::started, worker, &Worker::process);
    connect( worker, &Worker::new_result_available, this, &MyImageProvider::new_result_available); // signal to signal

    connect( worker, &Worker::finished,  thread, &QThread::quit);
    connect( worker, &Worker::finished,  worker, &Worker::deleteLater);
    connect( thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}


QImage MyImageProvider::requestImage(const QString & id, QSize * size, const QSize & requestedSize)
{
    qDebug() << __PRETTY_FUNCTION__ << id << requestedSize << std::rand();

    QImage image(400, 500, QImage::Format_RGB888);

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

    int i = cl.size() * std::rand() / RAND_MAX;
    c = cl.at(i);
    image.fill(c);

    return image;
}
