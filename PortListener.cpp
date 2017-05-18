/**
 * jaky, armner@gmail.com, FrSky Technology, www.frsky-rc.com
 */

#include <QTextStream>
#include <qextserialport.h>
#include "PortListener.h"
#include <math.h>

PortListener::PortListener(QextSerialPort * port, QObject * parent):
	QObject(parent)
{
	this->port = port;
        linkq=0;
        volt1=0;
        volt2=0;

        timer.setInterval(100);
        connect(&timer,SIGNAL(timeout()),this,SLOT(timeToReport()));
}
#define FSM_RCV_NULL    (0)
#define FSM_RCV_PRIM    (1)
#define FSM_RCV_THRE    (2)
#define FSM_RCV_GREAT   (3)
#define FSM_RCV_ALARM   (4)
#define FSM_RCV_VOLT1   (5)
#define FSM_RCV_VOLT2   (6)
#define FSM_RCV_LINKQ   (7)
#define FSM_RCV_LEN     (8)
#define FSM_RCV_SERIAL  (9)
#define FSM_RCV_DATA    (10)


void PortListener::receive()
{
    char position;
    char data[1024];

    int bytesRead = port->read(data, 1024);
    for(int i=0;i<bytesRead;i++)
    {
        unsigned char temp=data[i];
        //printf("%x ,%x\n",temp,fsm_rcv);
        switch(fsm_rcv)
        {
        case FSM_RCV_NULL:
            if(temp==0xFF)fsm_rcv=FSM_RCV_PRIM;
            break;
        case FSM_RCV_PRIM:
            switch(temp)
            {
                //volts
            case 0xFE:
                fsm_rcv=FSM_RCV_VOLT1;
                break;
                //user data
            case 0xFD:
                fsm_rcv=FSM_RCV_LEN;
                break;
                //
            case 0xFC:
            case 0xFB:
            case 0xFA:
            case 0xF9:
                threshold.channel=0xFC-temp;fsm_rcv=FSM_RCV_THRE;
                break;
            default:
                fsm_rcv=FSM_RCV_NULL;
                break;
            }

            break;
        case FSM_RCV_THRE:
            threshold.value=temp;fsm_rcv=FSM_RCV_GREAT;
            break;
        case FSM_RCV_GREAT:
            threshold.great=temp;fsm_rcv=FSM_RCV_ALARM;
            break;
        case FSM_RCV_ALARM:
            threshold.alarm=temp;
            pushThreshold(&threshold);
            fsm_rcv=FSM_RCV_NULL;
            break;

        case FSM_RCV_VOLT1:
            volt1=temp;fsm_rcv=FSM_RCV_VOLT2;
            break;
        case FSM_RCV_VOLT2:
            volt2=temp;fsm_rcv=FSM_RCV_LINKQ;
            break;
        case FSM_RCV_LINKQ:
            linkq=temp;
            pushVolts(volt1,volt2,linkq);
            fsm_rcv=FSM_RCV_NULL;
            break;

        case FSM_RCV_LEN:
            len=temp;fsm_rcv=FSM_RCV_SERIAL;
            break;
        case FSM_RCV_SERIAL:
            position=0;fsm_rcv=FSM_RCV_DATA;
            break;
        case FSM_RCV_DATA:
            userData[position]=temp;
            position++;
            if(position==len)
            {
                pushBytes(userData,len);
                fsm_rcv=FSM_RCV_NULL;
            }
            break;
        default:
               break;
        }
    }
}

void PortListener::reportWritten(qint64 bytes)
{
}

void PortListener::reportClose()
{
}

void PortListener::reportDsr(bool status)
{
}

/* timer expired, report data & volts */
void PortListener::timeToReport(void)
{
    //emit reportVolts(this->volt1,this->volt2,this->linkq);
    //printf("paint222 %.2x,%.2x %.2x\n",(unsigned char)this->volt1,(unsigned char)this->volt2,(unsigned char)this->linkq);
}
void PortListener::pushBytes(char *buf,char len)
{
    emit reportData(buf,len);
}

void PortListener::pushThreshold(Threshold *threshold)
{
    emit reportThreshold(threshold);
}

void PortListener::pushVolts(char volt1,char volt2,char linkq)
{
//    printf("paint %.2x,%.2x %.2x\n",(unsigned char)volt1,(unsigned char)volt2,(unsigned char)linkq);
    emit reportVolts(volt1,volt2,linkq);
    this->volt1=255-volt1;
    this->volt2=255-volt2;
    this->linkq= (unsigned char)(linkq*2.55);
}

