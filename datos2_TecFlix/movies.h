#ifndef MOVIES_H
#define MOVIES_H

#include <QDialog>
#include "QLabel"
#include "doublelinkedlist.h"
#include "linkedlist.h"
namespace Ui {

/*!
 * Declaración de la clase movies
 */
class movies;
}

class movies : public QDialog
{
    Q_OBJECT


public:
    /*!
     * \brief Constructor de la clase movies
     * \param parent
     * \param link
     * \param paginas
     */
    explicit movies(QWidget *parent =  NULL, std::string *link = NULL, DoubleLinkedList<movies *> *paginas = new DoubleLinkedList<movies *>());
    /*!
     * \brief Metodo que permite asignar a un label una imagen dada un url
     * \param strAvatarUrl
     * \param label
     */
    void LoadAvatar(const std::string &strAvatarUrl, QLabel &label);
    /*!
     * \brief Destructor de la clase movies
     */
    ~movies();

private slots:
    /*!
     * \brief Zoom in
     */
    void on_pushButton_3_clicked();
    /*!
     * \brief Zoom out
     */
    void on_pushButton_4_clicked();

    /*!
     * \brief Pagina siguiente
     */
    void on_pushButton_2_clicked();

    /*!
     * \brief Pagina anterior
     */
    void on_pushButton_clicked();

private:
    Ui::movies *ui;
    DoubleLinkedList<movies *> *paginas;
};

#endif // MOVIES_H
