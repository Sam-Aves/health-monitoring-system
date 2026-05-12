#include "bloodpressuremonitordialog.h"
#include "ui_bloodpressuremonitordialog.h"

BloodPressureMonitorDialog::BloodPressureMonitorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BloodPressureMonitorDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCompare, &QPushButton::clicked, this, &BloodPressureMonitorDialog::compareBloodPressure);
    connect(ui->buttonClear, &QPushButton::clicked, this, &BloodPressureMonitorDialog::clearInputs);
    connect(ui->buttonClose, &QPushButton::clicked, this, &BloodPressureMonitorDialog::closeDialog);

    ui->labelNormalBloodPressure->setText("Normal Blood Pressure: <120/80 mmHg");

}

BloodPressureMonitorDialog::~BloodPressureMonitorDialog()
{
    delete ui;
}
void BloodPressureMonitorDialog::compareBloodPressure()
{
    // Get user input pressures
    double userSystolic = ui->lineEditSystolic->text().toDouble();
    double userDiastolic = ui->lineEditDiastolic->text().toDouble();

    // Update the comparison result label
    updateComparisonResult(userSystolic, userDiastolic);
}
void BloodPressureMonitorDialog::clearInputs()
{
    ui->lineEditSystolic->clear();
    ui->lineEditDiastolic->clear();
    ui->labelComparisonResult->clear(); // Clear comparison result label
}
void BloodPressureMonitorDialog::closeDialog()
{
    close(); // Close the dialog window
}
void BloodPressureMonitorDialog::updateComparisonResult(double systolic, double diastolic)
{
    double normalSystolic = 120.0;
    double normalDiastolic = 80.0;

    QString resultText;

    // Check systolic pressure
    if (systolic > normalSystolic) {
        resultText += "High Systolic Pressure!\n ";
    } else if (systolic < normalSystolic) {
        resultText += "Low Systolic Pressure!\n ";
    } else {
        resultText += "Normal Systolic Pressure.\n ";
    }

    // Check diastolic pressure
    if (diastolic > normalDiastolic) {
        resultText += "High Diastolic Pressure!\n";
    } else if (diastolic < normalDiastolic) {
        resultText += "Low Diastolic Pressure!\n";
    } else {
        resultText += "Normal Diastolic Pressure.\n";
    }

    if (systolic <= 90.0 && diastolic <= 60.0) {
        resultText += "Severely Low Blood Pressure (Hypotension)\n";
    }
    // Check for hypertension (high blood pressure)
    else if ((systolic >= 140.0 && diastolic >= 90.0)) {
        resultText += "Hypertension\n";
    }
    else resultText += " ";
    // Update the comparison result label
    // Update the comparison result label
    ui->labelComparisonResult->setText(resultText);
}
