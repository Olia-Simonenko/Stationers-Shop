#include "prod.h"
#include "ui_prod.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QDate>

#include <QFileInfo>
#include <QDir>

Prod::Prod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Prod)
{
    ui->setupUi(this);

    model = new QSqlQueryModel;
    model1 = new QSqlQueryModel;
    prodM = new QSqlQueryModel;

    model6 = new QSqlQueryModel;

    connectSql2();
}

void Prod::connectSql2()
{
    const QString PATH = QFileInfo(".").absolutePath() + "/stationerShop/DataBase/DataBase.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);

    if(db.open()){

        qry1 = new QSqlQuery(db);
        qry1->prepare("Select * from Чек;");
        qry1->exec();
        model1->setQuery(*qry1);
        ui->ChequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model1->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model1->setHeaderData(1,Qt::Horizontal,tr(" Дата "));
        model1->setHeaderData(2,Qt::Horizontal,tr(" Сумма(грн) "));
        ui->ChequeView->setModel(model1);

        qry = new QSqlQuery(db);
        qry->prepare("Select Товар.Название,Продажи.Количество,Продажи.Цена_продажи from Товар INNER JOIN Продажи ON Товар.Код_товара = Продажи.Код_товара;");
        qry->exec();
        model->setQuery(*qry);
        ui->SaleView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0,Qt::Horizontal,tr(" Название "));
        model->setHeaderData(1,Qt::Horizontal,tr(" Количество "));
        model->setHeaderData(2,Qt::Horizontal,tr(" Цена "));
        ui->SaleView->setModel(model);
    } else {
        QMessageBox::critical(this,"Error",model->lastError().text());
    }
    db.close();
}

void Prod::refreshChequeList()
{
    qry1 = new QSqlQuery(db);
    qry1->prepare("Select * from Чек;");
    qry1->exec();
    model1->setQuery(*qry1);
}

Prod::~Prod()
{
    delete ui;
    delete model;
    delete model1;
    delete model6;
    delete qry;
    delete qry1;
    delete qry2;
    delete qry3;
}

void Prod::on_ChequeView_activated(const QModelIndex &index)
{
    //db.open();
    QString value=ui->ChequeView->model()->data(index).toString();
    QSqlQuery query;
    query.exec("Select * from Чек where Код_чека = '" +value+ "'");
    QSqlRecord record=query.record();
    if(!query.exec()){
        query.lastError().text();

    }
    query.first();
    QString id = query.value(record.indexOf("Код_чека")).toString();

    QSqlQuery qry2;
    qry2.exec("Select Товар.Название,Продажи.Количество,Продажи.Цена_продажи from Товар INNER JOIN Продажи ON Товар.Код_товара = Продажи.Код_товара Where Продажи.Код_чека= '" +id+ "'");
    ui->SaleView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    prodM->setHeaderData(0,Qt::Horizontal,tr(" Название "));
    prodM->setHeaderData(1,Qt::Horizontal,tr(" Количество "));
    prodM->setHeaderData(2,Qt::Horizontal,tr(" Цена "));
    prodM->setQuery(qry2);
    ui->SaleView->setModel(prodM);
    ui->SaleView ->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void Prod::on_pushButton_clicked()
{
    db.open();
    int kod = ui->lineEdit->text().toInt();
    QString dat1 = ui->dateEdit->date().toString("dd.MM.yyyy");

    double sum1 = ui->doubleSpinBox->value();
    double sum2 = ui->doubleSpinBox_2->value();

    if (ui->radioButton->isChecked()){
        qry1 = new QSqlQuery(db);
        qry1->prepare("Select * from Чек where Код_чека = :kod;");
        qry1->bindValue(":kod",kod);
        ui->ChequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Дата "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Сумма "));
        qDebug()<< qry1->exec();
        model6->setQuery(*qry1);
        ui->ChequeView->setModel(model6);
    }
    else if (ui->radioButton_2->isChecked()){
        qry1 = new QSqlQuery(db);
        qry1->prepare("Select * from Чек where Дата_чека=:dat1;");
        qry1->bindValue(":dat1",dat1);
        qry1->exec();
        ui->ChequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Дата "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Сумма "));

        model6->setQuery(*qry1);
        ui->ChequeView->setModel(model6);
    }
    else if (ui->radioButton_3->isChecked()){
        qry1 = new QSqlQuery(db);
    qry1->prepare("Select * from Чек where Общая_сумма >= :sum1 and Общая_сумма <= :sum2 ;");
    qry1->bindValue(":sum1",sum1);
    qry1->bindValue(":sum2",sum2);
    qDebug()<<qry1->exec();
    ui->ChequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
    model6->setHeaderData(1,Qt::Horizontal,tr(" Дата "));
    model6->setHeaderData(2,Qt::Horizontal,tr(" Сумма "));

    model6->setQuery(*qry1);
    ui->ChequeView->setModel(model6);
  }
    else {
        QMessageBox::critical(this,"Ошибка","Ошибка при выполнении поиска!");
    }
}

void Prod::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->doubleSpinBox->clear();
    ui->doubleSpinBox_2->clear();
    qry1->prepare("Select * from Чек;");
    qry1->exec();
    model1->setQuery(*qry1);
    ui->ChequeView->setModel(model1);
}
