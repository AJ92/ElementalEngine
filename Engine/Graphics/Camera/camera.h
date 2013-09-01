#ifndef CAMERA3D_H
#define CAMERA3D_H

#include <QtGui/qmatrix4x4.h>



class Camera
{
public:
    Camera();
    ~Camera();
    float x;
    float y;
    float z;
    float Z_FAR;
    float Z_NEAR;
    float FOV;

    // local - cam rotates
    void rotate_local_post(float angle, float axis_x, float axis_y, float axis_z);    // no gimbal lock
    void rotate_local_pre(float angle, float axis_x, float axis_y, float axis_z);     // along axis
    // global - world rotates
    void rotate_global_post(float angle, float axis_x, float axis_y, float axis_z);    // no gimbal lock
    void rotate_global_pre(float angle, float axis_x, float axis_y, float axis_z);     // along axis

    void move(float x_dir, float y_dir, float z_dir);
    void translate(float x_dir, float y_dir, float z_dir);




    QMatrix4x4 M_camera_view;
    QMatrix4x4 M_camera_rotation_local;
    QMatrix4x4 M_camera_rotation_global;
    QMatrix4x4 M_camera_rotation;
    QMatrix4x4 M_camera_translation;

signals:

public slots:

};

#endif // CAMERA_H
