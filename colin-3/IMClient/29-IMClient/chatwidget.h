#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();

    void setChatTitle(const QString & title);
    void setChatText(QString);

public slots:
    void slots_sendMsg();
    void slots_clearMsg();
    void slots_fileTransfer();
    void slots_emojiPicker();
    void slots_videoChat();
    void slots_boldText();
    void slots_fontDialog();
    void slots_colorDialog();

signals:
    void signals_sendMsg(QString);


private:
    Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
