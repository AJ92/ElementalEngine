#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QPoint>
#include <QMouseEvent>

class ElementBar;
class ElementList;
class ElementWindow;
class ElementImgRect;

class Element : public QObject
{
    Q_OBJECT
public:
    explicit Element();
    //Vererbung... Methoden MUESSEN implementiert werden...

    static long next_id();
    long get_id();

    //standard methoden für alle UI Elemente
    virtual void set_pos_space(float x_pos, float y_pos, float z_pos);
    virtual void set_x_pos_space(float x_pos);
    virtual void set_y_pos_space(float y_pos);
    virtual void set_z_pos_space(float z_pos);

    virtual void set_pos_px(int x_pos, int y_pos, int z_pos);
    virtual void set_x_pos_px(int x_pos);
    virtual void set_y_pos_px(int y_pos);
    virtual void set_z_pos_px(int z_pos);

    virtual void set_scale_space(float x_scale, float y_scale, float z_scale);
    virtual void set_x_scale_space(float x_scale);
    virtual void set_y_scale_space(float y_scale);
    virtual void set_z_scale_space(float z_scale);

    float x_pos_space();
    float y_pos_space();
    float z_pos_space();

    int x_pos_px();
    int y_pos_px();
    int z_pos_px();

    float x_scale_space();
    float y_scale_space();
    float z_scale_space();


    //new
    void set_size_px(int x_size, int y_size);
    void set_x_size_px(int x_size);
    void set_y_size_px(int y_size);

    int x_size_px();
    int y_size_px();




    void set_enabled(bool enable);
    bool is_enabled();

    bool used_pos_space_last();
    bool used_scale_space_last();


private:

    static long next_identifier;
    const long identifier;

    float my_x_position_space;
    float my_y_position_space;
    float my_z_position_space;

    int my_x_position_px;
    int my_y_position_px;
    int my_z_position_px;

    float my_x_scale_space;
    float my_y_scale_space;
    float my_z_scale_space;

    //new
    int my_x_size_px;
    int my_y_size_px;

    bool my_enabled;

    bool my_used_pos_space_last;
    bool my_used_scale_space_last;



signals:
    
public slots:
    virtual void check_mouse_move(QMouseEvent* e);
    virtual void check_mouse_press(QMouseEvent* e);
    virtual void check_mouse_release(QMouseEvent* e);
    virtual void update_screen_size(int size_x, int size_y);
};

#endif // ELEMENT_H
