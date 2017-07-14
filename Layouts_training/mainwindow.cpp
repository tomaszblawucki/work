#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QStringList>
#include <QMap>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("My Qt Window");
    root = new QFrame();
    this->setCentralWidget(root);
    QVBoxLayout *rootLayout = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QFormLayout *formLayout =  new QFormLayout;
    QGridLayout *sportsLayout = new QGridLayout;
    root->setLayout(rootLayout);
    //root->setFixedSize(400, 500);

    nameLabel = new QLabel("Name:");
    surnameLabel = new QLabel("LastName:");
    ageLabel = new QLabel("Age:");
    countryLabel = new QLabel("Country:");
    sportsLabel =  new QLabel("Sports:");

    nameEdit = new QLineEdit();
    nameEdit->setMaximumWidth(300);
    surnameEdit =  new QLineEdit();
    surnameEdit->setMaximumWidth(300);
    ageBox = new QSpinBox();
    ageBox->setRange(0, 100);
    ageBox->setFixedWidth(100);


    QStringList countries;
    countries.append("Poland");
    countries.append("England");
    countries.append("China");
    countries.append("Russia");
    countries.append("USA");
    countryBox = new QComboBox();
    countryBox->addItems(countries);
    countryBox->setMaximumWidth(140);
    countryBox->setMinimumWidth(120);


    formLayout->addRow(nameLabel, nameEdit);
    formLayout->addRow(surnameLabel, surnameEdit);
    formLayout->addRow(ageLabel, ageBox);
    formLayout->addRow(countryLabel, countryBox);
    formLayout->addRow(sportsLabel);


    QStringList sports = {"football", "basketball", "hockey", "cricket", "skating", "hvy weight lifting", "swimming", "running"};
    QMap<QString, QCheckBox *> sportsMap;
    QMap<QString, QCheckBox *>::iterator mapIterator;

        foreach (QString sport, sports)
        {
            QCheckBox *b =new QCheckBox(sport);
            sportsMap.insert(sport, b);
        }

    int row=0, col=0;
    for(mapIterator = sportsMap.begin(); mapIterator !=sportsMap.end(); mapIterator++)
    {
        sportsLayout->addWidget(mapIterator.value(),row, col);
        col++;
        if(col == 2)
        {
            row ++;
            col = 0;
        }

    }


    acceptButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");
    acceptButton->setFixedWidth(75);
    cancelButton->setFixedWidth(100);
    QSpacerItem *spacer = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Expanding);
    QSpacerItem *vSpacer = new QSpacerItem(300, 50, QSizePolicy::Maximum, QSizePolicy::Expanding);

    buttonsLayout->addWidget(acceptButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->setAlignment(acceptButton, Qt::AlignRight|Qt::AlignBaseline);


    rootLayout->addLayout(formLayout);
    rootLayout->addLayout(sportsLayout);
    rootLayout->addSpacerItem(vSpacer);
    rootLayout->addLayout(buttonsLayout);



    this->show();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
