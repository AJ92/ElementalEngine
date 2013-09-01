#include "element.h"

long Element::next_identifier = 0;

Element::Element() :
    identifier(next_id()),
    my_x_position_space(0.0),
    my_y_position_space(0.0),
    my_z_position_space(0.0),

    my_x_position_px(0),
    my_y_position_px(0),
    my_z_position_px(0),

    my_x_scale_space(1.0),
    my_y_scale_space(1.0),
    my_z_scale_space(1.0),

    my_x_size_px(0),
    my_y_size_px(0),

    my_enabled(true),

    my_used_pos_space_last(true),
    my_used_scale_space_last(true)
{

}

long Element::next_id(){
    next_identifier++;
    return next_identifier;
}

long Element::get_id(){
    return identifier;
}

void Element::set_pos_space(float x_pos, float y_pos, float z_pos){
    my_x_position_space = x_pos;
    my_y_position_space = y_pos;
    my_z_position_space = z_pos;
    my_used_pos_space_last = true;
}

void Element::set_x_pos_space(float x_pos){
    my_x_position_space = x_pos;
    my_used_pos_space_last = true;
}

void Element::set_y_pos_space(float y_pos){
    my_y_position_space = y_pos;
    my_used_pos_space_last = true;
}

void Element::set_z_pos_space(float z_pos){
    my_z_position_space = z_pos;
    my_used_pos_space_last = true;
}

void Element::set_pos_px(int x_pos, int y_pos, int z_pos){
    my_x_position_px = x_pos;
    my_y_position_px = y_pos;
    my_z_position_px = z_pos;
    my_used_pos_space_last = false;
}

void Element::set_x_pos_px(int x_pos){
    my_x_position_px = x_pos;
    my_used_pos_space_last = false;
}

void Element::set_y_pos_px(int y_pos){
    my_y_position_px = y_pos;
    my_used_pos_space_last = false;
}

void Element::set_z_pos_px(int z_pos){
    my_z_position_px = z_pos;
    my_used_pos_space_last = false;
}

void Element::set_scale_space(float x_scale, float y_scale, float z_scale){
    my_x_scale_space = x_scale;
    my_y_scale_space = y_scale;
    my_z_scale_space = z_scale;
    my_used_scale_space_last = true;
}

void Element::set_x_scale_space(float x_scale){
    my_x_scale_space = x_scale;
    my_used_scale_space_last = true;
}

void Element::set_y_scale_space(float y_scale){
    my_y_scale_space = y_scale;
    my_used_scale_space_last = true;
}

void Element::set_z_scale_space(float z_scale){
    my_z_scale_space = z_scale;
    my_used_scale_space_last = true;
}

float Element::x_pos_space(){
    return my_x_position_space;
}

float Element::y_pos_space(){
    return my_y_position_space;
}

float Element::z_pos_space(){
    return my_z_position_space;
}

int Element::x_pos_px(){
    return my_x_position_px;
}

int Element::y_pos_px(){
    return my_y_position_px;
}

int Element::z_pos_px(){
    return my_z_position_px;
}

float Element::x_scale_space(){
    return my_x_scale_space;
}

float Element::y_scale_space(){
    return my_y_scale_space;
}

float Element::z_scale_space(){
    return my_z_scale_space;
}


//new:

void Element::set_size_px(int x_size, int y_size){
    my_x_size_px = x_size;
    my_y_size_px = y_size;
}

void Element::set_x_size_px(int x_size){
    my_x_size_px = x_size;
}

void Element::set_y_size_px(int y_size){
    my_y_size_px = y_size;
}

int Element::x_size_px(){
    return my_x_size_px;
}

int Element::y_size_px(){
    return my_y_size_px;
}



void Element::set_enabled(bool enable){
    my_enabled = enable;
}

bool Element::is_enabled(){
    return my_enabled;
}

bool Element::used_pos_space_last(){
    return my_used_pos_space_last;
}

bool Element::used_scale_space_last(){
    return my_used_scale_space_last;
}

void Element::check_mouse_move(QMouseEvent* e){
    //
}

void Element::check_mouse_press(QMouseEvent* e){
    //
}

void Element::check_mouse_release(QMouseEvent* e){
    //
}

void Element::update_screen_size(int size_x, int size_y){
   //
}
