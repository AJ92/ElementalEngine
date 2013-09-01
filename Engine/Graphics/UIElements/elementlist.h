#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

#include <QObject>
#include <QSize>
#include <QPoint>
#include "UIElements/element.h"

class ElementList : public Element
{
    Q_OBJECT
public:
    explicit ElementList();
    /*
    void add_element(Element* e);
    bool remove_element(Element* e);
    void set_pos(float x_pos, float y_pos, float z_pos);

    float get_offset_top();
    float get_offset_bottom();
    float get_offset_left();
    float get_offset_right();

    void set_offset_top(float value);
    void set_offset_bottom(float value);
    void set_offset_left(float value);
    void set_offset_right(float value);

    void set_element_spacing(float value);
    void set_scrolling_factor(float value);
    void set_anti_scrolling_factor(float value);
    void set_max_scroll_offset(float value);

    void set_scrolling(bool scrolling);

    void set_x_axis_alignment(bool align);
    void set_y_axis_alignment(bool align);
    void set_z_axis_alignment(bool align);


private:
    float offset_top;
    float offset_bottom;
    float offset_left;
    float offset_right;

    float element_spacing;
    float scrolling_factor;
    float anti_scrolling_factor;
    float max_scroll_offset;

    bool is_scrolling;

    bool x_axis_alignment;
    bool y_axis_alignment;
    bool z_axis_alignment;

    QList<Element*> element_list;
    void adjust_element_pos(Element* e, float x_diff, float y_diff, float z_diff);
    
signals:
    
public slots:
     void adjust_list_pos();
     void check_touch(QMouseEvent* e);
     void resize_to_screen(float new_screen_size_x, float new_screen_size_y);
   */
};

#endif // ELEMENTLIST_H
