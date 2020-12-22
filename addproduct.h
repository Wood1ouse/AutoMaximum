#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class addproduct;
}

class addproduct : public QWidget
{
    Q_OBJECT

public:
    explicit addproduct(QWidget *parent = nullptr);
    ~addproduct();

private slots:
    void on_pushButton_clicked();

signals:
    void tableRefresh();

private:
    Ui::addproduct *ui;

};

#endif // ADDPRODUCT_H
