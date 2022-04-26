#include "deletedefine.h"
#include "ui_deletedefine.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cdefinelist.h"
#include"cdefine.h"

#include<QFile>
#include<QTextStream>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QMessageBox>
#include<QDebug>
DeleteDefine::DeleteDefine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDefine)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));
}

DeleteDefine::~DeleteDefine()
{
    delete ui;
};

void DeleteDefine::on_pushButton_clicked()
{
      int  row = ui->lineEdit->text().toInt();
    //  QString name  = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toString();
      //QString path = ui->tableView->model()->data(ui->tableView->model()->index(row,2)).toString();
       QString  name = ui->lineEdit_name->text();
       QString  path = ui->lineEdit_path->text();

       QFile file(path);
     if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
         qDebug() << "FILE OPENED";
         QTextStream stream (&file);
         QRegularExpression startline  (".*#define\\s*");
         QRegularExpression  endline ("\\s*.*");
         QRegularExpression regex (startline.pattern() + name + endline.pattern());

         while(!stream.atEnd()){
         QString line =stream.readLine();
         QRegularExpressionMatch regexMatcher = regex.match(line);
         if(regexMatcher.hasMatch())
         qDebug() << line;
         line.clear();

         }

         /*else{
            QMessageBox::information(this,"Error","error deleting define" );
         }*/

     }

       file.close();
       CDefineList obj;
       obj.setDefineList(path);

}

