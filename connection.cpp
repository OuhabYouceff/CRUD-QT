#include "connection.h"


Connection::Connection()
{

}


bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2a");//inserer le nom de la base de donnees
db.setUserName("youcef");//inserer nom de l'utilisateur
db.setPassword("youcef");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
