#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_quit_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_about_clicked();

    void on_lineEdit_decimal_textEdited(const QString &arg1);

    void on_lineEdit_hexadecimal_textEdited(const QString &arg1);

    void on_lineEdit_binary_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
