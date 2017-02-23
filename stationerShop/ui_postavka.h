/********************************************************************************
** Form generated from reading UI file 'postavka.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTAVKA_H
#define UI_POSTAVKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Postavka
{
public:
    QGroupBox *KolBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelKod;
    QLabel *labelName;
    QPushButton *ButtonKol;
    QLineEdit *kolEdit;

    void setupUi(QDialog *Postavka)
    {
        if (Postavka->objectName().isEmpty())
            Postavka->setObjectName(QStringLiteral("Postavka"));
        Postavka->resize(282, 242);
        Postavka->setStyleSheet(QStringLiteral("background-color: #B9F6CA;"));
        KolBox = new QGroupBox(Postavka);
        KolBox->setObjectName(QStringLiteral("KolBox"));
        KolBox->setGeometry(QRect(30, 30, 231, 181));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        KolBox->setFont(font);
        label = new QLabel(KolBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 91, 16));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        label_2 = new QLabel(KolBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 72, 61, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(KolBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 104, 121, 16));
        label_3->setFont(font1);
        labelKod = new QLabel(KolBox);
        labelKod->setObjectName(QStringLiteral("labelKod"));
        labelKod->setGeometry(QRect(100, 40, 46, 13));
        labelKod->setFont(font1);
        labelName = new QLabel(KolBox);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(80, 72, 141, 20));
        labelName->setFont(font1);
        ButtonKol = new QPushButton(KolBox);
        ButtonKol->setObjectName(QStringLiteral("ButtonKol"));
        ButtonKol->setGeometry(QRect(50, 140, 91, 23));
        QFont font2;
        font2.setPointSize(9);
        ButtonKol->setFont(font2);
        ButtonKol->setStyleSheet(QStringLiteral("background-color:#ECEFF1"));
        kolEdit = new QLineEdit(KolBox);
        kolEdit->setObjectName(QStringLiteral("kolEdit"));
        kolEdit->setGeometry(QRect(140, 104, 51, 20));
        kolEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        retranslateUi(Postavka);

        QMetaObject::connectSlotsByName(Postavka);
    } // setupUi

    void retranslateUi(QDialog *Postavka)
    {
        Postavka->setWindowTitle(QApplication::translate("Postavka", "\320\237\320\276\321\201\321\202\320\260\320\262\320\272\320\260", 0));
        KolBox->setTitle(QApplication::translate("Postavka", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\260 \321\202\320\276\320\262\320\260\321\200\320\260", 0));
        label->setText(QApplication::translate("Postavka", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\276\320\262\320\260\321\200\320\260", 0));
        label_2->setText(QApplication::translate("Postavka", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        label_3->setText(QApplication::translate("Postavka", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        labelKod->setText(QString());
        labelName->setText(QString());
        ButtonKol->setText(QApplication::translate("Postavka", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Postavka: public Ui_Postavka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTAVKA_H
