#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QDebug>
#include <QSpacerItem>
#include <QFormLayout>
#include <QDomNamedNodeMap>
#include <QDomElement>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QPair>



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
    choseDirectionCombo->addItem("From XML to JSON");
    choseDirectionCombo->addItem("From JSON to XML");


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


    xmlReader =  new QXmlStreamReader();



    show();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::translate()
{
    switch (choseDirectionCombo->currentIndex()) {
    case 0:
    {
            qDebug() << "Translating XML to JSON";
            QStringList xmlInputList;

            QStringList xmlContentList;

            QList<QXmlStreamAttribute> xmlPropertiesList;

            QList<QStringList> attributes;

            //QDomNamedNodeMap nodeMap;
            QString s = inputEdit->toPlainText();
            qDebug()<< "String content: " << inputEdit->toPlainText();
            qDebug()<< "DEBUG: " << inputEdit->toPlainText();
            xmlReader->clear();
            xmlReader->addData(s);
            int i=0;
            while(!xmlReader->atEnd())
            {
                if(xmlReader->isStartElement()){
                   xmlInputList << xmlReader->name().toString();
                   xmlPropertiesList = xmlReader->attributes().toList();
                   qDebug() <<"Props count:"<<xmlPropertiesList.count();
                   foreach(QXmlStreamAttribute attr, xmlPropertiesList)
                   {
                       qDebug() <<"ARRTIBUTE DEBUG!!"<<attr.name() << " => " <<attr.value();
                   }
                   xmlReader->readNext();
                   if(xmlReader->text().toString().trimmed() == "" && xmlReader->text().toString().trimmed().isEmpty())
                      xmlContentList << "";
                   else
                      xmlContentList << xmlReader->text().toString();
                }


                if(xmlReader->isEndElement()){
                    xmlInputList << xmlReader->name().toString() ;
                }


                xmlReader->readNext();
                //qDebug() << "Readen" << xmlInputList;
                i++;
            }


            qDebug()  << xmlInputList.size();

            for(int i = 0; i<xmlInputList.size(); i++)
            {
                qDebug() << xmlInputList[i];
            }
            qDebug()  << xmlContentList.size();
            for(int i = 0; i<xmlContentList.size(); i++)
            {
                qDebug() << xmlContentList[i];
            }
        break;
    }
    case 1:
    {
            qDebug() << "Translating JSON to XML";
            QString s = inputEdit->toPlainText();
            QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());

            QJsonObject jsonOb  = doc.object();
            QStringList keys = jsonOb.keys();
            qDebug() << "Keys count: " <<keys.count() << "keys:" << keys;
            qDebug() << "VALUE!!: "<<jsonOb.value("Address");
            QJsonObject address = jsonOb.value("Address").toObject();
            qDebug()<<address.value("City").toString();

        break;
    }
    default:
        break;
    }


}
