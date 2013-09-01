#include "elementwindow.h"

ElementWindow::ElementWindow(GLwindow* glwin):
    Element(),
    glwindow(glwin),
    scale_x(1.0),
    scale_y(1.0),
    scale_z(1.0)
{
    screen_size_x = glwindow->get_window_width();
    screen_size_y = glwindow->get_window_height();

    size_x = glwindow->get_window_width();
    size_y = glwindow->get_window_height();

    connect(glwindow, SIGNAL(resized(int,int)), this, SLOT(resize_elements(int,int)));
    connect(glwindow, SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(check_mouse_move(QMouseEvent*)));
    connect(glwindow, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(check_mouse_press(QMouseEvent*)));
    connect(glwindow, SIGNAL(mouseReleased(QMouseEvent*)), this, SLOT(check_mouse_release(QMouseEvent*)));

}


ElementWindow::ElementWindow(GLwindow* glwin, float x_size, float y_size):
    Element(),
    glwindow(glwin),
    scale_x(1.0),
    scale_y(1.0),
    scale_z(1.0)
{
    screen_size_x = glwindow->get_window_width();
    screen_size_y = glwindow->get_window_height();

    size_x = x_size;
    size_y = y_size;

    connect(glwindow, SIGNAL(resized(int,int)), this, SLOT(resize_elements(int,int)));
}


void ElementWindow::add_element(Element* e){
    element_list.append(e);
    e->update_screen_size(glwindow->get_window_width(), glwindow->get_window_height());
}

bool ElementWindow::remove_element(Element* e){
    if(element_list.indexOf(e) > -1){
        element_list.removeAt(element_list.indexOf(e));
        return true;
    }
    return false;
}

bool ElementWindow::touch(QMouseEvent* e){
    /*
    if(is_enabled()){
        //qDebug("ElementWindow touch checking...");

        if((Element::x_pos_px() <= e->x()) &&
                (Element::y_pos_px() <= e->y()) &&
                ((Element::x_pos_px() + Element::x_size_px()) >= e->x()) &&
                ((Element::y_pos_px() + Element::y_size_px()) >= e->y())){
            //touch recognized
            return true;
        }
    }
    return false;
    */
    if(is_enabled()){
        return true;
    }
    return false;
}



//SLOTS:

void ElementWindow::check_mouse_move(QMouseEvent* e){
    if(touch(e)){
        //qDebug("ElementWindow mouse moved (ID:%i)",get_id());
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_move(e);
        }
    }
}

void ElementWindow::check_mouse_press(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementWindow mouse press (ID:%i)",get_id());
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_press(e);
        }
    }
}

void ElementWindow::check_mouse_release(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementWindow mouse release(ID:%i)",get_id());
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_release(e);
        }
    }
}

void ElementWindow::resize_elements(int new_screen_size_x, int new_screen_size_y){
    for(int i = 0; i < element_list.length(); i++){
        qDebug("update_screen_size of element with ID:  %i", element_list[i]->get_id());
        element_list[i]->update_screen_size( new_screen_size_x, new_screen_size_y);
    }
}


