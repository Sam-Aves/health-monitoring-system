#ifndef CANCELAPPOINTMENTDIALOG_H
#define CANCELAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class CancelAppointmentDialog;
}

class CancelAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CancelAppointmentDialog(QWidget *parent = nullptr);
    explicit CancelAppointmentDialog(const QString &currentUsername, QWidget *parent = nullptr);
    ~CancelAppointmentDialog();

private slots:

    void on_buttonCancel_clicked();

    void on_buttonClose_clicked();

private:
    Ui::CancelAppointmentDialog *ui;
    QString currentUsername;
    void populateAppointments();
};

#endif // CANCELAPPOINTMENTDIALOG_H
