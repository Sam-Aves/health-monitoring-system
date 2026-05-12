#include "goalsdialog.h"
#include "ui_goalsdialog.h"

goalsdialog::goalsdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::goalsdialog)
{
    ui->setupUi(this);
    connect(ui->buttonSetGoal, &QPushButton::clicked, this, &goalsdialog::on_buttonSetGoal_clicked);
    connect(ui->buttonClear, &QPushButton::clicked, this, &goalsdialog::on_buttonClear_clicked);
    connect(ui->buttonClose, &QPushButton::clicked, this, &goalsdialog::on_buttonClose_clicked);
}

goalsdialog::~goalsdialog()
{
    delete ui;
}



void goalsdialog::on_buttonSetGoal_clicked()
{
    QString newGoal = ui->lineEditNewGoal->text();
    if (!newGoal.isEmpty()) {
        ui->textEditGoals->append(newGoal);
        ui->lineEditNewGoal->clear();
    }
}


void goalsdialog::on_buttonClear_clicked()
{
    ui->lineEditNewGoal->clear();
    ui->textEditGoals->clear();
}


void goalsdialog::on_buttonClose_clicked()
{
    close();
}


void goalsdialog::on_buttonRecord_clicked()
{

}

