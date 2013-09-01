#include "renderer.h"

Renderer::Renderer(QObject *parent, GLwindow *window) :
    QObject(parent)
{
    win = window;
    rt = new RenderThread(this, win);
    QTimer *timer = new QTimer(this);
    timer->singleShot(1000,this,SLOT(start_rendering()));
}

void Renderer::start_rendering(){
    win->swapbuffer();
    rt->start_render();
}

void Renderer::stop_rendering(){
    rt->stop_render();
}
