#ifndef ELEMENTGROUP_H
#define ELEMENTGROUP_H

#include <QObject>
#include <QSize>
#include <QPoint>
#include "UIElements/element.h"


class ElementGroup : public Element
{
    Q_OBJECT
public:
    explicit ElementGroup();

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




    void add_element(Element* e);
    bool remove_element(Element* e);


    QList<Element*> element_list;

    //new

    int screen_size_x;
    int screen_size_y;

    void update_my_elements_pos_space();
    void update_my_elements_pos_px();

    bool touch(QMouseEvent* e);

public:
    void arrange_my_elements();



signals:
    void mouse_moved(QMouseEvent* e);
    void mouse_pressed(QMouseEvent* e);
    void mouse_released(QMouseEvent* e);

public slots:
    void update_screen_size(int size_x, int size_y);
    void check_mouse_move(QMouseEvent* e);
    void check_mouse_press(QMouseEvent* e);
    void check_mouse_release(QMouseEvent* e);
    void resize_elements(int new_screen_size_x, int new_screen_size_y);
};

#endif // ELEMENTGROUP_H
