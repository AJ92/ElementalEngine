#include "shaderlibrary.h"
#include "shader.h"

Shaderlibrary::Shaderlibrary()
{
    const GLubyte * version = glGetString(GL_SHADING_LANGUAGE_VERSION);
    qDebug((const char *) glGetString(GL_VENDOR));
    qDebug((const char *) glGetString(GL_RENDERER));
    qDebug((const char *) glGetString(GL_VERSION));
    qDebug((const char *) glGetString(GL_SHADING_LANGUAGE_VERSION));
    qDebug((const char *) glGetString(GL_EXTENSIONS));
    if(version == 0){
        qDebug("GLSL version: 0");
        qDebug("  hardware does not support shaders ?");
    }
}

void Shaderlibrary::set_shader_of_material(QString material, Shader *shader){
    /*      old qmap solution
    //if there is already a reference then it will be overwritten...
    shaders[material] = shader;
    */


    int index = shader_names.indexOf(material);
    if(index>=0){
        shaders.removeAt(index);
        shader_names.removeAt(index);
    }

    shader_names.append(material);
    shaders.append(shader);
    if(shader->get_shader_name() == "standard"){
        qDebug("ADDED STANDARD SHADER");
        standard_shader = shader;
    }
}

Shader* Shaderlibrary::get_shader_of_material(QString material){
    /*      old qmap solution
    return shaders.value(material);
    */
    int index = shader_names.indexOf(material);
    if(index >= 0){
        return shaders.at(index);
    }
    else{
        if(standard_shader){
            return standard_shader;
        }
        else{
            qDebug("exit due to missing shader(s) (error: 101)");
            exit(101);
        }
    }
}
