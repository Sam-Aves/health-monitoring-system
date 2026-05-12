#include "cancelappointmentdialog.h"
#include "ui_cancelappointmentdialog.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>

CancelAppointmentDialog::CancelAppointmentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CancelAppointmentDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &CancelAppointmentDialog::on_buttonCancel_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &CancelAppointmentDialog::on_buttonClose_clicked);

    populateAppointments();
}
CancelAppointmentDialog::CancelAppointmentDialog(const QString &currentUsername, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CancelAppointmentDialog),
    currentUsername(currentUsername)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, &QPushButton::clicked, this, &CancelAppointmentDialog::on_buttonCancel_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &CancelAppointmentDialog::on_buttonClose_clicked);

    populateAppointments();
}
CancelAppointmentDialog::~CancelAppointmentDialog()
{
    delete ui;
}

void CancelAppointmentDialog::populateAppointments()
{
    // Clear the combo box before populating
    ui->comboBoxAvailableSlots->clear();

    // Add some example slots
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


void CancelAppointmentDialog::on_buttonCancel_clicked()
{
    QString selectedSlot = ui->comboBoxAvailableSlots->currentText();

    if (selectedSlot.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No slot selected to cancel.");
        return;
    }

    // Show success message
    QMessageBox::information(this, "Success", "Appointment canceled successfully.");
}


void CancelAppointmentDialog::on_buttonClose_clicked()
{
    close();
}

