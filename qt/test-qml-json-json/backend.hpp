#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <QObject>
#include <QTimer>


class Backend : public QObject
{
    Q_OBJECT

public:

    explicit Backend(QObject * parent = nullptr);
    virtual ~Backend();

    Q_INVOKABLE QString get_json();

private:

    int     m_a{12};

    double  m_b{25.999};

    QString m_c{"..."};

    bool    m_d{true};

    QTimer  m_refresh_timer;

};


#endif // BACKEND_HPP
