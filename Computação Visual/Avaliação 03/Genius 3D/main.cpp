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
    // Construindo o app Qt
    QApplication a(argc, argv);

    // Verificando o suporte ao OpenGl
    if (!QGLFormat::hasOpenGL()) {
        qDebug("Erro ao executar o OpenGL");
        return EXIT_FAILURE;
    }

    // Criando a janela OpenGl
    GLWidget w;
    w.setMinimumSize(700, 700);
    w.show();

    // Executando
    return a.exec();
}
