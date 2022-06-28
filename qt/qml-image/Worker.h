#ifndef WORKER_H
#define WORKER_H

#include <QObject>


class Worker : public QObject
{
    Q_OBJECT

public:

    explicit Worker(QObject * parent = nullptr);
    ~Worker();

public slots:

    void process();

signals:

    void started();
    void finished();

    void new_result_available();

private:

    // add your variables here

};


#endif // WORKER_H
