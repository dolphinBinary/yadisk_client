#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork/QNetworkAccessManager>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addNew->hide();
    ui->endEdit->hide();
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

    ui->search->clear();
    ui->search->setFocus();
}

void MainWindow::on_latest_clicked()
{

    QListWidgetItem* folderItem = new QListWidgetItem("test metadata about folder", ui->foldersListWidget);

    ui->foldersListWidget->addItem(folderItem);
    ui->foldersListWidget->setFocus();
}


void MainWindow::on_create_clicked()
{
    ui->addNew->show();
    ui->endEdit->show();
}


void MainWindow::on_endEdit_clicked()
{
    QListWidgetItem* itemForAdding = new QListWidgetItem(ui->addNew->text(), ui->foldersListWidget);

    ui->foldersListWidget->addItem(itemForAdding);
    itemForAdding->setFlags(itemForAdding->flags() | Qt::ItemIsEditable);
    ui->addNew->clear();
    ui->addNew->hide();
    ui->endEdit->hide();
    ui->foldersListWidget->setFocus();
}

