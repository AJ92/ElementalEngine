#ifndef ELEMENTIMGRECT_H
#define ELEMENTIMGRECT_H

#include <QObject>
#include <QSize>
#include <QPoint>
#include "UIElements/element.h"
#include <QImage>
#include "resources.h"
#include "Model/model.h"

class ElementImgRect : public Element
{
    Q_OBJECT
public:
    explicit ElementImgRect(QImage *image, Resources *resource);
    explicit ElementImgRect(QImage *image, Resources *resource, float x1, float y1, float x2, float y2);

    //update setter of Element
    void set_pos_space(float x_pos, float y_pos, float z_pos);
    void set_x_pos_space(float x_pos);
    void set_y_pos_space(float y_pos);
    void set_z_pos_space(float z_pos);

    void set_pos_px(int x_pos, int y_pos, int z_pos);
    void set_x_pos_px(int x_pos);
    void set_y_pos_px(int y_pos);
    void set_z_pos_px(int z_pos);

    void set_scale_space(float x_scale, float y_scale, float z_scale);
    void set_x_scale_space(float x_scale);
    void set_y_scale_space(float y_scale);
    void set_z_scale_space(float z_scale);


    //new
    void set_size_px(int x_size, int y_size);
    void set_x_size_px(int x_size);
    void set_y_size_px(int y_size);


    int img_x_size_px();
    int img_y_size_px();

private:

    int my_img_x_size_px;
    int my_img_y_size_px;


    QImage* img;
    Resources* res;
    Model* mdl;

    int screen_size_x;
    int screen_size_y;

    void update_pos_space();
    void update_pos_px();

    void update_size_space();
    void update_size_px();

    bool is_pow_2(int size);
    int next_pow_2_size(int size);

    bool touch(QMouseEvent* e);

signals:
    void mouse_moved(QMouseEvent* e);
    void mouse_pressed(QMouseEvent* e);
    void mouse_released(QMouseEvent* e);

public slots:
    void check_mouse_move(QMouseEvent* e);
    void check_mouse_press(QMouseEvent* e);
    void check_mouse_release(QMouseEvent* e);
    void update_screen_size(int size_x, int size_y);
};

#endif // ELEMENTIMGRECT_H
