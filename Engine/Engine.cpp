#include "engine.h"


Engine::Engine():
    window_width(600),
    window_height(400),
    window_title("EE0.01 OMEGA"),
    fullscreen(false)
{
    win = new sf::Window(sf::VideoMode(window_width,window_height),window_title.toStdString());
    win->setFramerateLimit(60);
    win->setActive();

    event_loop();
}

Engine::Engine(unsigned int window_width, unsigned int window_height, QString window_title, bool fullscreen):
    window_width(window_width),
    window_height(window_height),
    window_title(window_title),
    fullscreen(fullscreen)
{
    if(fullscreen)
        win = new sf::Window(sf::VideoMode(window_width,window_height),window_title.toStdString(),sf::Style::Fullscreen);
    else{
        win = new sf::Window(sf::VideoMode(window_width,window_height),window_title.toStdString(),sf::Style::Default);
    }
    win->setFramerateLimit(60);
    win->setActive();
    event_loop();
}

void Engine::set_world(World *world){
    this->world = world;
}

World* Engine::get_world(){
    return this->world;
}

void Engine::set_camera(Camera *camera){
    this->camera = camera;
}

Camera* Engine::get_camera(){
    return this->camera;
}


void Engine::event_loop(){

    win->setActive(false);


    //launch threads here...

    //thread for rendering in openGL
    RenderThread * rt = new RenderThread(0,win);
    rt->start_render();




    //thread for calculating physics
    //soon here...

    //thread for networking
    //soon here...


    while(win->isOpen()){
        // Process events
        sf::Event event;
        while (win->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                win->close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                win->close();

            // Resize event: adjust the viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
                //ratio = static_cast<float>(win->get_window()->getSize().x) / win->get_window()->getSize().y;
                //glFrustum(-1.f, 1.f, -1.f, 1.f, 1.f, 500.f);

        }

    }
    rt->stop_render();

    //might need to wait here till the render loop closed it self... not sure...

    qDebug("Event loop stopped. (Window closed)");
    exit(0);
}
