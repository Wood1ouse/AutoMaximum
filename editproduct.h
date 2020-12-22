#ifndef EDITPRODUCT_H
#define EDITPRODUCT_H

#include <QWidget>

namespace Ui {
class editproduct;
}

class editproduct : public QWidget
{
    Q_OBJECT

public:
    explicit editproduct(QWidget *parent = nullptr);
    ~editproduct();

private:
    Ui::editproduct *ui;
};

#endif // EDITPRODUCT_H
