#include "frskyupdate.h"
#include "ui_frskyupdate.h"
#include <qfiledialog.h>
#include "crc16.h"
#include "ymodem_host.h"
#include <qwaitcondition.h>
#include <QMessageBox>

#define FSM_DOWNLOAD_NULL   (0)
#define FSM_DOWNLOAD_START  (1)
#define FSM_DOWNLOAD_SER    (2)
#define FSM_DOWNLOAD_ACK    (3)
#define FSM_DOWNLOAD_NAK    (4)
#define FSM_DOWNLOAD_CAN    (5)
#define FSM_DOWNLOAD_WAIT   (6)

#if Q_OS_WIN
# define errno 0
# define strerror(a) ""
#else
# include <errno.h>
#endif

int fsm=FSM_DOWNLOAD_NULL;

frskyUpdate::frskyUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frskyUpdate)
{
    ui->setupUi(this);
    ui->pushButtonDownload->hide();


    ports = QextSerialEnumerator::getPorts();

    for (int i = 0; i < ports.size(); i++) {
/*
            printf("port name: %s\n", ports.at(i).portName.toLocal8Bit().constData());
            printf("friendly name: %s\n", ports.at(i).friendName.toLocal8Bit().constData());
            printf("physical name: %s\n", ports.at(i).physName.toLocal8Bit().constData());
            printf("enumerator name: %s\n", ports.at(i).enumName.toLocal8Bit().constData());
            printf("===================================\n\n");
*/
        ui->comboBoxPort->addItem(ports.at(i).portName.toLocal8Bit().constData());
    }

    ui->labelStatusBar->setText(ui->comboBoxPort->currentText()+"  "+(fileName.size()?fileName:"file not available"));
}

frskyUpdate::~frskyUpdate()
{
    delete ui;
}

void frskyUpdate::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void frskyUpdate::on_pushButtonOK_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
         tr("Open firmware"), "*.frk", tr("Frsky Files (*.frk)"));
    if(fileName.count())
    {
        ui->pushButtonDownload->show();
        ui->labelStatusBar->setText(ui->comboBoxPort->currentText()+"  "+(fileName.size()?fileName:"file not available"));

    }

    if(1)
    {
#if Q_OS_WIN
        commPort.setPortName(QString("\\\\.\\")+ui->comboBoxPort->currentText());
#else
	commPort.setPortName(ui->comboBoxPort->currentText());
#endif
        commPort.setQueryMode(QextSerialPort::EventDriven);
        commPort.open(QIODevice::ReadWrite);
	if (!commPort.isOpen())
	{
	  QMessageBox::critical(this,"Can't open", QString("Can't open device.")+(errno>0?(QString(" Error %1: %2").arg(QString::number(errno),QString::fromLocal8Bit(strerror(errno)))):""));
	}
        commPort.setBaudRate(BAUD115200);
        commPort.setFlowControl(FLOW_OFF);
        commPort.setParity(PAR_NONE);
        commPort.setDataBits(DATA_8);
        commPort.setStopBits(STOP_1);
//         commPort.setTimeout(2000);

        connect(&commPort,SIGNAL(readyRead()),this,SLOT(receive()));

        //send

    }
}


void frskyUpdate::on_pushButtonCancel_clicked()
{
    this->done(1);
}

void frskyUpdate::on_pushButtonDownload_clicked()
{
    int loop_times;

    if(file.isOpen())
    {
        file.seek(0);
    }
    else{
        file.setFileName(this->fileName);
        file.open(QIODevice::ReadOnly);
        file_size=file.size();
    }

    if(file.size()==0)
    {
        ui->labelStatusBar->setText("File is Vacant");
        file.close();
        return;
    }


    if(fsm==FSM_DOWNLOAD_WAIT)
    {
        fsm= FSM_DOWNLOAD_START;
    }

    /*
    //download file
    while(1){
        char temp;
        char c;
        if(commPort.read(&c,sizeof(c))){
            //check c
        }

        unsigned short crc_value;
        len=file.read(buffer,1024);
        crc_value=crc16_ccitt(buffer, len);
        buffer[len]=crc_value ;
        buffer[len+1]=crc_value>>8;
        commPort.write(buffer,len+2);
        commPort.flush();
    }*/
}

void frskyUpdate::on_comboBoxPort_currentIndexChanged(QString )
{
    ui->labelStatusBar->setText(ui->comboBoxPort->currentText()+"  "+(fileName.size()?fileName:"file not available"));
}

void frskyUpdate::receive()
{
    static char position;
    static char buffer[2048];
    static int len;
    static uint32_t file_len;

    int bytesRead = commPort.read(buffer, 1024);
    for(int i=0; i<bytesRead; i++)
    {
        char c= buffer[i];
        switch (fsm)
        {
        case FSM_DOWNLOAD_NULL:
            if(c== SER){
                fsm=FSM_DOWNLOAD_SER;
                position=0;
            }
            break;
        case FSM_DOWNLOAD_SER:
            if(position <16){
                serial[position]=c;
                position ++;
                if(position>=16){
                    fsm=FSM_DOWNLOAD_WAIT;
                    c=SER;
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    commPort.write(&c,1);
                    QString serialStr;
                    serialStr.sprintf("%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X V%d.%d",
                                      serial[0],serial[1],serial[2],serial[3],serial[4],serial[5],serial[6],serial[7],
                                      serial[11],serial[10]);
                    ui->labelStatusBar->setText("UID: "+serialStr);
                }
            }
            break;
        case FSM_DOWNLOAD_WAIT:
            c=SER;
            commPort.write(&c,1);
            break;
        case FSM_DOWNLOAD_START:
            ui->progressBarDownload->setValue(0);
            file_len=0;
            fsm=FSM_DOWNLOAD_ACK;
            break;
        case FSM_DOWNLOAD_ACK:
            if(c == ACK)
            {
                unsigned short crc_value;
                if(file.atEnd()){
                    fsm =FSM_DOWNLOAD_NULL;
                    c= EOT;
                    commPort.write(&c,sizeof(c));
                    ui->labelStatusBar->setText("Download OK");
                    //ui->progressBarDownload->setValue(100);
                }else{
                    len=file.read(buffer,1024);
                    len=1024;
                    crc_value=crc16_ccitt(buffer, len);
                    buffer[len]=crc_value >>8;
                    buffer[len+1]=crc_value;

                    file_len+=len;

                    ui->progressBarDownload->setValue((100*file_len) /file_size);

                    c = STX;
                    commPort.write(&c,sizeof(c));
                    commPort.write(buffer,len+2);
                }
            }else if(c==NAK){
                c = STX;
                commPort.write(&c,sizeof(c));
                commPort.write(buffer,len+2);
            }else if(c==CAN){
                fsm = FSM_DOWNLOAD_NULL;
                ui->labelStatusBar->setText("DOWNLOAD CANCELED");
            }
            break;
        }
    }

}
