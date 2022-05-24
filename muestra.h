#include "Posicion.h"

#ifndef _MUESTRA_H
#define _MUESTRA_H

class Muestra: public Posicion {
public:


Muestra(double& lat, double& lon, double& alt, double& temp, double& hum, double& vel, double& dis, double& pre, double& ine);

Muestra();

void getDatos(double& lat, double& lon, double& alt, double& temp, double& hum, double& vel, double& dis, double& pre, double& ine);


bool setDatos(double& lat, double& lon, double& alt, double& temp, double& hum, double& vel, double& dis, double& pre, double& ine);

double  getTemperatura(){return temperatura;}
void    setTemperatura(double temp){temperatura = temp;}
double  getHumedad(){return humedad;}
void    setHumedad(double hum){humedad = hum;}
double  getVelocidad(){return velocidad;}
void    setVelocidad(double vel){velocidad = vel;}
double  getDistancia(){return distancia;}
void    setDistancia(double dis){distancia = dis;}
double  getPrecipitacion(){return precipitacion;}
void    setPrecipitacion(double pre){precipitacion = pre;}
double  getIntensidad(){return intensidad;}
void    setIntensidad(double ine){intensidad = ine;}
//void operator=(Muestra& a){setLatitud( a.getLatitud() );
//                           setLongitud( a.getLongitud() );
//                           setAltura( a.getAltura() );
//                           temperatura= a.temperatura;
//                           humedad = a.humedad;}
private:
    double      temperatura;
    double      humedad;
    double      distancia;
    double      velocidad;
    double      precipitacion;
    double      intensidad;

};

#endif //_MUESTRA_H
