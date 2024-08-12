#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent, QString name, QString email, QString password) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

    ui->lineName->setText(name);
    ui->lineEmail->setText(email);
    ui->linePassword->setText(password);

    connect(this, &Profile::finished, this, [this](){
        emit dataAvailable("USER_MEME");
    });
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_save_clicked()
{
    close();
}
