#ifndef MATERIAL_H
#define MATERIAL_H

//for openGL access to store the textures...
#include "Graphics.h"

#include "Engine/General/identifiable.h"
#include "Math/Vector/vector3.h"

#include <QString>
#include <QStringList>
#include <QImage>

class Material : public Identifiable
{
public:
    Material();
    ~Material();

    //load the bitmaps, and creates openGL textures
    bool load_ambient_map(QString path);
    bool load_diffuse_map(QString path);
    bool load_specular_map(QString path);
    bool load_bump_map(QString path);

    //get
    QString     get_name();
    Vector3     get_ambient_c();
    Vector3     get_diffuse_c();
    Vector3     get_specular_c();
    float       get_specular_ns();
    float       get_specular_ni();
    float       get_transparency_d();
    float       get_transparency_tr();
    Vector3     get_transparency_tf();


    QString     get_ambient_map_name();
    GLuint      get_ambient_map_texture();
    //space for bitmap
    QString     get_diffuse_map_name();
    GLuint      get_diffuse_map_texture();
    //space for bitmap
    QString     get_specular_map_name();
    GLuint      get_specular_map_texture();
    //space for bitmap
    QString     get_bump_map_name();
    GLuint      get_bump_map_texture();
    //space for bitmap
    GLuint*     get_map_textures();
    int         get_illumination();


    //set
    void        set_name(QString name);
    void        set_ambient_c(Vector3 color);
    void        set_diffuse_c(Vector3 color);
    void        set_specular_c(Vector3 color);
    void        set_specular_ns(float value);
    void        set_specular_ni(float value);
    void        set_transparency_d(float value);
    void        set_transparency_tr(float value);
    void        set_transparency_tf(Vector3 color);

    //only the name, does not load anything
    void        set_ambient_map_name(QString map_name);
    void        set_diffuse_map_name(QString map_name);
    void        set_specular_map_name(QString map_name);
    void        set_bump_map_name(QString map_name);

    void        set_illumination(int value);

private:

    QString mtl_name;
    QString mtl_path;


    Vector3 mtl_ambient_c;
    Vector3 mtl_diffuse_c;
    Vector3 mtl_specular_c;
    float mtl_specular_ns;
    float mtl_specular_ni;
    float mtl_transparency_d;
    float mtl_transparency_tr;
    Vector3 mtl_transparency_tf;


    QString mtl_ambient_map;
    QString mtl_diffuse_map;
    QString mtl_specular_map;
    QString mtl_bump_map;

    GLuint*  gl_mtls;

    int mtl_illumination;


    //texture slots
    int tex_slots;

    //wrapper function for texture loading...
    bool load_map(QString path, int slot);

    bool load_map_rgba(QString path);



    int flagBits;

    enum {
        None            = 0x0001,   // No Texture   map defined...
        Ambient         = 0x0002,   // Ambient      map defined
        Diffuse         = 0x0004,   // Diffuse      map defined
        Specular        = 0x0008,   // Specular     map defined
        Bump            = 0x0010    // Bump         map defined
    };


};

#endif // MATERIAL_H
