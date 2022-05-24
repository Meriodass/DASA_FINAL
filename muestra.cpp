#include "Muestra.h"
#include <iostream>


Muestra::Muestra(double& lat, double& lon, double& alt, double& temp, double& hum, double& vel, double& dis, double& pre, double& ine) {
    setLatitud( lat );
    setLongitud( lon );
    setAltura ( alt );
    temperatura = temp;
    humedad = hum;
    velocidad = vel;
    distancia = dis;
    precipitacion = pre;
    intensidad = ine;
//    std::cout << "Muestra" << ": " <<  getLatitud() << ", " << getLongitud() << ", " << getAltura()  << ", " ;
//    std::cout << temperatura  << ", " << humedad << std::endl;
}

Muestra::Muestra(){
    temperatura = 0.;
    humedad = 0.;
    velocidad = 0.;
    distancia = 0.;
    precipitacion = 0.;
    intensidad = 0.;
}

void Muestra::getDatos(double &lat, double &lon, double &alt, double &temp, double &hum, double& vel, double& dis, double& pre, double& ine) {
    lat = getLatitud();
    lon = getLongitud();
    alt = getAltura();
    temp = temperatura;
    hum = humedad;
    vel = velocidad;
    dis = distancia;
    pre = precipitacion;
    ine = intensidad;
}

bool Muestra::setDatos(double &lat, double &lon, double &alt, double &temp, double &hum, double& vel, double& dis, double& pre, double& ine) {
    try{
        setLatitud( lat );
        setLongitud( lon );
        setAltura ( alt );
        temperatura = temp;
        humedad = hum;
        velocidad = vel;
        distancia = dis;
        precipitacion = pre;
        intensidad = ine;
        return true;
    }catch(...){
        return false;
    }
}


