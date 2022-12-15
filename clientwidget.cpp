//时间：2022/12/14
//作者：张凯歌
//作用:客户端
#include "clientwidget.h"
#include "ui_clientwidget.h"

clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWidget)
{
    ui->setupUi(this);
     socket = new QTcpSocket(this);

     //未连接状态
    connectState = false;
    //接收信息
    connect(socket, &QTcpSocket::readyRead, this, &clientWidget::readMessage);
    //打印断开连接信息
    connect(socket, &QTcpSocket::disconnected, this, &clientWidget::disconnectSlot);

}


void clientWidget::set(int* temp,QString temp_str)
{
    remains = temp;
    user= temp_str;
}
clientWidget::~clientWidget()
{
    delete ui;
}

void clientWidget::on_connectBtn_clicked()
{
    //界面显示的地址
    QString ipStr = ui->leipAddress->text();
    //界面显示的当前端口
    quint16 currentPort = ui->leport->text().toInt();
    //客户端还未连接服务端
    if(!connectState)
    {
        //连接服务端
        socket->connectToHost(ipStr, currentPort);
        //等待连接成功
        if(socket->waitForConnected())
        {
            ui->listWidget->addItem("连接成功");
            ui->connectBtn->setText("关闭连接");

            connectState = true;
        }
        //连接失败
        else
        {
            QMessageBox::warning(this, "连接失败", socket->errorString());   //连接错误信息提醒
        }
    }
   //客户端已经连接
    else
    {
        //关闭套接字，此时会发送disconnected信号
        socket->close();

        ui->connectBtn->setText("连接");
    }
}

//接收信息
void clientWidget::readMessage()
{

    QByteArray arr = socket->readAll();
    QString str = arr.data();
    //显示信息
    str = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss") + '\n' + arr.data();
    ui->textReceive->append(str);
    QString temp =str.at(str.size() - 1);
   //判断
    if(temp=="！")
    {
        qDebug()<<"zml";
        QMessageBox::information(this,"游戏结束","遗憾落败" ,QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}


//打印连接断开信息
void clientWidget::disconnectSlot()
{
    ui->listWidget->addItem("clint disconnected");
}

//给服务端发送信息
void clientWidget::send(int remains)
{
    QString str = QString::number(remains);
    if(socket->isOpen() && socket->isValid())
    {
        socket->write(str.toUtf8());

    }

}


void clientWidget::on_sendBtn_clicked()
{
    QString str = QString::number(*remains);
    str = "用户：" +user+ '\n' + str;
    if(socket->isOpen() && socket->isValid())
    {
        socket->write(str.toUtf8());

    }
}


void clientWidget::on_sendBtn_2_clicked()
{
    QString str = ui->textSend->toPlainText();

    str = "用户：" +user+ '\n' + str;
    if(socket->isOpen() && socket->isValid())
    {
        socket->write(str.toUtf8());    //给服务端发送信息
        ui->textSend->clear();
    }

    QString showStr = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss")+'\n' +str;
    ui->textReceive->append(showStr);     //显示自己发送的信息
}

