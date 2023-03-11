#include "product.h"
#include "ui_product.h"

product::product(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product)
{
    ui->setupUi(this);


}

product::~product()
{
    delete ui;
    delete model;
}

void product::on_addProductBtn_2_clicked()
{
    QString IDPRODUCT = ui->idLineEdit->text();
    QString LIBELLE = ui->libelleLineEdit->text();
    QString PRIX = ui->prixLineEdit->text();

    qDebug() <<"ID :" << IDPRODUCT << "LIBELLE :" << LIBELLE << "PRIX :" << PRIX;


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db");
    database.open();

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

    query.prepare("insert into product (IDPRODUCT, LIBELLE, PRIX) values('" + IDPRODUCT + "','" + LIBELLE + "', '" + PRIX +"')");


    if(query.exec()){
        QMessageBox::critical(this,tr("Add"),tr("Added Successfully! Try to click Display all Product Button to see the change. "));
        database.close();

    }
    else{
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
        database.commit();
    }
}


void product::on_displayBtn_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db");
    database.open();
    database.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qwery;
    qwery.prepare("select * from product order by IDPRODUCT;");
    qwery.exec();
    model->setQuery(qwery);
    ui->productTableView->setModel(model);
    database.close();

}


void product::on_deleteProductBtn_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db");
    database.open();

    QSqlQuery qwery;

    qwery.prepare("delete from product where IDPRODUCT = " + ui->lineEdit->text() + "");

    if(qwery.exec()){
        QMessageBox::critical(this,tr("Delete"),tr("Deleted Successfully! Try to click Display all Product Button to see the change."));
        database.close();

    }
    else{
        QMessageBox::critical(this,tr("Error::"),qwery.lastError().text());

    }
}


void product::on_editProductBtn_clicked()
{
    QString IDPRODUCT = ui->idLineEdit->text();
    QString LIBELLE = ui->libelleLineEdit->text();
    QString PRIX = ui->prixLineEdit->text();

    qDebug() <<"ID :" << IDPRODUCT << "LIBELLE :" << LIBELLE << "PRIX :" << PRIX;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Administrateur/OneDrive/Desktop/database/mydb.db");
    database.open();

    QSqlQuery qwery;

    qwery.prepare("update product set IDPRODUCT= '"+ IDPRODUCT +"', LIBELLE='"+ LIBELLE +"', PRIX='"+ PRIX +"' where IDPRODUCT = '"+ IDPRODUCT +"' ");
    qwery.bindValue(":LIBELLE",ui->libelleLineEdit->text());
    qwery.bindValue(":PRIX",ui->prixLineEdit->text());

    if(qwery.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Updated Successfully! Try to click Display all Product Button to see the change."));
        database.close();

    }
    else{
        QMessageBox::critical(this,tr("Error::"),qwery.lastError().text());
    }


   // QSqlDatabase::database().commit();

}


void product::on_resetBtn_clicked()
{
    ui->idLineEdit->clear();
    ui->libelleLineEdit->clear();
    ui->prixLineEdit->clear();
}

