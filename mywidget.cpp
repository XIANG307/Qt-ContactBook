#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QStringConverter>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->contactBook->setColumnCount(4);
    QStringList colTotal;
    colTotal<<"學號"<<"班級"<<"姓名"<<"電話";
    ui->contactBook->setHorizontalHeaderLabels(colTotal);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_insentButton_clicked()
{
    QTableWidgetItem *col1,*col2 ,*col3 ,*col4 ;
    col1 = new QTableWidgetItem(ui->lineEdit_1->text());
    col2 = new QTableWidgetItem(ui->lineEdit_2->text());
    col3 = new QTableWidgetItem(ui->lineEdit_3->text());
    col4 = new QTableWidgetItem(ui->lineEdit_4->text());
    int row = ui->contactBook->rowCount();
    qDebug()<<row;
    ui->contactBook->insertRow(row);
    ui->contactBook->setItem(row,0,col1);
    ui->contactBook->setItem(row,1,col2);
    ui->contactBook->setItem(row,2,col3);
    ui->contactBook->setItem(row,3,col4);
}
void CbWrite(QString fileName,QString str)
{
    QFile outFile(fileName);
    if(!outFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"Open File failed!";
        return;
    }
    QTextStream out(&outFile);
    out.setEncoding(QStringConverter::System);
    out<<str;
    outFile.flush();
    outFile.close();
}


void MyWidget::on_exportButton_clicked()
{
    QString fileName;
    QString saveStr;
    fileName = QFileDialog::getSaveFileName(this, "匯出通訊錄", ".",
                                            "csv(*.csv);;text(*.txt)");
    for(int i=0; i<ui->contactBook->rowCount(); i++)
    {
        for(int j=0; j<ui->contactBook->columnCount(); j++)
        {
            saveStr += ui->contactBook->item(i, j)->text() + ",";
        }
        saveStr += "\n";
    }
    CbWrite(fileName, saveStr);
}


void MyWidget::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, "匯入通訊錄", ".", "csv(*.csv);;text(*.txt)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "錯誤", "無法開啟檔案！");
        return;
    }

    ui->contactBook->setRowCount(0);

    QTextStream in(&file);
    in.setEncoding(QStringConverter::System);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) {
            continue;
        }

        QStringList fields = line.split(',');


        int currentRow = ui->contactBook->rowCount();
        ui->contactBook->insertRow(currentRow);

        for (int col = 0; col < fields.size() && col < ui->contactBook->columnCount(); col++) {
            ui->contactBook->setItem(currentRow, col, new QTableWidgetItem(fields.at(col)));
        }
    }

    file.close();

}

