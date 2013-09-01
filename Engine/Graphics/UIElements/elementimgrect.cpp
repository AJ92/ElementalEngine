#include "elementimgrect.h"



ElementImgRect::ElementImgRect(QImage *image, Resources* resource):
    Element(),
    img(image),
    res(resource),
    screen_size_x(1),
    screen_size_y(1)
{
    //set size of element by image size
    my_img_x_size_px = img->size().width();
    my_img_y_size_px = img->size().height();

    Element::set_x_size_px(my_img_x_size_px);
    Element::set_y_size_px(my_img_y_size_px);

    //e.g. scale image to pow of 2 and scale model by previous pixel size
    if(!is_pow_2(x_size_px()) || !is_pow_2(y_size_px())){
        img = new QImage(img->scaled(next_pow_2_size(x_size_px()),next_pow_2_size(y_size_px()),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }

    //generate model here
    //MATERIAL
    Material* mtl = new Material("2D_obj",":/");
    mtl->set_mtl_diffuse_map("64test.png");
    mtl->init();

    mtl->update_tex_map(img,2);

    //MESH

    GLfloat vertices[18] = {   0.0f, 0.0f, 0.0f, //triangle1
                                0.0f,-1.0f, 0.0f,
                                -1.0f, 0.0f, 0.0f,
                                0.0f,-1.0f, 0.0f, //triangle2
                                -1.0f,-1.0f, 0.0f,
                                -1.0f, 0.0f, 0.0f};

    GLfloat texcoords[18] = {   0.0f, 0.0f, 1.0f, //triangle1
                                0.0f, 1.0f, 1.0f,
                                1.0f, 0.0f, 1.0f,
                                0.0f, 1.0f, 1.0f, //triangle2
                                1.0f, 1.0f, 1.0f,
                                1.0f, 0.0f, 1.0f};


    GLfloat normals[18] = {    0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f};

    GLuint vertex_vbo;
    GLuint texcoord_vbo;
    GLuint normal_vbo;

    glGenBuffers(1, &vertex_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &texcoord_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, texcoord_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), texcoords, GL_STATIC_DRAW);

    glGenBuffers(1, &normal_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), normals, GL_STATIC_DRAW);


    //Create Mesh and add it to the Mesh-list and register those in the resman...
    Mesh* mesh = new Mesh("2D_mesh",2,vertices,texcoords,normals,
                          vertex_vbo,texcoord_vbo,normal_vbo,mtl);
    QList<Mesh*> meshs;
    meshs.append(mesh);
    bool ok;
    mdl = new Model(QString("2D_mdl"),meshs,res,ok);

    //resize model to screen size

}

ElementImgRect::ElementImgRect(QImage *image, Resources *resource, float x1, float y1, float x2, float y2):
    Element(),
    img(image),
    res(resource),
    screen_size_x(1),
    screen_size_y(1)

{
    int size_x = img->size().width();
    int size_y = img->size().height();

    //e.g. scale image to pow of 2 and scale model by previous pixel size
    if(!is_pow_2(size_x) || !is_pow_2(size_y)){
        img = new QImage(img->scaled(next_pow_2_size(size_x),next_pow_2_size(size_y),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }

    //generate model here
    //MATERIAL
    Material* mtl = new Material("2D_obj",":/");
    mtl->set_mtl_diffuse_map("64test.png");
    mtl->init();

    mtl->update_tex_map(img,2);

    //MESH
    //set size of element by resulting image size

    float tex_offset_x = x1/size_x;
    float tex_offset_y = y1/size_y;

    float tex_end_x = x2/size_x;
    float tex_end_y = y2/size_y;

    float width =  x2 - x1;
    float height = y2 - y1;

    GLfloat vertices[18] = {   0.0f, 0.0f, 0.0f, //triangle1
                                0.0f,-1.0f, 0.0f,
                                -1.0f, 0.0f, 0.0f,
                                0.0f,-1.0f, 0.0f, //triangle2
                                -1.0f,-1.0f, 0.0f,
                                -1.0f, 0.0f, 0.0f};

    GLfloat texcoords[18] = {   tex_offset_x, tex_offset_y, 1.0f, //triangle1
                                tex_offset_x, tex_end_y, 1.0f,
                                tex_end_x, tex_offset_y, 1.0f,
                                tex_offset_x, tex_end_y, 1.0f, //triangle2
                                tex_end_x, tex_end_y, 1.0f,
                                tex_end_x, tex_offset_y, 1.0f};

    GLfloat normals[18] = {    0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f,
                                0.0f, 0.0f,-1.0f};

    my_img_x_size_px = width;
    my_img_y_size_px = height;

    Element::set_x_size_px(my_img_x_size_px);
    Element::set_y_size_px(my_img_y_size_px);


    GLuint vertex_vbo;
    GLuint texcoord_vbo;
    GLuint normal_vbo;

    glGenBuffers(1, &vertex_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &texcoord_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, texcoord_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), texcoords, GL_STATIC_DRAW);

    glGenBuffers(1, &normal_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), normals, GL_STATIC_DRAW);


    //Create Mesh and add it to the Mesh-list and register those in the resman...

    QString mesh_name = "2D_mesh" + QString::number(get_id());

    Mesh* mesh = new Mesh(mesh_name,2,vertices,texcoords,normals,
                          vertex_vbo,texcoord_vbo,normal_vbo,mtl);
    QList<Mesh*> meshs;
    meshs.append(mesh);
    bool ok;
    mdl = new Model(QString("2D_mdl"),meshs,res,ok);

}



//override:
void ElementImgRect::set_pos_space(float x_pos, float y_pos, float z_pos){
    Element::set_pos_space(x_pos,y_pos,z_pos);
    update_pos_space();
}

void ElementImgRect::set_x_pos_space(float x_pos){
    Element::set_x_pos_space(x_pos);
    update_pos_space();
}

void ElementImgRect::set_y_pos_space(float y_pos){
    Element::set_y_pos_space(y_pos);
    update_pos_space();
}

void ElementImgRect::set_z_pos_space(float z_pos){
    Element::set_z_pos_space(z_pos);
    update_pos_space();
}

void ElementImgRect::set_pos_px(int x_pos, int y_pos, int z_pos){
    Element::set_pos_px(x_pos, y_pos, z_pos);
    update_pos_px();
}

void ElementImgRect::set_x_pos_px(int x_pos){
    Element::set_x_pos_px(x_pos);
    update_pos_px();
}

void ElementImgRect::set_y_pos_px(int y_pos){
    Element::set_y_pos_px(y_pos);
    update_pos_px();
}

void ElementImgRect::set_z_pos_px(int z_pos){
    Element::set_z_pos_px(z_pos);
    update_pos_px();
}

void ElementImgRect::set_scale_space(float x_scale, float y_scale, float z_scale){
    Element::set_scale_space(x_scale,y_scale,z_scale);
    update_size_space();
}

void ElementImgRect::set_x_scale_space(float x_scale){
    Element::set_x_scale_space(x_scale);
    update_size_space();
}

void ElementImgRect::set_y_scale_space(float y_scale){
    Element::set_y_scale_space(y_scale);
    update_size_space();
}

void ElementImgRect::set_z_scale_space(float z_scale){
    Element::set_z_scale_space(z_scale);
    update_size_space();
}




//new:

void ElementImgRect::set_size_px(int x_size, int y_size){
    Element::set_x_size_px(x_size);
    Element::set_y_size_px(y_size);
    update_size_px();
}

void ElementImgRect::set_x_size_px(int x_size){
    Element::set_x_size_px(x_size);
    update_size_px();
}

void ElementImgRect::set_y_size_px(int y_size){
    Element::set_x_size_px(y_size);
    update_size_px();
}

int ElementImgRect::img_x_size_px(){
    return my_img_x_size_px;
}

int ElementImgRect::img_y_size_px(){
    return my_img_y_size_px;
}



void ElementImgRect::update_pos_space(){
    mdl->translate(-x_pos_space(), -y_pos_space(), z_pos_space());
    Element::set_pos_px(x_pos_space()*screen_size_x, y_pos_space()*screen_size_y, z_pos_space()*1000);
    //qDebug("pos update space:");
    //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
    //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
}

void ElementImgRect::update_pos_px(){
    Element::set_pos_space((float)x_pos_px()/(float)screen_size_x, (float)y_pos_px()/(float)screen_size_y, (float)z_pos_px()/1000.0);
    mdl->translate(-x_pos_space(), -y_pos_space(), z_pos_space());
    //qDebug("pos update px:");
    //qDebug("    pos px: %i  %i  %i", x_pos_px(), y_pos_px(), z_pos_px());
    //qDebug("    pos space: %f  %f  %f", x_pos_space(), y_pos_space(), z_pos_space());
}

void ElementImgRect::update_size_space(){
    mdl->scale(x_scale_space(), y_scale_space(), z_scale_space());
    Element::set_size_px(x_scale_space()*screen_size_x, y_scale_space()*screen_size_y);
    qDebug("size update space:");
    qDebug("    scale px: %i  %i", x_size_px(), y_size_px());
    qDebug("    scale space: %f  %f", x_scale_space(), y_scale_space());
}

void ElementImgRect::update_size_px(){
    Element::set_scale_space((float)x_size_px()/screen_size_x, (float)y_size_px()/screen_size_y, z_scale_space());
    mdl->scale(x_scale_space(), y_scale_space(), z_scale_space());
    qDebug("size update space:");
    qDebug("    scale px: %i  %i", x_size_px(), y_size_px());
    qDebug("    scale space: %f  %f", x_scale_space(), y_scale_space());
}


bool ElementImgRect::is_pow_2(int size)
{
    return (size & (size - 1)) == 0;
}

int ElementImgRect::next_pow_2_size(int size){

    int pow = 1;
    int shift = size;
    while(shift > 0){
        shift = shift >> 1;
        pow = pow * 2;
    }

    int up_dist = (pow*2) - size;
    int lo_dist = size - pow;

    if(up_dist < lo_dist){
        return pow*2;
    }
    return pow;
}

bool ElementImgRect::touch(QMouseEvent* e){
    if(is_enabled()){
        if((x_pos_px() <= e->x()) &&
                (y_pos_px() <= e->y()) &&
                ((x_pos_px() + x_size_px()) >= e->x()) &&
                ((y_pos_px() + y_size_px()) >= e->y())){
            //touch recognized
            return true;
        }
    }
    return false;
}



//SIGNALS:



//SLOTS:

void ElementImgRect::check_mouse_move(QMouseEvent* e){
    if(touch(e)){
        //qDebug("ElementImgRect mouse moved (ID:%i)",get_id());
        mouse_moved(e);
    }
}

void ElementImgRect::check_mouse_press(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementImgRect mouse press (ID:%i)",get_id());
        mouse_pressed(e);
    }
}

void ElementImgRect::check_mouse_release(QMouseEvent* e){
    if(touch(e)){
        qDebug("ElementImgRect mouse release (ID:%i)",get_id());
        mouse_released(e);
    }
}


void ElementImgRect::update_screen_size(int size_x, int size_y){
    screen_size_x = size_x;
    screen_size_y = size_y;
    update_pos_px();
    update_size_px();
    qDebug("scaling imgrect...");
}

/*
void ElementImgRect::resize_to_screen(float new_screen_size_x, float new_screen_size_y){

    //resize model...
    this->mdl->scale(this->scale_x * (this->size().width() / new_screen_size_x),
                     this->scale_y * (this->size().height() / new_screen_size_y),
                     this->scale_z);

    //repos model...
    this->mdl->translate(-this->x_pos()/new_screen_size_x, -this->y_pos()/new_screen_size_y, this->z_pos());

    screen_size_x = new_screen_size_x;
    screen_size_y = new_screen_size_y;
}
*/
