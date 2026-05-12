#include "mainwindow.h"
#include "registrationdialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>  // for debugging purposes
void initializeDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("HealthMonitoringDatabase.sqlite");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Connection Error", db.lastError().text());
    } else {
        qDebug() << "Database connected successfully";  // Debugging line
    }
}
void addAppointmentsColumn()
{
    QSqlDatabase db = QSqlDatabase::database(); // Assuming the database is already connected

    QSqlQuery query(db);
    query.prepare("PRAGMA table_info(users)");
    if (!query.exec()) {
        qDebug() << "Error checking table info:" << query.lastError().text();
        return;
    }

    bool columnExists = false;
    while (query.next()) {
        QString columnName = query.value("name").toString();
        if (columnName == "appointments") {
            columnExists = true;
            break;
        }
    }

    if (!columnExists) {
        QString alterQuery = "ALTER TABLE users ADD COLUMN appointments TEXT";
        if (!query.exec(alterQuery)) {
            qDebug() << "Error adding appointments column:" << query.lastError().text();
            QMessageBox::critical(nullptr, "Database Error", "Error adding appointments column. Check logs for details.");
            return;
        }
        qDebug() << "Appointments column added successfully";
    } else {
        qDebug() << "Appointments column already exists";
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initializeDatabase();
    addAppointmentsColumn();
    MainWindow w;
    w.show();
    return a.exec();
}
