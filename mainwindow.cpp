#include "mainwindow.h"

#include "QtWidgets"
#include <QGridLayout>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QActionGroup>

MainWindow::MainWindow()
{
    QWidget *window = new QWidget();
    setCentralWidget(window);

    homeScreen();


}


void MainWindow::homeScreen()
{
    QWidget *window = new QWidget();
    setCentralWidget(window);

    QLabel *head = new QLabel();
    head->setText("Welcome to NepTrip");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignCenter);

    QLabel *logo = new QLabel();
    QPixmap logoNepTrip("C:/Users/HP/Documents/NepTrip/img/logoLabel.jpg");
    logo->setPixmap(logoNepTrip);
    logo->setMask(logoNepTrip.mask());
    logo->setAlignment(Qt::AlignCenter);

    QPushButton *gotoMap = new QPushButton("Let's Explore Nepal Together");
    gotoMap->setStyleSheet("font-size: 18pt; padding: 10; color: blue;");
    connect(gotoMap, SIGNAL(clicked()),this,SLOT(mapScreen()));

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(head, 1,4,2,2);
    layout->addWidget(logo, 4,4,2,2);
    layout->addWidget(gotoMap, 8,4,2,2);


    window->setLayout(layout);
    setWindowTitle("NepTrip");
    setFixedHeight(900);
    setFixedWidth(1200);

}

void MainWindow:: mapScreen()
{

    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel *head = new QLabel();
    head->setText("You can browse tourism Places Here");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignCenter);

    QLabel *body = new QLabel();
    body->setText("Under Maintenance");
    body->setStyleSheet("font-size: 40pt; color: grey;");
    body->setAlignment(Qt::AlignCenter);

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(head, 1,4,2,2);
    layout->addWidget(body, 4,4,2,2);


    window->setLayout(layout);
    setWindowTitle("NepTrip");
    setFixedHeight(900);
    setFixedWidth(1200);

}

