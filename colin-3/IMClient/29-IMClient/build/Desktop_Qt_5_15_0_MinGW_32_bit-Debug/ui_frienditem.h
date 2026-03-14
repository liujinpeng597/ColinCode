/********************************************************************************
** Form generated from reading UI file 'frienditem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendItem
{
public:
    QPushButton *pb_friimg;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *l_frinick;
    QLabel *l_frifeeling;

    void setupUi(QWidget *FriendItem)
    {
        if (FriendItem->objectName().isEmpty())
            FriendItem->setObjectName(QString::fromUtf8("FriendItem"));
        FriendItem->resize(300, 61);
        pb_friimg = new QPushButton(FriendItem);
        pb_friimg->setObjectName(QString::fromUtf8("pb_friimg"));
        pb_friimg->setGeometry(QRect(10, 10, 40, 40));
        pb_friimg->setIconSize(QSize(40, 40));
        layoutWidget = new QWidget(FriendItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 0, 241, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        l_frinick = new QLabel(layoutWidget);
        l_frinick->setObjectName(QString::fromUtf8("l_frinick"));
        QFont font;
        font.setPointSize(12);
        l_frinick->setFont(font);

        verticalLayout->addWidget(l_frinick);

        l_frifeeling = new QLabel(layoutWidget);
        l_frifeeling->setObjectName(QString::fromUtf8("l_frifeeling"));
        QFont font1;
        font1.setPointSize(10);
        l_frifeeling->setFont(font1);

        verticalLayout->addWidget(l_frifeeling);


        retranslateUi(FriendItem);

        QMetaObject::connectSlotsByName(FriendItem);
    } // setupUi

    void retranslateUi(QWidget *FriendItem)
    {
        FriendItem->setWindowTitle(QCoreApplication::translate("FriendItem", "Form", nullptr));
        pb_friimg->setText(QString());
        l_frinick->setText(QString());
        l_frifeeling->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendItem: public Ui_FriendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
