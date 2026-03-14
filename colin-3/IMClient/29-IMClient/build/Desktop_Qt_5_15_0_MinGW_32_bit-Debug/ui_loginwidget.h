/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab_login;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *l_pass;
    QLineEdit *le_tel;
    QLabel *l_tel;
    QLineEdit *le_pass;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_login;
    QWidget *tab_register;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_register_clear;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_register;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *l_nick;
    QLineEdit *le_nick;
    QLabel *l_register_tel;
    QLineEdit *le_register_tel;
    QLabel *l_register_pass;
    QLineEdit *le_register_pass;
    QLabel *l_pass_again;
    QLineEdit *le_pass_again;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(610, 450);
        label = new QLabel(LoginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 291, 451));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/login.png")));
        label->setScaledContents(true);
        tabWidget = new QTabWidget(LoginWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(290, 0, 321, 451));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        tabWidget->setFont(font);
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        layoutWidget = new QWidget(tab_login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 261, 181));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(false);
        layoutWidget->setFont(font1);
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        l_pass = new QLabel(layoutWidget);
        l_pass->setObjectName(QString::fromUtf8("l_pass"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(false);
        l_pass->setFont(font2);

        gridLayout_2->addWidget(l_pass, 0, 0, 1, 1);

        le_tel = new QLineEdit(layoutWidget);
        le_tel->setObjectName(QString::fromUtf8("le_tel"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        le_tel->setFont(font3);

        gridLayout_2->addWidget(le_tel, 0, 1, 1, 1);

        l_tel = new QLabel(layoutWidget);
        l_tel->setObjectName(QString::fromUtf8("l_tel"));
        l_tel->setFont(font2);

        gridLayout_2->addWidget(l_tel, 1, 0, 1, 1);

        le_pass = new QLineEdit(layoutWidget);
        le_pass->setObjectName(QString::fromUtf8("le_pass"));
        le_pass->setFont(font3);
        le_pass->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_pass, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(tab_login);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(70, 260, 202, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_clear = new QPushButton(layoutWidget_2);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(17);
        font4.setBold(false);
        pb_clear->setFont(font4);

        horizontalLayout_2->addWidget(pb_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_login = new QPushButton(layoutWidget_2);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));
        pb_login->setFont(font4);

        horizontalLayout_2->addWidget(pb_login);

        tabWidget->addTab(tab_login, QString());
        tab_register = new QWidget();
        tab_register->setObjectName(QString::fromUtf8("tab_register"));
        layoutWidget1 = new QWidget(tab_register);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 300, 202, 60));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_register_clear = new QPushButton(layoutWidget1);
        pb_register_clear->setObjectName(QString::fromUtf8("pb_register_clear"));
        pb_register_clear->setFont(font4);

        horizontalLayout->addWidget(pb_register_clear);

        horizontalSpacer_2 = new QSpacerItem(18, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pb_register = new QPushButton(layoutWidget1);
        pb_register->setObjectName(QString::fromUtf8("pb_register"));
        pb_register->setFont(font4);

        horizontalLayout->addWidget(pb_register);

        layoutWidget2 = new QWidget(tab_register);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 271, 243));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        l_nick = new QLabel(layoutWidget2);
        l_nick->setObjectName(QString::fromUtf8("l_nick"));
        l_nick->setFont(font2);

        gridLayout->addWidget(l_nick, 0, 0, 1, 1);

        le_nick = new QLineEdit(layoutWidget2);
        le_nick->setObjectName(QString::fromUtf8("le_nick"));
        le_nick->setFont(font3);

        gridLayout->addWidget(le_nick, 0, 1, 1, 1);

        l_register_tel = new QLabel(layoutWidget2);
        l_register_tel->setObjectName(QString::fromUtf8("l_register_tel"));
        l_register_tel->setFont(font2);

        gridLayout->addWidget(l_register_tel, 1, 0, 1, 1);

        le_register_tel = new QLineEdit(layoutWidget2);
        le_register_tel->setObjectName(QString::fromUtf8("le_register_tel"));
        le_register_tel->setFont(font3);

        gridLayout->addWidget(le_register_tel, 1, 1, 1, 1);

        l_register_pass = new QLabel(layoutWidget2);
        l_register_pass->setObjectName(QString::fromUtf8("l_register_pass"));
        l_register_pass->setFont(font2);

        gridLayout->addWidget(l_register_pass, 2, 0, 1, 1);

        le_register_pass = new QLineEdit(layoutWidget2);
        le_register_pass->setObjectName(QString::fromUtf8("le_register_pass"));
        le_register_pass->setFont(font3);
        le_register_pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_register_pass, 2, 1, 1, 1);

        l_pass_again = new QLabel(layoutWidget2);
        l_pass_again->setObjectName(QString::fromUtf8("l_pass_again"));
        l_pass_again->setFont(font2);

        gridLayout->addWidget(l_pass_again, 3, 0, 1, 1);

        le_pass_again = new QLineEdit(layoutWidget2);
        le_pass_again->setObjectName(QString::fromUtf8("le_pass_again"));
        le_pass_again->setFont(font3);
        le_pass_again->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_pass_again, 3, 1, 1, 1);

        tabWidget->addTab(tab_register, QString());

        retranslateUi(LoginWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225/\346\263\250\345\206\214", nullptr));
        label->setText(QString());
        l_pass->setText(QCoreApplication::translate("LoginWidget", "\346\211\213\346\234\272\345\217\267", nullptr));
        le_tel->setText(QCoreApplication::translate("LoginWidget", "12345678900", nullptr));
        l_tel->setText(QCoreApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        le_pass->setText(QCoreApplication::translate("LoginWidget", "123", nullptr));
        pb_clear->setText(QCoreApplication::translate("LoginWidget", "\346\270\205\347\251\272", nullptr));
        pb_login->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_login), QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        pb_register_clear->setText(QCoreApplication::translate("LoginWidget", "\346\270\205\347\251\272", nullptr));
        pb_register->setText(QCoreApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
        l_nick->setText(QCoreApplication::translate("LoginWidget", "\346\230\265\347\247\260", nullptr));
        le_nick->setText(QString());
        l_register_tel->setText(QCoreApplication::translate("LoginWidget", "\346\211\213\346\234\272\345\217\267", nullptr));
        le_register_tel->setText(QCoreApplication::translate("LoginWidget", "1234567890", nullptr));
        l_register_pass->setText(QCoreApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        le_register_pass->setText(QCoreApplication::translate("LoginWidget", "123", nullptr));
        l_pass_again->setText(QCoreApplication::translate("LoginWidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        le_pass_again->setText(QCoreApplication::translate("LoginWidget", "123", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_register), QCoreApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
