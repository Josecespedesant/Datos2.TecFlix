#ifndef MOVIES_H
#define MOVIES_H

#include <QDialog>
#include "QLabel"
#include "doublelinkedlist.h"
#include "linkedlist.h"
namespace Ui {
class movies;
}

class movies : public QDialog
{
    Q_OBJECT


public:
    explicit movies(QWidget *parent =  NULL, std::string *link = NULL);
    void LoadAvatar(const std::string &strAvatarUrl, QLabel &label);
    ~movies();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::movies *ui;
};

#endif // MOVIES_H
