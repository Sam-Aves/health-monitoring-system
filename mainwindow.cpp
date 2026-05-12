#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h" // Include the header file for SecDialog
#include "registrationdialog.h"

#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->setStyleSheet("QMessageBox { color: white; }"
                "QMessageBox QLabel { color: white; }");
    connect(ui->btnRegister, &QPushButton::clicked, this, &MainWindow::on_btnRegister_clicked);
    connect(ui->pushButton_login, &QPushButton::clicked, this, &MainWindow::on_pushButton_login_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Successful login
       // int userId = query.value(0).toInt(); // Assuming id is in the first column (index 0)
        QString firstName = query.value(1).toString(); // Assuming first_name is in the second column (index 1)
        QString lastName = query.value(2).toString(); // Assuming last_name is in the third column (index 2)
        // Fetch other relevant user information similarly
        currentUsername = username;
        QMessageBox::information(this, "Login Successful", "Welcome, " + firstName + " " + lastName + "!");

        // Open secDialog
        SecDialog *secDialog = new SecDialog(currentUsername, this);
        secDialog->exec();  // Use exec() for modal dialog
        delete secDialog;   // Delete dialog if not needed anymore
    } else {
        // Failed login
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}


void MainWindow::on_btnRegister_clicked()
{
    registrationdialog dialog(this);

    // Show the dialog modally
    dialog.exec();
}

