#include "addtov.h"
#include "ui_addtov.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

addTov::addTov(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addTov)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
    model1 = new QSqlQueryModel;

    katM = new QSqlQueryModel;
    QSqlQuery qry;
    QSqlQuery qry1;
    connecttosql1();

}

void addTov::connecttosql1()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DataBase.db");
    db.open();
    QSqlQuery qry2;
    qry2.prepare("SELECT Название_категории FROM Категории;");
    qry2.exec();
    katM->setQuery(qry2);
    ui->katBox->setModel(katM);


}

QString addTov::category()
{
    return ui->katBox->currentText();
}

void addTov::dialog()
{
    QString name=ui->nameEdit_2->text();
    int kol=ui->kolEdit_2->text().toInt();
    QString opis=ui->opisEdit_2->text();
    double price=ui->sumEdit_2->text().toDouble();
    //qDebug()<<kat;
    if(db.open()){
        qry = new QSqlQuery(db);
        qry->prepare("Insert into Товар (Название,Количество,Описание,Цена_за_единицу,Код_категории) Values(:name,:kol,:opis,:price,:index)");
        qry->bindValue(":name", name);
        qry->bindValue(":kol", kol);
        qry->bindValue(":opis", opis);
        qry->bindValue(":price", price);
        qry->bindValue(":index", index);
        qDebug()<<qry->exec();

        model->setQuery(*qry);
       // ui->productView->setModel(model);

    }
    else{
        QMessageBox::critical(this,"Error",model->lastError().text());
    }
    this->close();
    //MainWindow:refreshUi();
    //MainWindow::connectToSql();
}

addTov::~addTov()
{
    delete ui;
}

void addTov::on_pushButton_clicked()
{

    /*QString name=ui->nameEdit_2->text();
    int kol=ui->kolEdit_2->text().toInt();
    QString opis=ui->opisEdit_2->text();
    double price=ui->sumEdit_2->text().toDouble();
    //qDebug()<<kat;
    if(db.open()){
        qry = new QSqlQuery(db);
        qry->prepare("Insert into Товар (Название,Количество,Описание,Цена_за_единицу,Код_категории) Values(:name,:kol,:opis,:price,:index)");
        qry->bindValue(":name", name);
        qry->bindValue(":kol", kol);
        qry->bindValue(":opis", opis);
        qry->bindValue(":price", price);
        qry->bindValue(":index", index);
        qDebug()<<qry->exec();

        model->setQuery(*qry);
       // ui->productView->setModel(model);

    }
    else{
        QMessageBox::critical(this,"Error",model->lastError().text());
    }
    this->close();*/
    //MainWindow:refreshUi();
    //MainWindow::connectToSql();
    dialog();

}

void addTov::on_katBox_activated(const QString &arg1)
{
    index= ui->katBox->findText(category())+1;
    if(index!=-1){
        ui->katBox->setCurrentIndex(index);
        QString s=QString::number(index);
         QMessageBox::critical(this,"Error",s);
    }

}
