#include "mygl.h"
#include <iostream>

MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent) { }

void MyGL::initializeGL()  {

    initializeOpenGLFunctions(); // obvious (QOpenGLFunctions)

    GLfloat vertices[6][2] =
    {
    { -0.90f, -0.90f }, // Triangle 1
    { +0.85f, -0.90f },
    { -0.90f, +0.85f },

    { +0.90f, -0.85f }, // Triangle 2
    { +0.90f, +0.90f },
    { -0.85f, +0.90f }
    };

    buffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    Q_ASSERT(buffer.create());
    Q_ASSERT(buffer.bind());
    buffer.allocate(sizeof(vertices));
    buffer.write(0, vertices, sizeof(vertices));

    QString apath(QCoreApplication::applicationDirPath());
    QString path = apath + "/OtherFiles/vshader.vsh";
    shaderProg.addShaderFromSourceFile(QOpenGLShader::Vertex, path);
    path = apath + "/OtherFiles/vshader.fsh";
    shaderProg.addShaderFromSourceFile(QOpenGLShader::Fragment, path);
    Q_ASSERT(shaderProg.link());
    Q_ASSERT(shaderProg.bind());

    const int vPosition = 0;

    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPosition);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25, 0.45, 0.65, 1.0);


}

void MyGL::paintGL()  {
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glFlush();
}

void MyGL::resizeGL(int w, int h)  {
    Q_UNUSED(w); Q_UNUSED(h);
}
