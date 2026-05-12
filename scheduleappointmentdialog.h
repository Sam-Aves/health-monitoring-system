#ifndef SCHEDULEAPPOINTMENTDIALOG_H
#define SCHEDULEAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class scheduleappointmentdialog;
}

class scheduleappointmentdialog : public QDialog
{
    Q_OBJECT

public:
    explicit scheduleappointmentdialog(QWidget *parent = nullptr);
    explicit scheduleappointmentdialog(QString currentUsername, QWidget *parent = nullptr);

    ~scheduleappointmentdialog();

private slots:
    void on_buttonBook_clicked();

    void on_buttonClose_clicked();

private:
    Ui::scheduleappointmentdialog *ui;
    void populateAvailableSlots();
    QString currentUsername;
};

#endif // SCHEDULEAPPOINTMENTDIALOG_H
