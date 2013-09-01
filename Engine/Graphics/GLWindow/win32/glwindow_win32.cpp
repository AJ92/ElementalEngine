#include "GLwindow_win32.h"



GLwindow_win32::GLwindow_win32(QWidget *parent)
{
    qDebug("\nGLwindow_win32 creation...");
    //MessageBox(WindowFromDC(0), L"Starting window", L"Info", MB_ICONERROR | MB_OK);
    initWin();
}

GLwindow_win32::~GLwindow_win32()
{

}


void GLwindow_win32::resizeEvent(QResizeEvent *event){

}



void GLwindow_win32::initWin(){
    qDebug("\nGLwindow_win32::initWin()");


    init_success = 1;
}



void GLwindow_win32::swapbuffer(){


}

