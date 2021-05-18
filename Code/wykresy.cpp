#include "wykresy.h"
#include "ui_wykresy.h"

Wykresy::Wykresy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wykresy)
{
    ui->setupUi(this);
}

Wykresy::~Wykresy()
{
    delete ui;
}
