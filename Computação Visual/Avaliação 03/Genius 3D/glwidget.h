/*
 * This code was created by Jeff Molofee 1999
 * And ported to C++/Qt4 by Wesley Stessens 2009
 *
 * Contact Jeff through his website: http://nehe.gamedev.net/
 * Contact Wesley for port-specific comments: wesley@ubuntu.com
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTime>
#include <QHash>
#include <QLabel>
#include <QFrame>
#include <QSoundEffect>

extern "C" {
    #include "glm.h"
}

class QTimer;

class GLWidget : public QGLWidget {
    Q_OBJECT



// declaracoes de privacidade
private:
    void drawCube();
    void Verificar_btn_Animacao(int valor);
    QHash<GLuint, QString> Nome_verfic;
    GLfloat xrot, yrot, xspeed, yspeed, z;
    GLuint iniciador_textura(QImage imagem);
    GLuint carregaModelo(GLMmodel* modelo);
    GLuint filter;
    GLuint texture[2];
    GLuint  textura_chao, textura_centro, textura_ceu;
    float angulo = 0.0;
    bool lightChanged, filterChanged;
    bool _isAllowedCommands = true;
    int changeAmount;
    int nivel = 1;
    int atual_Suporsicao = 0;
    std::vector<int> escolhas;
    std::vector<int> valor_jogo;
    std::vector<bool> btn_ativador;
    QTimer *temporizador;
    QTime tempo;
    QSoundEffect toque;

public:
    ~GLWidget();
    GLWidget();

protected:
   void inicializador_GL();
   void InicializaJogo();
   void Verificacao_Nivel();
   void pintar_GL();
   void redimensionar_GL(int largura, int altura);
   void Selecionador_Musica(int botaoIndex);
   void Comando_Jogador(int key);
   void Mudar_Evento(QEvent *evento);
   void Btn_Pressionado(QKeyEvent *btn_evento);
   void Mouse_Pressionado(QMouseEvent *evento);
   void Verificar_Resultado();



};

#endif // GLWIDGET_H
