#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "ui_secdialog.h"
#include<navigationwindow.h>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    explicit SecDialog(QString currentUsername, QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_btnNavigation_clicked(); // Slot for navigation button
    void on_btnExit_clicked(); // Slot for exit button

private:
    Ui::secDialog *ui;
    QLabel *labelInstruction1;
    QLabel *labelInstruction2;
    QPushButton *btnNavigation;
    QPushButton *btnExit;
    QString currentUsername;
};

#endif // SECDIALOG_H
