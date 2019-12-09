#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSystemTrayIcon>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Produit
{public:
    Produit();
   Produit(int,QString,int,int,int,QString,QString);
    QString get_NAME();
     QString get_dateP();
      QString get_type();
   int get_STOCK();
     int get_prixu();
   int get_STOCKL();
   int get_REF();
    bool ajouter();

    void set_NAME(QString );
    void set_type(QString );
    void set_STOCK(int );
    void set_REF(int );
    void set_STOCKL(int );
    void set_prixu(int );
    void set_dateP(QString);




    QSqlQueryModel * afficher();
    bool supprimer(int);
    void chercher();
    void notification_sup_produit(int id);

    bool modifierproduit(Produit);
     QSqlQueryModel * triprix();
    QSqlQueryModel * recherche(int);
    QSqlQueryModel *  afficher_list();
    bool modifier_produit(Produit);
private:

    QString NAME,type,dateP;
    int REF,STOCK,STOCKL,prixu;
};

#endif // PRODUIT_H
