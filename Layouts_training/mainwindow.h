#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QFrame *root;

    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *ageLabel;
    QLabel *countryLabel;
    QLabel *sportsLabel;

    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;

    QSpinBox *ageBox;
    QComboBox *countryBox;

    QPushButton *acceptButton;
    QPushButton *cancelButton;



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
