#include <QtWidgets>

#include "mainwindow.h"
#include <QGridLayout>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QActionGroup>
#include <QFile>
#include <QString>
#include <QQuickView>
#include <QObject>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFrame>

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    homeScreen();

    createActions();
    createMenus();

    setWindowTitle(tr("NEPTRIP"));
    setMinimumSize(1280, 720);
    resize(480, 320);
}

QToolButton* MainWindow::getButton(QIcon x,QString s){
    QToolButton *button = new QToolButton;
    button->setIcon(x);
    button->setStyleSheet(" border: none; background-color:white;");
    button->setCursor(Qt::PointingHandCursor);
    button->setToolTip(s);
    return button;
}


QLabel* MainWindow::getCityImg(QPixmap x){
    QLabel *IMG = new QLabel();
    IMG->setPixmap(x);
    IMG->setAlignment(Qt::AlignCenter);
    return IMG;
}

QTextBrowser* MainWindow::getfile(QString p,QString t){
    QTextBrowser *displaydata = new QTextBrowser();
    QFile file(p);
         if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
             displaydata->setText(file.readAll());
             displaydata->setFrameStyle(QFrame::NoFrame);
             if (t=="Intro"){
                displaydata->setStyleSheet("background-image:url(:/Images/Rainbow.png);");
             }
             else if (t=="Hotel"){
                 displaydata->setStyleSheet("background-image:url(:/Images/Instagram.png);");
             }
             else if (t=="Extra"){
                 displaydata->setStyleSheet("background-image:url(:/Images/Dusk.png);");
             }
             else if (t=="Agency"){
                 displaydata->setStyleSheet("background-image:url(:/Images/Harmonic.png);");
             }
            }
   return displaydata;

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
    logo=getCityImg(QPixmap(":/Images/img/logoNepTrip.jpg"));

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

    QPixmap bkgnd(":/Images/img/map.jpg");

    bkgnd = bkgnd.scaled(1280,720, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QToolButton *gotoChitwan = new QToolButton;
    gotoChitwan = getButton(QIcon (":/Images/img/np.png"),QString ("Chitwan National Park"));
    connect(gotoChitwan, SIGNAL(clicked()),this,SLOT(chitwanScreen()));


    QToolButton *gotoKathmandu = new QToolButton;
    gotoKathmandu = getButton(QIcon (":/Images/img/icon.png"),QString ("Kathmandu Valley"));
    connect(gotoKathmandu, SIGNAL(clicked()),this,SLOT(kathmanduScreen()));

    QToolButton *gotoKhaptad = new QToolButton;
    gotoKhaptad = getButton(QIcon (":/Images/img/np.png"),QString ("Khaptad National Park"));
    connect(gotoKhaptad, SIGNAL(clicked()),this,SLOT(khaptadScreen()));

    QToolButton *gotoABC = new QToolButton;
    gotoABC = getButton(QIcon (":/Images/img/mt.png"),QString ("Everest Base Camp"));
    connect(gotoABC, SIGNAL(clicked()),this,SLOT(ABCScreen()));

    QToolButton *gotoPokhara = new QToolButton;
    gotoPokhara = getButton(QIcon (":/Images/img/icon.png"),QString ("Pokhara"));
    connect(gotoPokhara, SIGNAL(clicked()),this,SLOT(pokharaScreen()));

    QToolButton *gotoBhaktapur = new QToolButton;
    gotoBhaktapur = getButton(QIcon (":/Images/img/icon.png"),QString ("Bhaktapur"));
    connect(gotoBhaktapur, SIGNAL(clicked()),this,SLOT(bhaktapurScreen()));

    QToolButton *gotoDhulikhel = new QToolButton;
    gotoDhulikhel = getButton(QIcon (":/Images/img/icon.png"),QString ("Dhulikhel"));
    connect(gotoDhulikhel, SIGNAL(clicked()),this,SLOT(dhulikhelScreen()));

    QToolButton *gotoNagarkot = new QToolButton;
    gotoNagarkot = getButton(QIcon (":/Images/img/icon.png"),QString ("Nagarkot"));
    connect(gotoNagarkot, SIGNAL(clicked()),this,SLOT(nagarkotScreen()));

    QToolButton *gotoKakani = new QToolButton;
    gotoKakani = getButton(QIcon (":/Images/img/icon.png"),QString ("Kakani"));
    connect(gotoKakani, SIGNAL(clicked()),this,SLOT(kakaniScreen()));

    QToolButton *gotoEBC = new QToolButton;
    gotoEBC = getButton(QIcon (":/Images/img/mt.png"),QString ("Everest Base Camp"));
    connect(gotoEBC, SIGNAL(clicked()),this,SLOT(EBCScreen()));

    QToolButton *gotoSagarmatha = new QToolButton;
    gotoSagarmatha = getButton(QIcon (":/Images/img/np.png"),QString ("Sagarmatha National Park"));
    connect(gotoSagarmatha, SIGNAL(clicked()),this,SLOT(sagarmathaScreen()));

    QToolButton *gotoLhotse = new QToolButton;
    gotoLhotse = getButton(QIcon (":/Images/img/mt.png"),QString ("Lhotse"));
    connect(gotoLhotse, SIGNAL(clicked()),this,SLOT(lhotseScreen()));

    QToolButton *gotoHelambu = new QToolButton;
    gotoHelambu = getButton(QIcon (":/Images/img/icon.png"),QString ("Helambu"));
    connect(gotoHelambu, SIGNAL(clicked()),this,SLOT(helambuScreen()));

    QToolButton *gotoLumbini = new QToolButton;
    gotoLumbini = getButton(QIcon (":/Images/img/icon.png"),QString ("Lumbini"));
    connect(gotoLumbini, SIGNAL(clicked()),this,SLOT(lumbiniScreen()));

    QToolButton *gotoGorkha = new QToolButton;
    gotoGorkha = getButton(QIcon (":/Images/img/icon.png"),QString ("Gorkha"));
    connect(gotoGorkha, SIGNAL(clicked()),this,SLOT(gorkhaScreen()));

    QToolButton *gotoBandipur = new QToolButton;
    gotoBandipur = getButton(QIcon (":/Images/img/icon.png"),QString ("Bandipur"));
    connect(gotoBandipur, SIGNAL(clicked()),this,SLOT(bandipurScreen()));

    QToolButton *gotoJanakpur = new QToolButton;
    gotoJanakpur = getButton(QIcon (":/Images/img/icon.png"),QString ("Janakpur"));
    connect(gotoJanakpur, SIGNAL(clicked()),this,SLOT(janakpurScreen()));

    QToolButton *gotoBirgunj = new QToolButton;
    gotoBirgunj = getButton(QIcon (":/Images/img/icon.png"),QString ("Birgunj"));
    connect(gotoBirgunj, SIGNAL(clicked()),this,SLOT(birgunjScreen()));

    QToolButton *gotoIllam = new QToolButton;
    gotoIllam = getButton(QIcon (":/Images/img/icon.png"),QString ("Illam"));
    connect(gotoIllam, SIGNAL(clicked()),this,SLOT(illamScreen()));

    QToolButton *gotoManang = new QToolButton;
    gotoManang = getButton(QIcon (":/Images/img/icon.png"),QString ("Manang"));
    connect(gotoManang, SIGNAL(clicked()),this,SLOT(manangScreen()));

    QToolButton *gotoMustang = new QToolButton;
    gotoMustang = getButton(QIcon (":/Images/img/icon.png"),QString ("Mustang"));
    connect(gotoMustang, SIGNAL(clicked()),this,SLOT(mustangScreen()));

    QToolButton *gotoTansen = new QToolButton;
    gotoTansen = getButton(QIcon (":/Images/img/icon.png"),QString ("Tansen"));
    connect(gotoTansen, SIGNAL(clicked()),this,SLOT(tansenScreen()));

    QToolButton *gotoDaman = new QToolButton;
    gotoDaman = getButton(QIcon (":/Images/img/icon.png"),QString ("Daman"));
    connect(gotoDaman, SIGNAL(clicked()),this,SLOT(damanScreen()));

    QToolButton *gotoNamche = new QToolButton;
    gotoNamche = getButton(QIcon (":/Images/img/icon.png"),QString ("Namche"));
    connect(gotoNamche, SIGNAL(clicked()),this,SLOT(namcheScreen()));

    QToolButton *gotoHile = new QToolButton;
    gotoHile = getButton(QIcon (":/Images/img/icon.png"),QString ("Hile"));
    connect(gotoHile, SIGNAL(clicked()),this,SLOT(hileScreen()));

    QToolButton *gotoShivapuri = new QToolButton;
    gotoShivapuri = getButton(QIcon (":/Images/img/np.png"),QString ("Shivapuri National Park"));
    connect(gotoShivapuri, SIGNAL(clicked()),this,SLOT(shivapuriScreen()));

    QToolButton *gotoGhorepani = new QToolButton;
    gotoGhorepani = getButton(QIcon (":/Images/img/icon.png"),QString ("Ghorepani"));
    connect(gotoGhorepani, SIGNAL(clicked()),this,SLOT(ghorepaniScreen()));

    QToolButton *gotoLangtang = new QToolButton;
    gotoLangtang = getButton(QIcon (":/Images/img/np.png"),QString ("Langtang National Park"));
    connect(gotoLangtang, SIGNAL(clicked()),this,SLOT(langtangScreen()));

    QToolButton *gotoBesisahar = new QToolButton;
    gotoBesisahar = getButton(QIcon (":/Images/img/icon.png"),QString ("Besisahar"));
    connect(gotoBesisahar, SIGNAL(clicked()),this,SLOT(besisaharScreen()));

    QToolButton *gotoJiri = new QToolButton;
    gotoJiri = getButton(QIcon (":/Images/img/icon.png"),QString ("Jiri"));
    connect(gotoJiri, SIGNAL(clicked()),this,SLOT(jiriScreen()));

    QToolButton *gotoChitlang = new QToolButton;
    gotoChitlang = getButton(QIcon (":/Images/img/icon.png"),QString ("Chitlang"));
    connect(gotoChitlang, SIGNAL(clicked()),this,SLOT(chitlangScreen()));

    QToolButton *gotoBack = new QToolButton;
    gotoBack = getButton(QIcon (":/Images/img/icon.png"),QString ("Back"));
    connect(gotoBack, SIGNAL(clicked()),this,SLOT(mapScreen()));



    layout->addWidget(gotoChitwan, 700, 800);
    layout->addWidget(gotoShivapuri, 900, 900 );
    layout->addWidget(gotoKhaptad, 800, 500);
    layout->addWidget(gotoLangtang, 1625, 2100);
    layout->addWidget(gotoPokhara, 1600, 1625);
    layout->addWidget(gotoBhaktapur, 1650, 2100);
    layout->addWidget(gotoKathmandu, 1650, 2150);
    layout->addWidget(gotoDhulikhel, 1650, 2050);
    layout->addWidget(gotoChitlang, 1750, 2050);
    layout->addWidget(gotoDaman, 1700, 2050);
    layout->addWidget(gotoNagarkot, 700, 700);
    layout->addWidget(gotoKakani, 800, 800);
    layout->addWidget(gotoEBC, 1640, 2420);
    layout->addWidget(gotoSagarmatha, 1600, 2420);
    layout->addWidget(gotoLhotse, 1670, 2480);
    layout->addWidget(gotoNamche,1800,2500);
    layout->addWidget(gotoHelambu, 1600, 2100);
    layout->addWidget(gotoLumbini, 1700, 1300);
    layout->addWidget(gotoGorkha, 1500, 1800);
    layout->addWidget(gotoBandipur, 1650, 1750);
    layout->addWidget(gotoJanakpur, 2400, 2198);
    layout->addWidget(gotoBirgunj, 2400, 2100);
    layout->addWidget(gotoManang, 1425, 1700);
    layout->addWidget(gotoABC, 1425, 1675);
    layout->addWidget(gotoMustang, 1400, 1625);
    layout->addWidget(gotoTansen, 1650, 1550);
    layout->addWidget(gotoGhorepani, 1600, 1600);
    layout->addWidget(gotoJiri, 1670, 2198);
    layout->addWidget(gotoBesisahar, 1625, 1650);
    layout->addWidget(gotoHile, 2000, 2450);
    layout->addWidget(gotoIllam, 2100, 2500);
    layout->addWidget(gotoBack, 3100, 3100);

    window->setLayout(layout);
    setWindowTitle("NepTrip");
}


void MainWindow::chitwanScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QGridLayout *layout = new QGridLayout();

    QLabel *chitwan = new QLabel();
    chitwan=getCityImg(QPixmap(":/Images/img/chitwan.jpg"));

    window->setLayout(layout);
    layout->addWidget(chitwan);
    setWindowTitle("Chitwan National Park");
}


void MainWindow::kathmanduScreen(){
    QWidget *window = new QWidget();

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel *kathmandu = new QLabel();
    kathmandu=getCityImg(QPixmap(":/Images/img/kathmandu.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/ktm.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/ktmhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/ktm.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/ktmclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(kathmandu);
    topLayout->addWidget(displayIntro);
    topFiller->setLayout(topLayout);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(displayclimate);
    bottomLayout->addWidget(displayHotel);
    bottomLayout->addWidget(displayAgency);
    bottomFiller->setLayout(bottomLayout);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);

    window->setLayout(layout);

    setWindowTitle("Kathmandu");
}

void MainWindow::khaptadScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QGridLayout *layout = new QGridLayout();

    QLabel* khaptad =new QLabel();
    khaptad=getCityImg(QPixmap(":/Images/img/khaptad.jpg"));

    window->setLayout(layout);
    layout->addWidget(khaptad);
    setWindowTitle("Khaptad National Park");
}

void MainWindow::ABCScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* ABC =new QLabel();
    ABC=getCityImg(QPixmap(":/Images/img/abc.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(ABC);
    setWindowTitle("Annapurna Base Camp");
}

void MainWindow::pokharaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* pokhara =new QLabel();
    pokhara=getCityImg(QPixmap(":/Images/img/pokhara.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(pokhara);
    setWindowTitle("Pokhara");
}

void MainWindow::bhaktapurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* bhaktapur =new QLabel();
    bhaktapur=getCityImg(QPixmap(":/Images/img/bhaktapur.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(bhaktapur);
    setWindowTitle("Bhaktapur");
}

void MainWindow::dhulikhelScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* dhulikhel =new QLabel();
    dhulikhel=getCityImg(QPixmap(":/Images/img/dhulikhel.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(dhulikhel);
    setWindowTitle("Dhulikhel");
}

void MainWindow::nagarkotScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* nagarkot =new QLabel();
    nagarkot=getCityImg(QPixmap(":/Images/img/nagarkot.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(nagarkot);
    setWindowTitle("Nagarkot");
}

void MainWindow::kakaniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* kakani =new QLabel();
    kakani=getCityImg(QPixmap(":/Images/img/kakani.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(kakani);
    setWindowTitle("Kakani");
}

void MainWindow::EBCScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* EBC =new QLabel();
    EBC=getCityImg(QPixmap(":/Images/img/ebc.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(EBC);
    setWindowTitle("Everest Base Camp");
}

void MainWindow::sagarmathaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* sagarmatha =new QLabel();
    sagarmatha=getCityImg(QPixmap(":/Images/img/sagarmatha.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(sagarmatha);
    setWindowTitle("Sagarmatha National Park");
}

void MainWindow::lhotseScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* lhotse =new QLabel();
    lhotse=getCityImg(QPixmap(":/Images/img/lhotse.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(lhotse);
    setWindowTitle("Lhotse");
}

void MainWindow::helambuScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* helambu =new QLabel();
    helambu=getCityImg(QPixmap(":/Images/img/helambu.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(helambu);
    setWindowTitle("Helambu");
}

void MainWindow::lumbiniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* lumbini =new QLabel();
    lumbini=getCityImg(QPixmap(":/Images/img/lumbini.jpg"));
    \
    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(lumbini);
    setWindowTitle("Lumbini");
}

void MainWindow::gorkhaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* gorkha =new QLabel();
    gorkha=getCityImg(QPixmap(":/Images/img/gorkha.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(gorkha);
    setWindowTitle("Gorkha");
}

void MainWindow::bandipurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* bandipur =new QLabel();
    bandipur=getCityImg(QPixmap(":/Images/img/bandipur.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(bandipur);
    setWindowTitle("Bandipur");
}

void MainWindow::janakpurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* janakpur =new QLabel();
    janakpur=getCityImg(QPixmap(":/Images/img/janakpur.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(janakpur);
    setWindowTitle("Janakpur");
}

void MainWindow::birgunjScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* birgunj =new QLabel();
    birgunj=getCityImg(QPixmap(":/Images/img/birgunj.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(birgunj);
    setWindowTitle("Birgunj");
}

void MainWindow::illamScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* illam =new QLabel();
    illam=getCityImg(QPixmap(":/Images/img/illam.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(illam);
    setWindowTitle("Illam");
}

void MainWindow::manangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* manang =new QLabel();
    manang=getCityImg(QPixmap(":/Images/img/manang.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(manang);
    setWindowTitle("Manang");
}

void MainWindow::mustangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* mustang =new QLabel();
    mustang=getCityImg(QPixmap(":/Images/img/mustang.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(mustang);
    setWindowTitle("Mustang");
}

void MainWindow::tansenScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* tansen =new QLabel();
    tansen=getCityImg(QPixmap(":/Images/img/tansen.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(tansen);
    setWindowTitle("Tansen");
}

void MainWindow::damanScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* daman =new QLabel();
    daman=getCityImg(QPixmap(":/Images/img/daman.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(daman);
    setWindowTitle("Daman");
}

void MainWindow::namcheScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* namche =new QLabel();
    namche=getCityImg(QPixmap(":/Images/img/namche.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(namche);
    setWindowTitle("NamcheBazaar");
}

void MainWindow::hileScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* hile =new QLabel();
    hile=getCityImg(QPixmap(":/Images/img/hile.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(hile);
    setWindowTitle("Hile");
}

void MainWindow::shivapuriScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* shivapuri =new QLabel();
    shivapuri=getCityImg(QPixmap(":/Images/img/shivapuri.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(shivapuri);
    setWindowTitle("Shivapuri National Park");
}

void MainWindow::ghorepaniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* ghorepani =new QLabel();
    ghorepani=getCityImg(QPixmap(":/Images/img/ghorepani.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(ghorepani);
    setWindowTitle("Ghorepani Ghandruk");
}

void MainWindow::langtangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* langtang =new QLabel();
    langtang=getCityImg(QPixmap(":/Images/img/langtang.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(langtang);
    setWindowTitle("Langtang National Park");
}

void MainWindow::besisaharScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* besisahar =new QLabel();
    besisahar=getCityImg(QPixmap(":/Images/img/besisahar.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(besisahar);
    setWindowTitle("Besisahar");
}

void MainWindow::jiriScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* Jiri =new QLabel();
    Jiri=getCityImg(QPixmap(":/Images/img/jiri.jpg"));

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(Jiri);
    setWindowTitle("Jiri");
}

void MainWindow::chitlangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QLabel* chitlang =new QLabel();
    chitlang=getCityImg(QPixmap(":/Images/img/chitlang.jpg"));


    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    layout->addWidget(chitlang);
    setWindowTitle("Chitlang");
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

    aboutAct = new QAction(tr("&About"), this); // Displays About Box or it triggers about() slot
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    mapScreenAct = new QAction(tr("&GoBack"), this);
    connect(mapScreenAct, &QAction::triggered, this, &MainWindow::mapScreen);
    mapScreenAct->setShortcuts(QKeySequence::Back);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&NEPTRIP"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);

    back = menuBar()->addMenu("&GoBack");
    back->addAction(mapScreenAct);


}
