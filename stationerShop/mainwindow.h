#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include "prod.h"
#include "add.h"
#include "postavka.h"

#include "constants.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    void connectToSql();
    void refreshUi();
    QString toJson();
    ~MainWindow();

    /*QString id;
    double price=0.0;
    QString numCheque;
    int num;
    double chequesum =0.0;
    QString idCheque;
    int kolvo;
    int count=0;
    int kol=0;
    QString kol1;
    double sum=0.0;
    double summ=0.0;
    QString name;*/

signals:
    void sendData(QString id, QString name,QString kol1 );

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_action_triggered();

    void on_addCheque_clicked();

    void on_productView_activated(const QModelIndex &index);

    void on_chequeView_activated(const QModelIndex &index);

    void on_delCheque_clicked();

    void on_action_2_triggered();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_saveCheque_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;
    QSqlQueryModel *model6;
    QSqlQueryModel *chequeM;
    QSqlQueryModel *cheqM;
    QSqlQuery *qry;

    QSqlQueryModel *katM;
    Postavka *post;

    Prod prod;
    constants constant;

};

#endif // MAINWINDOW_H
