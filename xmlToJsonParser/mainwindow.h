#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QLabel *choseDirectionLabel;
    QLabel *inputLabel;
    QLabel *outputLabel;

    QTextEdit *inputEdit;
    QTextEdit *outputEdit;

    QComboBox *choseDirectionCombo;

    QPushButton *translateButton;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void translate();



};

#endif // MAINWINDOW_H
