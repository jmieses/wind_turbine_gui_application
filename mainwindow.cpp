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
    ui->textEdit_3->setText(QString::number(turbine.wind->getWindSpeed()));
    ui->textEdit_4->setText(QString::number(turbine.TurbinePower()));


}
