#ifndef LOADER_OBJ_H
#define LOADER_OBJ_H

#include "Graphics/Model/model.h"


#include "Math/Vector/vector3.h"

#include <QMap>
#include <QVector>

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>


class Loader_obj
{
public:
    Loader_obj();

    static bool load_model_data(Model& mdl, QString path);
};

#endif // LOADER_OBJ_H
