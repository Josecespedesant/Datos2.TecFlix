#ifndef PARSEADOR_H
#define PARSEADOR_H


#include <iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include "linkedlist.h"
#include "curl/curl.h"
#include <QXmlQuery>
#include <QtWebEngine/QtWebEngine>
#include <QWebEnginePage>
#include <QWebEngineSettings>

/*!
 * \brief Declaración de la clase parseador
 */
class parseador : QObject
{

private:
    QWebEnginePage * page;

public:
    /*!
     * \brief Constructor de la clase parseador
     * \param parent
     * \param linkPos
     * \param directory
     */
    parseador(QObject *parent = nullptr, int linkPos = NULL, std::string directory = NULL);
};

#endif // PARSEADOR_H
