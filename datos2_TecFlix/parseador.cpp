#include "parseador.h"
#include "movies.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "thread"

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)-> append((char*)contents, size* nmemb);
    return size * nmemb;
}

static std::string giveMeTextBetween(QString s, QString before, QString after){

   int start = s.indexOf(before);

   if(start == -1){
       return "";
   }

   start += before.length();

   int end = s.indexOf(after, start);

   if(end == -1){
       return "";
   }

   return s.toStdString().substr(start, end);

}

parseador::parseador(QObject *parent, int linkPos, std::string directory) : QObject (parent)
{

    LinkedList<std::string> *allMovieLinks = new LinkedList<std::string>();

    std::ifstream ifile(directory);
    std::string line;

    //Salta primera linea
    std::getline(ifile, line);

    while(std::getline(ifile, line)){

        //std::getline(ifile, line);
        std::istringstream iss{line};
        std::string token;

        LinkedList<std::string> *movieInfo = new LinkedList<std::string>();
        while(std::getline(iss, token, ',')){
            movieInfo->addLast(token);
        }


        std::string link = movieInfo->getByPos(linkPos);

        allMovieLinks->addLast(link);
    }

    LinkedList<std::string> *part1 = new LinkedList<std::string>();

    for(int k = 0; k<18;k++){
        part1->addLast(allMovieLinks->getByPos(k));
    }

    QJsonObject *recordObject = new QJsonObject;

    for(int i=0; i<2; i++){

        QJsonObject page;

        for(int j = 0; j<18; j++){
            std::string lin = part1->getByPos(j);

            //Cambia el enlace a https si es necesario
            if(lin[4]!='s'){
            lin.insert(4, "s");
            }

            //Tomado de https://gist.github.com/alghanmi/c5d7b761b2c9ab199157

            std::string html;
            CURL *curl;
            CURLcode res;

            curl = curl_easy_init();

            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, lin.c_str());
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }

            QString qstr = QString::fromStdString(html);

            QString start = "<link rel='image_src' href=\"";
            QString end = "\">";

            std::string subString = giveMeTextBetween(qstr, start, end);

            int end2 = QString::fromStdString(subString).indexOf(end);

            std::string moviePoster = subString.substr(0, end2);

            std::string peli = "pelicula"+std::to_string(j);

            page.insert(peli.c_str(), moviePoster.c_str());

            std::cout << "Entró" << std::endl;

        }
        std::string nombrePag = "pagina"+std::to_string(i);
        recordObject->insert(nombrePag.c_str(), page);
    }


    QJsonDocument doc(*recordObject);

    qDebug() << doc.toJson();

    QJsonObject jObj = doc.object();
    QJsonValue value = jObj.value(QString("pagina0"));
    QJsonValue value2 = jObj.value(QString("pagina1"));
    QJsonObject item = value.toObject();
    QJsonObject item2 = value2.toObject();

    std::string *array = new std::string[9];

    std::string *array2 = new std::string[9];


    for(int i = 0; i<9; i++){
        std::string palabra = "pelicula" + std::to_string(i);
        QJsonValue subObj = item[palabra.c_str()];
        array[i] = subObj.toString().toStdString();
    }


    for(int i = 0; i<9; i++){
        std::string palabra = "pelicula" + std::to_string(i);
        QJsonValue subObj = item2[palabra.c_str()];
        array2[i] = subObj.toString().toStdString();
    }

    DoubleLinkedList<movies *> *paginas = new DoubleLinkedList<movies *>();

    movies *m1 = new movies(NULL, array, paginas);
    movies *m2 = new movies(NULL, array2, paginas);



    paginas->addLast(m1);
    paginas->addLast(m2);

    m1->show();

}
