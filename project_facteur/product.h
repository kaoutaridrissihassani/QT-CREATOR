#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDialog>
#include <QMainWindow>
#include "databaseheader.h"


namespace Ui {
class product;
}

class product : public QDialog
{
    Q_OBJECT

public:
    explicit product(QWidget *parent = nullptr);
    ~product();

private slots:


    void on_displayBtn_clicked();

    void on_deleteProductBtn_clicked();

    void on_addProductBtn_2_clicked();

    void on_editProductBtn_clicked();

    void on_resetBtn_clicked();

private:
    Ui::product *ui;
    QSqlQueryModel *model;
};

#endif // PRODUCT_H
