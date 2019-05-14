#ifndef MYGL_H
#define MYGL_H

#include <QtWidgets>


class MyGL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MyGL(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    QOpenGLBuffer buffer;
    QOpenGLShaderProgram shaderProg;

};

#endif // MYGL_H
