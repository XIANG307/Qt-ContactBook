/********************************************************************************
** Form generated from reading UI file 'tcpfileserver.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPFILESERVER_H
#define UI_TCPFILESERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_TcpFileServer
{
public:

    void setupUi(QDialog *TcpFileServer)
    {
        if (TcpFileServer->objectName().isEmpty())
            TcpFileServer->setObjectName("TcpFileServer");
        TcpFileServer->resize(800, 600);

        retranslateUi(TcpFileServer);

        QMetaObject::connectSlotsByName(TcpFileServer);
    } // setupUi

    void retranslateUi(QDialog *TcpFileServer)
    {
        TcpFileServer->setWindowTitle(QCoreApplication::translate("TcpFileServer", "TcpFileServer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpFileServer: public Ui_TcpFileServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPFILESERVER_H
