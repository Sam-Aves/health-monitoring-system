#include "secdialog.h"
#include<ui_secdialog.h>
#include "mainwindow.h" // Include your MainWindow header if needed
#include<navigationwindow.h>
#include <QLabel>
#include <QPushButton>
#include <QCoreApplication>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this); // Initialize the UI elements defined in SecDialog.ui

    QLabel *labelInstruction1 = new QLabel("Click \"Go to Navigation Panel\" to navigate", this);
    labelInstruction1->setGeometry(50, 50, 300, 30);

    QLabel *labelInstruction2 = new QLabel("Click 'Exit' to exit the application", this);
    labelInstruction2->setGeometry(50, 100, 200, 30);
    // Connect QPushButton widgets to slots
    connect(ui->btnNavigation, &QPushButton::clicked, this, &SecDialog::on_btnNavigation_clicked);
    connect(ui->btnExit, &QPushButton::clicked, this, &SecDialog::on_btnExit_clicked);

}
SecDialog::SecDialog(QString currentUsername, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog),
    currentUsername(currentUsername)
{
    ui->setupUi(this);

    QLabel *labelInstruction1 = new QLabel("Click \"Go to Navigation Panel\" to navigate", this);
    labelInstruction1->setGeometry(50, 50, 300, 30);

    QLabel *labelInstruction2 = new QLabel("Click 'Exit' to exit the application", this);
    labelInstruction2->setGeometry(50, 100, 200, 30);
    // Connect QPushButton widgets to slots
    connect(ui->btnNavigation, &QPushButton::clicked, this, &SecDialog::on_btnNavigation_clicked);
    connect(ui->btnExit, &QPushButton::clicked, this, &SecDialog::on_btnExit_clicked);

}
SecDialog::~SecDialog()
{
    delete ui;
}


void SecDialog::on_btnNavigation_clicked()
{
    NavigationWindow *navigationWindow = new NavigationWindow(currentUsername, this);
    navigationWindow->exec(); // Use exec() if you want it to be modal
}

void SecDialog::on_btnExit_clicked()
{
    // Example: Close the application
    qApp->exit();
}
