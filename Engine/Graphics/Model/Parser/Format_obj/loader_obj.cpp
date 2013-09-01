#include "loader_obj.h"

Loader_obj::Loader_obj()
{
}

bool Loader_obj::load_model_data(Model& mdl, QString path){

    qDebug("Parsing obj file...");

    QStringList pathlist = path.split("/",QString::KeepEmptyParts); //KeepEmptyParts
    QString model_name = pathlist.last();

    qDebug("Model name: " + model_name.toUtf8());



    //LOAD MESH DATA
    QFile file(path);
    if (!file.open (QIODevice::ReadOnly))
    {
        qDebug("Model import: Error 1: Model file could not be loaded...");
        return false;
    }
    QTextStream stream ( &file );
    QString line;

    QString mtllib;


    QString current_mesh;
    QMap<QString,QVector<int> >mesh_faces;
    QMap<QString,QString> mesh_mtl;
    QMap<QString,Material* > mtln_mtl;
    QVector<Vector3> model_vertices;
    QVector<Vector3> model_vertex_normals;
    QVector<Vector3> model_vertex_texture_coordinates;

    while( !stream.atEnd() ) {
        line = stream.readLine();
        QStringList list = line.split(QRegExp("\\s+"),QString::SkipEmptyParts); //SkipEmptyParts

        if(!list.empty()){
            if(list.first() == "mtllib"){
                mtllib = list.last();
            }

            else if(list.first() == "v"){
                model_vertices.append(Vector3(  list.value(1).toFloat(),
                                                  list.value(2).toFloat(),
                                                  list.value(3).toFloat()));
            }
            else if(list.first() == "vn"){
                model_vertex_normals.append(Vector3(  list.value(1).toFloat(),
                                                        list.value(2).toFloat(),
                                                        list.value(3).toFloat()));
            }
            else if(list.first() == "vt"){
                model_vertex_texture_coordinates.append(Vector3(  list.value(1).toFloat(),
                                                                    list.value(2).toFloat(),
                                                                    list.value(3).toFloat()));
            }
            else if(list.first() == "g"){
                current_mesh = list.value(1);
            }
            else if(list.first() == "usemtl"){
                mesh_mtl[current_mesh] = list.value(1);
            }
            else if(list.first() == "f"){
                QStringList face_part_1_list = list.value(1).split("/",QString::SkipEmptyParts); //SkipEmptyParts
                QStringList face_part_2_list = list.value(2).split("/",QString::SkipEmptyParts); //SkipEmptyParts
                QStringList face_part_3_list = list.value(3).split("/",QString::SkipEmptyParts); //SkipEmptyParts
                mesh_faces[current_mesh].append(face_part_1_list.value(0).toInt());
                mesh_faces[current_mesh].append(face_part_1_list.value(1).toInt());
                mesh_faces[current_mesh].append(face_part_1_list.value(2).toInt());

                mesh_faces[current_mesh].append(face_part_2_list.value(0).toInt());
                mesh_faces[current_mesh].append(face_part_2_list.value(1).toInt());
                mesh_faces[current_mesh].append(face_part_2_list.value(2).toInt());

                mesh_faces[current_mesh].append(face_part_3_list.value(0).toInt());
                mesh_faces[current_mesh].append(face_part_3_list.value(1).toInt());
                mesh_faces[current_mesh].append(face_part_3_list.value(2).toInt());

            }
        }

    }
    file.close();


    //LOAD MTL DATA

    pathlist.removeAt(pathlist.length()-1);
    QString mtl_path = pathlist.join("/") + "/" + mtllib;
    QString tex_path = pathlist.join("/") + "/";

    QFile mtlfile(mtl_path);
    if (!mtlfile.open (QIODevice::ReadOnly))
    {
        qDebug("Model import: Error 2: Model material file could not be loaded...");
        return false;
    }
    QTextStream mtlstream ( &mtlfile );
    QString mtlline;


    QString current_mtl;
    QMap<QString,Vector3> mtl_ambient_c;          //Ka
    QMap<QString,Vector3> mtl_diffuse_c;          //Kd
    QMap<QString,Vector3> mtl_specular_c;         //Ks
    QMap<QString,float>     mtl_specular_ns;        //Ns
    QMap<QString,float>     mtl_transparency_d;     //d
    QMap<QString,float>     mtl_transparency_tr;    //Tr
    QMap<QString,Vector3> mtl_transparency_tf;    //Tf
    QMap<QString,QString>   mtl_ambient_map;        //map_Ka
    QMap<QString,QString>   mtl_diffuse_map;        //map_Kd
    QMap<QString,QString>   mtl_specular_map;       //map_Ks
    QMap<QString,QString>   mtl_bump_map;           //map_bump
    QMap<QString,int>       mtl_illumination;       //illum

    while( !mtlstream.atEnd() ) {
        mtlline = mtlstream.readLine();
        QStringList list = mtlline.split(QRegExp("\\s+"),QString::SkipEmptyParts); //SkipEmptyParts
        if(!list.empty()){
            if(list.first() == "newmtl"){
                current_mtl = list.last();
            }
            else if(list.first() == "Ka"){
                mtl_ambient_c[current_mtl] = Vector3(list.value(1).toFloat(),
                                                       list.value(2).toFloat(),
                                                       list.value(3).toFloat());
            }
            else if(list.first() == "Kd"){
                mtl_diffuse_c[current_mtl] = Vector3(list.value(1).toFloat(),
                                                       list.value(2).toFloat(),
                                                       list.value(3).toFloat());
            }
            else if(list.first() == "Ks"){
                mtl_specular_c[current_mtl] = Vector3(list.value(1).toFloat(),
                                                        list.value(2).toFloat(),
                                                        list.value(3).toFloat());
            }
            else if(list.first() == "Ns"){
                mtl_specular_ns[current_mtl] = list.value(1).toFloat();

            }
            else if(list.first() == "d"){
                mtl_transparency_d[current_mtl] = list.value(1).toFloat();

            }
            else if(list.first() == "Tr"){
                mtl_transparency_tr[current_mtl] = list.value(1).toFloat();

            }
            else if(list.first() == "Tf"){
                mtl_transparency_tf[current_mtl] = Vector3(list.value(1).toFloat(),
                                                             list.value(2).toFloat(),
                                                             list.value(3).toFloat());
            }
            else if(list.first() == "map_Ka"){
                mtl_ambient_map[current_mtl] = list.value(1).split("\\",QString::SkipEmptyParts).last().toUtf8();
            }
            else if(list.first() == "map_Kd"){
                mtl_diffuse_map[current_mtl] = list.value(1).split("\\",QString::SkipEmptyParts).last().toUtf8();
            }
            else if(list.first() == "map_Ks"){
                mtl_specular_map[current_mtl] = list.value(1).split("\\",QString::SkipEmptyParts).last().toUtf8();
            }
            else if((list.first() == "map_bump") || (list.first() == "bump")){
                mtl_bump_map[current_mtl] = list.value(1).split("\\",QString::SkipEmptyParts).last().toUtf8();
            }
            else if(list.first() == "illum"){
                mtl_illumination[current_mtl] = list.value(1).toInt();
            }
        }

    }


    return true;
}
