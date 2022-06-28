#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QImage>


class Worker : public QObject
{
    Q_OBJECT

public:

    explicit Worker(QObject * parent = nullptr);
    ~Worker();

public slots:

    void process();    
    void stop();

signals:

    void started();
    void finished();

    void new_result_available(QImage);

private:

    bool m_stop;

    // add your variables here

};


#endif // WORKER_H
