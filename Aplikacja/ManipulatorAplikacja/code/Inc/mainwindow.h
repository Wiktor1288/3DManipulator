#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "wykresy.h"
#include "Data.h"
#include "viewerman.h"
#include <QBoxLayout>
#include <QMessageBox>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// Główna klasa programu
///
/// Klasa ta jest odpowiedzialana za definicje i sterowanie oknem głównym aplikacji

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///
    /// \brief MainWindow to konstruktor parametryczny inicjujący obiekt klasy MainWindow w funkcji głównej.
    /// W konstruktorze tym definiowane są również połączenia między sygnałami a slotami oraz zajmowane jest miejsce w pamięci
    /// za pomocą operatora new dla wskaźników  myConnection, ui oraz myWykresy
    /// \param parent w przypadku nie podania parametru parent = nullptr
    MainWindow(QWidget *parent = nullptr);

    /// \brief ~MainWindow Dekonstruktor klasy MainWindow. W dekonstruktorze zwalniane jest miejsce po użyciu
    /// operatora new w konstruktorze.
    ~MainWindow();



private slots:
    ///
    /// \brief on_actionPo_czenie_triggered
    /// Slot obsługujący kliknięcie przycisku "Połączenie" w pasku menu. Kliknięcie powoduje wyświetlenie okna z
    /// konfiguracją połaczenia portu szeregowego
    void on_actionPo_czenie_triggered();

    ///
    /// \brief Slot obsługujący kliknięcie przycisku "Wyśli", kliknięcie przycisku powoduje
    /// wysłanie ustalonych za pomocą suwaka wartości przegubów
    ///
    void on_SendConf_clicked();

    ///
    /// \brief  Slot obsługujący kliknięcie przycisku "Wykresy" w zakładce menu. Kliknięcie
    /// powoduje wyświetlenie okna z wykresami
    ///
    void on_actionWykresy_triggered();

    ///
    /// \brief Slot odpowidzialny za wysłanie do metody klasy ViewerMan informacji o zmianie warotści kąta poszczególnego przegubu.
    /// slot ten jest uruchamiany po wygenerowaniu sygnału inforującego o nowych odczytach.
    /// \param newData parametr typu Data odpowiedzialny za przechowywanie informacji o kątach w przegubach. Parametr ten jest przekazywany
    /// dalej do metody ViewerMan:newAngles(Data newData)
    ///
    void AddNewDataToViewer(Data newData);

private:
    Ui::MainWindow *ui;

    ///
    /// \brief myConnection wskaźnik na objekt typu Connection. Wskaźnik ten to nowe okno dialog z pełnymi funkcjonalnościami
    /// klasy Connection
    ///
    Connection *myConnection;

    ///
    /// \brief myWykresywskaźnik na objekt typu Wykresy. Wskaźnik ten to nowe okno dialog z pełnymi funkcjonalnościami
    /// klasy Wykresy
    ///

    Wykresy *myWykresy;


};
#endif // MAINWINDOW_H
