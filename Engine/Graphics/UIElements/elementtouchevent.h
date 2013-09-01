#ifndef ELEMENTTOUCHEVENT_H
#define ELEMENTTOUCHEVENT_H

#include <QObject>
#include <UIElements/element.h>

class ElementTouchEvent
{

public:
    explicit ElementTouchEvent(int x, int y, int x_i, int y_i, Element* e);

    int x();
    int y();
    int x_internal();
    int y_internal();
    Element* element();

private:
    int touch_x;
    int touch_y;
    int touch_x_internal;
    int touch_y_internal;

    Element* touched_element;


signals:
    
public slots:
    
};

#endif // ELEMENTTOUCHEVENT_H
