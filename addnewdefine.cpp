#include "addnewdefine.h"
#include "ui_AddNewDefine.h"
#include "cdefinelist.h"
#include"cdefine.h"

#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QObject>
AddNewDefine::AddNewDefine(QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::AddNewDefine)
{
    ui->setupUi(this);
   connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));

}


AddNewDefine::~AddNewDefine()
{
    delete ui;
}


void AddNewDefine::on_pushButton_clicked()
{
    QString path=ui->lineEdit->text();
    QString NewDefine=ui->textEdit->toPlainText();

    QFile file(path);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
      QTextStream stream (&file);
       while(!stream.atEnd())
           stream.readLine();

      QStringList list =NewDefine.split('\n');
     for(  const auto &e : list ){
      stream << e <<'\n';


     }

  }

      file.close();

  CDefineList obj;
  obj.setDefineList(path);
}

