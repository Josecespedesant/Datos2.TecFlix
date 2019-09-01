#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    setWindowTitle("TecFlix");
    setWindowIcon(QIcon(":/icons/icon.png"));
    int wdth = 560;
    int hght = 310;
    setFixedSize(wdth, hght);

    browseButton = new QPushButton(tr("&Browse..."), this);
    browseButton->setAttribute(Qt::WA_TranslucentBackground, true);
    connect(browseButton,  SIGNAL (released()), this, SLOT (on_browseButton_clicked()));

    label = new QLabel;
    label->setPixmap(QPixmap(":/icons/icon.png"));
    label->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Preferred );

    texto = new QLabel;
    texto->setText("File directory");

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);

    mainLayout->addWidget(label, 0, 1);
    mainLayout->addWidget(browseButton, 1 , 0);
    mainLayout->addWidget(texto, 1, 1);
}

void MainWindow::on_browseButton_clicked(){
    QString directory =
            QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath(), "*.csv"));


    if (!directory.isEmpty()) {
        MainWindow::texto->setText(directory);
    }

}
