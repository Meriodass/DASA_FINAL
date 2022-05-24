#ifndef NITRO_H
#define NITRO_H

#include "sensor.h"

class Nitro: public Sensor{
public:
    Nitro():Sensor(2){}
    double NiO(){return leerDato(0);}
    double NiO2(){return leerDato(1);}
};

#endif // NITRO_H
