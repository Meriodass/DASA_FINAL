#include "ventppal.h"
#include "ui_ventppal.h"
#include <QString>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

int cont = 0;
ventppal::ventppal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventppal)
{
    ui->setupUi(this);
    ui->visibilidad->setText("Visible");
    ui->visibilidad->setVisible("false");
    visibilidad();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->start(1000);



    /*QSqlDatabase myDb = QSqlDatabase::addDatabase ("QSQLITE");
    myDb.setDatabaseName("/home/daniruiz11/Proyecto_Final/Qt/Proyecto_Final/DASA.db");

    if(!myDb.open())
        ui->label->setText("Failed to open the database");
        else
        ui->label->setText("connected");

*/
}
ventppal::~ventppal()
{
    delete ui;
}

ventppal::ventppal(QString _USUARIO, QString _CONTRA,QString _NOMBRE, QString _APELLIDO, QString _DOCUMENTO, QString _NACIMIENTO){
USUARIO=_USUARIO;
CONTRA=_CONTRA;
NOMBRE=_NOMBRE;
APELLIDO=_APELLIDO;
DOCUMENTO=_DOCUMENTO;
NACIMIENTO=_NACIMIENTO;
}
void ventppal::visibilidad(){
    if (ui->visibilidad->text()== "Visible"){
    ui->boton_atras->setVisible(false);
    ui->label_2->setVisible(false);
    ui->nombre_texto->setVisible(false);
    ui->Apellido_texto->setVisible(false);
    ui->documento_texto->setVisible(false);
    ui->Nacimiento_texto->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);
    ui->Contra_txt->setVisible(true);
    ui->Usuario_txt->setVisible(true);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->Agregar_boton->setVisible(false);
    ui->boton_sesion->setVisible(true);
    ui->label_12->setVisible(true);
    ui->label_13->setVisible(true);
    ui->Contra_text->setVisible(false);
    ui->Usuario_text->setVisible(false);
    ui->Color_humedad->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->Color_temperatura->setVisible(true);
    ui->groupBox->setVisible(true);
    ui->label_14->setVisible(true);
    ui->visibilidad->setVisible("false");
} else  if (ui->visibilidad->text()== "NOVisible"){
        ui->boton_atras->setVisible(true);
        ui->label_2->setVisible(true);
        ui->nombre_texto->setVisible(true);
        ui->Apellido_texto->setVisible(true);
        ui->documento_texto->setVisible(true);
        ui->Nacimiento_texto->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_8->setVisible(true);
        ui->label_9->setVisible(true);
        ui->Contra_txt->setVisible(false);
        ui->Usuario_txt->setVisible(false);
        ui->label_10->setVisible(true);
        ui->label_11->setVisible(true);
        ui->Agregar_boton->setVisible(true);
        ui->boton_sesion->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_13->setVisible(false);
        ui->Contra_text->setVisible(true);
        ui->Usuario_text->setVisible(true);
        ui->Color_humedad->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->Color_temperatura->setVisible(false);
        ui->groupBox->setVisible(false);
        ui->label_14->setVisible(false);
        ui->visibilidad->setVisible("false");

    }
}
void ventppal::Actualizar(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_15->setText(time_text);
    cont = cont+1;
    QString conta = QString::number(cont);
    //ui->label_16->setText(conta);
    if (cont==10){
            cont=0;
            UltimoDato();


}


}
void ventppal::UltimoDato(){
 readValues();
}

void ventppal::on_pushButton_clicked()
{
   // ventppal agregar("usu","adfa","asd","asdf","asdf","asdf");
   // ui->label->setText(USUARIO);
}
void ventppal::addValues(){
    qDebug()<<"start";
    BASE = QSqlDatabase::addDatabase("QSQLITE");
    BASE.setDatabaseName("/home/daniruiz11/Proyecto_Final/Qt/Proyecto_Final/DASA.db");
    BASE.open();
    if(!BASE.open()){
        qDebug()<<"Error de base de datos"; }else{
        ui->label->setText("connected ADD");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO testable(USUARIO, CONTRA, NOMBRE, APELLIDO, DOCUMENTO, NACIMIENTO)"
                   "VALUES (:USUARIO, :CONTRA, :NOMBRE, :APELLIDO, :DOCUMENTO, :NACIMIENTO)");
                    query.bindValue(":USUARIO", ui->Usuario_text->text());
                    query.bindValue(":CONTRA", ui->Contra_text->text());
                    query.bindValue(":NOMBRE", ui->nombre_texto->text());
                    query.bindValue(":APELLIDO", ui->Apellido_texto->text());
                    query.bindValue(":DOCUMENTO", ui->documento_texto->text());
                    query.bindValue(":NACIMIENTO", ui->Nacimiento_texto->text());
                    query.exec();
    /*QSqlDatabase db;
     *
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/daniruiz11/Proyecto_Final/Qt/Proyecto_Final/DASA.db");
    if(!db.open()){
        qDebug()<<"Error de base de datos"; }else{
        //ui->label->setText("connected");
        qDebug()<<"entrada";
    }


 QString query = "CREATE TABLE testable("
                    "USUARIO VARCHAR (20),"
                    "CONTRA VARCHAR(20),"
                    "NOMBRE VARCHAR (20),"
                    "APELLIDO VARCHAR(20),"
                    "DOCUMENTO VARCHAR (20),"
                    "NACIMIENTO VARCHAR(20);";
    QSqlQuery qry;
    if(!qry.exec(query))
    {
        qDebug()<<"Error creando tabla";
    }

        qry.prepare("INSERT INTO testable("
                    "USUARIO,"
                    "CONTRA,"
                    "NOMBRE,"
                    "APELLIDO,"
                    "DOCUMENTO,"
                    "NACIMIENTO)"
                    "VALUES (?,?,?,?,?,?);");
        qry.addBindValue((USUARIO));
        qry.addBindValue((CONTRA));
        qry.addBindValue((NOMBRE));
        qry.addBindValue((APELLIDO));
        qry.addBindValue((DOCUMENTO));
        qry.addBindValue((NACIMIENTO));

        db.close();*/
   ui->Usuario_text->setText("");
   ui->Contra_text->setText("");
   ui->nombre_texto->setText("");
   ui->Apellido_texto->setText("");
   ui->documento_texto->setText("");
   ui->Nacimiento_texto->setText("");
   BASE.close();
   QMessageBox::information(this,tr("CORRECTO"),tr ("NUEVO USUARIO AGREGADO"));
}

void ventppal::readValues(){
    BASE = QSqlDatabase::addDatabase("QSQLITE");
    BASE.setDatabaseName("/home/daniruiz11/Proyecto_Final/Qt/Proyecto_Final/DASA.db");
    BASE.open();
    if(!BASE.open()){
        qDebug()<<"Error de base de datos"; }else{
        ui->label->setText("connected ADD");
    }
    QSqlQuery query;
    query.exec("Select USUARIO, CONTRA from testable");
               while(query.next()){
                   QString USU = query.value(0).toString();
                   QString CONTRA = query.value(1).toString();
     // qDebug()<<USU<<CONTRA;
      if (ui->Usuario_txt->text()== USU && ui->Contra_txt->text()==CONTRA){
          ui->visibilidad->setText("NOVisible");
          visibilidad();
      }
      }
      query.exec("Select TEMPERATURA, HUMEDAD, VELOCIDAD, VIENTO, PRECIPITACION, LUZ from Sensores");
                 query.last();{
                     QString TEMPERATURA = query.value(0).toString();
                     QString HUMEDAD = query.value(1).toString();
                     QString VELOCIDAD = query.value(2).toString();
                     QString VIENTO = query.value(3).toString();
                     QString PRECIPITACION = query.value(4).toString();
                     QString LUZ = query.value(5).toString();
        //qDebug()<<TEMPERATURA<<HUMEDAD<<VELOCIDAD<<VIENTO<<PRECIPITACION<<LUZ;
          ui->label_16->setText("TEMPERATURA DE "+TEMPERATURA+" HUMEDAD DE "+HUMEDAD+" VELOCIDAD "+VELOCIDAD+" VIENTO "+VIENTO+" PRECIPITACION "+PRECIPITACION+" LUZ " + LUZ);
          int TEMPERATURAI  = TEMPERATURA.toInt();
          if (TEMPERATURAI<=0){
              ui->Color_temperatura->setStyleSheet("background-color:red;");
          } else if (TEMPERATURAI>0 && TEMPERATURAI<=30){
              ui->Color_temperatura->setStyleSheet("background-color:yellow;");
          }else if (TEMPERATURAI>31 && TEMPERATURAI<=45){
              ui->Color_temperatura->setStyleSheet("background-color:green;");
          }
          int HUMEDADI = HUMEDAD.toInt();
          if (HUMEDADI>0 && HUMEDADI<=20){
              ui->Color_humedad->setStyleSheet("background-color:red;");
          } else if (HUMEDADI>20 && HUMEDADI<=50){
              ui->Color_humedad->setStyleSheet("background-color:yellow;");
          }else if (HUMEDADI>50 && HUMEDADI<=100){
              ui->Color_humedad->setStyleSheet("background-color:green;");
          }
                 }

BASE.close();
}

void ventppal::on_Agregar_boton_clicked()
{
    if (ui->Usuario_text->text()== "" or ui->Contra_text->text()== "" or ui->nombre_texto->text()== "" or ui->Apellido_texto->text()== "" or ui->documento_texto->text()== "" or ui->Nacimiento_texto->text()== ""){
        QMessageBox::information(this,tr("ERROR"),tr ("ES NECESARIO LLENAR TODOS LOS DATOS PARA CONTINUAR"));
    }
        else{
     addValues();
    ui->visibilidad->setText("Visible");
    visibilidad();
       }
 }

void ventppal::on_boton_atras_clicked()
{
    ui->visibilidad->setText("Visible");
    visibilidad();
}

void ventppal::on_boton_sesion_clicked()
{
    readValues();
    ui->Usuario_txt->setText("");
    ui->Contra_txt->setText("");
}

void ventppal::on_actionPROBAR_triggered()
{
    BASE = QSqlDatabase::addDatabase("QSQLITE");
    BASE.setDatabaseName("/home/daniruiz11/Proyecto_Final/Qt/Proyecto_Final/DASA.db");
    BASE.open();
    if(!BASE.open()){
        QMessageBox::information(this,tr("ERROR"),tr ("BASE DE DATOS FUERA DEL LINK")); }else{
       QMessageBox::information(this,tr("EXCELENTE"),tr ("Vamos a pasar"));
    }
    BASE.close();
}
