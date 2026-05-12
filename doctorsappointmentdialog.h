#ifndef DOCTORSAPPOINTMENTDIALOG_H
#define DOCTORSAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class DoctorsAppointmentDialog;
}

class DoctorsAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorsAppointmentDialog(QWidget *parent = nullptr);
   explicit DoctorsAppointmentDialog(const QString &currentUsername, QWidget *parent = nullptr); // Ensure this is declared

    ~DoctorsAppointmentDialog();

private slots:
    void on_buttonScheduleAppointment_clicked();

    void on_buttonCancelAppointment_clicked();

    void on_buttonViewRecords_clicked();

    void on_buttonClose_clicked();

    void on_buttonExit_clicked();

private:
    Ui::DoctorsAppointmentDialog *ui;
    QString currentUsername;

};

#endif // DOCTORSAPPOINTMENTDIALOG_H
