/********************************************************************************
** Form generated from reading UI file 'frskyupdate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRSKYUPDATE_H
#define UI_FRSKYUPDATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_frskyUpdate
{
public:
    QProgressBar *progressBarDownload;
    QLabel *labelStatusBar;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonDownload;
    QComboBox *comboBoxPort;
    QLabel *label;

    void setupUi(QDialog *frskyUpdate)
    {
        if (frskyUpdate->objectName().isEmpty())
            frskyUpdate->setObjectName(QString::fromUtf8("frskyUpdate"));
        frskyUpdate->resize(296, 176);
        progressBarDownload = new QProgressBar(frskyUpdate);
        progressBarDownload->setObjectName(QString::fromUtf8("progressBarDownload"));
        progressBarDownload->setGeometry(QRect(30, 70, 251, 23));
        progressBarDownload->setValue(100);
        labelStatusBar = new QLabel(frskyUpdate);
        labelStatusBar->setObjectName(QString::fromUtf8("labelStatusBar"));
        labelStatusBar->setGeometry(QRect(20, 150, 201, 16));
        pushButtonOK = new QPushButton(frskyUpdate);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(20, 110, 81, 31));
        pushButtonCancel = new QPushButton(frskyUpdate);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(200, 110, 81, 31));
        pushButtonDownload = new QPushButton(frskyUpdate);
        pushButtonDownload->setObjectName(QString::fromUtf8("pushButtonDownload"));
        pushButtonDownload->setGeometry(QRect(110, 110, 81, 31));
        comboBoxPort = new QComboBox(frskyUpdate);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setGeometry(QRect(150, 20, 101, 22));
        label = new QLabel(frskyUpdate);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 54, 12));

        retranslateUi(frskyUpdate);

        QMetaObject::connectSlotsByName(frskyUpdate);
    } // setupUi

    void retranslateUi(QDialog *frskyUpdate)
    {
        frskyUpdate->setWindowTitle(QApplication::translate("frskyUpdate", "frskyUpdate", 0, QApplication::UnicodeUTF8));
        labelStatusBar->setText(QApplication::translate("frskyUpdate", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("frskyUpdate", "File", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("frskyUpdate", "End", 0, QApplication::UnicodeUTF8));
        pushButtonDownload->setText(QApplication::translate("frskyUpdate", "Download", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frskyUpdate", "Frsky @", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frskyUpdate: public Ui_frskyUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRSKYUPDATE_H
