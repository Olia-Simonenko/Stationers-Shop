#ifndef ADDTOV_H
#define ADDTOV_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

//#include "mainwindow.h"

namespace Ui {
class addTov;
}

class addTov : public QWidget
{
    Q_OBJECT
    
public:
    explicit addTov(QWidget *parent = 0);
    void connecttosql1();
    QString category();
    void dialog();
    int index;
    ~addTov();
    
private slots:
    void on_pushButton_clicked();

    void on_katBox_activated(const QString &arg1);

private:
    Ui::addTov *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;

    QSqlQueryModel *katM;
    QSqlQuery *qry;
    QSqlQuery *qry1;
};

#endif // ADDTOV_H
