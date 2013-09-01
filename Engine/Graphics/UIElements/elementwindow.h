#ifndef ELEMENTWINDOW_H
#define ELEMENTWINDOW_H

#include <QObject>
#include <QSize>
#include <QPoint>
#include <QList>
#include "glwindow.h"
#include "UIElements/element.h"
#include "glwindow.h"
#include "Camera/camera.h"


class ElementWindow : public Element
{
    Q_OBJECT
public:
    explicit ElementWindow(GLwindow* glwin);
    explicit ElementWindow(GLwindow* glwin, float x_size, float y_size);

    void add_element(Element* e);
    bool remove_element(Element* e);



private:
    GLwindow* glwindow;
    QList<Element*> element_list;

    float screen_size_x;
    float screen_size_y;

    float scale_x;
    float scale_y;
    float scale_z;

    float size_x;
    float size_y;

    bool touch(QMouseEvent* e);
    
signals:
    
public slots:
    void check_mouse_move(QMouseEvent* e);
    void check_mouse_press(QMouseEvent* e);
    void check_mouse_release(QMouseEvent* e);
    void resize_elements(int new_screen_size_x, int new_screen_size_y);

};

#endif // ELEMENTWINDOW_H
