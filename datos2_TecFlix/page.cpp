#include "page.h"
#include <iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include "linkedlist.h"

Page::Page(QWidget *parent, int linkPos, std::string directory)
{
    std::ifstream ifile(directory);
    std::string line;

    //Salta primera linea
    std::getline(ifile, line);

    std::getline(ifile, line);
    std::istringstream iss{line};
    std::string token;

    LinkedList<std::string> *movieInfo = new LinkedList<std::string>();
    while(std::getline(iss, token, ',')){
        movieInfo->addLast(token);
    }

    std::cout << movieInfo->getByPos(linkPos) << std::endl;

    setWindowTitle("TecFlix");
    setWindowIcon(QIcon(":/icons/icon.png"));
    int wdth = 700;
    int hght = 700;
    setFixedSize(wdth, hght);

    //Define el boton de arriba y le añade una acción al ser presionado
    upButton = new QPushButton(tr("&Up"), this);
    upButton->setAttribute(Qt::WA_TranslucentBackground, true);
    upButton->setMaximumWidth(150);
    connect(upButton,  SIGNAL (released()), this, SLOT (on_upButton_clicked()));


    //Define el boton de abajo y le añade una acción al ser presionado
    downButton = new QPushButton(tr("&Down"), this);
    downButton->setAttribute(Qt::WA_TranslucentBackground, true);
    downButton->setMaximumWidth(150);
    connect(downButton,  SIGNAL (released()), this, SLOT (on_downButton_clicked()));

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);

    mainLayout->addWidget(upButton,0,1);
    mainLayout->addWidget(downButton,5,1);

    int i=1;
    int j=0;
    while(i!=4){
        while(j!=3){
            mainLayout->addWidget(new QPushButton("A"),i,j);
            j++;
        }
        j=0;
        i++;
    }
}

void Page::on_upButton_clicked(){

}

void Page::on_downButton_clicked(){

}
