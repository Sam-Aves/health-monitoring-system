#include "glucosemonitordialog.h"
#include "ui_glucosemonitordialog.h"
#include <QMessageBox>

StatusDialog::StatusDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatusDialog)
{
    ui->setupUi(this);

    ui->setupUi(this);

    ui->labelGuide->setText("Please input your glucose level here:");
    ui->labelNormalLevel->setText("Normal glucose level: 70-140 mg/dL");

    // Align the texts to the center
    ui->labelGuide->setAlignment(Qt::AlignCenter);
    ui->labelNormalLevel->setAlignment(Qt::AlignCenter);
    ui->labelOutput->setAlignment(Qt::AlignCenter);


    connect(ui->buttonCompare, &QPushButton::clicked, this, &StatusDialog::on_buttonCompare_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &StatusDialog::on_buttonClose_clicked);
    connect(ui->buttonClear, &QPushButton::clicked, this, &StatusDialog::on_buttonClear_clicked);
}

StatusDialog::~StatusDialog()
{
    delete ui;
}

void StatusDialog::on_buttonCompare_clicked()
{
    bool ok;
    double glucoseLevel = ui->lineEditGlucose->text().toDouble(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number for glucose level.");
        return;
    }

    QString comparisonResult;
    if (glucoseLevel < 70) {
        comparisonResult = "Low Glucose Level";
    } else if (glucoseLevel >= 70 && glucoseLevel <= 140) {
        comparisonResult = "Normal Glucose Level";
    } else {
        comparisonResult = "High Glucose Level";
    }

    ui->labelOutput->setText(comparisonResult);
}


void StatusDialog::on_buttonClear_clicked()
{
    qDebug() << "Clear button clicked"; // Debugging line
    ui->lineEditGlucose->clear();
    ui->labelOutput->clear();
}


void StatusDialog::on_buttonClose_clicked()
{
    close();
}

