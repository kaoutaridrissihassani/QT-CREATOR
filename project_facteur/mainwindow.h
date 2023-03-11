#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "databaseheader.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_viewAllBtn_clicked();

    void on_addBtn_clicked();

    void on_selectBtn_clicked();

    void on_displayBtn_clicked();

    void on_productComboBox_textActivated(const QString &arg1);

    void on_resetBtn_clicked();

    void on_deleteProductBtn_clicked();

    void on_editProductBtn_clicked();

private:
    Ui::MainWindow *ui;
    product *ptrProduct;
    QSqlDatabase MyDatabase = QSqlDatabase::addDatabase("QSQLITE");
};
#endif // MAINWINDOW_H


