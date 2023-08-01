#include "services.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>
Services::Services()
{
    ID_SERVICE=0;
    NOM_SERVICE="";
    TYPE_SERVICE="";
    DUREE_SERVICE="";
    DATE_SERVICE="";
}


Services::Services(int ID_SERVICE,QString NOM_SERVICE,QString TYPE_SERVICE,QString DUREE_SERVICE ,QString DATE_SERVICE )
{
    this->ID_SERVICE=ID_SERVICE;
    this->NOM_SERVICE=NOM_SERVICE;
    this->TYPE_SERVICE=TYPE_SERVICE;
    this->DUREE_SERVICE=DUREE_SERVICE;
    this->DATE_SERVICE=DATE_SERVICE;

}

int Services::getid(){return ID_SERVICE;}
QString Services::getnom(){return NOM_SERVICE;}
QString Services::gettype(){return TYPE_SERVICE;}
QString Services::getduree(){return DUREE_SERVICE;}
QString Services::getdate(){return DATE_SERVICE;}

void Services::setid(int ID_SERVICE){ this->ID_SERVICE=ID_SERVICE;}
void Services::setnom(QString NOM_SERVICE){this->NOM_SERVICE=NOM_SERVICE;}
void Services::settype(QString TYPE_SERVICE){this->TYPE_SERVICE=TYPE_SERVICE;}
void Services::setduree(QString DUREE_SERVICE){this->DUREE_SERVICE=DUREE_SERVICE;}
void Services::setdate(QString DATE_SERVICE){this->DATE_SERVICE=DATE_SERVICE;}


bool Services::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(ID_SERVICE);
          query.prepare("INSERT INTO SERVICES (ID_SERVICE,NOM_SERVICE,TYPE_SERVICE,DUREE_SERVICE,DATE_SERVICE) "
                        "VALUES (:ID_SERVICE, :NOM_SERVICE, :TYPE_SERVICE,:DUREE_SERVICE,:DATE_SERVICE)");

          query.bindValue(":ID_SERVICE", id_string);
          query.bindValue(":NOM_SERVICE", NOM_SERVICE);
          query.bindValue(":TYPE_SERVICE", TYPE_SERVICE);
           query.bindValue(":DUREE_SERVICE", DUREE_SERVICE);
            query.bindValue(":DATE_SERVICE", DATE_SERVICE);

         return query.exec();



}

bool Services::supprimer(int ID_SERVICE)
{
    QSqlQuery query;
          query.prepare("Delete from SERVICES where ID_SERVICE=:ID_SERVICE");
          query.bindValue(0, ID_SERVICE);
          return  query.exec();
}




QSqlQueryModel* Services::afficher()
{
         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT*  FROM SERVICES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DURATION"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));



    return model;

}

bool Services::update(){
    QSqlQuery query;
      QString id_string=QString::number(ID_SERVICE);

      query.prepare( "UPDATE emissions SET ID_SERVICE=:ID_SERVICE , NOM_SERVICE=:NOM_SERVICE ,"
                     " TYPE_SERVICE=:TYPE_SERVICE , DATE_SERVICE=:DATE_SERVICE ,DUREE_SERVICE=:DUREE_SERVICE WHERE ID_SERVICE=:ID_SERVICE ");

   query.bindValue(":ID_SERVICE",id_string);
   query.bindValue(":NOM_SERVICE",NOM_SERVICE);
   query.bindValue(":TYPE_SERVICE",TYPE_SERVICE);
   query.bindValue(":DUREE_SERVICE",DUREE_SERVICE);
   query.bindValue(":DATE_SERVICE",DATE_SERVICE);


return query.exec();
}

