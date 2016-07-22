#ifndef QSOCKETTOOLS_H
#define QSOCKETTOOLS_H

#include <QDialog>
#include<QtNetwork/qtcpsocket.h>
#include <QtNetwork/qudpsocket.h>
#include<QtNetwork/QHostInfo>
#include<QNetworkInterface>


#include "protocol/include/ntprotocol.h"

namespace Ui {
class QSocketTools;
}

class QSocketTools : public QDialog
{
    Q_OBJECT

public:
    explicit QSocketTools(QWidget *parent = 0);
    ~QSocketTools();

private slots:
    void on_pb_TcpConnect_clicked();

    void on_pb_SendData_clicked();

    void readDataReceiveServer();

    void slotConnected();

    void slotDisconnected();

    void on_pb_CleanReceive_clicked();

    void on_cb_isDefaultProtocol_clicked();




    void on_pb_UdpConnect_clicked();

    void readDataReceiveUdp();

    void slotUdpConnected();

    void slotUdpDisconnected();


    void on_pb_SendData_udp_clicked();

private:
    bool isConnectFlag;
    bool isDefauleProtocol;
    QTcpSocket *tcpSocket;
    quint16 blockSize;
    long int receiveNum;
    QString ipAddress;
    char SecurityData[32];


    QUdpSocket * udpSocket;
    bool isUdpConnectFlag;



    QList<QHostAddress> address;

    void init(void);

    void connectToServer();

    void disConnectToServer();

    void connectToUdp();

    void disConnectToUdp();






private:
    Ui::QSocketTools *ui;


};

#endif // QSOCKETTOOLS_H
