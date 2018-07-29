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
#include "search.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    homeScreen();

    createActions();
    createMenus();

    setWindowTitle(tr("NEPTRIP"));
    setFixedSize(1600, 900);


}

QToolButton* MainWindow::getButton(QIcon x,QString s){
    QToolButton *button = new QToolButton;
    button->setIcon(x);
    button->setStyleSheet("QToolButton {border: none; background:none; border-radius: 5px;}");
    button->setCursor(Qt::PointingHandCursor);
    button->setToolTip(s);
    return button;
}


QLabel* MainWindow::getCityImg(QPixmap x){
    QLabel *IMG = new QLabel();
    IMG->setPixmap(x);
    IMG->setFixedSize(800,385);
    IMG->setAlignment(Qt::AlignCenter);
    return IMG;
}

QTextBrowser* MainWindow::getfile(QString p,QString t){
    QTextBrowser *displaydata = new QTextBrowser();
    QFile file(p);
         if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
             displaydata->setText(file.readAll());
             displaydata->setFrameStyle(QFrame::StyledPanel);
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
    setFixedSize(1600, 900);

    QLabel *head = new QLabel();
    head->setText("Welcome to NepTrip");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignCenter);

    QLabel *logo = new QLabel();
    QPixmap logojpg(":/Images/img/logoNepTrip.jpg");
    logo->setPixmap(logojpg);
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
    window->setStyleSheet("background: #f0f0f0");
    setWindowTitle("NepTrip");

}

void MainWindow:: mapScreen()
{

    QWidget *window = new QWidget();

    setCentralWidget(window);

    QGridLayout *layout = new QGridLayout();

    QPixmap bkgnd(":/Images/map.png");

    bkgnd = bkgnd.scaled(1600,900, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    gotoChitwan = new QToolButton;
    gotoChitwan = getButton(QIcon (":/Images/img/np.png"),QString ("Chitwan National Park"));
    connect(gotoChitwan, SIGNAL(clicked()),this,SLOT(chitwanScreen()));

    gotoKathmandu = new QToolButton;
    gotoKathmandu = getButton(QIcon (":/Images/img/icon.png"),QString ("Kathmandu Valley"));
    connect(gotoKathmandu, SIGNAL(clicked()),this,SLOT(kathmanduScreen()));

    gotoKhaptad = new QToolButton;
    gotoKhaptad = getButton(QIcon (":/Images/img/np.png"),QString ("Khaptad National Park"));
    connect(gotoKhaptad, SIGNAL(clicked()),this,SLOT(khaptadScreen()));

    gotoABC = new QToolButton;
    gotoABC = getButton(QIcon (":/Images/img/mt.png"),QString ("Annapurna Base Camp"));
    connect(gotoABC, SIGNAL(clicked()),this,SLOT(ABCScreen()));

    gotoPokhara = new QToolButton;
    gotoPokhara = getButton(QIcon (":/Images/img/icon.png"),QString ("Pokhara"));
    connect(gotoPokhara, SIGNAL(clicked()),this,SLOT(pokharaScreen()));

    gotoBhaktapur = new QToolButton;
    gotoBhaktapur = getButton(QIcon (":/Images/img/icon.png"),QString ("Bhaktapur"));
    connect(gotoBhaktapur, SIGNAL(clicked()),this,SLOT(bhaktapurScreen()));

    gotoDhulikhel = new QToolButton;
    gotoDhulikhel = getButton(QIcon (":/Images/img/icon.png"),QString ("Dhulikhel"));
    connect(gotoDhulikhel, SIGNAL(clicked()),this,SLOT(dhulikhelScreen()));

    gotoNagarkot = new QToolButton;
    gotoNagarkot = getButton(QIcon (":/Images/img/icon.png"),QString ("Nagarkot"));
    connect(gotoNagarkot, SIGNAL(clicked()),this,SLOT(nagarkotScreen()));

    gotoKakani = new QToolButton;
    gotoKakani = getButton(QIcon (":/Images/img/icon.png"),QString ("Kakani"));
    connect(gotoKakani, SIGNAL(clicked()),this,SLOT(kakaniScreen()));

    gotoEBC = new QToolButton;
    gotoEBC = getButton(QIcon (":/Images/img/mt.png"),QString ("Everest Base Camp"));
    connect(gotoEBC, SIGNAL(clicked()),this,SLOT(EBCScreen()));

    gotoSagarmatha = new QToolButton;
    gotoSagarmatha = getButton(QIcon (":/Images/img/np.png"),QString ("Sagarmatha National Park"));
    connect(gotoSagarmatha, SIGNAL(clicked()),this,SLOT(sagarmathaScreen()));

    gotoLhotse = new QToolButton;
    gotoLhotse = getButton(QIcon (":/Images/img/mt.png"),QString ("Lhotse"));
    connect(gotoLhotse, SIGNAL(clicked()),this,SLOT(lhotseScreen()));

    gotoHelambu = new QToolButton;
    gotoHelambu = getButton(QIcon (":/Images/img/icon.png"),QString ("Helambu"));
    connect(gotoHelambu, SIGNAL(clicked()),this,SLOT(helambuScreen()));

    gotoLumbini = new QToolButton;
    gotoLumbini = getButton(QIcon (":/Images/img/icon.png"),QString ("Lumbini"));
    connect(gotoLumbini, SIGNAL(clicked()),this,SLOT(lumbiniScreen()));

    gotoGorkha = new QToolButton;
    gotoGorkha = getButton(QIcon (":/Images/img/icon.png"),QString ("Gorkha"));
    connect(gotoGorkha, SIGNAL(clicked()),this,SLOT(gorkhaScreen()));

    gotoBandipur = new QToolButton;
    gotoBandipur = getButton(QIcon (":/Images/img/icon.png"),QString ("Bandipur"));
    connect(gotoBandipur, SIGNAL(clicked()),this,SLOT(bandipurScreen()));

    gotoJanakpur = new QToolButton;
    gotoJanakpur = getButton(QIcon (":/Images/img/icon.png"),QString ("Janakpur"));
    connect(gotoJanakpur, SIGNAL(clicked()),this,SLOT(janakpurScreen()));

    gotoBirgunj = new QToolButton;
    gotoBirgunj = getButton(QIcon (":/Images/img/icon.png"),QString ("Birgunj"));
    connect(gotoBirgunj, SIGNAL(clicked()),this,SLOT(birgunjScreen()));

    gotoIllam = new QToolButton;
    gotoIllam = getButton(QIcon (":/Images/img/icon.png"),QString ("Illam"));
    connect(gotoIllam, SIGNAL(clicked()),this,SLOT(illamScreen()));

    gotoManang = new QToolButton;
    gotoManang = getButton(QIcon (":/Images/img/icon.png"),QString ("Manang"));
    connect(gotoManang, SIGNAL(clicked()),this,SLOT(manangScreen()));

    gotoMustang = new QToolButton;
    gotoMustang = getButton(QIcon (":/Images/img/icon.png"),QString ("Mustang"));
    connect(gotoMustang, SIGNAL(clicked()),this,SLOT(mustangScreen()));

    gotoTansen = new QToolButton;
    gotoTansen = getButton(QIcon (":/Images/img/icon.png"),QString ("Tansen"));
    connect(gotoTansen, SIGNAL(clicked()),this,SLOT(tansenScreen()));

    gotoDaman = new QToolButton;
    gotoDaman = getButton(QIcon (":/Images/img/icon.png"),QString ("Daman"));
    connect(gotoDaman, SIGNAL(clicked()),this,SLOT(damanScreen()));

    gotoNamche = new QToolButton;
    gotoNamche = getButton(QIcon (":/Images/img/icon.png"),QString ("Namche"));
    connect(gotoNamche, SIGNAL(clicked()),this,SLOT(namcheScreen()));

    gotoHile = new QToolButton;
    gotoHile = getButton(QIcon (":/Images/img/icon.png"),QString ("Hile"));
    connect(gotoHile, SIGNAL(clicked()),this,SLOT(hileScreen()));

    gotoShivapuri = new QToolButton;
    gotoShivapuri = getButton(QIcon (":/Images/img/np.png"),QString ("Shivapuri National Park"));
    connect(gotoShivapuri, SIGNAL(clicked()),this,SLOT(shivapuriScreen()));

    gotoGhorepani = new QToolButton;
    gotoGhorepani = getButton(QIcon (":/Images/img/icon.png"),QString ("Ghorepani"));
    connect(gotoGhorepani, SIGNAL(clicked()),this,SLOT(ghorepaniScreen()));

    gotoLangtang = new QToolButton;
    gotoLangtang = getButton(QIcon (":/Images/img/np.png"),QString ("Langtang National Park"));
    connect(gotoLangtang, SIGNAL(clicked()),this,SLOT(langtangScreen()));

    gotoBesisahar = new QToolButton;
    gotoBesisahar = getButton(QIcon (":/Images/img/icon.png"),QString ("Besisahar"));
    connect(gotoBesisahar, SIGNAL(clicked()),this,SLOT(besisaharScreen()));

    gotoJiri = new QToolButton;
    gotoJiri = getButton(QIcon (":/Images/img/icon.png"),QString ("Jiri"));
    connect(gotoJiri, SIGNAL(clicked()),this,SLOT(jiriScreen()));

    gotoChitlang = new QToolButton;
    gotoChitlang = getButton(QIcon (":/Images/img/icon.png"),QString ("Chitlang"));
    connect(gotoChitlang, SIGNAL(clicked()),this,SLOT(chitlangScreen()));

    gotoBack = new QToolButton;
    gotoBack = getButton(QIcon (":/Images/img/icon.png"),QString ("Back"));
    connect(gotoBack, SIGNAL(clicked()),this,SLOT(mapScreen()));

    for (int i=0; i<64; i++){
            for(int j = 0; j<36; j++){
                icons[i][j] = new QLabel;
//                icons[i][j]->setStyleSheet("background-color: red;");
                icons[i][j]->setFixedSize(15,15);
                layout->addWidget(icons[i][j], j, i);
            }
    }

    QLabel *getPlacetitle = new QLabel;
    getPlacetitle->setText("Suggestions");
    getPlacetitle->setStyleSheet("font-family: Lato;");

    getPlaces = new QListWidget;
    searchBar = new QLineEdit;
    searchBar->setStyleSheet("font-family: Lato;");
    searchLabel = new QLabel;
    searchLabel->setText("Browse Places");
    searchLabel->setStyleSheet("font-family: Lato;");

    searchBar->setFixedSize(250,40);

    connect(searchBar,SIGNAL(textChanged(QString)), this, SLOT(searchPlaces()));
    connect(searchBar,SIGNAL(returnPressed()), this, SLOT(enteredTriggered()));

    QLabel *agencies = new QLabel;
    QListWidget *listOfFeaturedAgencies = new QListWidget;
    agencies->setText("Featured Travel Agencies");

    listOfFeaturedAgencies->insertItem(0, "8 Eyes Travel & Tours P. Ltd.\nAddress : Thamel-29, Kathmandu\nPhone : 977-1-4414742, 4414748\ne-info@8eyestravel.com\n");
    listOfFeaturedAgencies->insertItem(1, "VisitNepal Tours and Travels Pvt. Ltd\nAddress : Lazimpat-2, Kathmandu\nPhone : 977-1-4421744\ne-mail : info@aaryatravel.com\n");
    listOfFeaturedAgencies->insertItem(2, "Adarsha Nepal Travels Pvt. Ltd.\nAddress : Thamel, Kathmandu.\nPhone : 977-1-470 1549\ne-mail : hello@hotelimpala.com.np\n");
    listOfFeaturedAgencies->setStyleSheet("font-family: Lato;");
    getPlaces->setStyleSheet("font-family: Lato;");

    layout->addWidget(listOfFeaturedAgencies,23,1,15,14);
    layout->addWidget(agencies,21,1,2,14);
    layout->addWidget(getPlaces,2,50,15,14);
    layout->addWidget(getPlacetitle,0,50,2,14);
    layout->addWidget(searchLabel, 0, 24, 3, 6);
    layout->addWidget(searchBar, 0,30, 3, 8);
    layout->addWidget(gotoShivapuri, 22, 38, 2, 2, Qt::AlignCenter);
    layout->addWidget(gotoChitwan, 24, 32, 2, 2, Qt::AlignCenter);
    layout->addWidget(gotoKhaptad, 10, 12, 2, 2, Qt::AlignCenter);
    layout->addWidget(gotoKathmandu, 22, 37, 2, 2, Qt::AlignCenter);
    layout->addWidget(gotoGorkha,18,35,2,2, Qt::AlignTop);
    layout->addWidget(gotoBandipur,21,32,2,2, Qt::AlignCenter);
    layout->addWidget(gotoBesisahar,18,33,2,2);
    layout->addWidget(gotoBhaktapur,22,38,2,2, Qt::AlignBottom);
    layout->addWidget(gotoDhulikhel,23,39,2,2);
    layout->addWidget(gotoIllam,27,53,2,2, Qt::AlignCenter);
    layout->addWidget(gotoPokhara, 18,30,2,2, Qt::AlignCenter);
    layout->addWidget(gotoEBC,21,47,2,2, Qt::AlignTop);
    layout->addWidget(gotoSagarmatha,21,45,2,2);
    layout->addWidget(gotoNamche,23,46,2,2);
    layout->addWidget(gotoLhotse,21,46,2,2, Qt::AlignTop);
    layout->addWidget(gotoDaman,24,35,2,2, Qt::AlignBottom);
    layout->addWidget(gotoChitlang,23,35,2,2, Qt::AlignBottom);
    layout->addWidget(gotoJanakpur,29,41,2,2);
    layout->addWidget(gotoBirgunj,26,34,2,2, Qt::AlignCenter);
    layout->addWidget(gotoHelambu,19,37,2,2, Qt::AlignCenter);

    layout->addWidget(gotoHile,27,49,2,2, Qt::AlignCenter);
    layout->addWidget(gotoJiri,22,42,2,2);
    layout->addWidget(gotoLumbini,23,25,2,2, Qt::AlignCenter);
    layout->addWidget(gotoGhorepani,16,26,2,2, Qt::AlignCenter);
    layout->addWidget(gotoLangtang,19,38,2,2, Qt::AlignCenter);
    layout->addWidget(gotoManang,14,31,2,2, Qt::AlignBottom);
    layout->addWidget(gotoMustang,14,28,2,2, Qt::AlignCenter);
    layout->addWidget(gotoKakani,21, 36, 2, 2, Qt::AlignCenter);
    layout->addWidget(gotoNagarkot,23,38,1,1, Qt::AlignTop);
    layout->addWidget(gotoABC,13,29,2,2, Qt::AlignCenter);
    layout->addWidget(gotoTansen,21,27,2,2, Qt::AlignTop);

    window->setLayout(layout);
    setWindowTitle("NepTrip");
}

void MainWindow::enteredTriggered() {
    QString query = searchBar->text();

    if(query.length() == 0)
        return;

    vector<QString> matches = search(query);
    qDebug() << matches[0];

    if(matches[0] == gotoChitwan->toolTip()) {
        gotoChitwan->click();
    }
    if(matches[0] == gotoKathmandu->toolTip()) {
        gotoKathmandu->click();
    }
    if(matches[0] == gotoKhaptad->toolTip()) {
        gotoKhaptad->click();
    }
    if(matches[0] == gotoABC->toolTip()) {
        gotoABC->click();
    }
    if(matches[0] == gotoPokhara->toolTip()) {
        gotoPokhara->click();
    }
    if(matches[0] == gotoBhaktapur->toolTip()) {
        gotoBhaktapur->click();
    }
    if(matches[0] == gotoDhulikhel->toolTip()) {
        gotoDhulikhel->click();
    }
    if(matches[0] == gotoNagarkot->toolTip()) {
        gotoNagarkot->click();
    }
    if(matches[0] == gotoKakani->toolTip()) {
        gotoKakani->click();
    }
    if(matches[0] == gotoEBC->toolTip()) {
        gotoEBC->click();
    }
    if(matches[0] == gotoSagarmatha->toolTip()) {
        gotoSagarmatha->click();
    }
    if(matches[0] == gotoLhotse->toolTip()) {
        gotoLhotse->click();
    }
    if(matches[0] == gotoHelambu->toolTip()) {
        gotoHelambu->click();
    }
    if(matches[0] == gotoLumbini->toolTip()) {
        gotoLumbini->click();
    }
    if(matches[0] == gotoGorkha->toolTip()) {
        gotoGorkha->click();
    }
    if(matches[0] == gotoBandipur->toolTip()) {
        gotoBandipur->click();
    }
    if(matches[0] == gotoJanakpur->toolTip()) {
        gotoJanakpur->click();
    }
    if(matches[0] == gotoGorkha->toolTip()) {
        gotoGorkha->click();
    }
    if(matches[0] == gotoBandipur->toolTip()) {
        gotoBandipur->click();
    }
    if(matches[0] == gotoJanakpur->toolTip()) {
        gotoJanakpur->click();
    }
    if(matches[0] == gotoBirgunj->toolTip()) {
        gotoBirgunj->click();
    }
    if(matches[0] == gotoIllam->toolTip()) {
        gotoIllam->click();
    }
    if(matches[0] == gotoManang->toolTip()) {
        gotoManang->click();
    }
    if(matches[0] == gotoMustang->toolTip()) {
        gotoMustang->click();
    }
    if(matches[0] == gotoTansen->toolTip()) {
        gotoTansen->click();
    }
    if(matches[0] == gotoDaman->toolTip()) {
        gotoDaman->click();
    }
    if(matches[0] == gotoNamche->toolTip()) {
        gotoNamche->click();
    }
    if(matches[0] == gotoHile->toolTip()) {
        gotoHile->click();
    }
    if(matches[0] == gotoShivapuri->toolTip()) {
        gotoShivapuri->click();
    }
    if(matches[0] == gotoGhorepani->toolTip()) {
        gotoGhorepani->click();
    }
    if(matches[0] == gotoLangtang->toolTip()) {
        gotoLangtang->click();
    }
    if(matches[0] == gotoBesisahar->toolTip()) {
        gotoBesisahar->click();
    }
    if(matches[0] == gotoJiri->toolTip()) {
        gotoJiri->click();
    }
    if(matches[0] == gotoChitlang->toolTip()) {
        gotoChitlang->click();
    }
}

void MainWindow::searchPlaces() {
    QString query = searchBar->text();

    gotoKathmandu->setStyleSheet("background:transparent;");
    gotoChitwan->setStyleSheet("background:transparent;");
    gotoKhaptad->setStyleSheet("background:transparent;;");
    gotoABC->setStyleSheet("background:transparent;");
    gotoPokhara->setStyleSheet("background:transparent;");
    gotoBhaktapur->setStyleSheet("background:transparent;");
    gotoDhulikhel->setStyleSheet("background:transparent;");
    gotoNagarkot->setStyleSheet("background:transparent;");
    gotoKakani->setStyleSheet("background:transparent;");
    gotoEBC->setStyleSheet("background:transparent;");
    gotoSagarmatha->setStyleSheet("background:transparent;");
    gotoLhotse->setStyleSheet("background:transparent;");
    gotoHelambu->setStyleSheet("background:transparent;");
    gotoLumbini->setStyleSheet("background:transparent;");
    gotoGorkha->setStyleSheet("background:transparent;");
    gotoBandipur->setStyleSheet("background:transparent;");
    gotoJanakpur->setStyleSheet("background:transparent;");
    gotoBirgunj->setStyleSheet("background:transparent;");
    gotoIllam->setStyleSheet("background:transparent;");
    gotoManang->setStyleSheet("background:transparent;");
    gotoMustang->setStyleSheet("background:transparent;");
    gotoTansen->setStyleSheet("background:transparent;");
    gotoDaman->setStyleSheet("background:transparent;");
    gotoNamche->setStyleSheet("background:transparent;");
    gotoHile->setStyleSheet("background:transparent;");
    gotoShivapuri->setStyleSheet("background:transparent;");
    gotoGhorepani->setStyleSheet("background:transparent;");
    gotoLangtang->setStyleSheet("background:transparent;");
    gotoBesisahar->setStyleSheet("background:transparent;");
    gotoJiri->setStyleSheet("background:transparent;");
    gotoChitlang->setStyleSheet("background:transparent;");


    if(query.length() == 0){
        getPlaces->clear();
        return;
    }

    getPlaces->clear();

    vector<QString> matches = search(query);
    int j = 0;
    for(auto& i : matches) {

    getPlaces->insertItem(j, i);
    j++;

        if(gotoChitwan->toolTip() == i) {
            gotoChitwan->setStyleSheet("background:green;");
        }
        if(gotoKathmandu->toolTip() == i ) {
            gotoKathmandu->setStyleSheet("background: #4d91bb");
        }
        if(gotoKhaptad->toolTip() == i ) {
            gotoKhaptad->setStyleSheet("background:green;");
        }
        if(gotoABC->toolTip() == i ) {
            gotoABC->setStyleSheet("background:white;");
        }
        if(gotoPokhara->toolTip() == i ) {
            gotoPokhara->setStyleSheet("background: #4d91bb");
        }
        if(gotoBhaktapur->toolTip() == i ) {
            gotoBhaktapur->setStyleSheet("background: #4d91bb");
        }
        if(gotoDhulikhel->toolTip() == i ) {
            gotoDhulikhel->setStyleSheet("background: #4d91bb");
        }
        if(gotoNagarkot->toolTip() == i ) {
            gotoNagarkot->setStyleSheet("background: #4d91bb");
        }
        if(gotoKakani->toolTip() == i ) {
            gotoKakani->setStyleSheet("background: #4d91bb");
        }
        if(gotoEBC->toolTip() == i ) {
            gotoEBC->setStyleSheet("background:white;");
        }
        if(gotoSagarmatha->toolTip() == i ) {
            gotoSagarmatha->setStyleSheet("background:green;");
        }
        if(gotoLhotse->toolTip() == i ) {
            gotoLhotse->setStyleSheet("background:white;");
        }
        if(gotoHelambu->toolTip() == i ) {
            gotoHelambu->setStyleSheet("background: #4d91bb");
        }
        if(gotoLumbini->toolTip() == i ) {
            gotoLumbini->setStyleSheet("background: #4d91bb");
        }
        if(gotoGorkha->toolTip() == i ) {
            gotoGorkha->setStyleSheet("background: #4d91bb");
        }
        if(gotoBandipur->toolTip() == i ) {
            gotoBandipur->setStyleSheet("background: #4d91bb");
        }
        if(gotoJanakpur->toolTip() == i ) {
            gotoJanakpur->setStyleSheet("background: #4d91bb");
        }
        if(gotoBirgunj->toolTip() == i ) {
            gotoBirgunj->setStyleSheet("background: #4d91bb");
        }
        if(gotoIllam->toolTip() == i ) {
            gotoIllam->setStyleSheet("background: #4d91bb");
        }
        if(gotoManang->toolTip() == i ) {
            gotoManang->setStyleSheet("background: #4d91bb");
        }
        if(gotoMustang->toolTip() == i ) {
            gotoMustang->setStyleSheet("background: #4d91bb");
        }
        if(gotoTansen->toolTip() == i ) {
            gotoTansen->setStyleSheet("background: #4d91bb");
        }
        if(gotoDaman->toolTip() == i ) {
            gotoDaman->setStyleSheet("background: #4d91bb");
        }
        if(gotoNamche->toolTip() == i ) {
            gotoNamche->setStyleSheet("background: #4d91bb");
        }
        if(gotoHile->toolTip() == i ) {
            gotoHile->setStyleSheet("background: #4d91bb");
        }
        if(gotoShivapuri->toolTip() == i ) {
            gotoShivapuri->setStyleSheet("background:green;");
        }
        if(gotoGhorepani->toolTip() == i ) {
            gotoGhorepani->setStyleSheet("background: #4d91bb");
        }
        if(gotoLangtang->toolTip() == i ) {
            gotoLangtang->setStyleSheet("background:green;");
        }
        if(gotoBesisahar->toolTip() == i ) {
            gotoBesisahar->setStyleSheet("background: #4d91bb");
        }
        if(gotoJiri->toolTip() == i ) {
            gotoJiri->setStyleSheet("background: #4d91bb");
        }

        if(gotoChitlang->toolTip() == i ) {
            gotoChitlang->setStyleSheet("background: #4d91bb");
        }
    }
}

void MainWindow::chitwanScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    window->setStyleSheet("background:white;");

    QLabel *chitwan = new QLabel();
    chitwan=getCityImg(QPixmap(":/Images/img/chitwan.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/chitwan.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/chitwanhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/chitwanagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/chitwanclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(chitwan);
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
    setWindowTitle("Chitwan National Park");
}


void MainWindow::kathmanduScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    window->setStyleSheet("background:white;");

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
    displayAgency=getfile(QString(":/Files/files/ktmagency.txt"),QString("Agency"));

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
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* khaptad =new QLabel();
    khaptad=getCityImg(QPixmap(":/Images/img/khaptad.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/khaptad.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/khaptadhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/khaptadagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/khaptadclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(khaptad);
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
    setWindowTitle("Khaptad National Park");
}

void MainWindow::ABCScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* ABC =new QLabel();
    ABC=getCityImg(QPixmap(":/Images/img/abc.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/abc.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/abchotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/abcagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/abcclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(ABC);
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
    setWindowTitle("Annapurna Base Camp");
}

void MainWindow::pokharaScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* pokhara =new QLabel();
    pokhara=getCityImg(QPixmap(":/Images/img/pokhara.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/pokhara.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/pokharahotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/pokharaagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/pokharaclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(pokhara);
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
    setWindowTitle("Pokhara");
}

void MainWindow::bhaktapurScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* bhaktapur =new QLabel();
    bhaktapur=getCityImg(QPixmap(":/Images/img/bhaktapur.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/bhaktapur.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/bhaktapurhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/bhaktapuragency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/bhaktapurclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(bhaktapur);
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
    setWindowTitle("Bhaktapur");
}

void MainWindow::dhulikhelScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* dhulikhel =new QLabel();
    dhulikhel=getCityImg(QPixmap(":/Images/img/dhulikhel.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/dhulikhel.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/dhulikhelhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/dhulikhelagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/dhulikhelclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(dhulikhel);
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
    setWindowTitle("Dhulikhel");
}

void MainWindow::nagarkotScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* nagarkot =new QLabel();
    nagarkot=getCityImg(QPixmap(":/Images/img/nagarkot.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/nagarkot.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/nagarkothotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/nagarkotagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/nagarkotclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(nagarkot);
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
    setWindowTitle("Nagarkot");
}

void MainWindow::kakaniScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();


    setCentralWidget(window);

    QLabel* kakani =new QLabel();
    kakani=getCityImg(QPixmap(":/Images/img/kakani.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/kakani.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/kakanihotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/kakaniagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/kakaniclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(kakani);
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
    setWindowTitle("Kakani");
}

void MainWindow::EBCScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* EBC =new QLabel();
    EBC=getCityImg(QPixmap(":/Images/img/ebc.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/ebc.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/ebchotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/ebcagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/ebcclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(EBC);
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
    setWindowTitle("Everest Base Camp");
}

void MainWindow::sagarmathaScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* sagarmatha =new QLabel();
    sagarmatha=getCityImg(QPixmap(":/Images/img/sagarmatha.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/sagarmatha.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/sagarmathahotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/sagarmathaagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/sagarmathaclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(sagarmatha);
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
    setWindowTitle("Sagarmatha National Park");
}

void MainWindow::lhotseScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* lhotse =new QLabel();
    lhotse=getCityImg(QPixmap(":/Images/img/lhotse.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/lhotse.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/lhotsehotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/lhotseagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/lhotseclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(lhotse);
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
    setWindowTitle("Lhotse");
}

void MainWindow::helambuScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* helambu =new QLabel();
    helambu=getCityImg(QPixmap(":/Images/img/helambu.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/helambu.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/helambuhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/helambuagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/helambuclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(helambu);
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
    setWindowTitle("Helambu");
}

void MainWindow::lumbiniScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* lumbini =new QLabel();
    lumbini=getCityImg(QPixmap(":/Images/img/lumbini.jpg"));
    \
    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/lumbini.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/lumbinihotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/lumbiniagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/lumbiniclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(lumbini);
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
    setWindowTitle("Lumbini");
}

void MainWindow::gorkhaScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* gorkha =new QLabel();
    gorkha=getCityImg(QPixmap(":/Images/img/gorkha.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/gorkha.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/gorkhahotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/gorkhaagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/gorkhaclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(gorkha);
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
    setWindowTitle("Gorkha");
}

void MainWindow::bandipurScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* bandipur =new QLabel();
    bandipur=getCityImg(QPixmap(":/Images/img/bandipur.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/bandipur.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/bandipurhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/bandipuragency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/bandipurclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(bandipur);
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
    setWindowTitle("Bandipur");
}

void MainWindow::janakpurScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* janakpur =new QLabel();
    janakpur=getCityImg(QPixmap(":/Images/img/janakpur.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/janakpur.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/janakpurhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/janakpuragency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/janakpurclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(janakpur);
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
    setWindowTitle("Janakpur");
}

void MainWindow::birgunjScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* birgunj =new QLabel();
    birgunj=getCityImg(QPixmap(":/Images/img/birgunj.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/birgunj.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/birgunjhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/birgunjagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/birgunjclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(birgunj);
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
    setWindowTitle("Birgunj");
}

void MainWindow::illamScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* illam =new QLabel();
    illam=getCityImg(QPixmap(":/Images/img/illam.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/illam.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/illamhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/illamagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/illamclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(illam);
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
    setWindowTitle("Illam");
}

void MainWindow::manangScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* manang =new QLabel();
    manang=getCityImg(QPixmap(":/Images/img/manang.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/manang.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/mananghotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/manangagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/manangclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(manang);
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
    setWindowTitle("Manang");
}

void MainWindow::mustangScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* mustang =new QLabel();
    mustang=getCityImg(QPixmap(":/Images/img/mustang.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/mustang.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/mustanghotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/mustangagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/mustangclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(mustang);
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
    setWindowTitle("Mustang");
}

void MainWindow::tansenScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* tansen =new QLabel();
    tansen=getCityImg(QPixmap(":/Images/img/tansen.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/tansen.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/tansenhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/tansenagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/tansenclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(tansen);
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
    setWindowTitle("Tansen");
}

void MainWindow::damanScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* daman =new QLabel();
    daman=getCityImg(QPixmap(":/Images/img/daman.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/daman.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/damanhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/damanagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/damanclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(daman);
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
    setWindowTitle("Daman");
}

void MainWindow::namcheScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* namche =new QLabel();
    namche=getCityImg(QPixmap(":/Images/img/namche.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/namche.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/namchehotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/namcheagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/namcheclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(namche);
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
    setWindowTitle("NamcheBazaar");
}

void MainWindow::hileScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* hile =new QLabel();
    hile=getCityImg(QPixmap(":/Images/img/hile.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/hile.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/hilehotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/hileagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/hileclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(hile);
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
    setWindowTitle("Hile");
}

void MainWindow::shivapuriScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* shivapuri =new QLabel();
    shivapuri=getCityImg(QPixmap(":/Images/img/shivapuri.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/shivapuri.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/shivapurihotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/shivapuriagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/shivapuriclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(shivapuri);
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
    setWindowTitle("Shivapuri National Park");
}

void MainWindow::ghorepaniScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* ghorepani =new QLabel();
    ghorepani=getCityImg(QPixmap(":/Images/img/ghorepani.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/ghorepani.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/ghorepanihotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/ghorepaniagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/ghorepaniclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(ghorepani);
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
    setWindowTitle("Ghorepani Ghandruk");
}

void MainWindow::langtangScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* langtang =new QLabel();
    langtang=getCityImg(QPixmap(":/Images/img/langtang.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/langtang.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/langtanghotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/langtangagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/langtangclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(langtang);
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
    setWindowTitle("Langtang National Park");
}

void MainWindow::besisaharScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* besisahar =new QLabel();
    besisahar=getCityImg(QPixmap(":/Images/img/besisahar.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/besisahar.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/besisaharhotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/besisaharagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/besisaharclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(besisahar);
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
    setWindowTitle("Besisahar");
}

void MainWindow::jiriScreen(){
    QWidget *window = new QWidget();window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* Jiri =new QLabel();
    Jiri=getCityImg(QPixmap(":/Images/img/jiri.jpg"));

    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/jiri.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/jirihotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/jiriagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/jiriclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(Jiri);
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
    setWindowTitle("Jiri");
}

void MainWindow::chitlangScreen(){
    QWidget *window = new QWidget();
    window->setStyleSheet("background:white;");
    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel* chitlang =new QLabel();
    chitlang=getCityImg(QPixmap(":/Images/img/chitlang.jpg"));


    QTextBrowser *displayIntro = new QTextBrowser();
    displayIntro=getfile(QString(":/Files/files/chitang.txt"),QString("Intro"));

    QTextBrowser* displayHotel= new QTextBrowser();
    displayHotel=getfile(QString(":/Files/files/chitlanghotel.txt"),QString("Hotel"));

    QTextBrowser* displayAgency= new QTextBrowser();
    displayAgency=getfile(QString(":/Files/files/chitlangagency.txt"),QString("Agency"));

    QTextBrowser* displayclimate= new QTextBrowser();
    displayclimate=getfile(QString(":/Files/files/chitlangclimate.txt"),QString("Extra"));


    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(chitlang);
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

    mapScreenAct = new QAction(tr("&Map"), this);
    connect(mapScreenAct, &QAction::triggered, this, &MainWindow::mapScreen);
    mapScreenAct->setShortcuts(QKeySequence::Back);

    homeScreenAct = new QAction(tr("&Home"), this);
    connect(homeScreenAct, &QAction::triggered, this, &MainWindow::homeScreen);

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&NEPTRIP"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);

    options = menuBar()->addMenu("&Options");
//    connect(back, &QAction::triggered, this, &MainWindow::mapScreen);
    options->addAction(homeScreenAct);
    options->addAction(mapScreenAct);



}
