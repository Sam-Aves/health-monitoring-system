#ifndef TEMPERATUREMONITORDIALOG_H
#define TEMPERATUREMONITORDIALOG_H

#include <QDialog>

namespace Ui {
class TemperatureMonitorDialog;
}

class TemperatureMonitorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TemperatureMonitorDialog(QWidget *parent = nullptr);
    ~TemperatureMonitorDialog();

    void setUserTemperature(double temperature);

private slots:
    void on_buttonExit_clicked();

    void on_buttonClose_clicked();

private:
    Ui::TemperatureMonitorDialog *ui;
    double userTemperature;

    void updateTemperatureComparison();
};

#endif // TEMPERATUREMONITORDIALOG_H
