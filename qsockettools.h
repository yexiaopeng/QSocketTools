#ifndef QSOCKETTOOLS_H
#define QSOCKETTOOLS_H

#include <QDialog>
#include<QtNetwork/qtcpsocket.h>
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

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    bool isConnectFlag;
    bool isDefauleProtocol;
    QTcpSocket *tcpSocket;
    quint16 blockSize;
    long int receiveNum;
    QString ipAddress;
    char SecurityData[32];



    QList<QHostAddress> address;

    void init(void);

    void connectToServer();

    void disConnectToServer();



private:
    Ui::QSocketTools *ui;


};

#endif // QSOCKETTOOLS_H
