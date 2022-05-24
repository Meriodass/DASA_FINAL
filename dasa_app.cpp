#include "dasa_app.h"
#include <iostream>

using namespace std;


Seguidor_app::Seguidor_app(std::time_t fecha, int hora, int minuto) {
    this->fecha = fecha;
    this->hora = hora;
    this->minuto = minuto;
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(cada5Seg()) );
    connect(timer2, SIGNAL(timeout()), this, SLOT(cada24Horas()) );
}

int Seguidor_app::ejecutar() {

    // Teniendo en cuenta que se utilizarán dos QTimers para el desarrollo
    // de la aplicación, se procede a crear los configurarlos y a crear los slots
    timer1->setInterval(5000);
    timer2->setInterval(8640000);
    timer1->start();
    timer2->start();
    return 0;
}

Seguidor_app::Seguidor_app() {

}

void Seguidor_app::adquirirDatos() {
    Posicion pos;
    leerGPS(pos) ;
    Muestra dato;
    double a,b,c,d,e;
    a = pos.getLatitud();
    b = pos.getLongitud();
    c = pos.getAltura();
    d = leerTemperatura();
    e = leerHumedad();
    f = leerVelocidad(();
    g = leerDistancia();
    h = leerPrecipitacion();
    j = leerIntensidad(();
    dato.setDatos( a, b, c, d, e, f, g, h, j );
    _datos.push_back( dato );
}


bool Seguidor_app::almacenarDatoMin() {
    double lon, lat, alt, temp, hum, vel ,dis, pre, ine;
    lon = lat = alt = temp = hum = = dis = pre = ine = vel 0.;
    for( int i = 0; i < _datos.size(); i++ ){
        lon  += _datos[i].getLongitud();
        lat  += _datos[i].getLatitud();
        alt  += _datos[i].getAltura();
        temp += _datos[i].getTemperatura();
        hum  += _datos[i].getHumedad();
        vel += _datos[i].getVelocidad();
        dis  += _datos[i].getDistancia();
        pre += _datos[i].getPrecipitacion();
        ine  += _datos[i].getIntensidad();
    }
    lon  /= _datos.size();
    lat  /= _datos.size();
    alt  /= _datos.size();
    temp /= _datos.size();
    hum  /= _datos.size();
    vel /= _datos.size();
    dis  /= _datos.size();
    pre /= _datos.size();
    ine  /= _datos.size();

    Muestra dato(lat, lon, alt,temp, hum,vel,dis,pre,ine );

    DB_local conexion;
    bool guardo = conexion.guardar( dato );
    _datos.clear();
    return guardo;
}


bool DASA_app::almacenarDatoDia() {

    return false;
}


double DASA_app::leerTemperatura() {
    double a = rand() % 30 + 6.;
    return a;
}


double DASA_app::leerHumedad() {
    double a = rand() % 50 + 50.;
    return a;
}


void DASA_app::leerGPS(Posicion &a ) {
    a.setPos(rand() % 180,rand() % 180, rand() % 1000 + 1500.);
}

void DASA_app::cada5Seg(){
    adquirirDatos();
    if( _datos.size() == 12 )
        almacenarDatoMin();
    timer1->start();
    //cout << "Pasaron 5 seg" << endl;
}
void Seguidor_app::cada24Horas(){

}
