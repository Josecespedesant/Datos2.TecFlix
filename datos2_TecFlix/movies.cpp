#include "movies.h"
#include "ui_movies.h"
#include "QBitmap"
#include <QWebEngineView>
#include <QNetworkReply>
#include "iostream"

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)-> append((char*)contents, size* nmemb);
    return size * nmemb;
}

movies::movies(QWidget *parent, std::string *link, DoubleLinkedList<movies *> *paginas) :
    QDialog(parent),
    ui(new Ui::movies)
{

    this->paginas = paginas;
    setWindowIcon(QIcon(":/icons/icon.png"));

    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    ui->setupUi(this);


    LoadAvatar(link[0], *ui->label11);
    LoadAvatar(link[1], *ui->label12);
    LoadAvatar(link[2], *ui->label13);
    LoadAvatar(link[3], *ui->label21);
    LoadAvatar(link[4], *ui->label22);
    LoadAvatar(link[5], *ui->label23);
    LoadAvatar(link[6], *ui->label31);
    LoadAvatar(link[7], *ui->label32);
    LoadAvatar(link[8], *ui->label33);


}

void movies::LoadAvatar(const std::string &strAvatarUrl, QLabel &label){
    QUrl url(QString().fromStdString(strAvatarUrl));
       QNetworkAccessManager manager;
       QEventLoop loop;

       QNetworkReply *reply = manager.get(QNetworkRequest(url));
       QObject::connect(reply, &QNetworkReply::finished, &loop, [&reply, &label,&loop](){
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray jpegData = reply->readAll();
            QPixmap *pixmap = new QPixmap;
            pixmap->loadFromData(jpegData);
            if (!pixmap->isNull())
            {
                label.clear();
                label.setPixmap(*pixmap);
                label.setScaledContents(true);
            }
        }
        loop.quit();
      });

      loop.exec();
}

movies::~movies()
{
    delete ui;
}

void movies::on_pushButton_3_clicked()
{
    int w = ui->label11->width()+30;
    int h = ui->label11->height()+30;

    ui->label11->resize(w,h);
    ui->label12->resize(w,h);
    ui->label13->resize(w,h);
    ui->label21->resize(w,h);
    ui->label22->resize(w,h);
    ui->label23->resize(w,h);
    ui->label31->resize(w,h);
    ui->label32->resize(w,h);
    ui->label33->resize(w,h);

}

void movies::on_pushButton_4_clicked()
{
    int w = ui->label11->width()-30;
    int h = ui->label11->height()-30;

    ui->label11->resize(w,h);
    ui->label12->resize(w,h);
    ui->label13->resize(w,h);
    ui->label21->resize(w,h);
    ui->label22->resize(w,h);
    ui->label23->resize(w,h);
    ui->label31->resize(w,h);
    ui->label32->resize(w,h);
    ui->label33->resize(w,h);

}

void movies::on_pushButton_2_clicked()
{
    paginas->getByPos(1)->show();
    paginas->addLast(paginas->getByPos(0));
    hide();
}

void movies::on_pushButton_clicked()
{
    if(paginas->getSize()!=2){
    paginas->getByPos(0)->show();
    paginas->deleteFirst();
    hide();
    return;
    }
    else{
        paginas->getByPos(0)->show();
        hide();
    }
}
