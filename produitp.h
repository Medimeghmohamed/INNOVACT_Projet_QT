#ifndef PRODUITP_H
#define PRODUITP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class ProduitP
{
public:
    ProduitP();
    ProduitP(int,QString,int,int,int,QString,QString,int,int,QString);
     QString get_NAMEP();
      QString get_datealert();
      QString get_datePP();
       QString get_typeP();
    int get_STOCKP();
    int get_fn();
    int get_temp();
      int get_prixuP();
    int get_STOCKLP();
    int get_REFP();
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
 private:

     QString NAMEP,typeP,datePP,datealert;
     int REFP,STOCKP,STOCKLP,prixuP,temp,fn;
};

#endif // PRODUITP_H
