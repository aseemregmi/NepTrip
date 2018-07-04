#include <QtWidgets>

#include "mainwindow.h"
#include <QGridLayout>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QActionGroup>

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    homeScreen();

    createActions();
    createMenus();

    setWindowTitle(tr("NEPTRIP"));
    setMinimumSize(1600, 900);
    resize(480, 320);
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
    QPixmap logoNepTrip("C:/Everything/Project/NepTrip/img/logoNepTrip.jpg");
    logo->setPixmap(logoNepTrip);
    logo->setMask(logoNepTrip.mask());
    logo->setAlignment(Qt::AlignCenter);

    QPushButton *gotoMap = new QPushButton("Let's Explore Nepal Together");
    gotoMap->setCursor(Qt::PointingHandCursor);
    gotoMap->setStyleSheet("QPushButton {font-size: 18pt; padding: 10; color: blue; background-color: white; border: 2px solid blue; border-radius: 20px; } QPushButton:hover {border: 2px solid red; background-color: red; color: white;}");
    connect(gotoMap, SIGNAL(clicked()),this,SLOT(mapScreen()));

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(head, 1,4,2,2);
    layout->addWidget(logo, 4,4,2,2);
    layout->addWidget(gotoMap, 8,4,2,2);


    window->setLayout(layout);
    setWindowTitle("NepTrip");

}

void MainWindow:: mapScreen()
{

    QWidget *window = new QWidget();

    setCentralWidget(window);

    QGridLayout *layout = new QGridLayout();

    QPushButton *gotoChitwan = new QPushButton("Chitwan");
    gotoChitwan->setStyleSheet("font-size: 9pt; padding: 1; color: blue;");
    gotoChitwan->setMaximumWidth(100);
    connect(gotoChitwan, SIGNAL(clicked()),this,SLOT(chitwanScreen()));

    QPushButton *gotoKathmandu = new QPushButton("Kathmandu");
    gotoKathmandu->setStyleSheet("font-size: 9pt; padding: 1; color: blue;");
    gotoKathmandu->setMaximumWidth(100);
    connect(gotoKathmandu, SIGNAL(clicked()),this,SLOT(kathmanduScreen()));

    layout->addWidget(gotoChitwan,1,1,1,1);
    layout->addWidget(gotoKathmandu,1,2,1,1);

    window->setLayout(layout);
    setWindowTitle("NepTrip");
}

void MainWindow::chitwanScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel *head = new QLabel();
    head->setText("Welcome To Chitwan");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignTop);

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(head, 1,4,2,2);

    window->setLayout(layout);
    setWindowTitle("Chitwan");
}

void MainWindow::kathmanduScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel *head = new QLabel();
    head->setText("Welcome To Kathmandu");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignTop);

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(head, 1,1,1,1);

    window->setLayout(layout);
    setWindowTitle("Kathmandu");
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU



void MainWindow::about()
{
    QMessageBox::about(this, tr("About"),
            tr("Welcome to NepTrip."
               "This is a tourism based project developed by CE first year students at KU"));
}

void MainWindow::createActions()
{
    exitAct = new QAction(tr("&Exit"), this); // Exits Application
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    homeAct = new QAction(tr("&Home Page"), this);
    connect(homeAct, &QAction::triggered, this, &MainWindow::homeScreen);

    aboutAct = new QAction(tr("&About"), this); // Displays About Box or it triggers about() slot
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    mapScreenAct = new QAction(tr("&Go To Map"), this);
    connect(mapScreenAct, &QAction::triggered, this, &MainWindow::mapScreen);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&NEPTRIP"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(homeAct);
    optionsMenu->addAction(mapScreenAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);

}
