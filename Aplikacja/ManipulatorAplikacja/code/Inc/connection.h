#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QByteArray>
#include <cstdlib>
#include <iostream>
#include "Data.h"


namespace Ui {
class Connection;
}


/// \brief The Connection class  Klasa definiująca dialog z możliwością obsługi połączenia z portem COM
class Connection : public QDialog
{
    Q_OBJECT

public:
    /// \brief Connection konstruktor inicjalizujący obiekt klasy Connection
    /// \param parent
     Connection(QWidget *parent = nullptr);

    /// \brief ~Connection() dekonstruktor klasy Connection
    ~Connection();

signals:

     /// \brief changedAngle1 Sygnał informujący o odczytaniu nowej wartości kąta w przegubie numer jeden
     /// jego wystąpienie powoduje wykonanie slotu odpowiedzialnego za wyświetlenie wartości w oknie głownym aplikacji
     /// \param[in] Value1 wartość w przegubie pierwszym  0-360 (stopnie)
    void changedAngle1(int Value1);

    /// \brief changedAngle2 Sygnał informujący o odczytaniu nowej wartości kąta w przegubie numer dwa
    /// jego wystąpienie powoduje wykonanie slotu odpowiedzialnego za wyświetlenie wartości w oknie głownym aplikacji
    /// \param[in] Value1 wartość w przegubie drugim  0-180 (stopnie)
    void changedAngle2(int Value2);

    /// \brief changedAngle3 Sygnał informujący o odczytaniu nowej wartości kąta w przegubie numer trzy
    /// jego wystąpienie powoduje wykonanie slotu odpowiedzialnego za wyświetlenie wartości w oknie głownym aplikacji
    /// \param[in] Value1 wartość w przegubie trzecim 0-180 (stopnie)
    void changedAngle3(int Value3);

    /// \brief newDataToRead Sygnał informujący o zebraniu nowych danych o wartości kątów w przegubach.
    /// Wartości te są przechowywane w strukturze o nazwie Data
    /// \param[in] data Struktura zawierająca wartości poszczególnych kątów
    void newDataToRead(Data data);

private slots:

    /// \brief on_pushButtonSearch_clicked Slot obsługujący kliknięcie przycisku "Szukaj". Kliknięcie powoduje
    /// wyszukanie dostępnym na komputerze portów COM i wyświetlenie w comboxie
    void on_pushButtonSearch_clicked();


    /// \brief on_pushButtonOn_clicked Slot obsługujący kliknięcie przycisku "Połącz". Po kliknięciu następuje procedura łączenia
    /// z wybranym portem COM z comboboxa
    void on_pushButtonOn_clicked();


    /// \brief on_pushButtonOff_clicked Slot obsługujący kliknięcie przycisku "Rozłącz". Kliknięcie powoduje start procedury
    /// rozłączającej.
    void on_pushButtonOff_clicked();


    /// \brief readFromPort Slot obsługujący sygnał readyRead() z klasy QIODevice.
    /// Inicjalizacja syg. z slotem nastepuje dopiero po kliknięciu przysiku "Połącz"
    void readFromPort();


private:
    /// \brief Wskaźnik na okno dialogowe stworzone w Qcreatorze
    Ui::Connection *ui;
    ///
    /// \brief addToLogs Metoda dodająca odpowiednią informację tekstową w oknie tekstowym
    /// \param message wiadomość do wyświetlenia
    ///
    void addToLogs(QString message);

    ///
    /// \brief device wskaźnik na port COM
    ///
    QSerialPort *device;
    ///
    /// \brief checkCrc_8 Funkcja obliczająca sumę kontrolną
    /// \param input_str Wiadomości na na podstawie, której oblcizana jest suma kontrolna
    /// \param num_bytes rozmiar wiadomości w bajtach
    /// \return Wartość zwracana przez metodę to obliczona suma kontrolna
    ///
    uint8_t checkCrc_8( char *input_str, size_t num_bytes );
    ///
    /// \brief addValuesOfAngles Metoda aktualizująca wartośc kątów w poszczególnych przegubach
    /// \param[in] joint1 wartość w przegubie pierwszym 0-360 (stopnie)
    /// \param[in] joint2 wartość w przegubie drugim 0-180 (stopnie)
    /// \param[in] joint3 wartość w przegubie trzecim 0-180 (stopnie)
    ///
    void addValuesOfAngles(int joint1, int joint2, int joint3);

public:
    ///
    /// \brief Angles1 wartość kąta w przegubie pierwszym 0-360 (stopnie)
    ///
    int Angles1;
    ///
    /// \brief Angles2 wartość kąta w przegubie drugim 0-180 (stopnie)
    ///
    int Angles2;
    ///
    /// \brief Angles3 wartość kąta w przegubie trzecim 0-180 (stopnie)
    ///
    int Angles3;


    /// \brief SendConfiguration metoda odpowiedzialna za wysłanie wartośći przegubów zadanych przez użytkownika
    /// w oknie głównym aplikacji przy pomocy suwaków
    /// \param[in]  joint1 wartość kąta w przegubie pierwszym 0-360 (stopnie)
    /// \param[in]  joint2 wartość kąta w przegubie drugim 0-180 (stopnie)
    /// \param[in]  joint3 wartość kąta w przegubie trzecim 0-180 (stopnie)
    ///
    void SendConfiguration(int joint1, int joint2, int joint3);

};

#endif // CONNECTION_H
