#ifndef OXYGENMONITORDIALOG_H
#define OXYGENMONITORDIALOG_H

#include <QDialog>

namespace Ui {
class oxygenmonitordialog;
}

class oxygenmonitordialog : public QDialog
{
    Q_OBJECT

public:
    explicit oxygenmonitordialog(QWidget *parent = nullptr);
    ~oxygenmonitordialog();

private slots:
    void compareOxygenLevels();
    void clearInformation();

private:
    Ui::oxygenmonitordialog *ui;
};

#endif // OXYGENMONITORDIALOG_H
