//时间：2022/12/14
//作者：张凯歌
//作用:客户端
#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QSound>



namespace Ui {
class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = nullptr);
    ~clientWidget();
    void set(int*,QString);
    //发送消息
    void send(int);

private slots:
    //连接客户端
    void on_connectBtn_clicked();
    //接收信息
    void readMessage();
    //断开连接槽函数
    void disconnectSlot();


    void on_sendBtn_clicked();

    void on_sendBtn_2_clicked();

private:
    Ui::clientWidget *ui;
    QTcpSocket *socket;
     //客户端连接状态
    bool connectState;
    //发送的消息
    int* remains;
    //用户名
    QString user;
};

#endif // CLIENTWIDGET_H
