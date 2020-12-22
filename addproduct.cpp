#include "addproduct.h"
#include "ui_addproduct.h"

addproduct::addproduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addproduct)
{
    ui->setupUi(this);


}

addproduct::~addproduct()
{
    delete ui;
}

void addproduct::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("insert into Product(ProductName, Supplier, SellerID, Type, Price, InStock) values (:ProductName, :Supplier, :SellerID, :Type, :Price, :InStock)");
    query->bindValue(":ProductName", ui->lineEdit->text());
    query->bindValue(":Supplier", ui->lineEdit_2->text());
    query->bindValue(":SellerID", ui->lineEdit_3->text());
    query->bindValue(":Type", ui->lineEdit_4->text());
    query->bindValue(":Price", ui->lineEdit_5->text());
    query->bindValue(":InStock", ui->lineEdit_6->text());

    QMessageBox *mb = new QMessageBox();
    if (!query->exec()){
        mb->setText("Something Went Wrong!");
        mb->show();
    }
    else{
        close();
    }


    emit tableRefresh();
}
