#include "code/Inc/wykresy.h"
#include "ui_wykresy.h"



Wykresy::Wykresy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wykresy)
{
    ui->setupUi(this);

    ui->widget->plotLayout()->insertRow(0);
    ui->widget->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget, tr("Przegub 1"), QFont("sans", 12, QFont::Bold)));
    ui->widget_2->plotLayout()->insertRow(0);
    ui->widget_2->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget_2, tr("Przegub 2"), QFont("sans", 12, QFont::Bold)));
    ui->widget_3->plotLayout()->insertRow(0);
    ui->widget_3->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget_3, tr("Przegub 3"), QFont("sans", 12, QFont::Bold)));

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(QColor("red")));
    ui->widget->graph(0)->setName(tr("Value"));

    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->setPen(QPen(QColor("blue")));
    ui->widget_2->graph(0)->setName(tr("Value"));

    ui->widget_3->addGraph();
    ui->widget_3->graph(0)->setPen(QPen(QColor("black")));
    ui->widget_3->graph(0)->setName(tr("Value"));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->widget->xAxis->setTicker(timeTicker);
    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->xAxis->setLabel("Czas [hh:mm:ss]");

    ui->widget->yAxis->setRange(0,400);
    ui->widget->yAxis->setLabel("Kąt w przegubie 1 [stopnie]");


    ui->widget->legend->setVisible(true);

    ui->widget->setInteraction(QCP::iRangeDrag);

    ui->widget->setInteraction(QCP::iRangeZoom);

    ui->widget_2->xAxis->setTicker(timeTicker);
    ui->widget_2->axisRect()->setupFullAxesBox();
    ui->widget_2->xAxis->setLabel("Czas [hh:mm:sss]");

    ui->widget_2->yAxis->setRange(0,400);
    ui->widget_2->yAxis->setLabel("Kąt w przegubie 2 [stopnie]");

    ui->widget_2->legend->setVisible(true);

    ui->widget_2->setInteraction(QCP::iRangeDrag);

    ui->widget_2->setInteraction(QCP::iRangeZoom);


    ui->widget_3->xAxis->setTicker(timeTicker);
    ui->widget_3->axisRect()->setupFullAxesBox();
    ui->widget_3->xAxis->setLabel("Czas [hh:mm:ss]");

    ui->widget_3->yAxis->setRange(0,400);
    ui->widget_3->yAxis->setLabel("Kąt w przegubie 3 [stopnie]");

    ui->widget_3->legend->setVisible(true);

    ui->widget_3->setInteraction(QCP::iRangeDrag);

    ui->widget_3->setInteraction(QCP::iRangeZoom);
    time2.start();
}

Wykresy::~Wykresy()
{
    delete ui;
}

void Wykresy::newDataToDraw(Data newData)
{

        double key = time2.elapsed()/1000.0;

      ui->widget->graph(0)->addData(key, newData.Angle1);
      ui->widget->xAxis->setRange(key, 40, Qt::AlignRight);
      ui->widget->replot();
      ui->widget->update();

      ui->widget_2->graph(0)->addData(key, newData.Angle2);
      ui->widget_2->xAxis->setRange(key, 40, Qt::AlignRight);
      ui->widget_2->replot();
      ui->widget_2->update();


      ui->widget_3->graph(0)->addData(key, newData.Angle3);
      ui->widget_3->xAxis->setRange(key, 40, Qt::AlignRight);
      ui->widget_3->replot();
      ui->widget_3->update();
}
