#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "Graphics.h"


class GLwindow
{

public:
    GLwindow(unsigned int width, unsigned int height,char* title);
    ~GLwindow();

    void init_window();
    void set_depthBits(unsigned int depthBits);
    void set_antialiasingLevel(unsigned int antialiasingLevel);
    void set_stencilBits(unsigned int stencilBits);

    sf::RenderWindow * get_window();

    bool is_open();
    bool set_active(bool active = true);
    void set_framerate_limit(unsigned int limit);

    bool poll_event(sf::Event &event);
    void close();

    void display();

private:
    sf::RenderWindow * win;

    unsigned int width;
    unsigned int height;
    char* title;

    unsigned int depthBits;
    unsigned int antialiasingLevel;
    unsigned int stencilBits;


};

#endif // GLWINDOW_H
