#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"

#include "produitp.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void refresh();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pb_modifier_clicked();

     void on_comboBox_3_activated(const int &arg1);

private:
    Ui::MainWindow *ui;

    Produit tmpproduit;ProduitP tmpproduitP;

};
#endif // MAINWINDOW_H
