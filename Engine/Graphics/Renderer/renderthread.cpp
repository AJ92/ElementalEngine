#include "renderthread.h"

RenderThread::RenderThread(QObject *parent, sf::Window *window) :
    QThread(parent),
    abort(false)
{
    qDebug("\nRenderThread creation...");
    win = window;
    init_glext();
}

RenderThread::~RenderThread(){
    //destructor: stop thread...
    mutex.lock();
    render = false;
    abort = true;
    condition.wakeOne();
    mutex.unlock();
    wait();
}


void RenderThread::start_render(){
    QMutexLocker locker(&mutex);

    render = true;

    if (!isRunning()) {
        //start(LowPriority);
        start(HighPriority);
    } else {
        condition.wakeOne();
    }
}

void RenderThread::stop_render(){
    QMutexLocker locker(&mutex);

    render = false;

}

void RenderThread::init_glext(){
    qDebug("    initializing glext function pointers...");

    qDebug("    SHADER:");
    glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    qDebug("        glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
    qDebug("        glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
    qDebug("        glCompileShader");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
    qDebug("        glGetShaderiv");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
    qDebug("        glGetShaderInfoLog");

    qDebug("    PROGRAM:");
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
    qDebug("        glCreateProgram");
    glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
    qDebug("        glAttachShader");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
    qDebug("        glLinkProgram");
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
    qDebug("        glGetProgramiv");
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
    qDebug("        glGetProgramInfoLog");
    glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
    qDebug("        glUseProgram");

    qDebug("    PROGRAM-PARAMS:");
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
    qDebug("        glBindAttribLocation");
    glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
    qDebug("        glUniform1i");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
    qDebug("        glEnableVertexAttribArray");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
    qDebug("        glGetUniformLocation");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
    qDebug("        glVertexAttribPointer");
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
    qDebug("        glUniformMatrix4fv");
    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
    qDebug("        glUniformMatrix3fv");

    qDebug("    initialization done.");

}

void RenderThread::run(){
    if(!win){
        return;
    }

    win->setActive(true);

    //initialize some GL stuff...
    glViewport(0, 0, win->getSize().x, win->getSize().y);
    glClearDepth(1.f);
    glClearColor(0.f, 1.f, 0.f, 1.f);

    int sec_reach = 0;

    while(win->isOpen()){
        if (abort){
            return;
        }

        mutex.lock();
        //copy thread sensitive data...

        mutex.unlock();





        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //render here



        //render end
        win->display();

        if(sec_reach >= 60){
            qDebug(".");
            sec_reach = 0;
        }
        sec_reach++;


        //Thread needs to sleep too :D
        mutex.lock();
        if(!render){
            qDebug("RenderThread stopped. (Event loop stopped)");
            condition.wait(&mutex);
        }
        mutex.unlock();
    }
    qDebug("RenderThread stopped. (Window closed unexpectedly...)");
}
