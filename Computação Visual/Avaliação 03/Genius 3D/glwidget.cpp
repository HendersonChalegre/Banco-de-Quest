
#include "glwidget.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QTimer>
#include "timercpp.h"
#include <QKeyEvent>
#include <QDebug>
#include <chrono>
#include <thread>
#include <QRandomGenerator>
#include <QMessageBox>


enum Botoes
{
    btn_AMARELO  = 3,
    btn_VERDE    = 2,
    btn_VERMELHO = 1,
    btn_AZUL     = 0,
    m_btns
};

GLMmodel* cilindro = nullptr;
GLMmodel* btn_Verde = nullptr;
GLMmodel* btn_Azul = nullptr;
GLMmodel* btn_Vermelho = nullptr;
GLMmodel* btn_Amarelo = nullptr;

GLMmodel* ON_btn_Verde = nullptr;
GLMmodel* ON_btn_Vermelho = nullptr;
GLMmodel* ON_btn_Azul = nullptr;
GLMmodel* ON_btn_Amarelo = nullptr;

GLMmodel* centro = nullptr;
Timer tempoo = Timer();

// Construtor
GLWidget::GLWidget() {
    setWindowTitle("Pressione a tecla 'C' para iniciar o jogo - Genius 3D");
    tempo = QTime::currentTime();
    temporizador = new QTimer(this);
    temporizador->setSingleShot(true);
    connect(temporizador, SIGNAL(timeout()), this, SLOT(updateGL()));
}

// Destruidor
GLWidget::~GLWidget() {
    glDeleteTextures(1, &textura_chao);
    glDeleteTextures(1, &textura_ceu);
}

// Inicializacao do OpenGL
void GLWidget::inicializador_GL() {
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glEnable(GL_TEXTURE_2D);

     glEnable(GL_LIGHT0);


    QImage img1 = convertToGLFormat(QImage("objetos/chao.bmp"));
    QImage img2 = convertToGLFormat(QImage("objetos/ceu.bmp"));
    QImage img3 = convertToGLFormat(QImage("objetos/centro/concrete.jpg"));
    textura_chao = iniciador_textura(img1);
    textura_ceu = iniciador_textura(img2);
    textura_centro = iniciador_textura(img3);


    for (int i = 0; i < m_btns; ++i)
        btn_ativador.push_back(false);


    cilindro = glmReadOBJ("objetos/cilindro.obj");
    centro = glmReadOBJ("objetos/centro.obj");

     btn_Azul =  glmReadOBJ("objetos/azul.obj");
     ON_btn_Azul = glmReadOBJ("objetos/azul_claro.obj");

     btn_Amarelo = glmReadOBJ("objetos/amarelo.obj");
     ON_btn_Amarelo = glmReadOBJ("objetos/amarelo_claro.obj");

     btn_Verde = glmReadOBJ("objetos/verde.obj");
     ON_btn_Verde = glmReadOBJ("objetos/verde_claro.obj");

     btn_Vermelho = glmReadOBJ("objetos/vermelho.obj");
     ON_btn_Vermelho = glmReadOBJ("objetos/vermelho_claro.obj");
}

//redimencionar a janela
void GLWidget::redimensionar_GL(int largura, int altura) {

    const float ar = (float) largura / (float) altura;
    glViewport(0, 0, largura, altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// gera os elementos das texturas
void GLWidget::pintar_GL() {

    // Verifica qual modelo de botao sera carregado
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


     //Carrega o Modelo do cilindro
     glPushMatrix();
         glEnable(GL_LIGHTING);
         glBindTexture(GL_TEXTURE_2D, textura_centro);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glTranslatef(0,1.1,-8);
         // Deixa o objeto posicionado de frente
         glRotatef(-90, 1, 0, 0.0);
         glRotatef(angulo, 0, 0, 1.0);
         glScalef(2.5, 5, 2.5);
         carregaModelo(cilindro);
         glDisable(GL_LIGHTING);
     glPopMatrix();



    // configurando a textura de baixo (chao)
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, textura_chao);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,70.0,1);  glVertex3f(-50,-1.5,50);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-50,-1.5,-50);
            glTexCoord3f(70.0,0.0,-1);  glVertex3f(50,-1.5,-50);
            glTexCoord3f(70.0,70.0,1);  glVertex3f(50,-1.5,50);
        glEnd();
    glPopMatrix();


    // configurando a textura de cima (ceu)
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, textura_ceu);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-10);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,1.0,0.1);  glVertex3f(-10,10,0);
            glTexCoord3f(1.0,1.0,0.1);  glVertex3f(10,10,0);
            glTexCoord3f(1.0,0.0,0.1);  glVertex3f(10,-10,0);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-10,-10,0);
        glEnd();
    glPopMatrix();

    //Carrega o Modelo do botao verde (baixo)
    // Deixa o objeto posicionado de frente
    if (angulo < 0 && (angulo >= -80 || angulo < -280))
    {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,-0.4,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_VERDE] ? ON_btn_Verde : btn_Verde);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }
    else if (angulo >= 0  && (angulo <= 80 || angulo > 280))
    {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,-0.4,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_VERDE] ? ON_btn_Verde : btn_Verde);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }




     //Carrega o Modelo do botao azul (cima)
       // Deixa o objeto posicionado de frente
    if (angulo < 0 && (angulo >= -80 || angulo < -280))
    {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,2.2,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_AZUL] ? ON_btn_Azul : btn_Azul);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }
    else if (angulo >= 0  && (angulo <= 80 || angulo > 280))
    {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,2.2,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_AZUL] ? ON_btn_Azul : btn_Azul);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }


    // Giro pra esquerda
     //Carrega o Modelo do botao vermelho (direita)
    if (angulo < 0 && (angulo >= -40 || angulo < -320)) {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(1.2,0.85,-6);

            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_VERMELHO] ? ON_btn_Vermelho : btn_Vermelho);
            glDisable(GL_LIGHTING);
        glPopMatrix();

    }else if (angulo >= 0 && (angulo < 40 || angulo > 290)) {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(1.2,0.85,-6);
            // Deixa o objeto posicionado de frente
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_VERMELHO] ? ON_btn_Vermelho : btn_Vermelho);
            glDisable(GL_LIGHTING);
         glPopMatrix();
    }


    // Giro pra esquerda
    //Carrega o Modelo do botao amarelo (esquerda)
    if (angulo < 0 && (angulo >= -30 || angulo < -290)) {

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(-1.2,0.85,-6);
            // Deixa o objeto posicionado de frente
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_AMARELO] ? ON_btn_Amarelo : btn_Amarelo);
            glDisable(GL_LIGHTING);
        glPopMatrix();

    }else if (angulo >= 0 && (angulo < 50 || angulo > 310)){

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(-1.2,0.85,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            carregaModelo(btn_ativador[btn_AMARELO] ? ON_btn_Amarelo : btn_Amarelo);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }


//Carrega o Modelo do centro
    if (angulo < 0 && (angulo >= -80 || angulo < -280)){

        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,0.8,-6);
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            glScalef(0.5, 0.5, 0.5);
            carregaModelo(centro);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }else if (angulo >= 0  && (angulo <= 80 || angulo > 280))    {
        //Carrega o Modelo do centro
        glPushMatrix();
            glEnable(GL_LIGHTING);
            glTranslatef(0,0.8,-6);
            // Deixa o objeto posicionado de frente
            glRotatef(-80, 1, 0, 0.0);
            glRotatef(angulo, 0, 0, 1.0);
            glScalef(0.5, 0.5, 0.5);
            carregaModelo(centro);
            glDisable(GL_LIGHTING);
        glPopMatrix();
    }

    // Controlador
    int delay = tempo.msecsTo(QTime::currentTime());
    if (delay == 0)
        delay = 1;
    tempo = QTime::currentTime();
    temporizador->start(qMax(0, 20 - delay));
}

// Verificando as chaves
void GLWidget::Btn_Pressionado(QKeyEvent *evento) {
    switch (evento->key()) {
    case Qt::Key_Escape:
        close(); // Saida do jogo
        break;
    case Qt::Key_F1:
        setWindowState(windowState() ^ Qt::WindowFullScreen); // alterar para tela cheia
        break;
    case Qt::Key_A:
        angulo -= 10;
        if (angulo < -360)
            angulo = 0.0;
        break;
    case Qt::Key_D:
        angulo += 10;
        if (angulo > 360)
            angulo = 0.0;
        break;
    case Qt::Key_C:
        InicializaJogo();
        break;


    case Qt::Key_Left:
        Comando_Jogador(evento->key());
        break;
    case Qt::Key_Up:
        Comando_Jogador(evento->key());
        break;

    case Qt::Key_Right:

        Comando_Jogador(evento->key());
        break;

    case Qt::Key_Down:
        Comando_Jogador(evento->key());
        break;

        if (!_isAllowedCommands)
            return;

    default:
        QGLWidget::Btn_Pressionado(evento); // chamando a verficacao de eventos
    }
}

//seleciona o botao através da tecla
void GLWidget::Comando_Jogador(int chave)
{
    int valor = 0;

    switch(chave)
    {
         case Qt::Key_Left:
         valor = btn_AMARELO;
        break;

         case Qt::Key_Right:
         valor = btn_VERMELHO;
        break;
        case Qt::Key_Up:
           valor = btn_AZUL;
        break;

       case Qt::Key_Down:
             valor = btn_VERDE;
        break;


        default:
            break;
    }



    // Handle animation
    btn_ativador[valor] = true;
    tempoo.setTimeout([&, valor]()
    {
        btn_ativador[valor] = false;
        Verificar_Resultado();
    }, 800);

    escolhas.push_back(valor);
    Selecionador_Musica(valor);
    toque.play();
}



/*
 * Inicializando o jogo. Selecionando inicialmente o nivel do jogo
 */
void GLWidget::InicializaJogo()
{
    nivel = 1;
    setWindowTitle("Nivel: " + QString::number(nivel));
    escolhas.clear();
    valor_jogo.clear();
    atual_Suporsicao = 0;
    _isAllowedCommands = false;
    Verificacao_Nivel();
}

/*
 * Verifica o funcionamento do nivel do jogo
 */
void GLWidget::Verificacao_Nivel()
{
    for (int i = 0; i < nivel; ++i)
    {
        int currentVal = QRandomGenerator::global()->bounded(0, 4);
        tempoo.setTimeout([&, currentVal]()
        {
            Verificar_btn_Animacao(currentVal);
        }, i * 1000);

        // Libera os comandos do usuario, 100 ms apos o ultimo botao fazer animacao
        tempoo.setTimeout([&]()
        {
            _isAllowedCommands = true;
        }, nivel * 1100);
    }
}


/*
 * Verificar o resultados da jogadas
 *
*/
void GLWidget::Verificar_Resultado()
{
    if (escolhas[atual_Suporsicao] == valor_jogo[atual_Suporsicao])
    {
        // Checa se ja verificou todas as escolhas
        if (escolhas.size() ==  valor_jogo.size())
        {
            _isAllowedCommands = false;
            escolhas.clear();
            valor_jogo.clear();
            nivel++;
            atual_Suporsicao = 0;
            setWindowTitle("Nivel: " + QString::number(nivel));
            tempoo.setTimeout([&]()
            {
                Verificacao_Nivel();
            }, 1000);
            return;
        }

        // Ainda faltam respostas, entao aguarda o proximo comando
        ++atual_Suporsicao;
    }
    else
        InicializaJogo();
}


/*
 * Metodo responsavel por remover o cursor no modo tela cheia
 */
void GLWidget::Mudar_Evento(QEvent *evento) {
    switch (evento->type()) {
        case QEvent::WindowStateChange:

            if (windowState() == Qt::WindowFullScreen)
                setCursor(Qt::BlankCursor);
            else
                unsetCursor();
            break;
        default:
            break;
    }
}


/*
 * Verifica a animação ao clicar no botão
 */
void GLWidget::Verificar_btn_Animacao(int verificador)
{
    valor_jogo.push_back(verificador);
    btn_ativador[verificador] = true;
    tempoo.setTimeout([&, verificador]()
    {
         btn_ativador[verificador] = false;
    }, 800);
    Selecionador_Musica(verificador);
    toque.play();
}






/*
 * Ese metodo faz a edição da textura OpenGl, setando o as imagens, altura e largura
 * Configurando e armazenando os pixels no formato RGB
 */
GLuint GLWidget::iniciador_textura(QImage imagem) {
    GLuint identifocador_Textura;
    glGenTextures(1, &identifocador_Textura);
    glBindTexture(GL_TEXTURE_2D, identifocador_Textura);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 imagem.width(), imagem.height(),
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 imagem.bits());
    return identifocador_Textura;
}
/*
 *Esse metodo carrega o modelo gerado
 */
GLuint GLWidget::carregaModelo(GLMmodel* modelo) {
        glmUnitize(modelo);
        glmFacetNormals(modelo);
        glmVertexNormals(modelo, 90.0);

    glmDraw(modelo, GLM_SMOOTH | GLM_MATERIAL);

}


/*
 * Eventos do Mouse
 */

void GLWidget::Mouse_Pressionado(QMouseEvent *event)
{

    QGLWidget::mouseMoveEvent(event);
}


/*
 * Seleciona o audio que o deve tocar ao selecionar o botao
 */

void GLWidget::Selecionador_Musica(int valorMusica)
{
    switch(valorMusica)
    {
         case btn_VERMELHO:
        toque.setSource(QUrl::fromLocalFile("musica/vermelho.wav"));
        break;

         case btn_AMARELO:
        toque.setSource(QUrl::fromLocalFile("musica/amarelo.wav"));
        break;
        case btn_AZUL:
            toque.setSource(QUrl::fromLocalFile("musica/azul.wav"));
        break;

       case btn_VERDE:
            toque.setSource(QUrl::fromLocalFile("musica/verde.wav"));
        break;


        default:
            break;
    }
}

