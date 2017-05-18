#ifndef FRSKYUPDATE_H
#define FRSKYUPDATE_H

#include <QDialog>
#include <QFileSystemModel>
#include "qextserialenumerator.h"
#include "qextserialport.h"

namespace Ui {
    class frskyUpdate;
}

class frskyUpdate : public QDialog {
    Q_OBJECT
public:
    frskyUpdate(QWidget *parent = 0);
    ~frskyUpdate();

    QString fileName;
    QList<QextPortInfo> ports;
    unsigned char serial[32];
    QextSerialPort commPort;
    QFile file;
    int32_t file_size;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frskyUpdate *ui;

private slots:
    void on_comboBoxPort_currentIndexChanged(QString );
    void on_pushButtonDownload_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonOK_clicked();
    void receive();
};

#endif // FRSKYUPDATE_H
