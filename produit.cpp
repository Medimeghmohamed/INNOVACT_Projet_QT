#include "produit.h"

Produit::Produit()
{

}
Produit::Produit(int REF,QString NAME,int STOCK,int STOCKL,int prixu,QString type,QString dateP)
{
  this->REF=REF;
  this->NAME=NAME;
  this->STOCK=STOCK;
   this->STOCKL=STOCKL;
     this->prixu=prixu;
     this->type=type;
     this->dateP=dateP;

}
QString Produit::get_NAME(){return  NAME;}
QString Produit::get_type(){return  type;}
QString Produit::get_dateP(){return  dateP;}
int Produit::get_STOCK(){return STOCK;}
int Produit::get_REF(){return  REF;}
int Produit::get_STOCKL(){return STOCKL;}
int Produit::get_prixu(){return  prixu;}


void Produit::set_NAME(QString n){NAME=n;}
void Produit::set_type(QString t){  type=t;}
void Produit::set_dateP(QString d){ dateP=d;}
void Produit::set_STOCK(int S){STOCK=S;}
void Produit::set_REF(int R){REF=R;}
void Produit::set_STOCKL(int SL){STOCKL=SL;}
void Produit::set_prixu(int P){prixu=P;}














bool Produit::ajouter()
{
QSqlQuery query;
QString res= QString::number(REF);
query.prepare("INSERT INTO produit (REF, NAME,STOCK,STOCKL,prixu,type,dateP) "
                    "VALUES (:REF, :NAME, :STOCK, :STOCKL,:prixu,:type,:dateP)");
query.bindValue(":REF", res);
query.bindValue(":NAME", NAME);
query.bindValue(":STOCK", STOCK);
query.bindValue(":STOCKL", STOCKL);
query.bindValue(":prixu", prixu);
query.bindValue(":type", type);
query.bindValue(":date", dateP);

return    query.exec();
}

QSqlQueryModel * Produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STOCKL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prixu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("dateP"));




    return model;
}

bool Produit::supprimer(int REFF)
{
QSqlQuery query;
QString res= QString::number(REFF);
query.prepare("Delete from produit where REF = :REF ");
query.bindValue(":REF", res);
return    query.exec();
}


QSqlQueryModel * Produit:: recherche(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from Produit where REF= ? ");
    query.addBindValue(id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STOCKL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prixu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("dateP"));


    return model;
}



QSqlQueryModel *Produit::triprix()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from Produit ORDER BY prixu");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STOCKL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prixu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("dateP"));

    return model;

}

bool Produit::modifierproduit()
{      QSqlQuery query;

       query.prepare("update Produit set NAME=:NAME,STOCK=:STOCK,STOCKL=:STOCKL,prixu=:prixu,type=:type,dateP=:dateP where REF=:REF");
       query.bindValue(":REF",REF);
       query.bindValue(":NAME",NAME);
       query.bindValue(":STOCK",STOCK);
       query.bindValue(":STOCKL", STOCKL);
       query.bindValue(":prixu", prixu);
       query.bindValue(":type", type);
       query.bindValue(":dateP", dateP);


       return    query.exec();

}
QSqlQueryModel * Produit:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select REF from produit");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));


            return model;
}

void Produit:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT NAME,STOCK,STOCKL,prixu,type,dateP FROM produit WHERE REF =:REF");
     query1.bindValue(":REF",REF);
     query1.exec();
     while(query1.next())
     {
    NAME = query1.value(0).toString();
     STOCK = query1.value(0).toInt();
     STOCKL = query1.value(0).toInt();
      prixu = query1.value(2).toInt();
     type = query1.value(0).toString();
     prixu = query1.value(2).toInt();
     dateP = query1.value(0).toString();
     }

}
