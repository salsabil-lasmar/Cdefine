#ifndef ADDNEWDEFINE_H
#define ADDNEWDEFINE_H

#include <QDialog>

namespace Ui {
class AddNewDefine;
}

class AddNewDefine : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDefine(QWidget *parent = nullptr);
    ~AddNewDefine();



private slots:
    void on_pushButton_clicked();

private:
    Ui::AddNewDefine *ui;
};

#endif // ADDNEWDEFINE_H
