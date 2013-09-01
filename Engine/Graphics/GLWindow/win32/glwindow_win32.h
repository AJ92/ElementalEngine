#ifndef GLWINDOW_WIN32_H
#define GLWINDOW_WIN32_H
#define EE_USE_GLES_EMULATION

#include "GLWindow/glwindow.h"
#include <QObject>
#include <QtGui/QWidget>
#include <QTime>
#include <QResizeEvent>


#ifdef Q_OS_WIN
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <windows.h>
#endif


class GLwindow_win32 : public GLwindow
{
    Q_OBJECT

public:
    explicit GLwindow_win32(QWidget *parent = 0);
    ~GLwindow_win32();

    void initWin();


public slots:
    void swapbuffer();

protected:
    void resizeEvent(QResizeEvent *event);

private:



};

#endif // GLWINDOW_WIN32_H
