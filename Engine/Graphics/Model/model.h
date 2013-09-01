#ifndef MODEL_H
#define MODEL_H

#include "Engine/General/identifiable.h"
#include "Math/Math.h"

#include "Model/Components/material.h"

class Model : public Identifiable
{
public:
    Model();

    void set_position(float x, float y, float z);
    void set_position(Vector3 position);

    void set_rotation(float x, float y, float z);
    void set_rotation(Vector3 rotation);

    void set_scale(float x, float y, float z);
    void set_scale(Vector3 scale);

    Matrix4x4 get_model_matrix();

private:
    bool matrix_changed;

    //translation, scale, rotation...
    Vector3 pos;
    Vector3 rot;
    Vector3 scl;

    Matrix4x4 mat_pos;
    Matrix4x4 mat_rot;
    Matrix4x4 mat_scl;

    Matrix4x4 mat_m;

    void set_matrix_pos();
    void set_matrix_rot();
    void set_matrix_scl();

    void build_model_matrix();
};

#endif // MODEL_H
