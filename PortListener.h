/**
 * jaky, armner@gmail.com, FrSky Technology, www.frsky-rc.com
 */

#ifndef PORTLISTENER_H_
#define PORTLISTENER_H_

#include <QObject>
#include <qtimer.h>
#include "frsky_structs.h"

class QextSerialPort;

class PortListener : public QObject
{
    Q_OBJECT

    QextSerialPort * port;
    public:
        QTimer timer;
        PortListener(QextSerialPort * port, QObject * parent = 0);
        Threshold threshold;
        char volt1,volt2,linkq;
        char userData[128];
        char len;

    private:
        char fsm_rcv;
        void pushBytes(char *buf,char len);
        void pushThreshold(Threshold *threshold);
        void pushVolts(char volt1,char volt2,char volt3);

    public slots:
        void receive();
        void reportWritten(qint64 bytes);
        void reportClose();
        void reportDsr(bool status);
        void timeToReport(void);
signals:
        void reportThreshold(Threshold *threshold);
        void reportVolts(char volt1,char volt2,char linkq);
        void reportData(char *, int length);
};


#endif /*PORTLISTENER_H_*/
