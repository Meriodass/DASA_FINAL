#ifndef TEMP_H
#define TEMP_H

#include "sensor.h"

class Temp_Hum: public Sensor{
public:
    Temp_Hum():Sensor(2){}
    double temperatura() {return leerDato(0);}
    double humedad() { return leerDato(1);}
};

#endif // TEMP_H
