/*
 * This code was created by Jeff Molofee 1999
 * And ported to C++/Qt4 by Wesley Stessens 2009
 *
 * Contact Jeff through his website: http://nehe.gamedev.net/
 * Contact Wesley for port-specific comments: wesley@ubuntu.com
 */

#include <QApplication>
#include "glwidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if (!QGLFormat::hasOpenGL()) {
        qDebug("Your system does not seem to support OpenGL. Cannot run this example.");
        return EXIT_FAILURE;
    }

    GLWidget w;
    w.setMinimumSize(800, 600);
    w.show();

    return a.exec();
}
