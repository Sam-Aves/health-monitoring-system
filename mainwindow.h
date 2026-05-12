#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include<ui_secdialog.h>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();


    void on_btnRegister_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog; // Correctly declare SecDialog pointer here
    QString currentUsername;
};

#endif // MAINWINDOW_H
