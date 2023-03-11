#include "mainwindow.h"
#include <QApplication>


using namespace std;



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}




































    /*QApplication *app = new QApplication(argc, argv);

        QMainWindow* mw = new QMainWindow(nullptr);
        mw->setWindowTitle("FACTEUR");
        mw->resize(700, 500);

        QWidget* content = new QWidget;
        QFormLayout* form = new QFormLayout;

        QLineEdit *editId = new QLineEdit;
        QLineEdit *editLibelle = new QLineEdit;
        QLineEdit *editPrix = new QLineEdit;
        QLineEdit *editQte = new QLineEdit;


        form->addRow("ID:", editId);
        form->addRow("LIBELLE:", editLibelle);
        form->addRow("PRIX:", editPrix);
        form->addRow("QUANTITÉ:", editQte);


        QPushButton *addbutton = new QPushButton("Ajouter", nullptr);
        QPushButton *qbutton = new QPushButton("Fermer", nullptr);*/




           /* ui->tableWidget->setColumnCount(5);
            ui->tableWidget->setShowGrid(true);
            ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setHorizontalHeaderLabels(headers);
            ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
            ui->tableWidget->hideColumn(0);*/

        //QObject::connect(cbutton, &QPushButton::clicked, [=]() {
                         //cout << editPrenom->text().toStdString() << ", " << editNom->text().toStdString() << endl;
                        //});

    //    QObject::connect(qbutton, SIGNAL(clicked()), &app, SLOT(quit()));
      /*  QObject::connect(qbutton, &QPushButton::clicked, [=]() { app->quit(); });

        QGridLayout* gridbox = new QGridLayout;
        gridbox->addWidget(addbutton, 0, 0);
        gridbox->addWidget(qbutton, 0, 1);

        form->addRow(gridbox);

        content->setLayout(form);
        mw->setCentralWidget(content);

        mw->show();

        return app->exec();*/

