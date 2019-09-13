#include "mainwindow.h"
#include <QApplication>
#include "page.h"
#include "linkedlist.h"

/*!
 * Metodo main del proyecto
 * \param argc
 * \param argv
 * \return
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    w->show();
    return a.exec();
}
