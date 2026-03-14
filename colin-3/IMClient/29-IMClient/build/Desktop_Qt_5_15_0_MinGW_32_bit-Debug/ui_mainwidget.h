/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *pb_img;
    QTabWidget *tabWidget;
    QWidget *tab_space;
    QWidget *tab_friend;
    QListWidget *lw_friendlist;
    QWidget *tab_msg;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *l_nick;
    QLineEdit *le_feeling;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_menu;
    QSpacerItem *hs1;
    QPushButton *pb_f1;
    QSpacerItem *hs2;
    QPushButton *pb_f2;
    QSpacerItem *hs3;
    QPushButton *pb_f3;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(409, 654);
        pb_img = new QPushButton(MainWidget);
        pb_img->setObjectName(QString::fromUtf8("pb_img"));
        pb_img->setGeometry(QRect(30, 20, 71, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/0.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_img->setIcon(icon);
        pb_img->setIconSize(QSize(60, 60));
        pb_img->setCheckable(false);
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 120, 351, 471));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        tabWidget->setFont(font);
        tab_space = new QWidget();
        tab_space->setObjectName(QString::fromUtf8("tab_space"));
        tabWidget->addTab(tab_space, QString());
        tab_friend = new QWidget();
        tab_friend->setObjectName(QString::fromUtf8("tab_friend"));
        lw_friendlist = new QListWidget(tab_friend);
        lw_friendlist->setObjectName(QString::fromUtf8("lw_friendlist"));
        lw_friendlist->setGeometry(QRect(0, 0, 351, 441));
        tabWidget->addTab(tab_friend, QString());
        tab_msg = new QWidget();
        tab_msg->setObjectName(QString::fromUtf8("tab_msg"));
        tabWidget->addTab(tab_msg, QString());
        layoutWidget = new QWidget(MainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 30, 251, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        l_nick = new QLabel(layoutWidget);
        l_nick->setObjectName(QString::fromUtf8("l_nick"));
        QFont font1;
        font1.setPointSize(17);
        l_nick->setFont(font1);

        verticalLayout->addWidget(l_nick);

        le_feeling = new QLineEdit(layoutWidget);
        le_feeling->setObjectName(QString::fromUtf8("le_feeling"));
        le_feeling->setEnabled(false);
        QFont font2;
        font2.setPointSize(12);
        le_feeling->setFont(font2);

        verticalLayout->addWidget(le_feeling);

        layoutWidget1 = new QWidget(MainWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 600, 351, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_menu = new QPushButton(layoutWidget1);
        pb_menu->setObjectName(QString::fromUtf8("pb_menu"));
        QFont font3;
        font3.setPointSize(15);
        pb_menu->setFont(font3);

        horizontalLayout->addWidget(pb_menu);

        hs1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hs1);

        pb_f1 = new QPushButton(layoutWidget1);
        pb_f1->setObjectName(QString::fromUtf8("pb_f1"));
        pb_f1->setFont(font3);

        horizontalLayout->addWidget(pb_f1);

        hs2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hs2);

        pb_f2 = new QPushButton(layoutWidget1);
        pb_f2->setObjectName(QString::fromUtf8("pb_f2"));
        pb_f2->setFont(font3);

        horizontalLayout->addWidget(pb_f2);

        hs3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hs3);

        pb_f3 = new QPushButton(layoutWidget1);
        pb_f3->setObjectName(QString::fromUtf8("pb_f3"));
        pb_f3->setFont(font3);

        horizontalLayout->addWidget(pb_f3);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "\344\270\273\350\201\212\345\244\251\347\252\227\345\217\243", nullptr));
        pb_img->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_space), QCoreApplication::translate("MainWidget", "\347\251\272\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_friend), QCoreApplication::translate("MainWidget", "\346\234\213\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_msg), QCoreApplication::translate("MainWidget", "\346\266\210\346\201\257", nullptr));
        l_nick->setText(QCoreApplication::translate("MainWidget", "\345\274\240\344\270\211", nullptr));
        le_feeling->setText(QCoreApplication::translate("MainWidget", "\346\210\221\346\230\257\345\274\240\344\270\211", nullptr));
        pb_menu->setText(QCoreApplication::translate("MainWidget", "\350\217\234\345\215\225", nullptr));
        pb_f1->setText(QCoreApplication::translate("MainWidget", "\345\212\237\350\203\2751", nullptr));
        pb_f2->setText(QCoreApplication::translate("MainWidget", "\345\212\237\350\203\2752", nullptr));
        pb_f3->setText(QCoreApplication::translate("MainWidget", "\345\212\237\350\203\2753", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
