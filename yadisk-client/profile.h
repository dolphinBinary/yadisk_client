#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr, QString name = "user", QString email = "user@yandex.ru", QString password = "secret_password");
    ~Profile();

signals:
    void dataAvailable(const QString &date);

private slots:
    void on_save_clicked();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
