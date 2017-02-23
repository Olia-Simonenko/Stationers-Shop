#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QDate>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <QFile>
#include <QTextStream>

#include <QFileInfo>
#include <QDir>

#include "constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlQueryModel;
    model1 = new QSqlQueryModel;
    model2 = new QSqlQueryModel;
    model3 = new QSqlQueryModel;
    model6 = new QSqlQueryModel;
    chequeM= new QSqlQueryModel;
    cheqM = new QSqlQueryModel;
    katM = new QSqlQueryModel;

    ui->centralWidget->height();
    post = new Postavka();
    //connect(ui->action_5, SIGNAL(triggered()), post, SLOT(on_action_5_triggered()));
    connect(this, SIGNAL(sendData(QString,QString,QString)), post, SLOT(recieveData(QString,QString,QString)));
    QSqlQuery qry;

    connectToSql();
}

MainWindow::~MainWindow()
{
    delete model;
    delete model1;
    delete model2;
    delete model3;
    delete model6;
    delete qry;
    delete ui;
}

void MainWindow::connectToSql()
{
    const QString PATH = QFileInfo(".").absolutePath() + "/stationerShop/DataBase/DataBase.db";
    qDebug()<<PATH; //Показываем текущюю папку
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);

    if(!db.open()){
        qDebug()<<"Connect Failed";
    } else {
        qDebug()<<"Connect Success";
    }

    QFileInfo checkFile(PATH);
    if(checkFile.isFile()){
        qDebug()<<"Connect FULL DB";
    } else {
        qDebug()<<"Connect NULL DB";
    }

    if(db.open()){
        qry = new QSqlQuery(db);
        qry->prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории;");
        qry->exec();

        model->setQuery(*qry);
        ui->productView->setModel(model);
        ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
        model->setHeaderData(2,Qt::Horizontal,tr(" Название "));
        model->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
        model->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
        model->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
    } else {
        QMessageBox::critical(this,"Error",model->lastError().text());
    }
}

void MainWindow::refreshUi()
{
    qry->prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории;");
    qry->exec();

    model->setQuery(*qry);
    ui->productView->setModel(model);
}

QString MainWindow::toJson()
{
    QSqlQuery qry;
    db.open();
    qry.prepare("Select Товар.Код_товара, Товар.Название, Продажи.Количество , Продажи.Цена_продажи From Товар, Продажи Where (Товар.Код_товара=Продажи.Код_товара) and Продажи.Код_чека='"+constant.numCheque +"'");
    if(!qry.exec()){
        return QString();
        qDebug()<<"Qry not Exec"<< qry.lastError();
    }

    QJsonDocument json;
    QJsonArray jsonArray;

    while(qry.next()) {
        QJsonObject jsonObject;

        for(int i=0; i<qry.record().count(); i++) {
            jsonObject.insert(qry.record().fieldName(i),QJsonValue::fromVariant(qry.value(i)));
        }
        jsonArray.push_back(jsonObject);
    }
    json.setArray(jsonArray);
    qDebug()<<"numCheque = "<<constant.numCheque;

    QFile file;
    file.setFileName(constant.numCheque + ".json");
    QTextStream out(&file);
    if(file.open(QIODevice::Append))
    {
        out<<json.toJson();
    }
    file.close();
    return json.toJson();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
    ui->nameEdit->clear();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);

    qry->prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории;");
    qry->exec();
    model->setQuery(*qry);
    ui->productView->setModel(model);
    ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    model->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
    model->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
    model->setHeaderData(2,Qt::Horizontal,tr(" Название "));
    model->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
    model->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
    model->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));

}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery qry3;
    QString name = ui->nameEdit->text();

    int kol1 = ui->spinBox->value();
    int kol2 = ui->spinBox_2->value();

    double sum1 = ui->doubleSpinBox->value();
    double sum2 = ui->doubleSpinBox_2->value();

    if (ui->radioButton->isChecked()){

     qry3.prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории where Товар.Название LIKE  :name ;");
     qry3.bindValue(":name",'%'+name+'%');
     qDebug()<<qry3.exec();
     model6->setQuery(qry3);
     ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
     model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
     model6->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
     model6->setHeaderData(2,Qt::Horizontal,tr(" Название "));
     model6->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
     model6->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
     model6->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
     ui->productView->setModel(model6);

   }
    else if(ui->radioButton_2->isChecked()){

        qry3.prepare("SELECT Товар.Код_товара,Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории where Товар.Количество >=:kol1 and Товар.Количество <=:kol2 ;");
        qry3.bindValue(":kol1",kol1);
        qry3.bindValue(":kol2",kol2);
        qDebug()<<qry3.exec();
        model6->setQuery(qry3);
        ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Название "));
        model6->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
        model6->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
        model6->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
        ui->productView->setModel(model6);

    }
    else if(ui->radioButton_3->isChecked()){

        qry3.prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории where Товар.Цена_за_единицу >=:sum1 and Товар.Цена_за_единицу <=:sum2 ;");
        qry3.bindValue(":sum1",sum1);
        qry3.bindValue(":sum2",sum2);
        qDebug()<<qry3.exec();
        model6->setQuery(qry3);
        ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Название "));
        model6->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
        model6->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
        model6->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
        ui->productView->setModel(model6);

    } else {
         QMessageBox::critical(this,"Ошибка","Ошибка при выполнении поиска!");
     }

     model6->setQuery(qry3);
     ui->productView->setModel(model6);
}

void MainWindow::on_action_triggered()
{
    ui->chequeSum->setText("0 грн.");
    this->resize(820,480);
    QDate dat;
    dat =QDate::currentDate();

    QSqlQuery qry1;
    qry1.prepare("INSERT INTO Чек (Дата_чека,Общая_сумма) values (:dat,0)");
    qry1.bindValue(":dat", dat.toString("dd.MM.yyyy"));
    qry1.exec();
    qry1.prepare("Select Код_чека from Чек ORDER BY Код_чека desc LIMIT 1");
    qry1.exec();
    qry1.first();
    constant.numCheque = qry1.value(0).toString();
    constant.num = constant.numCheque.toInt();
    ui->label_3->setText(constant.numCheque);

}

void MainWindow::on_addCheque_clicked()
{
    db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery qry1,qry7,qry4,qry5;
    int count;
    count = ui->countBox->value();
    qDebug()<<"count"<<count;
    constant.sum = count * constant.price;
    qry1.prepare("INSERT INTO Продажи (Код_товара, Код_чека, Количество, Цена_продажи) values(:id,:numCheque,:countBox,:sum)");
    qry1.bindValue(":id", constant.id);
    qry1.bindValue(":numCheque", constant.numCheque);
    qry1.bindValue(":countBox", count);
    qry1.bindValue(":sum", constant.sum);

    qry1.exec();
    constant.chequesum+=constant.sum;
    constant.kol = model->data(model->index(ui->productView->currentIndex().row(),3),Qt::DisplayRole).toInt();

    if(count>constant.kol)
    {
        QMessageBox::critical(this,"Error","Вы выбрали больше товара чем доступно!");
    }
    else
    {
        int kolTov=0;
        kolTov=constant.kol-count;
        qry5.prepare("Update Товар set Количество=:kolTov where Код_товара=:id ;");
        qry5.bindValue(":kolTov", kolTov);
        qry5.bindValue(":id", constant.id);
        qry5.exec();
        qry7.prepare("Select Товар.Код_товара, Товар.Название, Продажи.Количество , Продажи.Цена_продажи From Товар, Продажи Where (Товар.Код_товара=Продажи.Код_товара) and Продажи.Код_чека='"+constant.numCheque +"'");
        qry7.exec();
        model2->setQuery(qry7);
        ui->chequeView->setModel(model2);

        qry4.prepare("Update Чек set Общая_сумма=:chequesum where Код_чека=:num ;");
        qry4.bindValue(":chequesum", constant.chequesum);
        qry4.bindValue(":num", constant.num);
        qry4.exec();
        ui->chequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Название "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Количество "));
        model6->setHeaderData(3,Qt::Horizontal,tr(" Сумма(грн) "));

        QSqlQuery qry6;
        qry6.prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории;");
        qry6.exec();
        model6->setQuery(qry6);
        ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model6->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
        model6->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
        model6->setHeaderData(2,Qt::Horizontal,tr(" Название "));
        model6->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
        model6->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
        model6->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
        ui->productView->setModel(model6);

        QSqlDatabase::database().commit();
        QString cheqCount=QString::number(constant.chequesum);
        ui->chequeSum->setText(cheqCount+" грн.");
    }

}

void MainWindow::on_productView_activated(const QModelIndex &index)
{
    db.open();
    QString value=ui->productView->model()->data(index).toString();
    QSqlQuery query;
    query.exec("Select Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории where Товар.Код_товара = '" + value + "'");
    QSqlRecord record=query.record();
    if(!query.exec()){
        query.lastError().text();
    }
    query.first();
    constant.id = query.value(record.indexOf("Код_товара")).toString();
    constant.name = ui->productView->model()->data(ui->productView->model()->index(index.row(),2)).toString();
    constant.kol1 = ui->productView->model()->data(ui->productView->model()->index(index.row(),3)).toString();
    qDebug()<<constant.name;
    QString s= ui->productView->model()->data(ui->productView->model()->index(index.row(),5)).toString();
    s.replace(',','.');
    qDebug()<<s;
    constant.price = s.toDouble();
    //QString str = QString::number(price, 'g', 2);

    ui->labelname->setText(constant.name);
    db.close();
}

void MainWindow::on_chequeView_activated(const QModelIndex &index)
{
    constant.idCheque= ui->chequeView->model()->data(ui->productView->model()->index(index.row(),0)).toString();
    constant.count = ui->chequeView->model()->data(ui->chequeView->model()->index(index.row(),2)).toInt();
    constant.summ = ui->chequeView->model()->data(ui->chequeView->model()->index(index.row(),3)).toDouble();
}

void MainWindow::on_delCheque_clicked()
{
   QSqlDatabase::database().transaction();
   QSqlQuery qryDCheque,qrySCheque,qry4,qry5,qry8;
   qryDCheque.prepare("Delete From Продажи Where Код_чека=:num and Код_товара=:idCheque;");
   qryDCheque.bindValue(":num", constant.num);
   qryDCheque.bindValue(":idCheque", constant.idCheque);
   qryDCheque.exec();
   qrySCheque.prepare("Select Товар.Код_товара, Товар.Название, Продажи.Количество , Продажи.Цена_продажи From Товар, Продажи Where (Товар.Код_товара=Продажи.Код_товара) and Продажи.Код_чека='"+constant.numCheque +"'");
   qrySCheque.exec();

   ui->chequeView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   chequeM->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
   chequeM->setHeaderData(1,Qt::Horizontal,tr(" Название "));
   chequeM->setHeaderData(2,Qt::Horizontal,tr(" Количество "));
   chequeM->setHeaderData(3,Qt::Horizontal,tr(" Сумма(грн) "));

   chequeM->setQuery(qrySCheque);
   ui->chequeView->setModel(chequeM);

   int kolTov=0;
   kolTov=constant.kol+constant.count;

   qry5.prepare("Update Товар set Количество=:kol where Код_товара=:id ;");
   qry5.bindValue(":kol", constant.kol);
   qry5.bindValue(":id", constant.id);
   qry5.exec();

   constant.chequesum=constant.chequesum - constant.summ;

   qry4.prepare("Update Чек set Общая_сумма=:chequesum where Код_чека=:num ;");
   qry4.bindValue(":chequesum", constant.chequesum);
   qry4.bindValue(":num", constant.num);
   qry4.exec();
   QString cheqCount=QString::number(constant.chequesum);
   ui->chequeSum->setText(cheqCount+" грн.");

   qry8.prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории");
   qry8.exec();

   cheqM->setQuery(qry8);
   ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   cheqM->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
   cheqM->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
   cheqM->setHeaderData(2,Qt::Horizontal,tr(" Название "));
   cheqM->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
   cheqM->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
   cheqM->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
   ui->productView->setModel(cheqM);

   QSqlDatabase::database().commit();

}

void MainWindow::on_action_2_triggered()
{
    prod.show();
}

void MainWindow::on_radioButton_clicked()
{
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->nameEdit->clear();
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->nameEdit->clear();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
}

void MainWindow::on_action_3_triggered()
{
    Add add1;
    if(add1.exec()){
       add1.value();
       model->setQuery( model->query().lastQuery() );
    }
}

void MainWindow::on_action_4_triggered()
{
    QSqlQuery qryDTov,qry;
    QMessageBox::StandardButton bYes;
    bYes = QMessageBox::question(this,"Подтверждение удаления","Вы действительно хотите удалить выбранный товар?",QMessageBox::Yes|QMessageBox::No);
    if(bYes == QMessageBox::Yes){
        db.open();
     qryDTov.prepare("Delete From Товар Where Код_товара=:id;");
     qryDTov.bindValue(":id", constant.id);

     qDebug()<<qryDTov.exec();
     qry.prepare("SELECT Товар.Код_товара, Категории.Название_категории, Товар.Название, Товар.Количество, Товар.Описание, Товар.Цена_за_единицу FROM Категории INNER JOIN Товар ON Категории.Код_категории = Товар.Код_категории;");
     qry.exec();

     model->setQuery(qry);
     ui->productView->setModel(model);
     ui->productView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
     model->setHeaderData(0,Qt::Horizontal,tr(" Номер "));
     model->setHeaderData(1,Qt::Horizontal,tr(" Категория "));
     model->setHeaderData(2,Qt::Horizontal,tr(" Название "));
     model->setHeaderData(3,Qt::Horizontal,tr(" Количество "));
     model->setHeaderData(4,Qt::Horizontal,tr(" Описание "));
     model->setHeaderData(5,Qt::Horizontal,tr(" Цена(грн)"));
     db.close();
    } else {
        QMessageBox::critical(this,"Отмена","Удаление товара отменено!");
    }
}

void MainWindow::on_action_5_triggered()
{
    emit sendData(constant.id, constant.name, constant.kol1);
    qDebug()<<constant.id<<constant.name<<constant.kol1;

   if(post->exec()){
       model->setQuery( model->query().lastQuery() );
    }
}

void MainWindow::on_saveCheque_clicked()
{
    toJson();
    QMessageBox::critical(this,"Успешно","Чек сохранен в файл "+constant.numCheque+".json!");

    ui->label_3->clear();
    ui->labelname->clear();
    ui->chequeSum->setText("0 грн.");
    ui->chequeView->setModel(0);

    constant.chequesum = 0.0;

    prod.refreshChequeList();
}
