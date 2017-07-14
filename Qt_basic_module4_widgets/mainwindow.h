#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTranslator>

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

    QTranslator translator;

    QVBoxLayout *v_layout;

    QComboBox *figures;
    QPushButton *calcButton;
    QPushButton *translateButton;
    //Containers
    QGroupBox *inputsBox;



    //Triangle inputs
    QLineEdit *t_a;
    QLineEdit *t_b;
    QLineEdit *t_c;


    QLabel *title;
    QLabel *result;


    bool valid(int);

public slots:
    void handleCombo(int);
    void handleCalcButton();
    //void MainWindow::changeEvent(QEvent *event);


};

#endif // MAINWINDOW_H
