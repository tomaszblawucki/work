#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->layout = new QHBoxLayout;
    layout->addSpacing(50);


    this->calcButton = new QPushButton(this);
    this->calcButton->setFixedSize(50, 20);
    //this->calcButton->show();
    this->layout->addWidget(this->calcButton);
    QPushButton *buttons[5];
    for(int i = 0; i<5; i++)
    {
        std::string s = "Button";
        s += std::to_string(i);
        buttons[i] = new QPushButton(s.c_str());
        //buttons[i]->setText(s.c_str());
        layout->addWidget(buttons[i]);
    }






    connect(this->calcButton, SIGNAL(pressed()), this, SLOT(handleButton()));

    setLayout(this->layout);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::handleButton()
{
    qDebug() << "Button pressed";
}

double MainWindow::calculate(double, double, double)
{
    qDebug() << "Calculating triangle";
}

double MainWindow::calculate(double, double)
{
    qDebug() << "Calculating rectangle";
}

double MainWindow::calculate(double)
{
    qDebug() << "Calculating circle";
}
