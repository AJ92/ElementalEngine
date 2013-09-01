#include "elementmodel.h"

ElementModel::ElementModel(Model *mdl):
    Element(),
    model(mdl)
{

}

void ElementModel::set_pos(float x_pos, float y_pos, float z_pos){
    //qDebug("%f  %f   %f",x_pos,y_pos,z_pos);
    model->translate(x_pos,y_pos,z_pos);
}

//SLOTS:
void ElementModel::check_touch(QMouseEvent* e){
    if(is_enabled()){
        qDebug("element model touch checking...");
    }
}
