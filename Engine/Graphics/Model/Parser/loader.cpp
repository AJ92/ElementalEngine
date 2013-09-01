#include "loader.h"

//constructor not needed ... class receives static functions anyways...
Loader::Loader()
{
}

//static
Model* Loader::import_model(QString path, bool &ok){

    qDebug("\n\n");
    qDebug("Import model...");
    qDebug(" path: '" + path.toUtf8() + "'");

    QStringList pathlist = path.split(".");
    QString suffix = pathlist.last();

    if(suffix.compare("fbx")==0){
        qDebug(" fbx format detected...");
        return import_model_format_fbx(path, ok);
    }
    else if(suffix.compare("bin")==0){
        qDebug(" bin format detected...");
        return import_model_format_bin(path, ok);
    }
    else if(suffix.compare("obj")==0){
        qDebug(" obj format detected...");
        return import_model_format_obj(path, ok);
    }
    qDebug("no suitable format detected...");
    ok = false;
    return NULL;
}

//static
void Loader::export_model_bin(QString path, Model* mdl, bool &ok){

}

//static
Model* Loader::import_model_format_bin(QString path, bool &ok){
    qDebug(" importing bin mdl");
    return NULL;
}

//static
Model* Loader::import_model_format_fbx(QString path, bool &ok){
    qDebug(" importing fbx mdl");
    return NULL;
}

//static
Model* Loader::import_model_format_obj(QString path, bool &ok){
    qDebug(" importing obj mdl");

    Model* mdl;
    if(!Loader_obj::load_model_data(*mdl,path)){
        qDebug("  import of obj mdl FAILED.");
        delete mdl;
        ok = false;
        return NULL;
    }
    ok = true;
    return mdl;
}
