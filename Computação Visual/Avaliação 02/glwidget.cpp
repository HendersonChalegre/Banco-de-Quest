
/*
 * This code was created by Jeff Molofee 1999
 * And ported to C++/Qt4 by Wesley Stessens 2009
 *
 * Contact Jeff through his website: http://nehe.gamedev.net/
 * Contact Wesley for port-specific comments: wesley@ubuntu.com
 */

#include "glwidget.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QKeyEvent>
#include <QTimer>

int nivel = 45;
// Constructor
GLWidget::GLWidget() {
    setWindowTitle("Casa 3D");
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    nivel = 45;
    distancia = -100;
}

// Destructor
GLWidget::~GLWidget() {
    glDeleteTextures(1, &_textureGrass);
    glDeleteTextures(1, &_textureIronBlock);
}

// Initialize OpenGL
void GLWidget::initializeGL() {
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    qglClearColor(Qt::black); // Set the clear color to a black background

    glClearDepth(1.0f); // Depth buffer setup
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Set type of depth test

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really nice perspective calculations

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    QImage img;
    img = convertToGLFormat(QImage("grass.bmp"));
    _textureGrass = loadTexture(img);
    img = convertToGLFormat(QImage("ironBlock.png"));
    _textureIronBlock = loadTexture(img);

    GLfloat ambLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat diffLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPos[] = {0.0f, 0.0f, 2.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffLight);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);

    blockId = makeBlock();
}

// This is called when the OpenGL window is resized
void GLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<GLfloat>(width)/height, 0.1f, 100.0f); // Calculate aspect ratio
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// OpenGL painting code goes here
void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,-10,distancia);

    glRotatef(_angle, 0.0, 1.0, 0.0);

    // Grass
    glBindTexture(GL_TEXTURE_2D, _textureGrass);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,70.0,1);  glVertex3f(-100,-0.5,100);
        glTexCoord3f(0.0,0.0,-1);  glVertex3f(-100,-0.5,-100);
        glTexCoord3f(70.0,0.0,-1);  glVertex3f(100,-0.5,-100);
        glTexCoord3f(70.0,70.0,1);  glVertex3f(100,-0.5,100);
    glEnd();

    // Piramide
    for(int i = nivel; i > 0; i--){
        int largura = i*2-1;
        for (int j = 0; j < largura; j++){
            for (int k = 0; k < largura; k++){
                glPushMatrix();
                    glTranslated(largura/2 - j, nivel - i, largura/2 - k);
                    glCallList(blockId);
                glPopMatrix();
            }
        }
    }
    makeBlock();
    glEndList();

    // Framerate control
    timer->start(30);
}

// Key handler
void GLWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    // Fechar
    case Qt::Key_Escape:
        close();
        break;
    // mover para esquerda
    case Qt::Key_Left:
        _angle -= 1;
        if (_angle > 360)
            _angle = 0.0;
        break;
    // mover para direita
    case Qt::Key_Right:
        _angle += 1;
        if (_angle > 360)
            _angle = 0.0;
        break;
    // aprocimar
    case Qt::Key_Up:
            distancia += 0.5f;
            if (distancia > 0) distancia = 0.0;
        break;
    // Afastar
    case Qt::Key_Down:
            distancia -= 0.5f;
            if (distancia < -110.0f) distancia = -150.0f;
        break;
    default:
        QGLWidget::keyPressEvent(event); // Let base class handle the other keys
    }
}

GLuint GLWidget::loadTexture(QImage image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image.width(), image.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,image.bits());
    return textureId;
}
