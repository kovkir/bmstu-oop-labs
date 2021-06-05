/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "constants.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    
    QVBoxLayout *floors_layout;
    QLabel *floor_label;
    
    std::vector<QPushButton *> floor_buttons;
    
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(200, 500);
        // MainWindow->setMinimumSize(QSize(230, 745));
        // MainWindow->setMaximumSize(QSize(230, 745));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        floors_layout = new QVBoxLayout();
        floors_layout->setObjectName(QString::fromUtf8("floors_layout"));
        floor_label = new QLabel(centralwidget);
        floor_label->setObjectName(QString::fromUtf8("floor_label"));
        QFont font;
        font.setPointSize(16);
        floor_label->setFont(font);
        floor_label->setAlignment(Qt::AlignCenter);

        floors_layout->addWidget(floor_label);
        
        floors_layout = new QVBoxLayout();
        floors_layout->setObjectName(QString::fromUtf8("floors_layout"));
        floor_label = new QLabel(centralwidget);
        floor_label->setObjectName(QString::fromUtf8("floor_label"));
        floor_label->setFont(font);
        floor_label->setAlignment(Qt::AlignCenter);

        floors_layout->addWidget(floor_label);

        QFont btn_font;
        btn_font.setPointSize(14);

        for (int i = 0; i < NUM_OF_FLOORS; ++i)
        {
            auto btn = new QPushButton(centralwidget);
            btn->setMinimumSize(QSize(70, 50));
//            btn->setMaximumSize(QSize(70, 60));
            btn->setFont(btn_font);

            floor_buttons.push_back(btn);
        }

        for (auto it = floor_buttons.rbegin(); it != floor_buttons.rend(); ++it)
        {
            floors_layout->addWidget(*it);
        }

        horizontalLayout->addLayout(floors_layout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi
    
    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "lab_04", nullptr));
        floor_label->setText(
                QApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266\320\270", nullptr));

        for (int i = 0; i < NUM_OF_FLOORS; ++i)
        {
            floor_buttons[i]->setText(
                    QApplication::translate("MainWindow", QString::number(i + 1).toUtf8().data(), nullptr));
        }

    } // retranslateUi
    
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
