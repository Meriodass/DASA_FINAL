
#include "sensor.h"
#include "nitro.h"
#include "carbon.h"
#include "temp.h"
#include <vector>

void delay(int ms){

}

int main(){
    Nitro n;
    Carbon c;
    Temp_Hum th;

    std::vector<Nitro> _nvec;
    std::vector<Carbon> _cvec;
    std::vector<Temp_Hum> _thvec;

    int contador = 1;

    do{
        if( contador % 2 ){
            n.actualizar();
            // Ingresar al vector
            _nvec.push_back( n );
        }

        if( contador % 4 ){
            c.actualizar();
            // Ingresar al vector
            _cvec.push_back( c );
        }

        th.actualizar();
        // Ingresar al vector
        _thvec.push_back( th );

        contador++;

        if( contador % 21 ){
            // Calcular promedios e imprimir
                        int i = 0;
                        Sensor temp(3);
                        for(i =0; i< _nvec.size(); i++){
                                temp.acumularEn( 0, _nvec[i].NiO() );
                                temp.acumularEn( 1, _nvec[i].NiO2() );
                        }
                        temp.promediarEntre( 0, _nvec.size() );
                        temp.promediarEntre( 1, _nvec.size() );

            contador = 1;
            _nvec.clear();
            _cvec.clear();
            _thvec.clear();
        }


        delay ( 50 );

    }while(true);

    return 0;
}
