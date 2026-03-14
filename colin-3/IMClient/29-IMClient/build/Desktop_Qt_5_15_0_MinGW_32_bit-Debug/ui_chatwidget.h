/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QTextBrowser *tb_chatrecord;
    QTextEdit *te_msg;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_file;
    QPushButton *pb_emo;
    QPushButton *pb_videochat;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_send;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_clear;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QString::fromUtf8("ChatWidget"));
        ChatWidget->resize(754, 462);
        tb_chatrecord = new QTextBrowser(ChatWidget);
        tb_chatrecord->setObjectName(QString::fromUtf8("tb_chatrecord"));
        tb_chatrecord->setGeometry(QRect(0, 0, 761, 291));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        tb_chatrecord->setFont(font);
        te_msg = new QTextEdit(ChatWidget);
        te_msg->setObjectName(QString::fromUtf8("te_msg"));
        te_msg->setGeometry(QRect(10, 330, 741, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        te_msg->setFont(font1);
        layoutWidget = new QWidget(ChatWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 300, 271, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(13);
        layoutWidget->setFont(font2);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_file = new QPushButton(layoutWidget);
        pb_file->setObjectName(QString::fromUtf8("pb_file"));
        pb_file->setFont(font);

        horizontalLayout->addWidget(pb_file);

        pb_emo = new QPushButton(layoutWidget);
        pb_emo->setObjectName(QString::fromUtf8("pb_emo"));
        pb_emo->setFont(font);

        horizontalLayout->addWidget(pb_emo);

        pb_videochat = new QPushButton(layoutWidget);
        pb_videochat->setObjectName(QString::fromUtf8("pb_videochat"));
        pb_videochat->setFont(font);

        horizontalLayout->addWidget(pb_videochat);

        layoutWidget1 = new QWidget(ChatWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(550, 430, 201, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_send = new QPushButton(layoutWidget1);
        pb_send->setObjectName(QString::fromUtf8("pb_send"));
        pb_send->setFont(font);

        horizontalLayout_2->addWidget(pb_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_clear = new QPushButton(layoutWidget1);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        pb_clear->setFont(font);

        horizontalLayout_2->addWidget(pb_clear);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        pb_file->setText(QCoreApplication::translate("ChatWidget", "\346\226\207\344\273\266\344\274\240\350\276\223", nullptr));
        pb_emo->setText(QCoreApplication::translate("ChatWidget", "\350\241\250\346\203\205", nullptr));
        pb_videochat->setText(QCoreApplication::translate("ChatWidget", "\350\247\206\351\242\221\350\201\212\345\244\251", nullptr));
        pb_send->setText(QCoreApplication::translate("ChatWidget", "\345\217\221\351\200\201", nullptr));
        pb_clear->setText(QCoreApplication::translate("ChatWidget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
