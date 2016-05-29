#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_decimal->setText("0");
    ui->lineEdit_hexadecimal->setText("0");
    ui->lineEdit_binary->setText("0");
}

void MainWindow::on_pushButton_about_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Developed by Edson Brilhante");
    msgBox.exec();
}

void MainWindow::on_lineEdit_decimal_textEdited(const QString &arg1)
{
    int a = arg1.toInt();

    QString b = QString::number(a,2);
    QString h = QString::number(a,16);
    h = h.toUpper();

    if (a != 0) {
        ui->lineEdit_hexadecimal->setText(h);
        ui->lineEdit_binary->setText(b);
    }
    else {
        ui->lineEdit_hexadecimal->setText("0");
        ui->lineEdit_binary->setText("0");
    }
}

void MainWindow::on_lineEdit_hexadecimal_textEdited(const QString &arg1)
{
    bool ok;
    int a = arg1.toUInt(&ok, 16);

    QString d = QString::number(a);
    QString b = QString::number(a,2);

    if (a != 0) {
        ui->lineEdit_decimal->setText(d);
        ui->lineEdit_binary->setText(b);
    }
    else {
        ui->lineEdit_binary->setText("0");
        ui->lineEdit_decimal->setText("0");
    }
}

void MainWindow::on_lineEdit_binary_textEdited(const QString &arg1)
{
    bool ok;
    int a = arg1.toInt(&ok,2);

    QString d = QString::number(a);
    QString h = QString::number(a,16);
    h = h.toUpper();

    if (a != 0) {
        ui->lineEdit_decimal->setText(d);
        ui->lineEdit_hexadecimal->setText(h);
    }
    else {
        ui->lineEdit_decimal->setText("0");
        ui->lineEdit_hexadecimal->setText("0");
    }
}
