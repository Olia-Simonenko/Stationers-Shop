/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Add
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *katBox;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *nameEdit_2;
    QLabel *label_9;
    QLineEdit *kolEdit_2;
    QLabel *label_10;
    QLineEdit *opisEdit_2;
    QLabel *label_11;
    QLineEdit *sumEdit_2;

    void setupUi(QDialog *Add)
    {
        if (Add->objectName().isEmpty())
            Add->setObjectName(QStringLiteral("Add"));
        Add->resize(333, 294);
        Add->setStyleSheet(QStringLiteral("background-color: #B9F6CA;"));
        groupBox = new QGroupBox(Add);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 271, 261));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 131, 16));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        katBox = new QComboBox(groupBox);
        katBox->setObjectName(QStringLiteral("katBox"));
        katBox->setGeometry(QRect(140, 36, 111, 22));
        katBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 220, 81, 32));
        buttonBox->setFont(font1);
        buttonBox->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 192, 46, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 120, 46, 13));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 121, 16));
        label_8->setFont(font1);
        nameEdit_2 = new QLineEdit(groupBox);
        nameEdit_2->setObjectName(QStringLiteral("nameEdit_2"));
        nameEdit_2->setGeometry(QRect(140, 77, 111, 20));
        nameEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 120, 131, 16));
        label_9->setFont(font1);
        kolEdit_2 = new QLineEdit(groupBox);
        kolEdit_2->setObjectName(QStringLiteral("kolEdit_2"));
        kolEdit_2->setGeometry(QRect(140, 118, 61, 20));
        kolEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 153, 71, 16));
        label_10->setFont(font1);
        opisEdit_2 = new QLineEdit(groupBox);
        opisEdit_2->setObjectName(QStringLiteral("opisEdit_2"));
        opisEdit_2->setGeometry(QRect(140, 150, 111, 20));
        opisEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 190, 111, 16));
        label_11->setFont(font1);
        sumEdit_2 = new QLineEdit(groupBox);
        sumEdit_2->setObjectName(QStringLiteral("sumEdit_2"));
        sumEdit_2->setGeometry(QRect(140, 188, 61, 20));
        sumEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        katBox->raise();
        label->raise();
        katBox->raise();
        buttonBox->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Add);
        QObject::connect(buttonBox, SIGNAL(accepted()), Add, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Add, SLOT(reject()));

        QMetaObject::connectSlotsByName(Add);
    } // setupUi

    void retranslateUi(QDialog *Add)
    {
        Add->setWindowTitle(QApplication::translate("Add", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        groupBox->setTitle(QApplication::translate("Add", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \321\202\320\276\320\262\320\260\321\200\320\260", 0));
        label->setText(QApplication::translate("Add", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216:", 0));
        label_2->setText(QApplication::translate("Add", "\320\263\321\200\320\275.", 0));
        label_3->setText(QApplication::translate("Add", "\321\210\321\202.", 0));
        label_8->setText(QApplication::translate("Add", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", 0));
        label_9->setText(QApplication::translate("Add", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", 0));
        label_10->setText(QApplication::translate("Add", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", 0));
        label_11->setText(QApplication::translate("Add", "\320\246\320\265\320\275\320\260 \320\267\320\260 \320\265\320\264\320\270\320\275\320\270\321\206\321\203:", 0));
    } // retranslateUi

};

namespace Ui {
    class Add: public Ui_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
