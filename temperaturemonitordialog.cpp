#include "temperaturemonitordialog.h"
#include "ui_temperaturemonitordialog.h"

TemperatureMonitorDialog::TemperatureMonitorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TemperatureMonitorDialog)
{
    ui->setupUi(this);
}

TemperatureMonitorDialog::~TemperatureMonitorDialog()
{
    delete ui;
}
void TemperatureMonitorDialog::setUserTemperature(double temperature)
{
    userTemperature = temperature;
    ui->lineEditUserTemperature->setText(QString::number(userTemperature, 'f', 1)); // Set QLineEdit text

    // Set the font color of user input text to white
    ui->lineEditUserTemperature->setStyleSheet("QLineEdit { color: white; }");

    updateTemperatureComparison();
}
void TemperatureMonitorDialog::updateTemperatureComparison()
{
    // Compare userTemperature with normal body temperature range
    double normalMin = 36.5; // Example normal body temperature range (adjust as needed)
    double normalMax = 37.3;

    // Display user input temperature
    ui->labelUserTemperature->setText(QString("Your Temperature: %1 °C").arg(userTemperature));

    // Compare and display result
    if (userTemperature >= normalMin && userTemperature <= normalMax) {
        ui->labelComparisonResult->setText("Your temperature is normal.");
    } else {
        ui->labelComparisonResult->setText("Your temperature is outside the normal range.");
    }
     ui->labelComparisonResult->setAlignment(Qt::AlignCenter);
}

void TemperatureMonitorDialog::on_buttonExit_clicked()
{
    QApplication::quit();
}


void TemperatureMonitorDialog::on_buttonClose_clicked()
{
    this->accept();
}

