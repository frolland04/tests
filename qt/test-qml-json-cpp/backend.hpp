#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <QObject>
#include <QTimer>


class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY (int a     READ get_a WRITE set_a NOTIFY a_changed);

    Q_PROPERTY (double b  READ get_b WRITE set_b NOTIFY b_changed);

    Q_PROPERTY (QString c READ get_c WRITE set_c NOTIFY c_changed);

    Q_PROPERTY (int d     READ get_d WRITE set_d NOTIFY d_changed);

public:

    explicit Backend(QObject * parent = nullptr);
    virtual ~Backend();

    int get_a();
    void set_a(int p_a);

    double get_b();
    void set_b(double p_b);

    QString get_c();
    void set_c(QString p_c);

    bool get_d();
    void set_d(bool p_d);

signals:

    void a_changed();
    void b_changed();
    void c_changed();
    void d_changed();

private:

    int     m_a{12};

    double  m_b{25.999};

    QString m_c{"..."};

    bool    m_d{true};

    QTimer  m_refresh_timer;

};


#endif // BACKEND_HPP
