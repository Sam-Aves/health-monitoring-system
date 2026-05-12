// navigationwindow.h
#ifndef NAVIGATIONWINDOW_H
#define NAVIGATIONWINDOW_H

#include <QDialog>
#include "ui_navigationwindow.h"
#include "doctorsappointmentdialog.h"
#include "temperaturemonitordialog.h"
#include "bloodpressuremonitordialog.h"
#include "goalsdialog.h"
#include "recommendedplansdialog.h"
#include <QString>
#include <QMainWindow>

namespace Ui {
class NavigationWindow;
}

class NavigationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NavigationWindow(QWidget *parent = nullptr);
    explicit NavigationWindow(const QString &currentUsername, QWidget *parent = nullptr);
    ~NavigationWindow();
private slots:
    void on_btnExit_clicked(); // Slot for exit button

    void on_btnDoctorsAppointment_clicked();

    void on_btnMonitorTemp_clicked();

    void on_btnMonitorOxygen_clicked();

    void on_btnMonitorBP_clicked();

    void on_btnViewGoal_clicked();

    void on_btnRecommendedPlans_clicked();

    void on_btnCurrentStatus_clicked();

private:
    Ui::NavigationWindow *ui;
    DoctorsAppointmentDialog *doctorsAppointmentDialog;
    TemperatureMonitorDialog *temperatureMonitorDialog;
    recommendedplansdialog *recommendedPlanDialog;
    QString currentUsername;
};

#endif // NAVIGATIONWINDOW_H
