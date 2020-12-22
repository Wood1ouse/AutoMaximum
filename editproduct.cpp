#include "editproduct.h"
#include "ui_editproduct.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

editproduct::editproduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editproduct)
{
    ui->setupUi(this);


}


editproduct::~editproduct()
{
    delete ui;
}
