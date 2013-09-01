#include "glwindow.h"

GLwindow::GLwindow(unsigned int width, unsigned int height,char* title):
    width(width),
    height(height),
    title(title),
    depthBits(32),
    antialiasingLevel(0),
    stencilBits(8)
{

}

GLwindow::~GLwindow()
{
    
}

void GLwindow::init_window(){
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = this->depthBits;
    contextSettings.antialiasingLevel = this->antialiasingLevel;
    contextSettings.stencilBits = this->stencilBits;
    win = new sf::RenderWindow(sf::VideoMode(width,height),title,sf::Style::Default,contextSettings);
}

void GLwindow::set_depthBits(unsigned int depthBits){
    this->depthBits = depthBits;
}

void GLwindow::set_antialiasingLevel(unsigned int antialiasingLevel){
    this->antialiasingLevel = antialiasingLevel;
}

void GLwindow::set_stencilBits(unsigned int stencilBits){
    this->stencilBits = stencilBits;
}

sf::RenderWindow * GLwindow::get_window(){
    return win;
}

bool GLwindow::is_open(){
    return win->isOpen();
}

bool GLwindow::set_active(bool active){
    return win->setActive(active);
}

void GLwindow::set_framerate_limit(unsigned int limit){
    win->setFramerateLimit(limit);
}

bool GLwindow::poll_event(sf::Event &event){
    return win->pollEvent(event);
}

void GLwindow::close(){
    win->close();
}

void GLwindow::display(){
    win->display();
}


