#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cdefinelist.h"
#include"cdefine.h"
#include"addnewdefine.h"
#include "deletedefine.h"
#include "editdefine.h"

#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Value"));
    model->setHorizontalHeaderItem(2, new QStandardItem("File_type"));

    ui->tableView->setModel(model);

    CDefineList obj;
    obj.init();
    QList<QStandardItem *> list_items;
    for(auto itr = obj.mDefineList.begin(); itr != obj.mDefineList.end() ; ++itr) {
             list_items.append(new QStandardItem(itr->name));
             list_items.append(new QStandardItem(itr->value));
             list_items.append(new QStandardItem(itr->type_file));

             model->appendRow(list_items);
             list_items.clear();
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::table_view(){
    ui->tableView->model();
}

void MainWindow::on_Add_pushButton_clicked()
{
    AddNewDefine* addNewDefine=new  AddNewDefine();
    addNewDefine->show();

}

void MainWindow::on_Delete_pushButton_clicked()
{
    DeleteDefine* deletedefine=new  DeleteDefine();
    deletedefine->show();
}


void MainWindow::on_Edit_pushButton_clicked()
{
    EditDefine* editDefine=new EditDefine();
    editDefine->show();

}

