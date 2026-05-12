#include "doctorsappointmentdialog.h"
#include "ui_doctorsappointmentdialog.h"
#include "scheduleappointmentdialog.h"
#include "cancelappointmentdialog.h"

DoctorsAppointmentDialog::DoctorsAppointmentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoctorsAppointmentDialog)
{
    ui->setupUi(this);

    connect(ui->buttonScheduleAppointment, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonScheduleAppointment_clicked);
    connect(ui->buttonCancelAppointment, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonCancelAppointment_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonClose_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonExit_clicked);
}
DoctorsAppointmentDialog::DoctorsAppointmentDialog(const QString &currentUsername, QWidget *parent)
    : QDialog(parent)  // Correct base class initialization
    , ui(new Ui::DoctorsAppointmentDialog)
    , currentUsername(currentUsername)
{
    ui->setupUi(this);
    connect(ui->buttonScheduleAppointment, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonScheduleAppointment_clicked);
    connect(ui->buttonCancelAppointment, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonCancelAppointment_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonClose_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &DoctorsAppointmentDialog::on_buttonExit_clicked);
}
DoctorsAppointmentDialog::~DoctorsAppointmentDialog()
{
    delete ui;
}

void DoctorsAppointmentDialog::on_buttonScheduleAppointment_clicked()
{
    scheduleappointmentdialog *dialog = new scheduleappointmentdialog(currentUsername, this);
    dialog->exec(); // Use exec() for modal dialog
    delete dialog;
}


void DoctorsAppointmentDialog::on_buttonCancelAppointment_clicked()
{
    CancelAppointmentDialog cancelDialog(this);

    // Show the dialog modally
    cancelDialog.exec();
}




void DoctorsAppointmentDialog::on_buttonClose_clicked()
{
    close();
}

void DoctorsAppointmentDialog::on_buttonExit_clicked()
{
    qApp->exit();
}

