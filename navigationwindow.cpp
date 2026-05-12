// navigationwindow.cpp
#include "navigationwindow.h"
#include "ui_navigationwindow.h"
#include "temperaturemonitordialog.h"
#include "oxygenmonitordialog.h"
#include "bloodpressuremonitordialog.h"
#include "goalsdialog.h"
#include "recommendedplansdialog.h"
#include "glucosemonitordialog.h"

#include <QInputDialog>

NavigationWindow::NavigationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigationWindow)
{
    ui->setupUi(this);

    doctorsAppointmentDialog = new DoctorsAppointmentDialog(this);

    // Connect the Doctors Appointment button click to the appropriate slot
    connect(ui->btnDoctorsAppointment, &QPushButton::clicked, this, &NavigationWindow::on_btnDoctorsAppointment_clicked);

    connect(ui->btnMonitorTemp, &QPushButton::clicked, this, &NavigationWindow::on_btnMonitorTemp_clicked);

    // Initialize TemperatureMonitorDialog instance
    temperatureMonitorDialog = new TemperatureMonitorDialog(this);
    connect(ui->btnMonitorBP, &QPushButton::clicked, this, &NavigationWindow::on_btnMonitorBP_clicked);

    connect(ui->btnViewGoal, &QPushButton::clicked, this, &NavigationWindow::on_btnViewGoal_clicked);

    recommendedPlanDialog = new recommendedplansdialog(this);
    connect(ui->btnRecommendedPlans, &QPushButton::clicked, this, &NavigationWindow::on_btnRecommendedPlans_clicked);
    connect(ui->btnCurrentStatus, &QPushButton::clicked, this, &NavigationWindow::on_btnCurrentStatus_clicked);

}
NavigationWindow::NavigationWindow(const QString &currentUsername, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NavigationWindow)
    , currentUsername(currentUsername)
{
    ui->setupUi(this);

    connect(ui->btnDoctorsAppointment, &QPushButton::clicked, this, &NavigationWindow::on_btnDoctorsAppointment_clicked);
    doctorsAppointmentDialog = new DoctorsAppointmentDialog(this);

    // Connect the Doctors Appointment button click to the appropriate slot
    connect(ui->btnDoctorsAppointment, &QPushButton::clicked, this, &NavigationWindow::on_btnDoctorsAppointment_clicked);

    connect(ui->btnMonitorTemp, &QPushButton::clicked, this, &NavigationWindow::on_btnMonitorTemp_clicked);

    // Initialize TemperatureMonitorDialog instance
    temperatureMonitorDialog = new TemperatureMonitorDialog(this);
    connect(ui->btnMonitorBP, &QPushButton::clicked, this, &NavigationWindow::on_btnMonitorBP_clicked);

    connect(ui->btnViewGoal, &QPushButton::clicked, this, &NavigationWindow::on_btnViewGoal_clicked);

    recommendedPlanDialog = new recommendedplansdialog(this);
    connect(ui->btnRecommendedPlans, &QPushButton::clicked, this, &NavigationWindow::on_btnRecommendedPlans_clicked);
    connect(ui->btnCurrentStatus, &QPushButton::clicked, this, &NavigationWindow::on_btnCurrentStatus_clicked);
}

NavigationWindow::~NavigationWindow()
{
    delete ui;
    delete doctorsAppointmentDialog;
    delete temperatureMonitorDialog;
    delete recommendedPlanDialog;
}

void NavigationWindow::on_btnExit_clicked()
{
    qApp->exit();
}


void NavigationWindow::on_btnDoctorsAppointment_clicked()
{
    DoctorsAppointmentDialog *dialog = new DoctorsAppointmentDialog(currentUsername, this);
    dialog->exec(); // Use exec() for modal dialog
}


void NavigationWindow::on_btnMonitorTemp_clicked()
{
    // Get user input temperature (for demo purposes, you can replace this with actual input retrieval)
    bool ok;
    double userInputTemp = QInputDialog::getDouble(this, "Enter Temperature", "Enter your temperature (in °C):", 37.0, -100, 100, 1, &ok);

    if (ok) {
        // Set user input temperature and show the TemperatureMonitorDialog
        temperatureMonitorDialog->setUserTemperature(userInputTemp);
        temperatureMonitorDialog->exec(); // Show the dialog as modal
    }
}


void NavigationWindow::on_btnMonitorOxygen_clicked()
{
    oxygenmonitordialog *oxygenDialog = new oxygenmonitordialog(this);
    oxygenDialog->exec(); // Show the dialog as modal
}


void NavigationWindow::on_btnMonitorBP_clicked()
{
    BloodPressureMonitorDialog *bpDialog = new BloodPressureMonitorDialog(this);
    bpDialog->exec(); // Show the dialog as modal
}


void NavigationWindow::on_btnViewGoal_clicked()
{
    goalsdialog *goalsDialog = new goalsdialog(this);
    goalsDialog->exec();
}


void NavigationWindow::on_btnRecommendedPlans_clicked()
{
   recommendedPlanDialog->exec();
}


void NavigationWindow::on_btnCurrentStatus_clicked()
{
    StatusDialog statusDialog(this); // Create an instance of StatusDialog
    statusDialog.exec(); // Show the dialog modally
}

