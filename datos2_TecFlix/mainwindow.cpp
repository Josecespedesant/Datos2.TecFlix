#include "mainwindow.h"
#include <iostream>
#include "parseador.h"
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>

#include "movies.h"

#include "linkedlist.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
{
    //Configura la ventana
    setWindowTitle("TecFlix");
    setWindowIcon(QIcon(":/icons/icon.png"));
    int wdth = 560;
    int hght = 400;
    setFixedSize(wdth, hght);

    //Define el boton de busqueda y le añade una acción al ser presionado
    browseButton = new QPushButton(tr("&Browse..."), this);
    browseButton->setAttribute(Qt::WA_TranslucentBackground, true);
    connect(browseButton,  SIGNAL (released()), this, SLOT (on_browseButton_clicked()));

    //Define el boton de aceptar y le añade una acción al ser presionado
    acceptButton = new QPushButton(tr("&Accept..."), this);
    acceptButton->setAttribute(Qt::WA_TranslucentBackground, true);
    acceptButton->setMaximumWidth(200);
    connect(acceptButton,  SIGNAL (released()), this, SLOT (on_acceptButton_clicked()));

    //Agrega el icono de la aplicacion
    label = new QLabel;
    label->setPixmap(QPixmap(":/icons/icon.png"));
    label->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Preferred );

    //Agrega un texto donde aparecerá el nombre del directorio
    texto = new QLabel;
    texto->setText("File directory");
    texto->setMaximumWidth(600);

    //Se agrega todo al layout
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);

    mainLayout->addWidget(label, 0, 2);
    mainLayout->addWidget(browseButton, 1 , 0);
    mainLayout->addWidget(acceptButton, 1, 3);
    mainLayout->addWidget(texto, 1, 2);
}

void MainWindow::on_browseButton_clicked(){ 
    //Define un string con el path al archivo csv
    directory =
            QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath(), "*.csv"));
    if (!directory.isEmpty()) {
        MainWindow::texto->setText(directory);
    }
}

void MainWindow::on_acceptButton_clicked(){
        if (!directory.isEmpty()) {

        std::ifstream ifile(directory.toStdString());
        std::string line;
        columns = new LinkedList<std::string>();

        std::getline(ifile, line);
        std::istringstream iss{line};
        std::string token;

        while(std::getline(iss, token, ',')){
            columns->addLast(token);
        }


        numCol = columns->getSize();

        posLink = columns->getPosByElem("movie_imdb_link");

        hide();

        parseador *p = new parseador(NULL, posLink, directory.toStdString());

        //movies *m = new movies;
        //m->show();
       }

        else{
            MainWindow::texto->setText("Please select the file you want to load");
        }
}
