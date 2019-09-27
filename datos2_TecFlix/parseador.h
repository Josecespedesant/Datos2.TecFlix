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


class parseador : QObject
{

private:
    QWebEnginePage * page;

public:
    parseador(QObject *parent = nullptr, int linkPos = NULL, std::string directory = NULL);
    std::string giveMeTextBetween(QString s, QString before, QString after);
};

#endif // PARSEADOR_H
