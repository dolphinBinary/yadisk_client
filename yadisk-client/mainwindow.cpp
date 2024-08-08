#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_upload_clicked()
{
    // логика по открытию диалогового окна, где выбирался бы файл для загрузки
}

void MainWindow::on_startSearch_clicked()
{
    QString searchText = ui->search->text();

//    ui->foldersScrollArea->;
}

