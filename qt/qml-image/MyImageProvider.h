#ifndef MYIMAGEPROVIDER_H
#define MYIMAGEPROVIDER_H

#include <QQuickImageProvider>

#include "Worker.h"


class MyImageProvider : public QQuickImageProvider
{
    Q_OBJECT

public:

    explicit MyImageProvider(QObject * parent = nullptr);

    QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize) override;

signals:

    void new_result_available();

};

#endif // MYIMAGEPROVIDER_H
