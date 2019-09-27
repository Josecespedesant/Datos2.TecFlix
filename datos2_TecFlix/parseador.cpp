#include "parseador.h"
#include "movies.h"
#include <QJsonObject>
#include <QJsonDocument>

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)-> append((char*)contents, size* nmemb);
    return size * nmemb;
}

parseador::parseador(QObject *parent, int linkPos, std::string directory) : QObject (parent)
{


    std::ifstream ifile(directory);
    std::string line;

    //Salta primera linea
    std::getline(ifile, line);

    std::string *array = new std::string[9];
    std::string *array2 = new std::string[9];



    for(int i = 0 ; i < 18 ; i++)
{
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

        curl_easy_cleanup(curl);
      }

    QString qstr = QString::fromStdString(html);

    QString start = "<link rel='image_src' href=\"";
    QString end = "\">";

    std::string subString = giveMeTextBetween(qstr, start, end);

    int end2 = QString::fromStdString(subString).indexOf(end);

    std::string moviePoster = subString.substr(0, end2);

    if(i<9){
        array[i] = moviePoster;
    }

    if(i >= 9){
        array2[i-9] = moviePoster;
    }


    }
    QJsonObject recordObject;

    QJsonObject page;

    page.insert("Enlace1", "asdasd");
    page.insert("Enlace2", "asdafassd");
    page.insert("Enlace3", "asdashadfd");
    page.insert("Enlace4", "asdahahsd");
    page.insert("Enlace5", "asdaahsd");
    page.insert("Enlace6", "asdaadfdsd");
    page.insert("Enlace7", "asdasjrfjd");
    page.insert("Enlace8", "asdasfghd");
    page.insert("Enlace9", "asdasfghfghd");

    recordObject.insert("Pagina", page);

    QJsonDocument doc(recordObject);
    qDebug() << doc.toJson();

    /*
    QString val;
    QFile file;
    file.setFileName("/home/josecespedes/Datos2.TecFlix/test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    val = file.readAll();
    file.close();

    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("persona"));
    qWarning() << value;
    QJsonObject item = value.toObject();
    qWarning() << tr("QJsonObject of description:" ) << item;
    QJsonValue subobj = item["nombre"];
    qWarning() << subobj.toString();


*/




    LinkedList<movies *> *paginas = new LinkedList<movies *>();

    movies *m1 = new movies(NULL, array);
    movies *m2 = new movies(NULL, array2);


    m2->show();


}

std::string parseador::giveMeTextBetween(QString s, QString before, QString after){

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

