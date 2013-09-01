#include "identifiable.h"

//init the next_id var...
long Identifiable::static_id = 0;

Identifiable::Identifiable():
    my_id(next_id())
{

}

long Identifiable::id(){
    return my_id;
}

long Identifiable::next_id(){
    static_id++;
    return static_id;
}
