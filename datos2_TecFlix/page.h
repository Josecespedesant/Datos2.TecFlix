#ifndef PAGE_H
#define PAGE_H

#include "QWidget"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"

class Page : public QWidget
{
    Q_OBJECT
public:
    Page(QWidget *parent = nullptr, int linkPos = NULL, std::string directory = NULL);

private slots:
    void on_upButton_clicked();
    void on_downButton_clicked();

private:
    QGridLayout *mainLayout;
    QPushButton *upButton;
    QPushButton *downButton;
    QString directory;
};

#endif // PAGE_H
