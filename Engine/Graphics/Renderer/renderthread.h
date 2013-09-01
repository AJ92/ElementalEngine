#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QMutex>
#include <QString>
#include <QList>

#include "Engine.h"

class GLWindow;

class RenderThread : public QThread
{
    Q_OBJECT
public:
    RenderThread(QObject *parent = 0, sf::Window *window = 0);
    ~RenderThread();

    void start_render();
    void stop_render();

protected:
    void run();

private:
    QMutex mutex;
    QWaitCondition condition;


    bool render;
    bool abort;

    sf::Window *win;


    //initialize rendering functions that are not part of glcore...
    void init_glext();

    /*
      Huge part with glext function pointers...

      Currently everything needed for shaders n stuff...

    */

    PFNGLCREATESHADERPROC glCreateShader;
    PFNGLSHADERSOURCEPROC glShaderSource;
    PFNGLCOMPILESHADERPROC glCompileShader;
    PFNGLGETSHADERIVPROC glGetShaderiv;
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;

    PFNGLCREATEPROGRAMPROC glCreateProgram;
    PFNGLATTACHSHADERPROC glAttachShader;
    PFNGLLINKPROGRAMPROC glLinkProgram;
    PFNGLGETPROGRAMIVPROC glGetProgramiv;
    PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
    PFNGLUSEPROGRAMPROC glUseProgram;

    PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
    PFNGLUNIFORM1IPROC glUniform1i;
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
    PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;


    
signals:
    
public slots:
    
};

#endif // RENDERTHREAD_H
