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
#include "linkedlist.h"
#include "movies.h"

/*!
 * Clase de la primera ventana donde permite buscar el archivo csv
 */

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /*!
     * Constructor de la clase MainWindow
     * \param parent
     */
    MainWindow(QWidget *parent = nullptr);


private slots:
    /*!
     * Abre el buscador de archivos al presionar el boton de buscar
     */
    void on_browseButton_clicked();

    /*!
     * Una vez se selecciona el archivo se presiona este boton para aceptar
     */
    void on_acceptButton_clicked();


private:
    QGridLayout *mainLayout;
    QLabel *texto;
    QLabel *label;
    QPushButton *browseButton;
    QPushButton *acceptButton;
    QDir currDir;
    QString directory;
    LinkedList<std::string> *columns;
    LinkedList<std::string> *movieInfo;
    int numCol;
    int posLink;
};

#endif // MAINWINDOW_H
