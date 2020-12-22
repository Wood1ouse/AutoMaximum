#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    HideAll();
    ui->pushButton_2->setVisible(false);
    dblogin = new login();
    dblogin->exec();
    ui->lineEdit_6->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
     ShowAll();
     ui->pushButton_2->setVisible(true);
     model = new QSqlTableModel();
     model->setTable("Product");
     ui->tableView->resize(725, 651);
     model->select();
     ui->tableView->setModel(model);
     ui->tableView->show();


}

void MainWindow::on_pushButton_2_clicked()
{
    addprod = new addproduct();
    connect(addprod, SIGNAL(tableRefresh()), this, SLOT(getTableRefresh()));
    addprod->show();
}

void MainWindow::getTableRefresh(){
    on_pushButton_clicked();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{


    int pk;
    pk = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();
    QSqlQuery * query = new QSqlQuery();
    query->prepare("select ProductName, Supplier, SellerID, Type, Price, InStock from Product where ProductID = :id");
    query->bindValue(":id", pk);
    ui->lineEdit_6->setText(QString::number(pk));

    if (query->exec()){
        query->next();
        ui->lineEdit_0->setText(query->value(0).toString());
        ui->lineEdit_1->setText(query->value(1).toString());
        ui->lineEdit_2->setText(query->value(2).toString());
        ui->lineEdit_3->setText(query->value(3).toString());
        ui->lineEdit_4->setText(query->value(4).toString());
        ui->lineEdit_5->setText(query->value(5).toString());



    }

}


void MainWindow::on_pushButton_5_clicked()
{
    HideAll();
    ui->pushButton_2->setVisible(false);
    model = new QSqlTableModel();
    model->setTable("Supplier");
    ui->tableView->resize(625, 651);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();


}


void MainWindow::on_pushButton_6_clicked()
{
    HideAll();
    ui->pushButton_2->setVisible(false);
    model = new QSqlTableModel();
    model->setTable("Staff");
    ui->tableView->resize(925, 651);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();


}

void MainWindow::ShowAll(){
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_7->setVisible(true);
    ui->lineEdit_0->setVisible(true);
    ui->lineEdit_1->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->lineEdit_3->setVisible(true);
    ui->lineEdit_4->setVisible(true);
    ui->lineEdit_5->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->comboBox->setVisible(true);
}


void MainWindow::HideAll(){
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->lineEdit_0->setVisible(false);
    ui->lineEdit_1->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->comboBox->setVisible(false);



}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("update Product set ProductName=?,Supplier=?,SellerID=?,Type=?,Price=?,InStock=? where ProductID=?");
    query->bindValue(0, ui->lineEdit_0->text());
    query->bindValue(1, ui->lineEdit_1->text());
    query->bindValue(2, ui->lineEdit_2->text());
    query->bindValue(3, ui->lineEdit_3->text());
    query->bindValue(4, ui->lineEdit_4->text());
    query->bindValue(5, ui->lineEdit_5->text());
    query->bindValue(6, ui->lineEdit_6->text());
    query->exec();
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("delete from Product where ProductID=?");
    query->bindValue(0, ui->lineEdit_6->text());
    query->exec();
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_7_clicked()
{
    model = new QSqlTableModel();
    model->setTable("Product");
    model->setFilter("Type = '" + ui->comboBox->currentText() + "'");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();
}
