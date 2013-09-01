#include "glextiniter.h"
#include <QDebug>

GLextiniter::GLextiniter()
{
    qDebug("Loading openGL function pointers...");
    glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    qDebug("    -glCreateShader function pointer loaded");

    glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
    qDebug("    -glShaderSource function pointer loaded");

    glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
    qDebug("    -glCompileShader function pointer loaded");

    glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
    qDebug("    -glGetShaderiv function pointer loaded");

    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
    qDebug("    -glGetShaderInfoLog function pointer loaded");


    glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
    qDebug("    -glCreateProgram function pointer loaded");

    glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
    qDebug("    -glAttachShader function pointer loaded");

    glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
    qDebug("    -glLinkProgram function pointer loaded");

    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
    qDebug("    -glGetProgramiv function pointer loaded");

    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
    qDebug("    -glGetProgramInfoLog function pointer loaded");

    glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
    qDebug("    -glUseProgram function pointer loaded");




    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
    qDebug("    -glBindAttribLocation function pointer loaded");

    glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
    qDebug("    -glUniform1i function pointer loaded");

    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
    qDebug("    -glEnableVertexAttribArray function pointer loaded");

    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
    qDebug("    -glGetUniformLocation function pointer loaded");

    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
    qDebug("    -glVertexAttribPointer function pointer loaded");


    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
    qDebug("    -glUniformMatrix4fv function pointer loaded");

    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
    qDebug("    -glUniformMatrix3fv function pointer loaded");



    glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
    qDebug("    -glActiveTexture function pointer loaded");

    glBindTexture = (PFNGLBINDTEXTUREPROC)wglGetProcAddress("glBindTexture");
    qDebug("    -glBindTexture function pointer loaded");

    glTexParameteri = (PFNGLTEXPARAMETERIPROC)wglGetProcAddress("glTexParameteri");
    qDebug("    -glTexParameteri function pointer loaded");



    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
    qDebug("    -glBindBuffer function pointer loaded");



    glDrawArrays = (PFNGLDRAWARRAYSPROC)wglGetProcAddress("glDrawArrays");
    qDebug("    -glDrawArrays function pointer loaded");


    glGetString = (PFNGLGETSTRINGPROC)wglGetProcAddress("glGetString");
    qDebug("    -glGetString function pointer loaded");

}
