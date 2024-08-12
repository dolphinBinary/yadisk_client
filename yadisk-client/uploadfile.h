#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QDialog>

namespace Ui {
class UploadFile;
}

class UploadFile : public QDialog
{
    Q_OBJECT

public:
    explicit UploadFile(QWidget *parent = nullptr);
    ~UploadFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UploadFile *ui;
};

#endif // UPLOADFILE_H
