#include <QtCore/QTimer>

#ifndef _SEGUIDOR_APP_H
#define _SEGUIDOR_APP_H

#include "DB_dasa.h"
#include "DB_remota.h"
#include "muestra.h"
#include "posicion.h"
#include <ctime>
#include <vector>


class DASA_app:QObject {
    Q_OBJECT
public:

Seguidor_app(std::time_t fecha, int hora, int minuto);

int ejecutar();
private:
    std::time_t fecha;
    int hora;
    int minuto;
    QTimer *timer1;
    QTimer *timer2;
    DB_dasa *base_datos;
    DB_remota *remota_Db;
    vector<Muestra> _datos;

    Seguidor_app();

    void adquirirDatos();

    bool almacenarDatoMin();

    bool almacenarDatoDia();

    double leerTemperatura();

    double leerHumedad();

    double leerVelocida();

    double leerDistancia();

    double leerPrecipitacion();

    double leerIntensidad();

    void leerGPS(Posicion& a);
private  slots:
    void cada5Seg(void);
    void cada24Horas(void);
};

#endif //_SEGUIDOR_APP_H
