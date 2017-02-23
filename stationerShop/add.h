#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QFileInfo>

#include "mainwindow.h"
#include "constants.h"

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT
    
public:
    explicit Add(QWidget *parent = 0);
     QString category();
     void value();
     void connecttosql1();

     int index;
    ~Add();
    
private slots:
     void on_katBox_activated(const QString &arg1);

     void on_pushButton_2_clicked();

     void on_buttonBox_accepted();

private:
    Ui::Add *ui;
    QSqlDatabase db;
    QSqlQuery *qry1;
    QSqlQuery *qry;
    QSqlQueryModel *katM;
    QSqlQueryModel *model;
};

#endif // ADD_H



