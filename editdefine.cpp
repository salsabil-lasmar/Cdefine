#include "editdefine.h"
#include "ui_editdefine.h"
#include "cdefinelist.h"
#include"cdefine.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFile>
#include<QTextStream>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QMessageBox>
#include<QDebug>
EditDefine::EditDefine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDefine)
{
    ui->setupUi(this);
  connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));


}

EditDefine::~EditDefine()
{
    delete ui;
}

void EditDefine::on_pushButton_clicked()
{
        int row=ui->lineEdit->text().toInt();
        QString NewDefineName=ui->lineEdit_2->text();

       // QString oldname= ui->tableView->model()->data(ui->tableView->model()->index(row,1)).toString();;
        //QString path= ui->tableView->model()->data(ui->tableView->model()->index(row,3)).toString();;
        QString  oldname = ui->lineEdit_name->text();
        QString  path = ui->lineEdit_path->text();

        QFile file(path);
          if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
              QString  s= file.readAll();
              s.replace(oldname, NewDefineName);
              QFile newfile(path);
                  if(newfile.open(QFile::WriteOnly | QFile::Truncate)) {
                      QTextStream out(&newfile);
                      out <<s;
                  }
                  newfile.close();
       }
                   /* else
                       QMessageBox::information(this,"Error","error editing define" );*/
      file.close();
      CDefineList obj;
      obj.setDefineList(path);
}

