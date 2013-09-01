#include "elementgroup.h"

ElementGroup::ElementGroup()
{
}

//override:
void ElementGroup::set_pos_space(float x_pos, float y_pos, float z_pos){
    Element::set_pos_space(x_pos,y_pos,z_pos);
    update_pos_space();
}

void ElementGroup::set_x_pos_space(float x_pos){
    Element::set_x_pos_space(x_pos);
    update_pos_space();
}

void ElementGroup::set_y_pos_space(float y_pos){
    Element::set_y_pos_space(y_pos);
    update_pos_space();
}

void ElementGroup::set_z_pos_space(float z_pos){
    Element::set_z_pos_space(z_pos);
    update_pos_space();
}

void ElementGroup::set_pos_px(int x_pos, int y_pos, int z_pos){
    Element::set_pos_px(x_pos, y_pos, z_pos);
    update_pos_px();
}

void ElementGroup::set_x_pos_px(int x_pos){
    Element::set_x_pos_px(x_pos);
    update_pos_px();
}

void ElementGroup::set_y_pos_px(int y_pos){
    Element::set_y_pos_px(y_pos);
    update_pos_px();
}

void ElementGroup::set_z_pos_px(int z_pos){
    Element::set_z_pos_px(z_pos);
    update_pos_px();
}

void ElementGroup::set_scale_space(float x_scale, float y_scale, float z_scale){
    Element::set_scale_space(x_scale,y_scale,z_scale);
    update_size_space();
}

void ElementGroup::set_x_scale_space(float x_scale){
    Element::set_x_scale_space(x_scale);
    update_size_space();
}

void ElementGroup::set_y_scale_space(float y_scale){
    Element::set_y_scale_space(y_scale);
    update_size_space();
}

void ElementGroup::set_z_scale_space(float z_scale){
    Element::set_z_scale_space(z_scale);
    update_size_space();
}




//new:

void ElementGroup::set_size_px(int x_size, int y_size){
    Element::set_x_size_px(x_size);
    Element::set_y_size_px(y_size);
    update_size_px();
}

void ElementGroup::set_x_size_px(int x_size){
    Element::set_x_size_px(x_size);
    update_size_px();
}

void ElementGroup::set_y_size_px(int y_size){
    Element::set_x_size_px(y_size);
    update_size_px();
}





void ElementGroup::add_element(Element* e){
    element_list.append(e);
    e->update_screen_size(screen_size_x, screen_size_y);
    arrange_my_elements();
}

bool ElementGroup::remove_element(Element* e){
    if(element_list.indexOf(e) > -1){
        element_list.removeAt(element_list.indexOf(e));
        return true;
    }
    return false;
}


void ElementGroup::update_my_elements_pos_space(){
    Element::set_pos_px(x_pos_space()*screen_size_x, y_pos_space()*screen_size_y, z_pos_space()*1000);

    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->set_pos_px(x_pos_space()*screen_size_x, y_pos_space()*screen_size_y, z_pos_space()*1000);
        //qDebug("pos update space:");
        //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
        //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
    }
    //arrange_my_elements();
}

void ElementGroup::update_my_elements_pos_px(){

    Element::set_pos_space((float)x_pos_px()/(float)screen_size_x, (float)y_pos_px()/(float)screen_size_y, (float)z_pos_px()/1000.0);
    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->set_pos_space((float)x_pos_px()/(float)screen_size_x, (float)y_pos_px()/(float)screen_size_y, (float)z_pos_px()/1000.0);
        //qDebug("pos update px:");
        //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
        //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
    }
    //arrange_my_elements();
}


void ElementGroup::arrange_my_elements(){
    for(int i = 0; i < element_list.length(); i++){
        //element_list[i]->set_x_pos_px(this->space_to_left + x_pos_px()+ px_width_offset );
        //element_list[i]->set_y_pos_px(this->space_to_top + y_pos_px());
        //element_list[i]->set_z_pos_space(z_pos_space());
    }
}

bool ElementGroup::touch(QMouseEvent* e){
    if(is_enabled()){
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


void ElementGroup::update_screen_size(int size_x, int size_y){
    screen_size_x = size_x;
    screen_size_y = size_y;
    //update_my_elements_pos_px();
    //update_my_elements_size_px();
    qDebug("scaling scrolllisthorizontal...");

    resize_elements(size_x, size_y);
}

void ElementGroup::check_mouse_move(QMouseEvent* e){
    //qDebug("ElementScrollListHorizontal mouse moved (ID:%i)",get_id());

    //adjusting list pos...

    mouse_x = e->x();
    mouse_y = e->y();

    if(pressed){

        set_x_pos_px(Element::x_pos_px() + (mouse_x - mouse_x_old));
        offset_x -= (mouse_x - mouse_x_old);


        //set_y_pos_px(Element::y_pos_px() + (mouse_y - mouse_y_old));
        //offset_y -= (mouse_y - mouse_y_old);

        //qDebug("offsetadd:  x: %i   y: %i", mouse_x - mouse_x_old, mouse_y - mouse_y_old);

    }

    mouse_x_old = mouse_x;
    mouse_y_old = mouse_y;

    //qDebug("old pos:  x: %i   y: %i", Element::x_pos_px() + offset_x, Element::y_pos_px() + offset_y);


    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->check_mouse_move(e);
    }
}

void ElementGroup::check_mouse_press(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementScrollListHorizontal mouse press (ID:%i)",get_id());

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

void ElementGroup::check_mouse_release(QMouseEvent* e){
    if(pressed){
        qDebug("ElementScrollListHorizontal mouse release (ID:%i)",get_id());
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_mouse_release(e);
        }
        scroll = true;
        pressed = false;
    }
}

void ElementGroup::resize_elements(int new_screen_size_x, int new_screen_size_y){
    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->update_screen_size( new_screen_size_x, new_screen_size_y);
    }
}
