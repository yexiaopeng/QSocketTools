#include "qsockettools.h"
#include "ui_qsockettools.h"
#include <QTime>




QSocketTools::QSocketTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QSocketTools)
{
    ui->setupUi(this);

    this->init();
}

QSocketTools::~QSocketTools()
{
    delete ui;
}

void QSocketTools::init()
{
    /* the tcp socket is connected or not */
    this->isConnectFlag = false;
    QPalette pal = ui->pb_TcpConnect->palette();
    pal.setColor(QPalette::Button,Qt::red);
    ui->pb_TcpConnect->setPalette(pal);


    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                this->ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }



    /* default socket param */
    ui->le_ServerAddr->setText("127.0.0.1");
    ui->le_ServerPort->setText("21688");
    ui->le_localAddr->setDisabled(true);
    ui->le_localPort->setDisabled(true);


    /* new a tcp socket */
    this->tcpSocket = new QTcpSocket(this);

    /* is use my protocol or not */
    this->isDefauleProtocol = false;
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readDataReceiveServer()));
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));


    /* receive number */
    this->receiveNum = 0;

    /*defaule not use user-defined's  protocol */
    this->isDefauleProtocol = false;

    char  msecur[32] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    memcpy(this->SecurityData,msecur,sizeof(char)*32);

}


void QSocketTools::on_pb_TcpConnect_clicked()
{


    if(this->isConnectFlag){
        this->disConnectToServer();
    }else{

        this->connectToServer();
    }
}



void QSocketTools::connectToServer()
{
    //初始化数据大小信息为0
      blockSize = 0;
      //取消已有的连接
      tcpSocket->abort();
      //连接到主机
      tcpSocket->connectToHost(ui->le_ServerAddr->text(),
                               ui->le_ServerPort->text().toInt());
}

void QSocketTools::slotConnected()
{
    QPalette pal = ui->pb_TcpConnect->palette();
    this->isConnectFlag = true;
    pal.setColor(QPalette::Button,Qt::green);
    ui->pb_TcpConnect->setPalette(pal);

    ui->le_localAddr->setText(ipAddress);
    ui->le_localPort->setText(QString("%1").arg(this->tcpSocket->localPort()));
}

void QSocketTools::slotDisconnected()
{
    QPalette pal = ui->pb_TcpConnect->palette();
    this->isConnectFlag = false;
    pal.setColor(QPalette::Button,Qt::red);
    ui->pb_TcpConnect->setPalette(pal);
    ui->le_localAddr->setText("");
    ui->le_localPort->setText("");
}

void QSocketTools::disConnectToServer()
{
    if(this->isConnectFlag == false){
        return ;
    }

    this->tcpSocket->abort();
}



void QSocketTools::on_pb_SendData_clicked()
{
    if(this->isConnectFlag == false){
        return ;
    }

    if(this->isDefauleProtocol){
        //use-protocol
        QString  message;
        message = ui->le_SendData->text();
        QByteArray bytearray= message.toLocal8Bit();
        char* pstr = (char*)bytearray.data();

        //data use protocol process

       //
        BYTE mprotocolType = 2;
        NTDeviceMark  *pdeviceID = (NTDeviceMark  *)malloc(sizeof(NTDeviceMark));
        pdeviceID->deviceID = 1234;
        pdeviceID->deviceType = 32;
        INT16 mpackID = 45;
        BYTE mprotocolID = 7;
        BYTE mver = 1;
        DWORD mtime = 145567;
        WORD mlength = bytearray.length();
 //         const NTDeviceMark* pdeviceID,
//                                              INT16 mpackID, BYTE mprotocolID, BYTE mver, DWORD mtime,
//                                              WORD mlength,void *pdata, const char*SecurityData
        char  msecur[32] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
      NTNetProtocolPack * sendData =    NetProtocolPackage(mprotocolType,pdeviceID,mpackID,mprotocolID,mver,mtime,mlength,pstr,msecur);
        this->tcpSocket->write((const char *)sendData,sizeof(NTNetProtocolPack) - sizeof(WORD) +  mlength);
//      free(pdeviceID);
//      free(sendData);

    }else{
        //not use protocol
        QString  message;
        message = ui->le_SendData->text();
        QByteArray bytearray= message.toLocal8Bit();
        char* pstr = (char*)bytearray.data();

        this->tcpSocket->write((const char *)pstr,strlen(pstr));
    }
}




void QSocketTools::readDataReceiveServer()
{
       QByteArray buffer=tcpSocket->readAll();
       char *message = buffer.data();
       QString data = QString(QLatin1String(message));
       QDateTime time = QDateTime::currentDateTime();
       QString str = time.toString("yyyy-MM-dd hh:mm:ss");
       QString TAG = str  + "  " + "CLIent";

       QString showData = TAG + "Receive Data "+" size :" + QString::number(data.size(),10) + " Receive num: " + QString::number(++this->receiveNum,10);
       ui->tb_ReceiveData->setTextColor(QColor("red"));
       ui->tb_ReceiveData->append(showData);
       ui->tb_ReceiveData->setTextColor(QColor("blue"));
       ui->tb_ReceiveData->append(data);
}



void QSocketTools::on_pb_CleanReceive_clicked()
{
    ui->tb_ReceiveData->clear();
}



void QSocketTools::on_cb_isDefaultProtocol_clicked()
{
    if(ui->cb_isDefaultProtocol->isChecked())
        this->isDefauleProtocol = true;
    else
        this->isDefauleProtocol = false;
}

void QSocketTools::on_pushButton_3_clicked()
{

}

void QSocketTools::on_pushButton_clicked()
{

}

void QSocketTools::on_pushButton_2_clicked()
{

}
