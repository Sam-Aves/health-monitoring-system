#ifndef RECOMMENDEDPLANSDIALOG_H
#define RECOMMENDEDPLANSDIALOG_H
#include "recommendedplansdialog.h"
#include <QDialog>

namespace Ui {
class recommendedplansdialog;
}

class recommendedplansdialog : public QDialog
{
    Q_OBJECT

public:
    explicit recommendedplansdialog(QWidget *parent = nullptr);
    ~recommendedplansdialog();


private slots:
    void on_btnRegisterPlan_clicked();

    void on_btnClose_clicked();

    void on_comboBoxPlan_currentIndexChanged(int index);

private:
    Ui::recommendedplansdialog *ui;
};

#endif // RECOMMENDEDPLANSDIALOG_H
