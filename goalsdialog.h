#ifndef GOALSDIALOG_H
#define GOALSDIALOG_H

#include <QDialog>

namespace Ui {
class goalsdialog;
}

class goalsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit goalsdialog(QWidget *parent = nullptr);
    ~goalsdialog();

private slots:


    void on_buttonSetGoal_clicked();

    void on_buttonClear_clicked();

    void on_buttonClose_clicked();

    void on_buttonRecord_clicked();

private:
    Ui::goalsdialog *ui;
};

#endif // GOALSDIALOG_H
