#include "test.h"


#include <QDebug>
#include <QFile>

#include <QMatrix4x4>
#include <QMatrix3x3>


Test::Test(){


    Model mdl;
    qDebug("ID : %lu",mdl.id());


    Material mtl;
    qDebug("ID : %lu",mtl.id());


    //Engine * e = new Engine(800,600,"EE0.01 OMEGA test",false);

    //atm no execution of code from here...

    exit(0);


    /*
    qDebug("\nQT started.");

    qDebug("\nTesting EE components:");

    qDebug("\nCamera...");
    ee::Camera cam();
    qDebug("ok.");
    */


/*
    sf::Window *win = new sf::Window(sf::VideoMode(600,400),"EE0.01 OMEGA");
    win->setFramerateLimit(60);
    win->setActive();


    qDebug("\nOpenGL...");
    qDebug("Vendor: %s", glGetString (GL_VENDOR));
    qDebug("Renderer: %s", glGetString (GL_RENDERER));
    qDebug("Version: %s", glGetString (GL_VERSION));
    qDebug("ok.");

    qDebug("\nOpenGLSL...");
    qDebug("GLSL: %s", glGetString (GL_SHADING_LANGUAGE_VERSION));
    qDebug("ok.");



    PFNGLCREATESHADERPROC glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    PFNGLSHADERSOURCEPROC glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
    PFNGLCOMPILESHADERPROC glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
    PFNGLGETSHADERIVPROC glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");


    qDebug("    #Vertex shader:");
    GLuint m_standart_v_shader = glCreateShader(GL_VERTEX_SHADER);
    if(!m_standart_v_shader){
        qDebug("vertex shader error in creation...");
        exit(1);
    }

    GLint compiled;

    qDebug("C:/Users/AJ/Desktop/Code/QTProjects/EE/ElementalEngine/Engine/Graphics/Shaders/standart_vertex_shader.vsh");
    QFile vfile("C:/Users/AJ/Desktop/Code/QTProjects/EE/ElementalEngine/Engine/Graphics/Shaders/standart_vertex_shader.vsh");
    if (!vfile.open(QFile::ReadOnly)) {
        qWarning() << "Shader: Unable to open file" << "C:/Users/AJ/Desktop/Code/QTProjects/EE/ElementalEngine/Engine/Graphics/Shaders/standart_vertex_shader.vsh";
        exit(2);
    }

    QByteArray vcontents = vfile.readAll();
    const char * vshader = vcontents.constData();
    glShaderSource(m_standart_v_shader,1,&vshader,NULL);

    glCompileShader(m_standart_v_shader);

    glGetShaderiv(m_standart_v_shader, GL_COMPILE_STATUS, &compiled);

    qDebug("    " + QString::number(compiled).toUtf8());
    if (compiled){
        qDebug("    vshader compiled");
    }
    else{
        qDebug("    vshader compile failed!!!");
        char messages[256];
        glGetShaderInfoLog(m_standart_v_shader, sizeof(messages), 0, &messages[0]);
        qDebug(messages);
        exit(3);
    }
    */










/*

    glViewport(0, 0, win->get_window()->getSize().x, win->get_window()->getSize().y);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //GLfloat ratio = static_cast<float>(win->get_window()->getSize().x) / win->get_window()->getSize().y;
    //glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Disable lighting and texturing
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
    GLfloat cube[] =
    {
        // positions    // colors (r, g, b, a)
        -1, -1, 0,  1, 0, 0, 1,
        -1,  1, 0,  0, 1, 0, 1,
         1,  1, 0,  0, 0, 1, 1,
         1,  1, 0,  0, 0, 1, 1,
         1, -1, 0,  0, 1, 0, 1,
        -1, -1, 0,  1, 0, 0, 1,
    };

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);


    // Create a clock for measuring the time elapsed


    while(win->is_open()){
        // Process events
        sf::Event event;
        while (win->poll_event(event))
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
        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // Apply some transformations to rotate the cube
        //glMatrixMode(GL_MODELVIEW);
        //glLoadIdentity();
        //glTranslatef(0.f, 0.f, -5.f);


        // Draw the cube
        initializer->glDrawArrays(GL_TRIANGLES, 0, 6);
        //glDrawArrays(GL_TRIANGLES, 0, 6);

        //render here...
       // win->get_window()->draw(text);

        // Finally, display the rendered frame on screen
        win->display();
    }
    exit(0);
    */















    /*
    // Request a 32-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 32;
    contextSettings.antialiasingLevel = 16;
    contextSettings.stencilBits = 8;

    // Create the main window
    sf::Window window(sf::VideoMode(640, 480), "EE v0.01 Omega", sf::Style::Default, contextSettings);
    window.setFramerateLimit(60);

    // Make it the active window for OpenGL calls
    window.setActive();


    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Disable lighting and texturing
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, window.getSize().x, window.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    // Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
    GLfloat cube[] =
    {
        // positions    // colors (r, g, b, a)
        -50, -50, -50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50,  50,  50,  0, 0, 1, 1,

         50, -50, -50,  0, 1, 0, 1,
         50,  50, -50,  0, 1, 0, 1,
         50, -50,  50,  0, 1, 0, 1,
         50, -50,  50,  0, 1, 0, 1,
         50,  50, -50,  0, 1, 0, 1,
         50,  50,  50,  0, 1, 0, 1,

        -50, -50, -50,  1, 0, 0, 1,
         50, -50, -50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
         50, -50, -50,  1, 0, 0, 1,
         50, -50,  50,  1, 0, 0, 1,

        -50,  50, -50,  0, 1, 1, 1,
         50,  50, -50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
         50,  50, -50,  0, 1, 1, 1,
         50,  50,  50,  0, 1, 1, 1,

        -50, -50, -50,  1, 0, 1, 1,
         50, -50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
         50, -50, -50,  1, 0, 1, 1,
         50,  50, -50,  1, 0, 1, 1,

        -50, -50,  50,  1, 1, 0, 1,
         50, -50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
         50, -50,  50,  1, 1, 0, 1,
         50,  50,  50,  1, 1, 0, 1,
    };

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // Create a clock for measuring the time elapsed
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            // Resize event: adjust the viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Finally, display the rendered frame on screen
        window.display();
    }
    exit(0);
    */
}
