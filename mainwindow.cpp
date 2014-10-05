#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "dbconnect.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findButton_clicked()
{
     QString searchString = ui->lineEdit->text();
     ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void MainWindow::loadTextFile()
{
    createConnection();
    QString file = getTextFromQuery();
    closeConnection();
    QString str = ":/";
    str += file.simplified();
    QFile inputFile(str);
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}