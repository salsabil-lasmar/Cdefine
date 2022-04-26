#ifndef DELETEDEFINE_H
#define DELETEDEFINE_H

#include <QDialog>

namespace Ui {
class DeleteDefine;
}

class DeleteDefine : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDefine(QWidget *parent = nullptr);
    ~DeleteDefine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteDefine *ui;
};

#endif // DELETEDEFINE_H
