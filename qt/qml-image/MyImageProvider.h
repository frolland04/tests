#ifndef MYIMAGEPROVIDER_H
#define MYIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage.h>

#include "Worker.h"


class MyImageProvider : public QQuickImageProvider
{
    Q_OBJECT

public:

    explicit MyImageProvider(QObject * parent = nullptr);
    ~MyImageProvider();

    QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize) override;

signals:

    void new_result_available();

private:

    QImage m_last_image;

};

#endif // MYIMAGEPROVIDER_H
