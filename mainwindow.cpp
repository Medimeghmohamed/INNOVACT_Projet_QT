#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabproduit->setModel(tmpproduit.afficher());
      ui->tabproduitP->setModel(tmpproduitP.afficher());

}

void MainWindow::refresh()
{
  ui->tabproduit->setModel(tmpproduit.afficher());
  ui->comboBox_3->setModel(tmpproduit.afficher_list());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    int stock = ui->lineEdit_stock->text().toInt();
    int stockl = ui->lineEdit_stockl->text().toInt();
    int prixu = ui->lineEdit_prixu->text().toInt();
    QDate da = ui->dateEdit_3->date();
    QString dateP=da.toString();

  QString type = ui->lineEdit_type->text();





  Produit P(id,nom,stock,stockl,prixu,type,dateP);
  bool test=P.ajouter();
  if(test==true)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit ajouté.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpproduit.supprimer(id);
    if(test)
    {ui->tabproduit->setModel(tmpproduit.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int idP = ui->lineEdit_id_3->text().toInt();
    QString nomP= ui->lineEdit_nom_2->text();
    int stockP = ui->lineEdit_stock_2->text().toInt();
    int stocklP = ui->lineEdit_stockl_2->text().toInt();
    int prixuP = ui->lineEdit_prixu_2->text().toInt();
    QDate daP = ui->dateEdit->date();
    QString datePP=daP.toString();

  QString typeP = ui->lineEdit_type_2->text();
  int fn = ui->lineEdit_fn->text().toInt();
  int temp = ui->lineEdit_temp->text().toInt();
  QDate alert = ui->dateEdit_2->date();
  QString alertd=alert.toString();






  ProduitP PP(idP,nomP,stockP,stocklP,prixuP,typeP,datePP,fn,temp,alertd);
  bool test=PP.ajouter();
  if(test==true)
{ui->tabproduitP->setModel(tmpproduitP.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit ajouté.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_clicked()
{
    int cherch = ui->lineEdit_rech->text().toInt();
    ui->tabproduit->setModel(tmpproduit.recherche(cherch));

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabproduit->setModel(tmpproduit.triprix());

}


void MainWindow::on_pb_modifier_clicked()
{

}

void MainWindow::on_comboBox_3_activated(const int &arg1)
{ ui->comboBox_3->setModel(tmpproduit.afficher_list());
    tmpproduit.set_REF(arg1);
    tmpproduit.chercher();

    /*ui->lineEdit_nom_3->setText(tmpproduit.get_NAME());
    ui->lineEdit_stock_3->setText(QString::number(tmpproduit.get_STOCK()));
    ui->lineEdit_stockl_3->setText(QString::number(tmpproduit.get_STOCKL()));
    ui->lineEdit_prixu_3->setText(QString::number(tmpproduit.get_prixu()));
    ui->lineEdit_type_3->setText(tmpproduit.get_type());*/
    //refresh();

}
