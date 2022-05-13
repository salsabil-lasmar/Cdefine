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
    void loadData();
    void EditDefine();
    ~MainWindow();

private slots:
    void on_Add_pushButton_clicked();
    void slotCustomMenuRequested(QPoint pos);
    void SlotDeleteDefine();
    void SlotEditDefine();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
   
};
#endif // MAINWINDOW_H
