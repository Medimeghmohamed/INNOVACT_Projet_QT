#include "produitp.h"

ProduitP::ProduitP()
{

}
ProduitP::ProduitP(int REFP,QString NAMEP,int STOCKP,int STOCKLP,int prixuP,QString typeP,QString datePP,int fn,int temp,QString datealert)
{
  this->REFP=REFP;
  this->NAMEP=NAMEP;
  this->STOCKP=STOCKP;
   this->STOCKLP=STOCKLP;
     this->prixuP=prixuP;
     this->typeP=typeP;
     this->datePP=datePP;
    this->fn=fn;
    this->datealert=datealert;
    this->temp=temp;

}
QString ProduitP::get_NAMEP(){return  NAMEP;}
QString ProduitP::get_typeP(){return  typeP;}
QString ProduitP::get_datePP(){return  datePP;}
QString ProduitP::get_datealert(){return  datealert;}

int ProduitP::get_STOCKP(){return STOCKP;}
int ProduitP::get_REFP(){return  REFP;}
int ProduitP::get_STOCKLP(){return STOCKLP;}
int ProduitP::get_prixuP(){return  prixuP;}
int ProduitP::get_fn(){return  fn;}
int ProduitP::get_temp(){return  temp;}

bool ProduitP::ajouter()
{
QSqlQuery query;
QString res= QString::number(REFP);
query.prepare("INSERT INTO produitP (REFP, NAMEP,STOCKP,STOCKLP,prixuP,typeP,datePP,fn,temp,datealert) "
                    "VALUES (:REFP, :NAMEP, :STOCKP, :STOCKLP,:prixuP,:typeP,:datePP,:fn,:temp,:datealert)");
query.bindValue(":REFP", res);
query.bindValue(":NAMEP", NAMEP);
query.bindValue(":STOCKP", STOCKP);
query.bindValue(":STOCKLP", STOCKLP);
query.bindValue(":prixuP", prixuP);
query.bindValue(":typeP", typeP);
query.bindValue(":datePP", datePP);
query.bindValue(":fn", fn);
query.bindValue(":temp", temp);
query.bindValue(":datealert", datealert);





return    query.exec();
}

QSqlQueryModel * ProduitP::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produitP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAMEP "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCKP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STOCKLP"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prixuP"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("typeP"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("datePP"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("fn"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("temp"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datealert"));


    return model;
}

bool ProduitP::supprimer(int REFF)
{
QSqlQuery query;
QString res= QString::number(REFF);
query.prepare("Delete from produitP where REFP = :REFP ");
query.bindValue(":REFP", res);
return    query.exec();
}

