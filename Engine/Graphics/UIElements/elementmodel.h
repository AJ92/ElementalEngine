#ifndef ELEMENTMODEL_H
#define ELEMENTMODEL_H


#include "UIElements/element.h"
#include <QObject>
#include <QSize>
#include <QPoint>
#include "Model/model.h"

class ElementModel: public Element
{
    Q_OBJECT
public:
    ElementModel(Model* mdl);
    void set_pos(float x_pos, float y_pos, float z_pos);

private:
    Model* model;

signals:

public slots:
    void check_touch(QMouseEvent* e);

};

#endif // ELEMENTMODEL_H
