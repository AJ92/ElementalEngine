#-------------------------------------------------
#
# Project created by QtCreator 2013-07-27T13:50:59
#
#-------------------------------------------------

QT       += core gui

TARGET = ElementalEngine
TEMPLATE = app

INCLUDEPATH += Engine
INCLUDEPATH += Engine/Graphics

#freeGLUT
#INCLUDEPATH += C:/freeglut/include
#DEPENDPATH += C:/freeglut/include

#SFML
INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

INCLUDEPATH += Engine/Graphics/openGL

SOURCES += main.cpp\
        mainwindow.cpp \
    Engine/Graphics/Camera/camera.cpp \
    Custom/test.cpp \
    Engine/Engine.cpp \
    Engine/Graphics/World/world.cpp \
    Engine/Graphics/Renderer/renderthread.cpp \
    Engine/Math/Matrix/matrix4x4.cpp \
    Engine/Math/Matrix/matrix3x3.cpp \
    Engine/Math/Vector/vector3.cpp \
    Engine/Math/Vector/vector4.cpp \
    Engine/General/identifiable.cpp \
    Engine/Graphics/Model/model.cpp \
    Engine/Graphics/Model/Parser/loader.cpp \
    Engine/Graphics/Model/Parser/Format_obj/loader_obj.cpp \
    Engine/Graphics/Model/Components/material.cpp \
    Engine/Graphics/Model/Components/mesh.cpp


HEADERS  += mainwindow.h \
    Engine/Engine.h \
    Engine/Graphics/Graphics.h \
    Engine/Graphics/Camera/camera.h \
    Custom/test.h \
    Engine/Graphics/World/world.h \
    Engine/Graphics/Renderer/renderthread.h \
    Engine/Math/Matrix/matrix4x4.h \
    Engine/Math/Matrix/matrix3x3.h \
    Engine/Math/Math.h \
    Engine/Math/Vector/vector3.h \
    Engine/Math/Vector/vector4.h \
    Engine/General/identifiable.h \
    Engine/Graphics/Model/model.h \
    Engine/Graphics/Model/Parser/loader.h \
    Engine/Graphics/Model/Parser/Format_obj/loader_obj.h \
    Engine/Graphics/Model/Components/material.h \
    Engine/Graphics/Model/Components/mesh.h





FORMS    += mainwindow.ui

RESOURCES +=

windows: {
    message(Windows desktop build)

    #Emulation of gles 2.0...
    #INCLUDEPATH += Engine/Graphics/win_emu/OGLES2/Include
    #LIBS += -L$$_PRO_FILE_PWD_/Engine/Graphics/win_emu/OGLES2/WindowsX86/Lib



    LIBS += -lopengl32

    #freeGLUT
    #LIBS += -LC:/freeglut/lib
    #CONFIG(release, debug|release): LIBS += -lfreeglut
    #CONFIG(debug, debug|release): LIBS += -lfreeglut

    #SFML
    LIBS += -LC:/SFML/build/lib
    CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
    CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

    message($$INCLUDEPATH)
    message($$LIBS)
}
