#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <glm.h>
#include <vector>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void cleanup();
    void setShaders(QString fragment_filename, QString vertex_filename);
    void setElements(std::vector<int> elements);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

private:
    bool m_core;

 //   QOpenGLVertexArrayObject m_vao;
 //   QOpenGLBuffer m_logoVbo;
    QOpenGLShaderProgram *m_program;

    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;

 //   QMatrix4x4 m_proj;
 //   QMatrix4x4 m_camera;
 //   QMatrix4x4 m_world;

};

#endif // GLWIDGET_H
