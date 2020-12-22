#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
        QPixmap bkgnd("F:/BD/Kurcsach/images/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        ui->PassLine->setEchoMode(QLineEdit::Password);
        ui->LoginLine->setPlaceholderText("Login");
        ui->PassLine->setPlaceholderText("Password");
        mb = new QMessageBox;
        isConnected = false;




}

login::~login()
{
    delete ui;
}


void login::on_LogInButton_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={Sql server};SERVER=DESKTOP-D0G40ML;DATABASE=CarEquiqmentShop;");
    db.setUserName(ui->LoginLine->text());
    db.setPassword(ui->PassLine->text());

    if (db.open()){
        isConnected = true;
        close();


    }
    else{
        isConnected = false;
        mb->setText("Login Error, please check your data.");
        mb->show();

    }
}
