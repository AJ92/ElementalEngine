#ifndef GLWINDOW_SYMBIAN_H
#define GLWINDOW_SYMBIAN_H

#include <QObject>
#include <QtGui/QWidget>
#include <QTime>
#include <QResizeEvent>

/**
#ifdef Q_OS_WIN
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#endif
**/


#include "Engine/Graphics/win_emu/OGLES2/Include/EGL/egl.h"
#include "Engine/Graphics/win_emu/OGLES2/Include/GLES2/gl2.h"


#ifdef Q_OS_SYMBIAN
class CRepository;
#endif

class GLwindow_symbian : public QWidget
{
    Q_OBJECT

public:
    GLwindow_symbian(QWidget *parent = 0);
    ~GLwindow_symbian();

    void initEGL();
    bool initialized();

    float get_fps();
    float get_timestep();
    int get_renderstep();
    int get_window_width();
    int get_window_height();
    float get_window_aspect();

    void set_clear_color(float r, float g, float b, float d);

    //TOUCH FUNCS:
        void mouseReleaseEvent(QMouseEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);

    signals:
        void mouseReleased(QMouseEvent *event);
        void mousePressed(QMouseEvent *event);
        void mouseMoved(QMouseEvent *event);

        void resized(int size_x, int size_y);


public slots:
    void swapbuffer();

protected:
    // EGL variables and functions
    EGLDisplay  eglDisplay;
    EGLConfig   eglConfig;
    EGLSurface  eglSurface;
    EGLContext  eglContext;


    float clear_color_r;
    float clear_color_g;
    float clear_color_b;
    float clear_color_d;

    bool testEGLError(const char* pszLocation);
    void cleanupAndExit(EGLDisplay eglDisplay);

    //window stuff
    virtual void resizeEvent(QResizeEvent *event);
    int window_w;
    int window_h;
    float window_aspect;
    //debug on(1) / off(0)
    int     gldebug;
    //framerate timestep vars and helper vars
    QTime   time;
    int     framecount;
    float   fps;
    float   timestep;
    //important value to prevent overhead and asyncroniouse cpu/gpu coordination and stack filling
    int     renderstep;
    //1 if glwindow is initialized 0 if not and -1 if failed ...
    int     init;

};

#endif // GLWINDOW_SYMBIAN_H
