#include "glwidget.h"
#include <GL/glut.h>
#include <QtOpenGL/qgl.h>
#include <QtOpenGL/qglbuffer.h>
#include <QtOpenGL/qglcolormap.h>
#include <QtOpenGL/qglframebufferobject.h>
#include <QtOpenGL/qglfunctions.h>
#include <QtOpenGL/qglpixelbuffer.h>
#include <QtOpenGL/qglshaderprogram.h>
#include <QtDebug>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void GLWidget::initializeGL()
{

    initializeOpenGLFunctions();
    glClearColor(0.8,0.8,0.9,0);
    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    const char *fragmentShaderSource="#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    int  success;
    char infoLog[512];
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        qDebug() << "elo";
    }
    glUseProgram(shaderProgram);

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float positons[9]={

        -0.5f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    unsigned int buffer;
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER,9* sizeof (float),positons,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, sizeof(float)*3, 0);
    glDrawArrays(GL_TRIANGLES,0,3);


   /* glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(0.0f,-0.5f);
    glVertex2f(-0.5f,0.5f);
    glEnd(); */

}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);


}
