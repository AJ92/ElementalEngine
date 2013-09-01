#include "resources.h"

Resources::Resources()
{

}

void Resources::add_instance(Model* temp, Model *instanced_from){
    qDebug("adding model to instances");
    if(models_id.indexOf(temp->get_id()) == -1){


        int instanced_from_index = models.indexOf(instanced_from);
        if(instanced_from_index != -1){


            //fill models_id and models lists
            models_id.append(temp->get_id());
            models.append(temp);
            qDebug("    added to model list...");



            models_instanced_id[instanced_from_index].append(temp->get_id());
            models_instanced[instanced_from_index].append(temp);
            qDebug("    added to instance lists...");


            //now load the model into the render list
            add_to_render_lists(temp);
            return;
        }
        qDebug("instance base model could not be found...");
        return;
    }
    qDebug("model already there...");
}

void Resources::add_model(Model* temp){
    qDebug("adding model to resources");
    if(models_id.indexOf(temp->get_id()) == -1){
        //fill models_id and models lists
        models_id.append(temp->get_id());
        models.append(temp);
        qDebug("    added to model list...");


        //fill materials_id and materials lists
        QList<Mesh*> temp_meshs = temp->get_meshs();
        for(int i = 0; i < temp_meshs.length(); i++){
            Material* new_mat = temp_meshs[i]->get_material();

            if(materials.indexOf(new_mat) == -1){
                materials_id.append(new_mat->get_id());
                materials.append(new_mat);

                //create new lists in render lists...

                QList<Model*> new_model_list;
                model_render_list.append(new_model_list);
                QList<Mesh*> new_mesh_list;
                mesh_render_list.append(new_mesh_list);
            }

        }
        qDebug("    added to material list...");

        //fill models_instanced_id and models_instanced lists with new empty lists
        QList<int> new_instance_id_list;
        models_instanced_id.append(new_instance_id_list);
        QList<Model*> new_instance_list;
        models_instanced.append(new_instance_list);
        qDebug("    created new instance lists...");


        //now load the model into the render list
        add_to_render_lists(temp);
        return;
    }
    qDebug("model already there...");
}

bool Resources::remove_model(Model* temp){

    qDebug("removing model from resources");
    int model_index = models.indexOf(temp);
    if((model_index != -1) && (temp->is_instanced() == false)){

        qDebug("    model is not an instance, thus delete everything...");


        //remove model from ALL lists
        models.removeAt(model_index);
        models_id.removeAt(model_index);

        models_instanced.removeAt(model_index);
        models_instanced_id.removeAt(model_index);

        QList<Mesh*> temp_meshs = temp->get_meshs();
        for(int i = 0; i < temp_meshs.length(); i++){
            int materials_index = materials.indexOf(temp_meshs[i]->get_material());
            if(materials_index != -1){
                delete materials[materials_index];
                materials.removeAt(materials_index);
                materials_id.removeAt(materials_index);

                model_render_list.removeAt(materials_index);
                mesh_render_list.removeAt(materials_index);
            }
        }
        //delete model data...
        return true;
    }
    else if(model_index != -1){

        qDebug("    model is an instance, thus delete only instanced entries..");

        models.removeAt(model_index);
        models_id.removeAt(model_index);
        qDebug("    model entrys removed...");

        //remove model from instance lists and render lists..
        int model_instance = models.indexOf(temp->get_instance_base());
        int model_instance_entry = models_instanced[model_instance].indexOf(temp);

        if(model_instance_entry != -1){
            models_instanced[model_instance].removeAt(model_instance_entry);
            models_instanced_id[model_instance].removeAt(model_instance_entry);
            qDebug("    model instance entrys removed...");
        }

        //gather indizes for delete...
        int index_of_temp = -1;
        int ii = 0;
        bool indexed = true;
        while(indexed){
            for(int i = 0; i < model_render_list.length(); i++){
                index_of_temp = model_render_list[i].indexOf(temp);
                ii = i;
                if(index_of_temp != -1){
                    break;
                }
            }
            if(index_of_temp != -1){
                model_render_list[ii].removeAt(index_of_temp);
                mesh_render_list[ii].removeAt(index_of_temp);
            }
            else{
                indexed = false;
            }
        }
        qDebug("    render lists entrys removed...");

        //delete model data...
        return false;
    }

    //if the model isnt in both lists... dont delete it, might be bug...
    return false;
}

void Resources::add_to_render_lists(Model* temp){
    //fill render lists
    qDebug("adding to render lists");
    QList<Mesh*> temp_meshs = temp->get_meshs();
    for(int i = 0; i < temp_meshs.length(); i++){
        Material* new_mat = temp_meshs[i]->get_material();
        int material_index = materials.indexOf(new_mat);
        if(material_index != -1){
            model_render_list[material_index].append(temp);
            mesh_render_list[material_index].append(temp_meshs[i]);
        }
    }
    qDebug("    added to render lists...");

    qDebug("\n\nRESOURCES:");
    qDebug("    materials:");
    for(int i = 0; i < materials.length(); i++){
        qDebug("    %s", materials.at(i)->get_material_name().toUtf8().data());
    }
    qDebug("\n");

    qDebug("    model_render_list:");
    for(int i = 0; i < model_render_list.length(); i++){
        qDebug("    -");
        for(int j = 0; j < model_render_list[i].length(); j++){
            qDebug("    %s", model_render_list[i][j]->get_model_name().toUtf8().data());
        }
    }
    qDebug("\n");

    qDebug("    mesh_render_list:");
    for(int i = 0; i < mesh_render_list.length(); i++){
        qDebug("    -");
        for(int j = 0; j < mesh_render_list[i].length(); j++){
            qDebug("    %s", mesh_render_list[i][j]->get_mesh_name().toUtf8().data());
        }
    }
    qDebug("\n");
}




//GETTER

QList< QList<Model*> > Resources::get_model_render_list(){
    return model_render_list;
}

QList< QList<Mesh*> > Resources::get_mesh_render_list(){
    return mesh_render_list;
}

QList<Material*> Resources::get_materials(){
    return materials;
}

void Resources::debug_stats(){

}
