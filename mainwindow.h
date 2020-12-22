#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QMessageBox>

#include "login.h"
#include "ui_login.h"

#include "addproduct.h"
#include "ui_addproduct.h"

#include "editproduct.h"
#include "ui_editproduct.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    login* dblogin;
    addproduct* addprod;
    editproduct* editprod;
    QMessageBox* mb;





private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void getTableRefresh();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void HideAll();

    void ShowAll();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel* model;

};
#endif // MAINWINDOW_H
