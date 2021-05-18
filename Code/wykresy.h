#ifndef WYKRESY_H
#define WYKRESY_H

#include <QDialog>

namespace Ui {
class Wykresy;
}

class Wykresy : public QDialog
{
    Q_OBJECT

public:
    explicit Wykresy(QWidget *parent = nullptr);
    ~Wykresy();

private:
    Ui::Wykresy *ui;
};

#endif // WYKRESY_H
