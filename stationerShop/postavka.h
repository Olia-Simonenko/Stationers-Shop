#ifndef POSTAVKA_H
#define POSTAVKA_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFileInfo>

#include "constants.h"

namespace Ui {
class Postavka;
}

class Postavka : public QDialog
{
    Q_OBJECT
    
public:
    explicit Postavka(QWidget *parent = 0);

    ~Postavka();
    
public slots:
    void recieveData(QString id, QString name,QString kol1);

private slots:
    void on_ButtonKol_clicked();

private:
    Ui::Postavka *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QString kol2;
    QString id2;
    QString name2;
};

#endif // POSTAVKA_H
