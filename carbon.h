#ifndef CARBON_H
#define CARBON_H

#include "sensor.h"

class Carbon: public Sensor{
public:
    Carbon():Sensor(3){}
    double C_Measure(){return leerDato(0);}
    double CO2_Measure(){return leerDato(2);}
    double CO_Measure(){return leerDato(1);}
};

#endif // CARBON_H
