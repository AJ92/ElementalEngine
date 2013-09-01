#ifndef GRAPHICS_H
#define GRAPHICS_H

//glcorearb.h might not be needed because SFML already imports standard win header...
//might cause some conflicts here...
#include "openGL/glcorearb.h"
//glext.h for some more advanced gl functions... those need to be loaded manually !!!
#include "openGL/glext.h"
#include "openGL/wglext.h"

//SFML for window/context creation and event handling...
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


//EE headers...

//rest of ee
#include "Camera/camera.h"
#include "World/world.h"
#include "Renderer/renderthread.h"
#include "Model/model.h"



#endif // GRAPHICS_H
