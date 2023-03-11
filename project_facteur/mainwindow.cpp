#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrProduct = new product();
    MyDatabase.setDatabaseName("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrProduct;
}


void MainWindow::on_viewAllBtn_clicked()
{
    ptrProduct->show();

}


void MainWindow::on_addBtn_clicked()
{

       QString ID = ui->IDlineEdit->text();
       QString LIBELLEPRODUCT = ui->productComboBox->currentText();
       QString PRIX = ui->PrixLineEdit->text();
       QString QTE = ui->qteLineEdit->text();
       QString TOTAL = ui->totalLineEdit->text();
       QString DATE = ui->dateEdit->text();


       qDebug() << "ID :" << ID << "LIBELLEPRODUCT :" << LIBELLEPRODUCT << "PRIX :" << PRIX << "QTE :" << QTE << "TOTAL :" << TOTAL << "DATE :" << DATE;



          QSqlDatabase database = QSqlDatabase::database();
            database.open();


        /*QSqlQuery queryinsert,qwerySelect,qweryUpdate;
        if(qwerySelect.exec("select id from invoice where id ='"+id+"'")){
            while (qwerySelect.next()) {
                if(qwerySelect.value(0).toString()==id){
                    qweryUpdate.exec("update invoice set LIBELLEPRODUCT=LIBELLEPRODUCT ||';'||'"+LIBELLEPRODUCT+"',PRIX=PRIX+'"+PRIX+"',TOTAL=TOTAL+'"+TOTAL+"'");
                    qDebug()<<"updated ";
                    return;
                }

            }
        }*/


            if(QFile::exists("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db"))

            {
                qDebug() << "Database file exist";
            }
            else
            {
                qDebug() << "Database file doesnt exist";
                return;
            }

            if(!database.open())
            {
                qDebug() << "Error : Unable to open Database" << database.lastError();
                return;
            }
            else
            {
                qDebug() << "Database open successfully";
            }


            QSqlQuery query(database);

            query.prepare("insert into invoice (ID,LIBELLEPRODUCT,PRIX, QTE, DATE, TOTAL) values('" + ID + "','" + LIBELLEPRODUCT + "','" + PRIX + "','" + QTE + "','" + DATE + "','" + TOTAL + "')");





            if(query.exec()){
                QMessageBox::critical(this,tr("Add"),tr("Added Successfully! Try to click Display all Invoices Button to see the change. "));
                database.close();

            }
            else{
                QMessageBox::critical(this,tr("Error:"),query.lastError().text());
                database.commit();
            }


    }


void MainWindow::on_selectBtn_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlDatabase database = QSqlDatabase::database();
      database.open();

      QSqlQuery* qry = new QSqlQuery(database);

      qry->prepare("select LIBELLE from product");
      qry->exec();
      modal->setQuery(*qry);
      ui->productComboBox->setModel(modal);
      database.close();

      qDebug() << (modal->rowCount());


}


void MainWindow::on_displayBtn_clicked()
{
    QSqlDatabase database = QSqlDatabase::database();
    database.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qwery;
    qwery.prepare("select * from invoice order by ID;");
    qwery.exec();
    model->setQuery(qwery);
    ui->facteurTableView->setModel(model);
    database.close();
}


void MainWindow::on_productComboBox_textActivated(const QString &arg1)
{
    QSqlDatabase database = QSqlDatabase::database();
    database.open();
   QSqlQuery qwery;
   if(qwery.exec("select PRIX from product where LIBELLE='"+arg1+"'")){
       while (qwery.next()) {
           ui->PrixLineEdit->setText(qwery.value(0).toString());
           if(ui->qteLineEdit->text()!=""){
               QString total = QString::number(ui->PrixLineEdit->text().toFloat()*ui->qteLineEdit->text().toInt());

               ui->totalLineEdit->setText(total);
           }
       }
   }
   database.close();
}


void MainWindow::on_resetBtn_clicked()
{
    ui->productComboBox->clear();
    ui->PrixLineEdit->clear();
    ui->qteLineEdit->clear();
    ui->totalLineEdit->clear();
    ui->dateEdit->clear();
    ui->IDlineEdit->clear();
}


void MainWindow::on_deleteProductBtn_clicked()
{
    QSqlDatabase database = QSqlDatabase::database();
      database.open();

    QSqlQuery qwery;

    qwery.prepare("delete from invoice where ID = " + ui->IDlineEdit->text() + "");

    if(qwery.exec()){
        QMessageBox::critical(this,tr("Delete"),tr("Deleted Successfully! Try to click Display all Invoice Button to see the change."));
        database.close();

    }
    else{
        QMessageBox::critical(this,tr("Error:"),qwery.lastError().text());
    }
}


void MainWindow::on_editProductBtn_clicked()
{
    QString ID = ui->IDlineEdit->text();
    QString LIBELLEPRODUCT = ui->productComboBox->currentText();
    QString PRIX = ui->PrixLineEdit->text();
    QString QTE = ui->qteLineEdit->text();
    QString TOTAL = ui->totalLineEdit->text();
    QString DATE = ui->dateEdit->text();

    qDebug() <<"ID :" << ID << "LIBELLEPRODUCT :" << LIBELLEPRODUCT << "PRIX :" << PRIX << "QTE :" << QTE << "TOTAL :" << TOTAL << "DATE :" << DATE;

    QSqlDatabase database = QSqlDatabase::database();
      database.open();


    QSqlQuery qwery;

    qwery.prepare("update invoice set ID= '"+ ID +"', LIBELLEPRODUCT='"+ LIBELLEPRODUCT +"', PRIX='"+ PRIX +"', QTE='"+ QTE +"', TOTAL='"+ TOTAL +"', DATE='"+ DATE +"' where ID = '"+ ID +"' ");
    qwery.bindValue(":LIBELLEPRODUCT",ui->productComboBox->currentText());
    qwery.bindValue(":PRIX",ui->PrixLineEdit->text());
    qwery.bindValue(":QTE",ui->qteLineEdit->text());
    qwery.bindValue(":TOTAL",ui->totalLineEdit->text());
    qwery.bindValue(":DATE",ui->dateEdit->text());

    if(qwery.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Updated Successfully! Try to click Display all Invoices Button to see the change."));
        database.close();

    }
    else{
        QMessageBox::critical(this,tr("Error:"),qwery.lastError().text());
    }

}

