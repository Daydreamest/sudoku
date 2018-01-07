#include "Initializer.h"

//TODO remove
#include <iostream>

#include <UiData.h>

Initializer::Initializer()
{
    //ctor
}

Initializer::~Initializer()
{
    //dtor
}

AbstractData::handle_type Initializer::get()
{
    UiData::handle_type p = UiData::create();

    // TODO automatic read from a file

    p->set_value(0,0,'7');
    p->set_value(2,0,'6');
    p->set_value(7,0,'4');
    p->set_value(8,0,'9');
    p->set_value(2,1,'9');
    p->set_value(5,1,'1');
    p->set_value(6,1,'5');
    p->set_value(0,2,'2');
    p->set_value(3,2,'7');
    p->set_value(4,2,'6');
    p->set_value(5,3,'4');
    p->set_value(7,3,'8');
    p->set_value(2,4,'7');
    p->set_value(3,4,'9');
    p->set_value(3,5,'3');
    p->set_value(4,5,'7');
    p->set_value(5,5,'2');
    p->set_value(0,6,'8');
    p->set_value(2,6,'2');
    p->set_value(7,6,'3');
    p->set_value(8,6,'5');
    p->set_value(1,7,'5');
    p->set_value(3,7,'1');
    p->set_value(7,7,'9');
    p->set_value(4,8,'2');
    p->set_value(5,8,'8');
    p->set_value(8,8,'4');

//    p->set_value(1, 2, '1');
//    p->set_value(2, 1, '5');

//    std::cout << "Initializer::get (1,2) = " << p->get_value(1, 2) << std::endl;

    return p;
}

Initializer::handle_type Initializer::create()
{
    return handle_type(new Initializer);
}
