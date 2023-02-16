#include <QDebug>
#include <QList>


class MyDataI
{
public:

    MyDataI() = default;
    virtual ~MyDataI() = default; // needed by "delete bb"

    virtual void text()
    {
        qDebug() << "This is MyDataI!" << __PRETTY_FUNCTION__ ;
    }
};


template<class T>
class MyData : public MyDataI
{
public:

    MyData() = default;
    ~MyData() = default;

    MyData(const MyData &) = delete;
    MyData(const MyData *) = delete;
    //MyData(const MyData &) = default; // needed by QList<MyData<T>>::push_back()

    void text() override
    {
        qDebug() << "This is MyData!" << __PRETTY_FUNCTION__ ;
    }

};


int main(int, char**)
{
    qDebug() << "HELLO!" << __PRETTY_FUNCTION__ ;

    MyData<int> a;
    a.text(); // MyData<T>::text() [with T = int]

    MyData<bool> b;
    b.text(); // MyData<T>::text() [with T = bool]

    //QList<MyData<int>> c;
    //c.push_back(a);

    MyDataI * aa = new MyData<int>();
    aa->text(); // MyData<T>::text() [with T = int]

    MyDataI * bb = new MyData<bool>();
    bb->text(); // MyData<T>::text() [with T = bool]
    delete bb;

    QList<MyDataI*> cc;
    cc.push_back(aa);
    cc[0]->text(); // MyData<T>::text() [with T = int]

    QList<MyDataI> dd;
    dd.push_back(*aa);
    dd[0].text(); // void MyDataI::text()

    return 0;
}
