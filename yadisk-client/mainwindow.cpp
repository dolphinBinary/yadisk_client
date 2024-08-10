#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addNew->hide();
    ui->endEdit->hide();
    ui->deleteElement->hide();

    QFile file(databaseLocation);

    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "ошибка", file.errorString());

    QTextStream fileIn(&file);

    while(!fileIn.atEnd())
    {
        QListWidgetItem* item = new QListWidgetItem(fileIn.readLine(), ui->foldersListWidget);
        ui->foldersListWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

MainWindow::~MainWindow()
{
    QFile file(databaseLocation);

    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "ошибка", file.errorString());

    QTextStream fileOut(&file);
    for(int i = 0; i < ui->foldersListWidget->count(); ++i)
        fileOut << ui->foldersListWidget->item(i)->text() << Qt::endl;

    file.close();

    delete ui;
}


void MainWindow::on_upload_clicked()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("Внимание!");
    messageBox.setText("Тут пока котики не напрограммировали :3");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.exec();
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
    ui->foldersListWidget->clear();
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
    if(ui->addNew->text() != "")
    {
        QListWidgetItem* itemForAdding = new QListWidgetItem(ui->addNew->text(), ui->foldersListWidget);

        ui->foldersListWidget->addItem(itemForAdding);
        itemForAdding->setFlags(itemForAdding->flags() | Qt::ItemIsEditable);
        ui->addNew->clear();
        ui->foldersListWidget->setFocus();
    } else {
        QMessageBox messageBox;
        messageBox.setWindowTitle("Внимание!");
        messageBox.setText("Название папки не может быть пустым");
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.exec();
    }
    ui->addNew->hide();
    ui->endEdit->hide();

}


void MainWindow::on_trash_clicked()
{
    ui->foldersListWidget->clear();
    QStringList trashItems;

    trashItems << "testFile1" << "testFile 2" << "testFile 3";

    ui->foldersListWidget->addItems(trashItems);
    ui->foldersListWidget->setFocus();

    ui->deleteElement->show();
}


void MainWindow::on_deleteElement_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->foldersListWidget->selectedItems();

    foreach (QListWidgetItem* item, selectedItems) {
        int row = ui->foldersListWidget->row(item);
        ui->foldersListWidget->takeItem(row);
    }
}
