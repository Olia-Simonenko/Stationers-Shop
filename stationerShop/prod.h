#ifndef PROD_H
#define PROD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include "constants.h"

namespace Ui {
class Prod;
}

class Prod : public QWidget
{
    Q_OBJECT
    
public:
    explicit Prod(QWidget *parent = 0);
    void connectSql2();
    void refreshChequeList();
    ~Prod();
    
private slots:
    void on_ChequeView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Prod *ui;

    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model6;
    QSqlQueryModel *prodM;
    QSqlQuery *qry;
    QSqlQuery *qry1;
    QSqlQuery *qry2;
    QSqlQuery *qry3;
};

#endif // PROD_H
