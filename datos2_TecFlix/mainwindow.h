#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QWidget"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QGraphicsPixmapItem"
#include "QDesktopWidget"
#include "QIcon"
#include "QPushButton"
#include "QGridLayout"
#include "QLabel"
#include "QDir"
#include "QFileDialog"
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void on_browseButton_clicked();

private:
    QGridLayout *mainLayout;
    QLabel *texto;
    QLabel *label;
    QPushButton *browseButton;
    QDir currDir;

};

#endif // MAINWINDOW_H
