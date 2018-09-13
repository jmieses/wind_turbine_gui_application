#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 4; i++)
        ui->comboBox->addItem("5/" + QString::number(i+3) + "/2017");

    for(int i = 0; i < 4; i++)
        ui->comboBox_2->addItem("5/" + QString::number(i+3) + "/2017");

    QFont results_font("Arial",10,QFont::Bold);
    ui->label_5->setFont(results_font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString start_date = ui->comboBox->currentText();
    QString start_time = ui->textEdit->toPlainText();

    QString end_date = ui->comboBox_2->currentText();
    QString end_time = ui->textEdit_2->toPlainText();


    double density = 1.225;     // kg/m^3
    double rotor_radius = 48; // meters
    double power_coefficient = 0.3; // typical value

    Read read;
    read.ReadStoreData();
    WindSpeed wind(0.5, read);
    Turbine turbine(0.5,0.5,wind);


    turbine.wind->averageWind(start_date + ',' + start_time,
                           end_date + ',' + end_time);

    // display the result
    ui->textEdit_3->setText(QString::number(turbine.wind->getWindSpeed()) + " m/s");
    ui->textEdit_4->setText(QString::number(turbine.TurbinePower()) + " kW");

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:


    ui->widget->addGraph();
    ui->widget->graph(0)->setData(turbine.wind->windX, turbine.powerY);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("Wind Speed [m/s]");
    ui->widget->yAxis->setLabel("Electrical Power [kW]");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(turbine.wind->windX.at(0), turbine.wind->windX.at(turbine.wind->windX.back()));
    ui->widget->yAxis->setRange(turbine.powerY.at(0), turbine.powerY.at(turbine.powerY.back()));
    ui->widget->replot();
}
