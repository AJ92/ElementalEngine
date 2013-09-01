/*
  AJ's 4th attemp of a perfect 3D engine...
  Elemental Engine v0.01 OMEGA

  ChangeLog:

  08.08.2013:
  -Born.


*/
#ifndef ENGINE_H
#define ENGINE_H

#include <QString>
#include "Graphics/Graphics.h"


class Engine
{
public:
    //Default constructor, creates some default stuff ...
    Engine();
    Engine(unsigned int window_width, unsigned int window_height, QString window_title, bool fullscreen);


    //GETTER AND SETTER
    void set_world(World *world);
    World* get_world();

    void set_camera(Camera *camera);
    Camera* get_camera();



private:
    //window stuff
    unsigned int window_width;
    unsigned int window_height;
    QString window_title;
    bool fullscreen;

    sf::Window *win;



    //world stuff
    World *world;


    //Camera stuff
    Camera *camera;


    //main event loop
    void event_loop();



};

#endif // ENGINE_H
