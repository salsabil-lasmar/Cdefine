#ifndef EDITDEFINE_H
#define EDITDEFINE_H

#include <QDialog>

namespace Ui {
class EditDefine;
}

class EditDefine : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefine(QWidget *parent = nullptr , Ui::MainWindow *Win = nullptr);
    ~EditDefine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *Win;
    Ui::EditDefine *ui;
};

#endif // EDITDEFINE_H
