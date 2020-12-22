#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QMessageBox* mb;
    bool isConnected;

private slots:

    void on_LogInButton_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;

};

#endif // LOGIN_H
