#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "MyImageProvider.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    std::srand(std::time(0)); // use current time as seed for random generator

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    MyImageProvider mip;

    engine.addImageProvider(QLatin1String("MyImageProvider"), &mip);
    engine.rootContext()->setContextProperty("mip", &mip);

    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject * obj, const QUrl & objUrl)
                     {
                         if (!obj && url == objUrl) QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
