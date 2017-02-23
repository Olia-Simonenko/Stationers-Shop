#include "add.h"
#include "ui_add.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    katM = new QSqlQueryModel;
    model = new QSqlQueryModel;
    index=1;
    connecttosql1();
}

Add::~Add()
{
    delete ui;
}

void Add::connecttosql1()
{
    const QString PATH = QFileInfo(".").absolutePath() + "/stationerShop/DataBase/DataBase.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);
    db.open();

    QSqlQuery qry2;
    qry2.prepare("SELECT Название_категории FROM Категории;");
    qry2.exec();
    katM->setQuery(qry2);
    ui->katBox->setModel(katM);
}

QString Add::category()
{
    return ui->katBox->currentText();
}

void Add::on_katBox_activated(const QString &arg1)
{
    index= ui->katBox->findText(category())+1;
    if(index!=-1){
        ui->katBox->setCurrentIndex(index-1);
    }
}

void Add::value()
{
    QString name=ui->nameEdit_2->text();
    int kol=ui->kolEdit_2->text().toInt();
    QString opis=ui->opisEdit_2->text();
    double price=ui->sumEdit_2->text().toDouble();

    if(db.open()){
        qry1 = new QSqlQuery(db);
        qry1->prepare("Insert into Товар (Название,Количество,Описание,Цена_за_единицу,Код_категории) Values(:name,:kol,:opis,:price,:index)");
        qry1->bindValue(":name", name);
        qry1->bindValue(":kol", kol);
        qry1->bindValue(":opis", opis);
        qry1->bindValue(":price", price);
        qry1->bindValue(":index", index);
        qry1->exec();
    } else {
        QMessageBox::critical(this,"Ошибка","Ошибка при добавлении товара!");
    }
}

void Add::on_pushButton_2_clicked()
{
    ui->kolEdit_2->clear();
    ui->nameEdit_2->clear();
    ui->opisEdit_2->clear();
    ui->sumEdit_2->clear();
}

void Add::on_buttonBox_accepted()
{
    QMessageBox::critical(this,"Добавление","Новый товар успешно добавлен!");
}
