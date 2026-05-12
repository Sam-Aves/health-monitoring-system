#include "scheduleappointmentdialog.h"
#include "ui_scheduleappointmentdialog.h"
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QWidget>
#include <QSqlDatabase>
#include "mainwindow.h"


scheduleappointmentdialog::scheduleappointmentdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::scheduleappointmentdialog)
{
    ui->setupUi(this);
    connect(ui->buttonBook, &QPushButton::clicked, this, &scheduleappointmentdialog::on_buttonBook_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &scheduleappointmentdialog::on_buttonClose_clicked);

    populateAvailableSlots();

}
scheduleappointmentdialog::scheduleappointmentdialog(QString currentUsername, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scheduleappointmentdialog),
    currentUsername(currentUsername)
{
    ui->setupUi(this);
    connect(ui->buttonBook, &QPushButton::clicked, this, &scheduleappointmentdialog::on_buttonBook_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &scheduleappointmentdialog::on_buttonClose_clicked);

    populateAvailableSlots();
}
scheduleappointmentdialog::~scheduleappointmentdialog()
{
    delete ui;
}



void scheduleappointmentdialog::on_buttonBook_clicked()
{
    QString selectedSlot = ui->comboBoxAvailableSlots->currentText(); // Get selected slot from combobox
    QString customSelection = ui->lineEditCustomSlot->text(); // Get custom selection from line edit

    // Validate inputs (if needed)

    if (currentUsername.isEmpty()) {
        qDebug() << "Error: Username not available.";
        QMessageBox::critical(this, "Error", "Username not available.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database(); // Assuming the database is already connected

    QSqlQuery query(db);
    query.prepare("UPDATE users SET appointments = :appointments WHERE username = :username");
    query.bindValue(":appointments", selectedSlot + " - " + customSelection); // Concatenate selected slot and custom selection
    query.bindValue(":username", currentUsername); // Bind currentUsername

    if (!query.exec()) {
        qDebug() << "Error booking appointment:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to book appointment.");
    } else {
        qDebug() << "Appointment booked successfully";
        QMessageBox::information(this, "Success", "Appointment booked successfully.");

        // Optionally, emit a signal or perform additional actions after successful booking
    }
}
void scheduleappointmentdialog::on_buttonClose_clicked()
{
    close();
}

void scheduleappointmentdialog::populateAvailableSlots()
{
    ui->comboBoxAvailableSlots->addItem("09:00 AM - 09:30 AM");
    ui->comboBoxAvailableSlots->addItem("10:00 AM - 10:30 AM");
    ui->comboBoxAvailableSlots->addItem("11:00 AM - 11:30 AM");
    ui->comboBoxAvailableSlots->addItem("01:00 PM - 01:30 PM");
    ui->comboBoxAvailableSlots->addItem("02:00 PM - 02:30 PM");
    ui->comboBoxAvailableSlots->addItem("03:00 PM - 03:30 PM");
    ui->comboBoxAvailableSlots->addItem("04:00 PM - 04:30 PM");
    ui->comboBoxAvailableSlots->addItem("05:00 PM - 05:30 PM");
    ui->comboBoxAvailableSlots->addItem("06:00 PM - 06:30 PM");
    ui->comboBoxAvailableSlots->addItem("07:00 PM - 07:30 PM");
    ui->comboBoxAvailableSlots->addItem("08:00 PM - 08:30 PM");

}
