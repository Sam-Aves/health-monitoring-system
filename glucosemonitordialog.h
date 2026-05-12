#ifndef GLUCOSEMONITORDIALOG_H
#define GLUCOSEMONITORDIALOG_H

#include <QDialog>

namespace Ui {
class StatusDialog;
}

class StatusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatusDialog(QWidget *parent = nullptr);
    ~StatusDialog();

private slots:
    void on_buttonCompare_clicked();

    void on_buttonClear_clicked();

    void on_buttonClose_clicked();

private:
    Ui::StatusDialog *ui;
};

#endif // GLUCOSEMONITORDIALOG_H
