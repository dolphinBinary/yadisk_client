#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_upload_clicked();

    void on_startSearch_clicked();

    void on_latest_clicked();

    void on_create_clicked();

    void on_endEdit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
