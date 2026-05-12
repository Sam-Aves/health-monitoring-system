#include "recommendedplansdialog.h"
#include "ui_recommendedplansdialog.h"
#include <QMessageBox>

recommendedplansdialog::recommendedplansdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::recommendedplansdialog)
{
    ui->setupUi(this);
    connect(ui->btnRegisterPlan, &QPushButton::clicked, this, &recommendedplansdialog::on_btnRegisterPlan_clicked);
    connect(ui->btnClose, &QPushButton::clicked, this, &recommendedplansdialog::on_btnClose_clicked);
    connect(ui->comboBoxPlan, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &recommendedplansdialog::on_comboBoxPlan_currentIndexChanged);


    ui->comboBoxPlan->addItem("Plan 90 day fitness");
    ui->comboBoxPlan->addItem("Plan 200 day stay active");
    ui->comboBoxPlan->addItem("Plan 360 days monitoring");
    ui->comboBoxPlan->addItem("Plan 600 days monitor body weight");

}

recommendedplansdialog::~recommendedplansdialog()
{
    delete ui;
}



void recommendedplansdialog::on_btnRegisterPlan_clicked()
{
    QString selectedPlan = ui->comboBoxPlan->currentText(); // Get the current selected plan

    // Perform registration logic here, e.g., update database or perform any required actions

    // Display success message
    QMessageBox::information(this, "Registration Success", "Successfully registered for " + selectedPlan + " plan.");
}


void recommendedplansdialog::on_btnClose_clicked()
{
    close();
}

void recommendedplansdialog::on_comboBoxPlan_currentIndexChanged(int index)
{
    // Get the selected plan text
    QString selectedPlan = ui->comboBoxPlan->itemText(index);

    // You can perform actions based on the selected plan
    if (selectedPlan == "Plan 90 day fitness") {
        // Example: Update details for Plan A
        ui->labelPlanDetails->setText("Plan 90 day fitness Details: This plan includes basic health check-ups.");
    } else if (selectedPlan == "Plan 200 day stay active") {
        // Example: Update details for Plan B
        ui->labelPlanDetails->setText("Plan 200 day stay active Details: This plan includes comprehensive health coverage.");
    } else if (selectedPlan == "Plan 360 days monitoring") {
        // Example: Update details for Plan C
        ui->labelPlanDetails->setText("Plan 360 days monitoring Details: This plan includes specialized treatments.");
    } else if (selectedPlan == "Plan 600 days monitor body weight") {
        // Example: Update details for Plan C
        ui->labelPlanDetails->setText("Plan 600 days monitor body weight Details: This plan includes specialized body weight monitoring plans.");
    }

    // Optionally, you can perform other actions or updates here
}
