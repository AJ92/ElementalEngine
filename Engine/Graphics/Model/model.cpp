#include "model.h"

Model::Model()
{
    pos = Vector3(0,0,0);
    rot = Vector3(0,0,0);
    scl = Vector3(1,1,1);
    matrix_changed = true;
}


void Model::set_position(float x, float y, float z){
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    set_matrix_pos();
}

void Model::set_position(Vector3 position){
    pos = position;
    set_matrix_pos();
}


void Model::set_rotation(float x, float y, float z){
    rot[0] = x;
    rot[1] = y;
    rot[2] = z;
    set_matrix_rot();
}

void Model::set_rotation(Vector3 rotation){
    pos = rotation;
    set_matrix_rot();
}


void Model::set_scale(float x, float y, float z){
    scl[0] = x;
    scl[1] = y;
    scl[2] = z;
    set_matrix_scl();
}

void Model::set_scale(Vector3 scale){
    pos = scale;
    set_matrix_scl();
}

Matrix4x4 Model::get_model_matrix(){
    build_model_matrix();
    return mat_m;
}





void Model::set_matrix_pos(){
    mat_pos.translate(pos);
    matrix_changed = true;
}

void Model::set_matrix_rot(){
    mat_rot.rotate_x(rot.x());
    mat_rot.rotate_y(rot.y());
    mat_rot.rotate_z(rot.z());
    matrix_changed = true;
}

void Model::set_matrix_scl(){
    mat_scl.scale(scl);
    matrix_changed = true;
}

void Model::build_model_matrix(){
    if(matrix_changed){
        mat_m = mat_scl * mat_pos * mat_rot;
        matrix_changed = false;
    }
}


