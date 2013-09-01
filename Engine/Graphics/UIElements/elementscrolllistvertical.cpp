#include "elementscrolllistvertical.h"


ElementScrollListVertical::ElementScrollListVertical():
    Element(),
    screen_size_x(1),
    screen_size_y(1),
    space_to_top(5),
    space_to_left(5),
    space_to_bottom(5),
    space_to_right(5),
    space_between_elements(15),
    content_width(0),
    content_height(0),
    content_rect_width(0),
    content_rect_height(0),
    init_x_pos(0),
    init_y_pos(0),
    offset_x(0),
    offset_y(0),
    pressed(false),
    scroll(false)
{

    //Timer for scrolling
    timer = new QTimer();
    timer->setInterval(15);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(scroll_back()));
    timer->start();

}


void ElementScrollListVertical::add_element(Element* e){
    element_list.append(e);
    e->update_screen_size(screen_size_x, screen_size_y);
    arrange_my_elements();
}

bool ElementScrollListVertical::remove_element(Element* e){
    if(element_list.indexOf(e) > -1){
        element_list.removeAt(element_list.indexOf(e));
        return true;
    }
    return false;
}

//override:
void ElementScrollListVertical::set_pos_space(float x_pos, float y_pos, float z_pos){
    Element::set_pos_space(x_pos,y_pos,z_pos);
    //update_my_elements_pos_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_x_pos_space(float x_pos){
    Element::set_x_pos_space(x_pos);
    //update_my_elements_pos_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_y_pos_space(float y_pos){
    Element::set_y_pos_space(y_pos);
    //update_my_elements_pos_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_z_pos_space(float z_pos){
    Element::set_z_pos_space(z_pos);
    //update_my_elements_pos_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_pos_px(int x_pos, int y_pos, int z_pos){
    Element::set_pos_px(x_pos, y_pos, z_pos);
    //update_my_elements_pos_px();
    arrange_my_elements();
}

void ElementScrollListVertical::set_x_pos_px(int x_pos){
    Element::set_x_pos_px(x_pos);
    //update_my_elements_pos_px();
    arrange_my_elements();
}

void ElementScrollListVertical::set_y_pos_px(int y_pos){
    Element::set_y_pos_px(y_pos);
    //update_my_elements_pos_px();
    arrange_my_elements();
}

void ElementScrollListVertical::set_z_pos_px(int z_pos){
    Element::set_z_pos_px(z_pos);
    //update_my_elements_pos_px();
    arrange_my_elements();
}

void ElementScrollListVertical::set_scale_space(float x_scale, float y_scale, float z_scale){
    Element::set_scale_space(x_scale,y_scale,z_scale);
    //update_size_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_x_scale_space(float x_scale){
    Element::set_x_scale_space(x_scale);
    //update_size_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_y_scale_space(float y_scale){
    Element::set_y_scale_space(y_scale);
    //update_size_space();
    arrange_my_elements();
}

void ElementScrollListVertical::set_z_scale_space(float z_scale){
    Element::set_z_scale_space(z_scale);
    //update_size_space();
    arrange_my_elements();
}


void ElementScrollListVertical::set_content_rect_height(int height){
    this->content_rect_height = height;
}


void ElementScrollListVertical::update_my_elements_pos_space(){
    Element::set_pos_px(x_pos_space()*screen_size_x, y_pos_space()*screen_size_y, z_pos_space()*1000);

    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->set_pos_px(x_pos_space()*screen_size_x, y_pos_space()*screen_size_y, z_pos_space()*1000);
        //qDebug("pos update space:");
        //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
        //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
    }
    //arrange_my_elements();
}

void ElementScrollListVertical::update_my_elements_pos_px(){

    Element::set_pos_space((float)x_pos_px()/(float)screen_size_x, (float)y_pos_px()/(float)screen_size_y, (float)z_pos_px()/1000.0);
    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->set_pos_space((float)x_pos_px()/(float)screen_size_x, (float)y_pos_px()/(float)screen_size_y, (float)z_pos_px()/1000.0);
        //qDebug("pos update px:");
        //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
        //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
    }
    //arrange_my_elements();
}


void ElementScrollListVertical::arrange_my_elements(){
    int total_width = 0;
    int total_height = 0;
    for(int i = 0; i < element_list.length(); i++){
        int px_height_offset = 0;
        total_height += element_list[i]->y_size_px() + space_between_elements;
        if(total_width < element_list[i]->x_size_px()){
            total_width = element_list[i]->x_size_px();
        }
        for(int j = 0; j < i; j++){
            px_height_offset += element_list[j]->y_size_px() + space_between_elements;
        }
        element_list[i]->set_x_pos_px(this->space_to_left + x_pos_px());
        element_list[i]->set_y_pos_px(this->space_to_top + y_pos_px()+ px_height_offset);
        element_list[i]->set_z_pos_space(z_pos_space());
    }
    total_width += space_to_left + space_to_right;

    total_height -= space_between_elements;
    total_height += space_to_top + space_to_bottom;

    Element::set_x_size_px(total_width);
    Element::set_y_size_px(total_height);
    content_width = total_width;
    content_height = total_height;

    content_rect_width =  content_width + space_to_left + space_to_right;
}





bool ElementScrollListVertical::touch(QMouseEvent* e){
    if(is_enabled()){
        //qDebug("ElementScrollListVertical touch checking...");

        if((Element::x_pos_px() <= e->x()) &&
           (Element::y_pos_px() <= e->y()) &&
           ((Element::x_pos_px() + Element::x_size_px()) >= e->x()) &&
           ((Element::y_pos_px() + Element::y_size_px()) >= e->y())){
            //touch recognized
            return true;
        }
    }
    return false;
}

int ElementScrollListVertical::abs(int x){
    return (x > 0) ? x : -x;
}

//Scrolling stuff here....



//SIGNALS:


//SLOTS:


void ElementScrollListVertical::scroll_back(){
    if(scroll){
        int scroll_factor = 8;



        if(0 < offset_x && offset_x < scroll_factor){
            set_x_pos_px(Element::x_pos_px() + offset_x);
            offset_x = 0;
        }
        else if(0 > offset_x && offset_x > -scroll_factor){
            set_x_pos_px(Element::x_pos_px() + offset_x);
            offset_x = 0;
        }

        if(0 < offset_y && offset_y < scroll_factor){
            set_y_pos_px(Element::y_pos_px() + offset_y);
            offset_y = 0;
        }
        else if(0 > offset_y && offset_y > -scroll_factor){
            set_y_pos_px(Element::y_pos_px() + offset_y);
            offset_y = 0;
        }


        scroll = false;
        if(abs(offset_y) >  abs(content_rect_height - content_height) || offset_y < 0){

            if(offset_x > 0){
                set_x_pos_px(Element::x_pos_px() + scroll_factor);
                offset_x -= scroll_factor;
                scroll = true;
            }
            if(offset_x < 0){
                set_x_pos_px(Element::x_pos_px() - scroll_factor);
                offset_x += scroll_factor;
                scroll = true;
            }
            if(offset_y > 0){
                set_y_pos_px(Element::y_pos_px() + scroll_factor);
                offset_y -= scroll_factor;
                scroll = true;
            }
            if(offset_y < 0){
                set_y_pos_px(Element::y_pos_px() - scroll_factor);
                offset_y += scroll_factor;
                scroll = true;
            }
        }
        if(!scroll){
            qDebug("Scrolling stopped!");
        }
    }
}

void ElementScrollListVertical::update_screen_size(int size_x, int size_y){
    screen_size_x = size_x;
    screen_size_y = size_y;
    //update_my_elements_pos_px();
    //update_my_elements_size_px();
    qDebug("scaling ElementScrollListVertical...");

    resize_elements(size_x, size_y);
}

void ElementScrollListVertical::check_mouse_move(QMouseEvent* e){
    //qDebug("ElementScrollListVertical mouse moved (ID:%i)",get_id());

    //adjusting list pos...

    mouse_x = e->x();
    mouse_y = e->y();

    if(pressed){

        //set_x_pos_px(Element::x_pos_px() + (mouse_x - mouse_x_old));
        //offset_x -= (mouse_x - mouse_x_old);


        set_y_pos_px(Element::y_pos_px() + (mouse_y - mouse_y_old));
        offset_y -= (mouse_y - mouse_y_old);

        //qDebug("offsetadd:  x: %i   y: %i", mouse_x - mouse_x_old, mouse_y - mouse_y_old);

    }

    mouse_x_old = mouse_x;
    mouse_y_old = mouse_y;

    //qDebug("old pos:  x: %i   y: %i", Element::x_pos_px() + offset_x, Element::y_pos_px() + offset_y);


    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->check_mouse_move(e);
    }
}

void ElementScrollListVertical::check_mouse_press(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementScrollListVertical mouse press (ID:%i)",get_id());

        mouse_x = e->x();
        mouse_y = e->y();
        mouse_press_x = e->x();
        mouse_press_y = e->y();
        mouse_x_old = mouse_press_x;
        mouse_y_old = mouse_press_y;

        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_press(e);
        }

        pressed = true;
    }
}

void ElementScrollListVertical::check_mouse_release(QMouseEvent* e){
    if(pressed){
        qDebug("ElementScrollListVertical mouse release (ID:%i)",get_id());
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_release(e);
        }
        scroll = true;
        pressed = false;
    }
}

void ElementScrollListVertical::resize_elements(int new_screen_size_x, int new_screen_size_y){
    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->update_screen_size( new_screen_size_x, new_screen_size_y);
    }
}
