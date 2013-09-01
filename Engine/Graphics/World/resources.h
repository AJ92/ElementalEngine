#ifndef RESOURCES_H
#define RESOURCES_H

#include "Model/loader.h"
#include "Model/model.h"
#include "Model/mesh.h"
#include "Model/material.h"

#include <QMap>

class Model;
class Mesh;
class Material;

class Resources
{
public:
    Resources();

    //adds data to the resources
    void add_model(Model* temp);
    void add_instance(Model* temp, Model* instanced_from);
    bool remove_model(Model* temp);

    QList< QList<Model*> > get_model_render_list();
    QList< QList<Mesh*> > get_mesh_render_list();
    QList<Material*> get_materials();

    void debug_stats();

private:

    void add_to_render_lists(Model* temp);

    //pointers to objects to be rendered
    QList< QList<Model*> > model_render_list;       //index i
    QList< QList<Mesh*> > mesh_render_list;         //index i


    //loaded DATA

    //MODELS
    QList<Model*>               models;             //index j
    QList<int>                  models_id;          //index j

    //INSTANCES
    //used to keep DATA and INSTANCES working after delete
    QList< QList<Model*> >      models_instanced;   //index j
    QList< QList<int> >         models_instanced_id;//index j

    //MATERIALS                 unique (all other lists can have same entries)
    QList<Material*>            materials;          //index i
    QList<int>                  materials_id;       //index i
};

#endif // RESOURCES_H
