#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include "../extensions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SaveButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadTextFile();
    bool checkFormFields();
};

#endif // MAINWINDOW_H
