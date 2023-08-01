#ifndef SERVICES_H
#define SERVICES_H
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class Services
{
public:
    Services();
    Services(int,QString,QString,QString,QString );

       int getid();
       QString getnom();
       QString gettype();
       QString getduree();
       QString getdate();

       void setid(int);
       void setnom(QString);
       void settype(QString);
       void setduree(QString);
       void setdate(QString);
       bool ajouter();
       bool supprimer(int);
       bool update();
      QSqlQueryModel* afficher();
      QSqlQueryModel* search_emission(QString  ,QString );
      QSqlQueryModel* afficher_emission(QString order);
      QSqlQueryModel *afficher_calendar(QString x);
   private:
       int ID_SERVICE;
       QString NOM_SERVICE,TYPE_SERVICE,DUREE_SERVICE,DATE_SERVICE;
};
#endif // SERVICES_H
