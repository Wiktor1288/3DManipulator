#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent=nullptr);
protected:

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;


    QOpenGLContext *m_context;

};

#endif // GLWIDGET_H
