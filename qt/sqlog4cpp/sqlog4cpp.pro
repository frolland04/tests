TEMPLATE = app

CONFIG += console c++11
QT += core sql

SOURCES += \
    log_message.cpp \
    logger.cpp \
    main.cpp \
    sqlite_backend.cpp

HEADERS += \
    global.h \
    log_message.h \
    logger.h \
    sqlite_backend.h
