#ifndef DB_DASA_H
#define DB_DASA_H


#include "Muestra.h"
#include <string>
#include <sqlite3.h>

using namespace std;
class DB_dasa {
public:

DB_dasa();

DB_dasa(string path);

     bool guardar(Muestra& dato);

     Muestra getPromHora(int hora);

     bool vaciarDB();

     void getUltimoMin(Muestra& dato);

     string getUsuarioRemoto();
     string getHostRemoto();
     string getDBNameRemoto();
     string getPassWDRemoto();

private:
    string path;
    sqlite3 *database;

bool crearDB();

static int recuperar(void *data, int argc, char **argv, char **azColName);
};

#endif // DB_DASA_H
