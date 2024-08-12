#include "uploadfile.h"
#include "ui_uploadfile.h"

UploadFile::UploadFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadFile)
{
    ui->setupUi(this);
}

UploadFile::~UploadFile()
{
    delete ui;
}

void UploadFile::on_pushButton_clicked()
{
    close();
}

