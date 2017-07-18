#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylayout.h"
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QHBoxLayout l;
    QWidget *rootFrame = new QWidget();
    QWidget *customFrame = new QWidget();

    QVBoxLayout *rootLayout = new QVBoxLayout;
    MyLayout *customLayout = new MyLayout(l);

    QComboBox *combo = new QComboBox();
    combo->addItem("vertical");
    combo->addItem("horizontal");

    QPushButton *wide = new QPushButton("WIDE");
    wide->setFixedSize(50, 40);
    QPushButton *high = new QPushButton("HIGH");
    high->setFixedSize(40, 50);
    QPushButton *little = new QPushButton("LITTLE");
    little->setFixedSize(30, 60);

    rootFrame->setLayout(rootLayout);


    this->setCentralWidget(rootFrame);
    customLayout->addWidget(wide);
    customLayout->addWidget(high);
    customLayout->addWidget(little);
    customLayout->reorder(1);
    customFrame->setLayout(customLayout);
    rootLayout->addWidget(customFrame);

    this->show();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
