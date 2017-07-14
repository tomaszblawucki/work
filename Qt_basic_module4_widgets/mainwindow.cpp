#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QFrame>
#include <QDebug>
#include <math.h>
#include <QDoubleValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    qDebug() << translator.load("QtLanguage_pl_PL", ".");
//    qDebug() <<  qApp->installTranslator(&translator);
//    qDebug() << translator.isEmpty();

    v_layout = new QVBoxLayout;
    figures = new QComboBox();
    calcButton = new QPushButton(this->tr("Calculate"));
    title = new QLabel(tr("HOME"));
    result = new QLabel;
    QHBoxLayout *h_layout = new QHBoxLayout;
    inputsBox = new QGroupBox();
    QFrame *root = new QFrame();

    inputsBox->setTitle(tr("Triangle inputs"));

    t_a = new QLineEdit();
    t_b = new QLineEdit();
    t_c = new QLineEdit();
    t_a->setPlaceholderText("Give 'A' value");
    t_b->setPlaceholderText("Give 'B' value");
    t_c->setPlaceholderText("Give 'C' value");

//  t_a->setValidator(new QDoubleValidator(0, 100, 2, this));
//  t_b->setValidator(new QDoubleValidator(0, 100, 2, this));
//  t_c->setValidator(new QDoubleValidator(0, 100, 2, this));
//  h_layout->addWidget(t_a);
//  h_layout->addWidget(t_b);
//  h_layout->addWidget(t_c);

 //   inputsBox->setLayout(h_layout);

    figures->addItem("triangle");
    figures->addItem("rectangle");
    figures->addItem("circle");


 //   layout->addWidget(inputsBox);
 //   layout->addWidget(calcButton);
    h_layout->addWidget(t_a);
    h_layout->addWidget(t_b);
    h_layout->addWidget(t_c);

    inputsBox->setLayout(h_layout);
    v_layout->addWidget(title);
    v_layout->addWidget(figures);
    v_layout->addWidget(inputsBox);
    v_layout->addWidget(result);
    v_layout->addWidget(calcButton);

    root->setLayout(v_layout);

    this->connect(figures, SIGNAL(activated(int)), this, SLOT(handleCombo(int)) );
    this->connect(calcButton, SIGNAL(pressed()), this,SLOT(handleCalcButton()) );



    this->setCentralWidget(root);
    this->show();



        //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::valid(int index)
{
    if(index == 0){
    if(t_a->text().isEmpty() || t_b->text().isEmpty() || t_c->text().isEmpty())
    {
        return false;
    }}
    if(index == 1){
    if(t_a->text().isEmpty() || t_b->text().isEmpty())
    {
        return false;
    }}
    if(index == 2){
    if(t_a->text().isEmpty())
    {
        return false;
    }}

   return true;
}

void MainWindow::handleCombo(int index)
{
    switch (index) {
    case 0:
        t_a->show();
        t_b->show();
        t_c->show();
        inputsBox->setTitle("Triangle inputs");
        qDebug()<<"Triangle";
        break;
    case 1:
        t_a->show();
        t_b->show();
        t_c->hide();
        inputsBox->setTitle("Rectangle inputs");
        qDebug()<<"Rectangle";
        break;
    case 2:
        t_a->setPlaceholderText("Give 'R' value");
        t_a->show();
        t_b->hide();
        t_c->hide();
        inputsBox->setTitle("Circle inputs");
        qDebug()<<"Circle";
        break;
    default:
        break;
    }
}

void MainWindow::handleCalcButton()
{
    double p, a, b, c;
    QString res;
    switch (figures->currentIndex()) {
    case 0:
        if(valid(0)){
        a = t_a->text().toDouble();
        b = t_b->text().toDouble();
        c = t_c->text().toDouble();
        p = (a + b + c )/2;
        res = QString::number( sqrt(p*(p-a)*(p-b)*(p-c)) );
        qDebug() << res;
        result->setText(QString("Result is: ").append(res));
        }
        else
            result->setText(QString(this->tr("Wrong parameters!")));
        break;
    case 1:
        if(valid(1)){
        a = t_a->text().toDouble();
        b = t_b->text().toDouble();
        res = QString::number( a * b );
        result->setText(QString("Result is: ").append(res));
        }
        else
            result->setText(QString(this->tr("Wrong parameters!")));
        break;
    case 2:
        if(valid(2)){
        a = t_a->text().toDouble();
        res = QString::number( M_PI*pow(a, 2) );
        result->setText(QString("Result is: ").append(res));
        }
        else
            result->setText(QString(this->tr("Wrong parameters!")));
        break;
    default:
        break;
    }
}
