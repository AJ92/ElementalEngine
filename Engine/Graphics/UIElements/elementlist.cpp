#include "elementlist.h"

ElementList::ElementList():
    Element(),
    offset_top(0.0f),
    offset_bottom(0.0f),
    offset_left(0.0f),
    offset_right(0.0f),
    element_spacing(0.0f),
    scrolling_factor(0.0f),
    anti_scrolling_factor(0.0f),
    max_scroll_offset(0.0f),
    is_scrolling(false),
    x_axis_alignment(false),
    y_axis_alignment(false),
    z_axis_alignment(false)
{

}

/*
float ElementList::get_offset_top(){
    return this->offset_top;
}

float ElementList::get_offset_bottom(){
    return this->offset_bottom;
}

float ElementList::get_offset_left(){
    return this->offset_left;
}

float ElementList::get_offset_right(){
    return this->offset_right;
}


void ElementList::set_offset_top(float value){
    this->offset_top = value;
}

void ElementList::set_offset_bottom(float value){
    this->offset_bottom = value;
}

void ElementList::set_offset_left(float value){
    this->offset_left = value;
}

void ElementList::set_offset_right(float value){
    this->offset_right = value;
}



void ElementList::set_element_spacing(float value){
    this->element_spacing = value;
}
void ElementList::set_scrolling_factor(float value){
    this->scrolling_factor = value;
}
void ElementList::set_anti_scrolling_factor(float value){
    this->anti_scrolling_factor = value;
}
void ElementList::set_max_scroll_offset(float value){
    this->max_scroll_offset = value;
}

void ElementList::set_scrolling(bool scrolling){
    this->is_scrolling = scrolling;
}

void ElementList::set_x_axis_alignment(bool align){
    this->x_axis_alignment = align;
}

void ElementList::set_y_axis_alignment(bool align){
    this->y_axis_alignment = align;
}

void ElementList::set_z_axis_alignment(bool align){
    this->z_axis_alignment = align;
}




void ElementList::add_element(Element* e){
    element_list.append(e);
}

bool ElementList::remove_element(Element* e){
    if(element_list.indexOf(e) > -1){
        element_list.removeAt(element_list.indexOf(e));
        return true;
    }
    return false;
}


void ElementList::adjust_element_pos(Element* e, float x_diff, float y_diff, float z_diff){
    //qDebug(" old element pos:  %f  %f   %f",e->x_pos(),e->y_pos(),e->z_pos());
    e->set_pos(e->x_pos()+x_diff, e->y_pos()+y_diff, e->z_pos()+z_diff);
    //qDebug(" new element pos:  %f  %f   %f",e->x_pos(),e->y_pos(),e->z_pos());
}


void ElementList::set_pos(float x_pos, float y_pos, float z_pos){
    //adjust all elements added to this object...
    for(int i = 0; i < element_list.length(); i++){
        adjust_element_pos(element_list[i], x_pos - this->x_pos(),
                                            y_pos - this->y_pos(),
                                            z_pos - this->z_pos());
    }
    this->set_x_pos(x_pos);
    this->set_y_pos(y_pos);
    this->set_z_pos(z_pos);
}


//SLOTS:
void ElementList::adjust_list_pos(){
    //scroll back...
    if(!this->is_scrolling){
        if(this->scrolling_factor > 0){
            this->scrolling_factor -= this->anti_scrolling_factor;
        }
        else if(this->scrolling_factor < 0){
            this->scrolling_factor += this->anti_scrolling_factor;
        }
    }

    //check if scrolling is in bound
    if(this->scrolling_factor > 0){
        if(this->scrolling_factor > ((element_list.length()*this->element_spacing) -    //elements length
                                          (this->offset_top - this->offset_bottom) + this->max_scroll_offset))         //list height
        {
            this->scrolling_factor = this->max_scroll_offset;
        }
    }
    else if(this->scrolling_factor < 0){
        if(this->scrolling_factor < -this->max_scroll_offset)
        {
            this->scrolling_factor = -this->max_scroll_offset;
        }
    }

    if((this->scrolling_factor < this->anti_scrolling_factor) && (this->scrolling_factor > -this->anti_scrolling_factor)){
        this->scrolling_factor = 0.0;
    }


    //set right position...
    for(int i = 0; i < element_list.length(); i++){
        float new_pos = this->offset_top+(i*this->element_spacing)+this->scrolling_factor;



        if(this->x_axis_alignment){
            element_list[i]->set_pos(this->x_pos() - new_pos, element_list[i]->y_pos(), element_list[i]->z_pos());
        }
        if(this->y_axis_alignment){
            element_list[i]->set_pos(element_list[i]->x_pos(), this->y_pos() - new_pos, element_list[i]->z_pos());
        }
        if(this->z_axis_alignment){
            element_list[i]->set_pos(element_list[i]->x_pos(), element_list[i]->y_pos(), this->z_pos() - new_pos);
        }
    }
}


//SLOTS:
void ElementList::check_touch(QMouseEvent* e){
    if(is_enabled()){
        qDebug("element list touch checking...");
        for(int i = 0; i < element_list.length(); i++){
            element_list[i]->check_touch(e);
        }
    }
}

void ElementList::resize_to_screen(float new_screen_size_x, float new_screen_size_y){
    for(int i = 0; i < element_list.length(); i++){
        element_list[i]->resize_to_screen((float) new_screen_size_x, (float) new_screen_size_y);
    }
}
*/
