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

void MainWindow::homeScreen()
{
    QWidget *window = new QWidget();
    setCentralWidget(window);

    QLabel *head = new QLabel();
    head->setText("Welcome to NepTrip");
    head->setStyleSheet("font-size: 27pt; color: red;");
    head->setAlignment(Qt::AlignCenter);

    QLabel *logo = new QLabel();
    QPixmap logoNepTrip("/home/aashish/NepTrip/img/logoNepTrip.jpg");
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

    /*QLabel *map = new QLabel();
    QPixmap nepalmap("/home/aashish/Desktop/map.jpg");
    map->setPixmap(nepalmap);
    map->setMask(nepalmap.mask());
    map->setAlignment(Qt::AlignCenter);*/

    QPixmap bkgnd("/home/aashish/NepTrip/img/map.jpg");

    bkgnd = bkgnd.scaled(1280,720, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);


    /*QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(512,512);
    container->setMaximumSize(512,512);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("home/aashish/NepTrip/QML/map.qml"));
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(container);
    view->show();
    container->show();*/

    QToolButton *gotoChitwan = new QToolButton;
    QPixmap pixmap("/home/aashish/NepTrip/img/np.png");
    QIcon ButtonIcon(pixmap);
    gotoChitwan->setIcon(ButtonIcon);
    //gotoChitwan->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    gotoChitwan->setStyleSheet(" border: none; background-color:green;");
    gotoChitwan->setCursor(Qt::PointingHandCursor);
    gotoChitwan->setToolTip("Chitwan National Park");
    connect(gotoChitwan, SIGNAL(clicked()),this,SLOT(chitwanScreen()));


    QToolButton *gotoKathmandu = new QToolButton;
    QPixmap pixmap1("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon1(pixmap1);
    gotoKathmandu->setIcon(ButtonIcon1);
    gotoKathmandu->setStyleSheet(" border: none; background-color:white;");
    gotoKathmandu->setCursor(Qt::PointingHandCursor);
    gotoKathmandu->setToolTip("Kathmandu Valley");
    connect(gotoKathmandu, SIGNAL(clicked()),this,SLOT(kathmanduScreen()));

    QToolButton *gotoKhaptad = new QToolButton;
    QPixmap pixmap01("/home/aashish/Desktop/np.png");
    QIcon ButtonIcon01(pixmap01);
    gotoKhaptad->setIcon(ButtonIcon01);
    gotoKhaptad->setStyleSheet(" border: none; background-color:green;");
    gotoKhaptad->setCursor(Qt::PointingHandCursor);
    gotoKhaptad->setToolTip("Khaptad National Park");
    connect(gotoKhaptad, SIGNAL(clicked()),this,SLOT(khaptadScreen()));

    QToolButton *gotoABC = new QToolButton;
    QPixmap pixmap2("/home/aashish/NepTrip/img/mt.png");
    QIcon ButtonIcon2(pixmap2);
    gotoABC->setIcon(ButtonIcon2);
    gotoABC->setStyleSheet(" border: none; background-color:white;");
    gotoABC->setCursor(Qt::PointingHandCursor);
    gotoABC->setToolTip("Annapurna Base Camp");
    connect(gotoABC, SIGNAL(clicked()),this,SLOT(ABCScreen()));

    QToolButton *gotoPokhara = new QToolButton;
    QPixmap pixmap3("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon3(pixmap3);
    gotoPokhara->setIcon(ButtonIcon3);
    gotoPokhara->setStyleSheet(" border: none; background-color:white;");
    gotoPokhara->setCursor(Qt::PointingHandCursor);
    gotoPokhara->setToolTip("Pokhara");
    connect(gotoPokhara, SIGNAL(clicked()),this,SLOT(pokharaScreen()));

    QToolButton *gotoBhaktapur = new QToolButton;
    QPixmap pixmap4("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon4(pixmap4);
    gotoBhaktapur->setIcon(ButtonIcon4);
    gotoBhaktapur->setStyleSheet(" border: none; background-color:white;");
    gotoBhaktapur->setCursor(Qt::PointingHandCursor);
    gotoBhaktapur->setToolTip("Bhaktapur");
    connect(gotoBhaktapur, SIGNAL(clicked()),this,SLOT(bhaktapurScreen()));

    QToolButton *gotoDhulikhel = new QToolButton;
    QPixmap pixmap5("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon5(pixmap5);
    gotoDhulikhel->setIcon(ButtonIcon5);
    gotoDhulikhel->setStyleSheet(" border: none; background-color:white;");
    gotoDhulikhel->setCursor(Qt::PointingHandCursor);
    gotoDhulikhel->setToolTip("Dhulikhel");
    connect(gotoDhulikhel, SIGNAL(clicked()),this,SLOT(dhulikhelScreen()));

    QToolButton *gotoNagarkot = new QToolButton;
    QPixmap pixmap6("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon6(pixmap6);
    gotoNagarkot->setIcon(ButtonIcon6);
    gotoNagarkot->setStyleSheet(" border: none; background-color:white;");
    gotoNagarkot->setCursor(Qt::PointingHandCursor);
    gotoNagarkot->setToolTip("Nagarkot");
    connect(gotoNagarkot, SIGNAL(clicked()),this,SLOT(nagarkotScreen()));

    QToolButton *gotoKakani = new QToolButton;
    QPixmap pixmap7("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon7(pixmap7);
    gotoKakani->setIcon(ButtonIcon7);
    gotoKakani->setStyleSheet(" border: none; background-color:white;");
    gotoKakani->setCursor(Qt::PointingHandCursor);
    gotoKakani->setToolTip("Kakani");
    connect(gotoKakani, SIGNAL(clicked()),this,SLOT(kakaniScreen()));

    QToolButton *gotoEBC = new QToolButton;
    QPixmap pixmap8("/home/aashish/NepTrip/img/mt.png");
    QIcon ButtonIcon8(pixmap8);
    gotoEBC->setIcon(ButtonIcon8);
    gotoEBC->setStyleSheet(" border: none; background-color:white;");
    gotoEBC->setCursor(Qt::PointingHandCursor);
    gotoEBC->setToolTip("Everest Base Camp");
    connect(gotoEBC, SIGNAL(clicked()),this,SLOT(EBCScreen()));

    QToolButton *gotoSagarmatha = new QToolButton;
    QPixmap pixmap9("/home/aashish/NepTrip/img/np.png");
    QIcon ButtonIcon9(pixmap9);
    gotoSagarmatha->setIcon(ButtonIcon9);
    gotoSagarmatha->setStyleSheet(" border: none; background-color:green;");
    gotoSagarmatha->setCursor(Qt::PointingHandCursor);
    gotoSagarmatha->setToolTip("Sagarmatha National Park");
    connect(gotoSagarmatha, SIGNAL(clicked()),this,SLOT(sagarmathaScreen()));

    QToolButton *gotoLhotse = new QToolButton;
    QPixmap pixmap10("/home/aashish/NepTrip/img/mt.png");
    QIcon ButtonIcon10(pixmap10);
    gotoLhotse->setIcon(ButtonIcon10);
    gotoLhotse->setStyleSheet(" border: none; background-color:white;");
    gotoLhotse->setCursor(Qt::PointingHandCursor);
    gotoLhotse->setToolTip("Lhotse");
    connect(gotoLhotse, SIGNAL(clicked()),this,SLOT(lhotseScreen()));

    QToolButton *gotoHelambu = new QToolButton;
    QPixmap pixmap11("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon11(pixmap11);
    gotoHelambu->setIcon(ButtonIcon11);
    gotoHelambu->setStyleSheet(" border: none; background-color:white;");
    gotoHelambu->setCursor(Qt::PointingHandCursor);
    gotoHelambu->setToolTip("Helambu");
    connect(gotoHelambu, SIGNAL(clicked()),this,SLOT(helambuScreen()));

    QToolButton *gotoLumbini = new QToolButton;
    QPixmap pixmap12("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon12(pixmap12);
    gotoLumbini->setIcon(ButtonIcon12);
    gotoLumbini->setStyleSheet(" border: none; background-color:white;");
    gotoLumbini->setCursor(Qt::PointingHandCursor);
    gotoLumbini->setToolTip("Lumbini");
    connect(gotoLumbini, SIGNAL(clicked()),this,SLOT(lumbiniScreen()));

    QToolButton *gotoGorkha = new QToolButton;
    QPixmap pixmap13("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon13(pixmap13);
    gotoGorkha->setIcon(ButtonIcon13);
    gotoGorkha->setStyleSheet(" border: none; background-color:white;");
    gotoGorkha->setCursor(Qt::PointingHandCursor);
    gotoGorkha->setToolTip("Gorkha");
    connect(gotoGorkha, SIGNAL(clicked()),this,SLOT(gorkhaScreen()));

    QToolButton *gotoBandipur = new QToolButton;
    QPixmap pixmap14("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon14(pixmap14);
    gotoBandipur->setIcon(ButtonIcon14);
    gotoBandipur->setStyleSheet(" border: none; background-color:white;");
    gotoBandipur->setCursor(Qt::PointingHandCursor);
    gotoBandipur->setToolTip("Bandipur");
    connect(gotoBandipur, SIGNAL(clicked()),this,SLOT(bandipurScreen()));

    QToolButton *gotoJanakpur = new QToolButton;
    QPixmap pixmap15("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon15(pixmap15);
    gotoJanakpur->setIcon(ButtonIcon15);
    gotoJanakpur->setStyleSheet(" border: none; background-color:white;");
    gotoJanakpur->setCursor(Qt::PointingHandCursor);
    gotoJanakpur->setToolTip("Janakpur");
    connect(gotoJanakpur, SIGNAL(clicked()),this,SLOT(janakpurScreen()));

    QToolButton *gotoBirgunj = new QToolButton;
    QPixmap pixmap16("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon16(pixmap16);
    gotoBirgunj->setIcon(ButtonIcon16);
    gotoBirgunj->setStyleSheet(" border: none; background-color:white;");
    gotoBirgunj->setCursor(Qt::PointingHandCursor);
    gotoBirgunj->setToolTip("Birgunj");
    connect(gotoBirgunj, SIGNAL(clicked()),this,SLOT(birgunjScreen()));

    QToolButton *gotoIllam = new QToolButton;
    QPixmap pixmap17("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon17(pixmap17);
    gotoIllam->setIcon(ButtonIcon17);
    gotoIllam->setStyleSheet(" border: none; background-color:white;");
    gotoIllam->setCursor(Qt::PointingHandCursor);
    gotoIllam->setToolTip("Illam");
    connect(gotoIllam, SIGNAL(clicked()),this,SLOT(illamScreen()));

    QToolButton *gotoManang = new QToolButton;
    QPixmap pixmap18("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon18(pixmap18);
    gotoManang->setIcon(ButtonIcon18);
    gotoManang->setStyleSheet(" border: none; background-color:white;");
    gotoManang->setCursor(Qt::PointingHandCursor);
    gotoManang->setToolTip("Manang");
    connect(gotoManang, SIGNAL(clicked()),this,SLOT(manangScreen()));

    QToolButton *gotoMustang = new QToolButton;
    QPixmap pixmap19("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon19(pixmap19);
    gotoMustang->setIcon(ButtonIcon19);
    gotoMustang->setStyleSheet(" border: none; background-color:white;");
    gotoMustang->setCursor(Qt::PointingHandCursor);
    gotoMustang->setToolTip("Mustang");
    connect(gotoMustang, SIGNAL(clicked()),this,SLOT(mustangScreen()));

    QToolButton *gotoTansen = new QToolButton;
    QPixmap pixmap20("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon20(pixmap20);
    gotoTansen->setIcon(ButtonIcon20);
    gotoTansen->setStyleSheet(" border: none; background-color:white;");
    gotoTansen->setCursor(Qt::PointingHandCursor);
    gotoTansen->setToolTip("Tansen");
    connect(gotoTansen, SIGNAL(clicked()),this,SLOT(tansenScreen()));

    QToolButton *gotoDaman = new QToolButton;
    QPixmap pixmap21("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon21(pixmap21);
    gotoDaman->setIcon(ButtonIcon21);
    gotoDaman->setStyleSheet(" border: none; background-color:white;");
    gotoDaman->setCursor(Qt::PointingHandCursor);
    gotoDaman->setToolTip("Daman");
    connect(gotoDaman, SIGNAL(clicked()),this,SLOT(damanScreen()));

    QToolButton *gotoNamche = new QToolButton;
    QPixmap pixmap22("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon22(pixmap22);
    gotoNamche->setIcon(ButtonIcon22);
    gotoNamche->setStyleSheet(" border: none; background-color:white;");
    gotoNamche->setCursor(Qt::PointingHandCursor);
    gotoNamche->setToolTip("Namche Bazaar");
    connect(gotoNamche, SIGNAL(clicked()),this,SLOT(namcheScreen()));

    QToolButton *gotoHile = new QToolButton;
    QPixmap pixmap23("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon23(pixmap23);
    gotoHile->setIcon(ButtonIcon23);
    gotoHile->setStyleSheet(" border: none; background-color:white;");
    gotoHile->setCursor(Qt::PointingHandCursor);
    gotoHile->setToolTip("Hile");
    connect(gotoHile, SIGNAL(clicked()),this,SLOT(hileScreen()));

    QToolButton *gotoShivapuri = new QToolButton;
    QPixmap pixmap24("/home/aashish/NepTrip/img/np.png");
    QIcon ButtonIcon24(pixmap24);
    gotoShivapuri->setIcon(ButtonIcon24);
    gotoShivapuri->setStyleSheet(" border: none; background-color:green;");
    gotoShivapuri->setCursor(Qt::PointingHandCursor);
    gotoShivapuri->setToolTip("Shivapuri National Park");
    connect(gotoShivapuri, SIGNAL(clicked()),this,SLOT(shivapuriScreen()));

    QToolButton *gotoGhorepani = new QToolButton;
    QPixmap pixmap25("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon25(pixmap25);
    gotoGhorepani->setIcon(ButtonIcon25);
    gotoGhorepani->setStyleSheet(" border: none; background-color:white;");
    gotoGhorepani->setCursor(Qt::PointingHandCursor);
    gotoGhorepani->setToolTip("Ghorepani,Ghandruk");
    connect(gotoGhorepani, SIGNAL(clicked()),this,SLOT(ghorepaniScreen()));

    QToolButton *gotoLangtang = new QToolButton;
    QPixmap pixmap26("/home/aashish/NepTrip/img/np.png");
    QIcon ButtonIcon26(pixmap26);
    gotoLangtang->setIcon(ButtonIcon26);
    gotoLangtang->setStyleSheet(" border: none; background-color:green;");
    gotoLangtang->setCursor(Qt::PointingHandCursor);
    gotoLangtang->setToolTip("Langtang National Park");
    connect(gotoLangtang, SIGNAL(clicked()),this,SLOT(langtangScreen()));

    QToolButton *gotoBesisahar = new QToolButton;
    QPixmap pixmap27("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon27(pixmap27);
    gotoBesisahar->setIcon(ButtonIcon27);
    gotoBesisahar->setStyleSheet(" border: none; background-color:white;");
    gotoBesisahar->setCursor(Qt::PointingHandCursor);
    gotoBesisahar->setToolTip("Besisahar");
    connect(gotoBesisahar, SIGNAL(clicked()),this,SLOT(besisaharScreen()));

    QToolButton *gotoJiri = new QToolButton;
    QPixmap pixmap28("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon28(pixmap28);
    gotoJiri->setIcon(ButtonIcon28);
    gotoJiri->setStyleSheet(" border: none; background-color:white;");
    gotoJiri->setCursor(Qt::PointingHandCursor);
    gotoJiri->setToolTip("Jiri");
    connect(gotoJiri, SIGNAL(clicked()),this,SLOT(jiriScreen()));

    QToolButton *gotoChitlang = new QToolButton;
    QPixmap pixmap29("/home/aashish/NepTrip/img/icon.png");
    QIcon ButtonIcon29(pixmap29);
    gotoChitlang->setIcon(ButtonIcon29);
    gotoChitlang->setStyleSheet(" border: none; background-color:white;");
    gotoChitlang->setCursor(Qt::PointingHandCursor);
    gotoChitlang->setToolTip("Chitlang");
    connect(gotoChitlang, SIGNAL(clicked()),this,SLOT(chitlangScreen()));


    layout->addWidget(gotoChitwan,18,17,1,1);
    layout->addWidget(gotoKathmandu,2,2,1,1);
    layout->addWidget(gotoKhaptad,7,5,1,1);
    layout->addWidget(gotoABC,3,4,1,1);
    layout->addWidget(gotoPokhara,4,5,1,1);
    layout->addWidget(gotoBhaktapur,5,6,1,1);
    layout->addWidget(gotoDhulikhel,6,7,1,1);
    layout->addWidget(gotoNagarkot,7,8,1,1);
    layout->addWidget(gotoKakani,8,9,1,1);
    layout->addWidget(gotoEBC,9,10,1,1);
    layout->addWidget(gotoSagarmatha,10,11,1,1);
    layout->addWidget(gotoLhotse,11,12,1,1);
    layout->addWidget(gotoHelambu,12,13,1,1);
    layout->addWidget(gotoLumbini,13,14,1,1);
    layout->addWidget(gotoGorkha,14,15,1,1);
    layout->addWidget(gotoBandipur,15,16,1,1);
    layout->addWidget(gotoJanakpur,16,17,1,1);
    layout->addWidget(gotoBirgunj,17,18,1,1);
    layout->addWidget(gotoIllam,18,19,1,1);
    layout->addWidget(gotoManang,19,20,1,1);
    layout->addWidget(gotoMustang,20,21,1,1);
    layout->addWidget(gotoTansen,21,22,1,1);
    layout->addWidget(gotoDaman,22,23,1,1);
    layout->addWidget(gotoNamche,23,24,1,1);
    layout->addWidget(gotoHile,24,25,1,1);
    layout->addWidget(gotoShivapuri,25,26,1,1);
    layout->addWidget(gotoGhorepani,26,27,1,1);
    layout->addWidget(gotoLangtang,27,28,1,1);
    layout->addWidget(gotoBesisahar,28,29,1,1);
    layout->addWidget(gotoJiri,29,30,1,1);
    layout->addWidget(gotoChitlang,30,31,1,1);

    window->setLayout(layout);
    setWindowTitle("NepTrip");
}

void MainWindow::chitwanScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QGridLayout *layout = new QGridLayout();
    m_pTableWidget = new QTableWidget;

    layout->addWidget(m_pTableWidget,1,1,1,1);

    QPixmap bkgnd("/home/aashish/NepTrip/img/chitwan.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    window->setLayout(layout);
    setWindowTitle("Chitwan");
    m_pTableWidget->setRowCount(7);
    m_pTableWidget->setColumnCount(1);
    m_pTableWidget->setColumnWidth(2,400);
    m_TableHeader<<"Details";
    QStringList verticalHeader;
    verticalHeader<<"District"<<"Climate"<<"Tourism Places"<<"Temperature"<<"Yearly Tourists"<<"Average Expenditure"<<"Working Agencies";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);
    m_pTableWidget->setVerticalHeaderLabels(verticalHeader);
    m_pTableWidget->verticalHeader()->setVisible(true);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setFixedHeight(255);
    m_pTableWidget->setStyleSheet("QTableView {selection-background-color: red;}");
    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());

    QFile file("/home/aashish/NepTrip/chitwan.txt");
      if (file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
           QTextStream status(&file);
           QString line;
           int i= 0;
           do{
               line = status.readLine();
               m_pTableWidget->setItem(0, i,new QTableWidgetItem(line));
               i++;
           }while (!line.isNull());
           file.close();
      }

}

void MainWindow::kathmanduScreen(){
    QWidget *window = new QWidget();

    QWidget *topFiller = new QWidget();
    QWidget *bottomFiller = new QWidget();

    setCentralWidget(window);

    QLabel *kathmandu = new QLabel();
    QPixmap ktmmap("/home/aashish/NepTrip/img/kathmandu.jpg");
    kathmandu->setPixmap(ktmmap);
    kathmandu->setMask(ktmmap.mask());
    kathmandu->setAlignment(Qt::AlignCenter);



    QTextEdit *txt = new QTextEdit();
    txt->setText("Hello This is Kathmandu");

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(kathmandu);
    topLayout->addWidget(txt);
    topFiller->setLayout(topLayout);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(kathmandu);
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

    QPixmap bkgnd("/home/aashish/NepTrip/img/khaptad.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    window->setLayout(layout);
    setWindowTitle("Khaptad National Park");
}

void MainWindow::ABCScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/abc.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Annapurna Base Camp");
}

void MainWindow::pokharaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/pokhara.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Pokhara");
}

void MainWindow::bhaktapurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/bhaktapur.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Bhaktapur");
}

void MainWindow::dhulikhelScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/dhulikhel.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Dhulikhel");
}

void MainWindow::nagarkotScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/nagarkot.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Nagarkot");
}

void MainWindow::kakaniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/kakani.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Kakani");
}

void MainWindow::EBCScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/ebc.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Everest Base Camp");
}

void MainWindow::sagarmathaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/sagarmatha.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Sagarmatha National Park");
}

void MainWindow::lhotseScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/lhotse.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Lhotse");
}

void MainWindow::helambuScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/helambu.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Helambu");
}

void MainWindow::lumbiniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/lumbini.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Lumbini");
}

void MainWindow::gorkhaScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/gorkha.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Gorkha");
}

void MainWindow::bandipurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/bandipur.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Bandipur");
}

void MainWindow::janakpurScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/janakpur.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Janakpur");
}

void MainWindow::birgunjScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/birgunj.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Birgunj");
}

void MainWindow::illamScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/illam.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Illam");
}

void MainWindow::manangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/manang.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Manang");
}

void MainWindow::mustangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/mustang.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Mustang");
}

void MainWindow::tansenScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/tansen.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Tansen");
}

void MainWindow::damanScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/daman.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Daman");
}

void MainWindow::namcheScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/namche.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("NamcheBazaar");
}

void MainWindow::hileScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/hile.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Hile");
}

void MainWindow::shivapuriScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/shivapuri.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Shivapuri National Park");
}

void MainWindow::ghorepaniScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/ghorepani.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Ghorepani Ghandruk");
}

void MainWindow::langtangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/langtang.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Langtang National Park");
}

void MainWindow::besisaharScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/besisahar.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Besisahar");
}

void MainWindow::jiriScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/jiri.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

    window->setLayout(layout);
    setWindowTitle("Jiri");
}

void MainWindow::chitlangScreen(){
    QWidget *window = new QWidget();

    setCentralWidget(window);

    QPixmap bkgnd("/home/aashish/NepTrip/img/chitlang.jpg");

    bkgnd = bkgnd.scaled(1090,700, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    QGridLayout *layout = new QGridLayout();

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
