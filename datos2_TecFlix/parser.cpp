#include "parser.h"
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


static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)-> append((char*)contents, size* nmemb);
    return size * nmemb;
}

Parser::Parser(int linkPos, std::string directory)
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


    std::string link = movieInfo->getByPos(linkPos);

    QUrl *url = new QUrl(link.c_str());

    //Cambia el enlace a https si es necesario
    if(link[4]!='s'){
      link.insert(4, "s");
    }



    //Tomado de https://gist.github.com/alghanmi/c5d7b761b2c9ab199157

    std::string html;

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);

        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
      }

    QString qstr = QString::fromStdString(html);

    QWebEnginePage * page = new QWebEnginePage();

    page->setHtml(link.c_str());



//    std::cout << html <<std::endl;


}
