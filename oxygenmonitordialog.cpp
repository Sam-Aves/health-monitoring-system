#include "oxygenmonitordialog.h"
#include "ui_oxygenmonitordialog.h"

#include <QString>
#include <QDebug>

oxygenmonitordialog::oxygenmonitordialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::oxygenmonitordialog)
{
    ui->setupUi(this);

    ui->lineEditUserOxygenLevel->setPlaceholderText("Enter Oxygen Level");
    ui->lineEditNormalOxygenLevel->setReadOnly(true);
    ui->lineEditNormalOxygenLevel->setText("95% to 100%(SpO2)");
    connect(ui->buttonCompare, &QPushButton::clicked, this, &oxygenmonitordialog::compareOxygenLevels);
    connect(ui->buttonClear, &QPushButton::clicked, this, &oxygenmonitordialog::clearInformation);
    connect(ui->buttonClose, &QPushButton::clicked, this, &QDialog::close); // Close the dialog
    ui->labelComparisonResult->setAlignment(Qt::AlignCenter);
}

oxygenmonitordialog::~oxygenmonitordialog()
{
    delete ui;
}
void oxygenmonitordialog::compareOxygenLevels()
{
    // Get user input oxygen level
    double userOxygenLevel = ui->lineEditUserOxygenLevel->text().toDouble();
    double normalOxygenLevelMin = 95.0;
    double normalOxygenLevelMax = 100.0;

    // Perform comparison logic
    QString resultText;
    if (userOxygenLevel < normalOxygenLevelMin) {
        resultText = "Your oxygen level is low.";
    } else if (userOxygenLevel > normalOxygenLevelMax) {
        resultText = "Your oxygen level is high.";
    } else {
        resultText = "Your oxygen level is normal.";
    }

    ui->labelComparisonResult->setText(resultText);
}
void oxygenmonitordialog::clearInformation()
{
    // Clear the line edits and comparison result label
    ui->lineEditUserOxygenLevel->clear();
    ui->labelComparisonResult->clear();
}
