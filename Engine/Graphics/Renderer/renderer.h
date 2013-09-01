#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QTimer>
#include "renderthread.h"


class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = 0, GLwindow *window = 0);
    
private:
    GLwindow *win;
    RenderThread *rt;

signals:
    
public slots:
    void start_rendering();
    void stop_rendering();
    
};

#endif // RENDERER_H
