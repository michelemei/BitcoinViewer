/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ctrlButton;
    QLabel *bitcoinValue;
    QLabel *datetimeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(327, 92);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ctrlButton = new QPushButton(centralWidget);
        ctrlButton->setObjectName(QStringLiteral("ctrlButton"));
        ctrlButton->setGeometry(QRect(30, 30, 75, 23));
        bitcoinValue = new QLabel(centralWidget);
        bitcoinValue->setObjectName(QStringLiteral("bitcoinValue"));
        bitcoinValue->setGeometry(QRect(140, 10, 191, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        bitcoinValue->setFont(font);
        bitcoinValue->setLayoutDirection(Qt::RightToLeft);
        datetimeLabel = new QLabel(centralWidget);
        datetimeLabel->setObjectName(QStringLiteral("datetimeLabel"));
        datetimeLabel->setGeometry(QRect(140, 60, 171, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(10);
        datetimeLabel->setFont(font1);
        datetimeLabel->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bitcoin 2 Euro", Q_NULLPTR));
        ctrlButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        bitcoinValue->setText(QApplication::translate("MainWindow", "Waiting ...", Q_NULLPTR));
        datetimeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
