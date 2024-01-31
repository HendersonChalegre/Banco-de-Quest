QT += opengl
QT += multimedia
QT += core

TARGET = Genius

TEMPLATE = app

SOURCES +=  main.cpp \
            glm.cpp \
            glwidget.cpp

HEADERS +=  glwidget.h \
            glm.h \
            materials.h \
            timercpp.h

RESOURCES += res.qrc

win32 {
    INCLUDEPATH += \
        C:/freeglut-build-3.2.1/install/include

    LIBS += \
        -LC:/freeglut-build-3.2.1/install/lib \
        -lfreeglut \
        -lopengl32 \
        -lglu32
}

unix {
    INCLUDEPATH += /usr/include

    LIBS += /usr/lib/x86_64-linux-gnu/libglut.so \
        -lGL \
        -lGLU
}

DISTFILES +=



