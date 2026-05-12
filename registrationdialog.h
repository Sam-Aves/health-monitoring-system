#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H
#include <QDialog>

#include <QDebug>
#include <QSqlDatabase>

namespace Ui {
class registrationdialog;
}

class registrationdialog : public QDialog
{
    Q_OBJECT

public:
    explicit registrationdialog(QWidget *parent = nullptr);
    ~registrationdialog();

private slots:
    void on_btnRegister_clicked();

    void on_btnClear_clicked();

    void on_btnReturn_clicked();

private:
    Ui::registrationdialog *ui;
    QSqlDatabase db; // Database connection object

    bool openDatabase();
    void closeDatabase();
    bool createDatabase();
};

#endif // REGISTRATIONDIALOG_H
