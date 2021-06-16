#ifndef WYKRESY_H
#define WYKRESY_H

#include <QDialog>
#include "Data.h"
#include "QcustomPlot/qcustomplot.h"
#include <QElapsedTimer>
#include <QTime>

namespace Ui {
class Wykresy;
}

///
/// \brief The Wykresy class Klasa obsługujaca okno z wykresami.
///
class Wykresy : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief Wykresy konstruktor parametryczny inicjulizujacy obiekt klasy Wykresy
    /// \param parent
    ///
     Wykresy(QWidget *parent = nullptr);
    ~Wykresy();
private slots:
     ///
     /// \brief newDataToDraw Slot odpowiedzialny za aktualizację wartości na wykresie. Slot jest wykonywany po pojawieniu się
     /// sygnału Connection:newDataToRead(Data data).
     /// \param newData argument typu Data przechowujacy informacje o wartościach kątów w przegubie
     ///
    void newDataToDraw(Data newData);
private:
    ///
    /// \brief ui wskaźnik na obiekt odpowiedzialny za wyświetlenia okna z wykresami.
    ///
    Ui::Wykresy *ui;
    ///
    /// \brief time2 obiekt klasy QElapsedTimer służacy jako timer do zliczania czasu
    ///
    QElapsedTimer  time2;
};

#endif // WYKRESY_H
