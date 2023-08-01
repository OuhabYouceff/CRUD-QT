#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{
    int ID_SERVICE=ui->add_emission_id->text().toInt();
    QString NOM_SERVICE=ui->add_emission_name->text();


    QString TYPE_SERVICE;
    QString DUREE_SERVICE;


    if(ui->add_emission_type_fun->isChecked())
    {
     TYPE_SERVICE="fun";
    }
    else if(ui->add_emission_type_info->isChecked())
    {
     TYPE_SERVICE="info";
    }
    else if(ui->add_emission_type_sport->isChecked())
    {
    TYPE_SERVICE="sport";
    }


    if(ui->add_emission_duration_5->isChecked())
    {
     DUREE_SERVICE="5mn";
    }
    else if(ui->add_emission_duration_10->isChecked())
    {
     DUREE_SERVICE="10mn";
    }
    else if(ui->add_emission_duration_15->isChecked())
    {
     DUREE_SERVICE="15mn";
    }

    QDate date = ui->dateTimeEdit->date();
    QString DATE_SERVICE = date.toString();


  Services S(ID_SERVICE,NOM_SERVICE,TYPE_SERVICE,DUREE_SERVICE,DATE_SERVICE);


  bool test=S.ajouter();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("ajout effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->add_emission_id->setText("");
           ui->add_emission_name->setText("");
          ui->tableView_emission->setModel(S.afficher());

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("ajout non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



        ui->add_emission_id->setText("");
        ui->add_emission_name->setText("");
}

void MainWindow::on_delete_emission_clicked()
{
    Services S;

        S.setid (ui->lineEdit_8->text().toInt());

        bool test=S.supprimer(S.getid());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_emission->setModel(S.afficher());

    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
        ui->lineEdit_8->setText("");
}

void MainWindow::on_pushButton_update_clicked()
{
    int ID_SERVICE=ui->update_id->text().toInt();
    QString NOM_SERVICE=ui->update_emission_name->text();

    QString TYPE_SERVICE;
    QString DUREE_SERVICE;


    if(ui->update_fun->isChecked())
    {
     TYPE_SERVICE="fun";
    }
    else if(ui->update_info->isChecked())
    {
     TYPE_SERVICE="info";
    }
    else if(ui->update_sport->isChecked())
    {
    TYPE_SERVICE="sport";
    }


    if(ui->update_duration_5->isChecked())
    {
     DUREE_SERVICE="5mn";
    }
    else if(ui->update_duration_10->isChecked())
    {
     DUREE_SERVICE="10mn";
    }
    else if(ui->update_duration_15->isChecked())
    {
     DUREE_SERVICE="15mn";
    }

    QDate date = ui->dateTimeEdit_2->date();
    QString DATE_SERVICE = date.toString();


  Services S(ID_SERVICE,NOM_SERVICE,TYPE_SERVICE,DUREE_SERVICE,DATE_SERVICE);

  bool test=S.update();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("update effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_emission->setModel(S.afficher());
   }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("update non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }

       ui->update_id->setText("");
       ui->update_emission_name->setText("");

}
