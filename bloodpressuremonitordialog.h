#ifndef BLOODPRESSUREMONITORDIALOG_H
#define BLOODPRESSUREMONITORDIALOG_H

#include <QDialog>

namespace Ui {
class BloodPressureMonitorDialog;
}

class BloodPressureMonitorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BloodPressureMonitorDialog(QWidget *parent = nullptr);
    ~BloodPressureMonitorDialog();

private slots:
    void compareBloodPressure();
    void clearInputs();
    void closeDialog();

private:
    Ui::BloodPressureMonitorDialog *ui;

    void updateComparisonResult(double systolic, double diastolic);
};

#endif // BLOODPRESSUREMONITORDIALOG_H
