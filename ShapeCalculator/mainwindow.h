#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <math.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGroupBox *groupTriangle;
    QLineEdit *t_a;
    QLineEdit *t_b;
    QLineEdit *t_c;

    QGroupBox *groupRectangle;
    QLineEdit *r_a;
    QLineEdit *r_b;

    QGroupBox *groupCircle;
    QLineEdit *c_r;

    QPushButton *calcButton;

    QHBoxLayout *layout;

    public slots:
    void handleButton();


    double calculate(double, double, double);
    double calculate(double, double);
    double calculate(double);

};

#endif // MAINWINDOW_H
