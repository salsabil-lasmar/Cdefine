#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     void table_view();
    ~MainWindow();

private slots:
    void on_Add_pushButton_clicked();

    void on_Delete_pushButton_clicked();

    void on_Edit_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QAbstractItemModel *model1 ;
};
#endif // MAINWINDOW_H
