#include "registrationdialog.h"
#include "ui_registrationdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

registrationdialog::registrationdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registrationdialog)
{
    ui->setupUi(this);
    connect(ui->btnRegister, &QPushButton::clicked, this, &registrationdialog::on_btnRegister_clicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &registrationdialog::on_btnClear_clicked);
    connect(ui->btnReturn, &QPushButton::clicked, this, &registrationdialog::on_btnReturn_clicked);

    ui->comboBoxAge->addItem("Below 18");
    ui->comboBoxAge->addItem("18 - 30");
    ui->comboBoxAge->addItem("31 - 55");
    ui->comboBoxAge->addItem("55+");

    ui->comboBoxGender->addItem("Female");
    ui->comboBoxGender->addItem("Male");

    // Populate comboBoxCountry
    ui->comboBoxCountry->addItem("Bangladesh");
    ui->comboBoxCountry->addItem("India");
    ui->comboBoxCountry->addItem("Pakistan");
    ui->comboBoxCountry->addItem("Japan");
    ui->comboBoxCountry->addItem("Singapore");
    ui->comboBoxCountry->addItem("Malaysia");
    ui->comboBoxCountry->addItem("China");
    ui->comboBoxCountry->addItem("Korea");
    ui->comboBoxCountry->addItem("Indonesia");

    if (!openDatabase()) {
        qDebug() << "Database connection failed.";
    } else {
        if (createDatabase()) {
            qDebug() << "Database and table created successfully.";
        } else {
            qDebug() << "Failed to create database or table.";
        }
    }

}

registrationdialog::~registrationdialog()
{
    closeDatabase();
    delete ui;
}

bool registrationdialog::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("HealthMonitoringDatabase.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect database.";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected.";
    return true;
}
void registrationdialog::closeDatabase()
{
    db.close();
    qDebug() << "Database closed.";
}
bool registrationdialog::createDatabase()
{
    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            first_name TEXT NOT NULL,
            last_name TEXT NOT NULL,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            age INTEGER,
            gender TEXT,
            country TEXT
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return false;
    }

    return true;
}
void registrationdialog::on_btnRegister_clicked()
{
    qDebug() << "Register button clicked!";
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString email = ui->lineEditEmail->text();
    QString age = ui->comboBoxAge->currentText();
    QString gender = ui->comboBoxGender->currentText();
    QString country = ui->comboBoxCountry->currentText();
    if (firstName.isEmpty() || lastName.isEmpty() || username.isEmpty() ||
        password.isEmpty() || email.isEmpty() || age.isEmpty() ||
        gender.isEmpty() || country.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }
    // Prepare SQL query
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username OR email = :email");
    query.bindValue(":username", username);
    query.bindValue(":email", email);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Count of existing users with same username or email:" << count;  // Debugging line
        if (count > 0) {
            QMessageBox::warning(this, "Registration Error", "Username or email already in use.");
            return;
        }
    }

    // Insert new user
    query.prepare("INSERT INTO users (first_name, last_name, username, password, email, age, gender, country) "
                  "VALUES (:first_name, :last_name, :username, :password, :email, :age, :gender, :country)");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":gender", gender);
    query.bindValue(":country", country);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Registration successful.");
        // Clear inputs after successful registration
        ui->lineEditFirstName->clear();
        ui->lineEditLastName->clear();
        ui->lineEditUsername->clear();
        ui->lineEditPassword->clear();
        ui->lineEditEmail->clear();
        ui->comboBoxAge->setCurrentIndex(0);
        ui->comboBoxGender->setCurrentIndex(0);
        ui->comboBoxCountry->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Registration Error", query.lastError().text());
    }
}


void registrationdialog::on_btnClear_clicked()
{
    qDebug() << "Clear button clicked!";
    ui->lineEditFirstName->clear();
    ui->lineEditLastName->clear();
    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
    ui->lineEditEmail->clear();
    ui->comboBoxAge->setCurrentIndex(0);
    ui->comboBoxGender->setCurrentIndex(0);
    ui->comboBoxCountry->setCurrentIndex(0);
}


void registrationdialog::on_btnReturn_clicked()
{
    qDebug() << "Close button clicked!";
    close();
}

