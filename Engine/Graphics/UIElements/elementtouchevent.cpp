#include "elementtouchevent.h"

ElementTouchEvent::ElementTouchEvent(int x, int y, int x_i, int y_i, Element* e):
    touch_x(x),
    touch_y(y),
    touch_x_internal(x_i),
    touch_y_internal(y_i),
    touched_element(e)
{

}


int ElementTouchEvent::x(){
    return touch_x;
}

int ElementTouchEvent::y(){
    return touch_y;
}

int ElementTouchEvent::x_internal(){
    return touch_x_internal;
}

int ElementTouchEvent::y_internal(){
    return touch_y_internal;
}

Element* ElementTouchEvent::element(){
    return touched_element;
}
