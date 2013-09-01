#ifndef GLEXTINITER_H
#define GLEXTINITER_H

#include "Engine/Graphics/Graphics.h"
#include <stdio.h>


class GLextiniter
{
public:
    GLextiniter();

    //shader function definitions...
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


    //Texture
    PFNGLACTIVETEXTUREPROC glActiveTexture;
    PFNGLBINDTEXTUREPROC glBindTexture;
    PFNGLTEXPARAMETERIPROC glTexParameteri;

    //Buffer
    PFNGLBINDBUFFERPROC glBindBuffer;


    //other stuff
    PFNGLDRAWARRAYSPROC glDrawArrays;


    PFNGLGETSTRINGPROC glGetString;
};

#endif // GLEXTINITER_H
