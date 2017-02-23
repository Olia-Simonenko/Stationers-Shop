/********************************************************************************
** Form generated from reading UI file 'prod.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROD_H
#define UI_PROD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Prod
{
public:
    QTableView *SaleView;
    QTableView *ChequeView;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_2;
    QDateEdit *dateEdit;
    QRadioButton *radioButton_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Prod)
    {
        if (Prod->objectName().isEmpty())
            Prod->setObjectName(QStringLiteral("Prod"));
        Prod->resize(746, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("images/i.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Prod->setWindowIcon(icon);
        Prod->setStyleSheet(QStringLiteral("background-color: #B9F6CA;"));
        SaleView = new QTableView(Prod);
        SaleView->setObjectName(QStringLiteral("SaleView"));
        SaleView->setGeometry(QRect(430, 10, 301, 261));
        SaleView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ChequeView = new QTableView(Prod);
        ChequeView->setObjectName(QStringLiteral("ChequeView"));
        ChequeView->setGeometry(QRect(180, 10, 241, 261));
        ChequeView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(Prod);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 161, 261));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 40, 82, 17));
        QFont font1;
        font1.setPointSize(10);
        radioButton->setFont(font1);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 40, 61, 20));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 80, 51, 17));
        radioButton_2->setFont(font1);
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(70, 80, 81, 22));
        dateEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 120, 141, 17));
        radioButton_3->setFont(font1);
        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(10, 150, 62, 22));
        doubleSpinBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        doubleSpinBox->setMaximum(1e+06);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(90, 150, 62, 22));
        doubleSpinBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        doubleSpinBox_2->setMaximum(1e+06);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 190, 75, 23));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(74, 150, 16, 20));
        QFont font2;
        font2.setPointSize(7);
        label->setFont(font2);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 220, 75, 23));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));

        retranslateUi(Prod);

        QMetaObject::connectSlotsByName(Prod);
    } // setupUi

    void retranslateUi(QWidget *Prod)
    {
        Prod->setWindowTitle(QApplication::translate("Prod", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        groupBox->setTitle(QApplication::translate("Prod", "\320\237\320\276\320\270\321\201\320\272", 0));
        radioButton->setText(QApplication::translate("Prod", "\320\232\320\276\320\264 \321\207\320\265\320\272\320\260", 0));
        radioButton_2->setText(QApplication::translate("Prod", "\320\224\320\260\321\202\320\260", 0));
        radioButton_3->setText(QApplication::translate("Prod", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260(\320\263\321\200\320\275.)", 0));
        pushButton->setText(QApplication::translate("Prod", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", 0));
        label->setText(QApplication::translate("Prod", "\342\200\224", 0));
        pushButton_2->setText(QApplication::translate("Prod", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Prod: public Ui_Prod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROD_H
