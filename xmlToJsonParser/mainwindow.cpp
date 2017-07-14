#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QDebug>
#include <QSpacerItem>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setMinimumSize(700, 400);
    QFrame *root = new QFrame;
    this->setCentralWidget(root);
    QVBoxLayout *rootLayout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    QFormLayout *formLayout = new QFormLayout;
    root->setLayout(rootLayout);

    choseDirectionLabel = new QLabel("Translate:");
    inputLabel = new QLabel("Input:");
    outputLabel = new QLabel("Output:");
    choseDirectionCombo = new QComboBox();
    choseDirectionCombo->addItem("From JSON to XML");
    choseDirectionCombo->addItem("From XML to JSON");

    inputEdit = new QTextEdit();
    outputEdit = new QTextEdit();

    translateButton = new QPushButton("Translate");
    connect( translateButton, SIGNAL(pressed()), this, SLOT(translate()) );


    formLayout->addRow(choseDirectionLabel, choseDirectionCombo);
    choseDirectionCombo->setFixedWidth(150);

    grid->addWidget(inputLabel, 0, 0);
    grid->addWidget(outputLabel, 0, 1);
    grid->addWidget(inputEdit, 1, 0);
    grid->addWidget(outputEdit, 1, 1);

    //formLayout->addSpacerItem(new QSpacerItem(200, 50, QSizePolicy::Maximum, QSizePolicy::Expanding));
    //formLayout->setAlignment(choseDirectionLabel, Qt::AlignTop|Qt::AlignLeft);
    //formLayout->setAlignment(choseDirectionCombo, Qt::AlignTop|Qt::AlignLeft);
    //formLayout->addStretch(1);

    rootLayout->addLayout(formLayout);
    rootLayout->addLayout(grid);
    rootLayout->addWidget(translateButton);
    rootLayout->setAlignment(translateButton, Qt::AlignLeft|Qt::AlignBottom);

    show();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::translate()
{
    qDebug() << "Translating";
}
