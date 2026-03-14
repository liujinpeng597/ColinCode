#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &str);

    void on_pb_emitSignal_clicked();

public slots: //槽函数前必须有两个关键字修饰
    //返回类型固定void 函数名任意 参数应当与信号保持一致
    void slots_ctrlLineEdit(int); //槽函数声明

    void slots_dealButton(QAbstractButton *button); //槽函数声明

signals: //一个关键字修饰 不要加访问修饰符
    void signals_sendNumber(int number);//信号只需要声明不需要定义

private:
    Ui::MainWindow *ui;

    //自定义弹出框
    QMessageBox m_msgBox;
    QPushButton * pOk;
    QPushButton * pNo;
};
#endif // MAINWINDOW_H
