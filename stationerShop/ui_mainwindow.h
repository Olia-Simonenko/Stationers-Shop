/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralWidget;
    QTableView *productView;
    QGroupBox *groupBox_2;
    QLineEdit *nameEdit;
    QPushButton *pushButton_4;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QTableView *chequeView;
    QSpinBox *countBox;
    QPushButton *addCheque;
    QPushButton *delCheque;
    QPushButton *saveCheque;
    QLabel *chequeSum;
    QLabel *label_4;
    QLabel *labelname;
    QLabel *labelcheck;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 266);
        QIcon icon;
        icon.addFile(QStringLiteral("images/i.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(30, 30));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"background-color: #B9F6CA;"));
        productView = new QTableView(centralWidget);
        productView->setObjectName(QStringLiteral("productView"));
        productView->setGeometry(QRect(220, 10, 591, 211));
        productView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(3, 10, 211, 211));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox_2->setFont(font);
        groupBox_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox_2->setAcceptDrops(false);
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(90, 40, 111, 20));
        nameEdit->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 170, 81, 23));
        QFont font1;
        font1.setPointSize(9);
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(100, 80, 40, 22));
        spinBox->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        spinBox->setMaximum(9999);
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(160, 80, 41, 22));
        spinBox_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        spinBox_2->setMaximum(9999);
        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 120, 51, 22));
        doubleSpinBox->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        doubleSpinBox->setMaximum(1e+06);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(150, 120, 51, 22));
        doubleSpinBox_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        doubleSpinBox_2->setMaximum(1e+06);
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 40, 71, 17));
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 80, 90, 17));
        radioButton_2->setFont(font1);
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 120, 51, 17));
        radioButton_3->setFont(font1);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 120, 16, 20));
        QFont font2;
        font2.setPointSize(7);
        label->setFont(font2);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 80, 16, 21));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 170, 81, 23));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 230, 811, 171));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        groupBox_3->setFont(font3);
        groupBox_3->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        chequeView = new QTableView(groupBox_3);
        chequeView->setObjectName(QStringLiteral("chequeView"));
        chequeView->setGeometry(QRect(310, 40, 421, 91));
        chequeView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        countBox = new QSpinBox(groupBox_3);
        countBox->setObjectName(QStringLiteral("countBox"));
        countBox->setGeometry(QRect(120, 110, 71, 22));
        countBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        countBox->setMinimum(1);
        countBox->setMaximum(9999);
        addCheque = new QPushButton(groupBox_3);
        addCheque->setObjectName(QStringLiteral("addCheque"));
        addCheque->setGeometry(QRect(70, 140, 81, 23));
        addCheque->setFont(font1);
        addCheque->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        delCheque = new QPushButton(groupBox_3);
        delCheque->setObjectName(QStringLiteral("delCheque"));
        delCheque->setGeometry(QRect(160, 140, 81, 23));
        delCheque->setFont(font1);
        delCheque->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        saveCheque = new QPushButton(groupBox_3);
        saveCheque->setObjectName(QStringLiteral("saveCheque"));
        saveCheque->setGeometry(QRect(730, 140, 81, 23));
        saveCheque->setFont(font1);
        saveCheque->setStyleSheet(QStringLiteral("background-color: #ECEFF1;"));
        chequeSum = new QLabel(groupBox_3);
        chequeSum->setObjectName(QStringLiteral("chequeSum"));
        chequeSum->setGeometry(QRect(630, 140, 81, 16));
        QFont font4;
        font4.setFamily(QStringLiteral("Times New Roman"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        chequeSum->setFont(font4);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 62, 71, 16));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setWeight(50);
        label_4->setFont(font5);
        labelname = new QLabel(groupBox_3);
        labelname->setObjectName(QStringLiteral("labelname"));
        labelname->setGeometry(QRect(140, 62, 151, 16));
        labelname->setFont(font5);
        labelcheck = new QLabel(groupBox_3);
        labelcheck->setObjectName(QStringLiteral("labelcheck"));
        labelcheck->setGeometry(QRect(100, 30, 51, 21));
        labelcheck->setFont(font4);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(165, 30, 41, 20));
        label_3->setFont(font4);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 88, 71, 16));
        label_5->setFont(font5);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(510, 140, 111, 21));
        label_6->setFont(font4);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(470, 20, 101, 16));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setUnderline(true);
        font6.setWeight(50);
        label_7->setFont(font6);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_2->addAction(action_3);
        menu_2->addAction(action_4);
        menu_2->addAction(action_5);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\275\321\206\321\202\320\276\320\262\320\260\321\200\321\213", 0));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\321\200\320\276\320\264\320\260\320\266\321\203", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\262\321\201\320\265", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_5->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\260\320\262\320\272\320\260", 0));
        groupBox_2->setStyleSheet(QApplication::translate("MainWindow", "border-color: rgb(0, 0, 0);", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260", 0));
        label->setText(QApplication::translate("MainWindow", "\342\200\224", 0));
        label_2->setText(QApplication::translate("MainWindow", " \342\200\224", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\207\320\265\320\272", 0));
        addCheque->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        delCheque->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        saveCheque->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        chequeSum->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 :", 0));
        labelname->setText(QString());
        labelcheck->setText(QApplication::translate("MainWindow", "\320\247\320\265\320\272 \342\204\226", 0));
        label_3->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        label_6->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260:", 0));
        label_7->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\321\213 \320\262 \321\207\320\265\320\272\320\265 :", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
