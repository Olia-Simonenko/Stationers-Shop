#include "postavka.h"
#include "ui_postavka.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

Postavka::Postavka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Postavka)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
}

Postavka::~Postavka()
{
    delete model;
    delete ui;
}

void Postavka::recieveData(QString id, QString name,QString kol1)
{
    ui->labelKod->setText(id);
    ui->labelName->setText(name);
    id2=id;
    name2=name;
    kol2=kol1;
}

void Postavka::on_ButtonKol_clicked()
{
    const QString PATH = QFileInfo(".").absolutePath() + "/stationerShop/DataBase/DataBase.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);

    db.open();
    QSqlQuery qry;
    int kol= ui->kolEdit->text().toInt();
    int kolvo=kol+kol2.toInt();
    qDebug()<<kolvo;
    qry.prepare("Update Товар set Количество=:kolvo where Код_товара=:id2 ;");
    qry.bindValue(":kolvo", kolvo);
    qry.bindValue(":id2", id2);
    qDebug()<<qry.exec();
    this->accept();
    QMessageBox::critical(this,"Поставка","Добавление успешно завершено!");
}
