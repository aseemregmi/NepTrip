
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolButton>
#include <QTextBrowser>
#include <QFile>
#include <QListWidget>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();


protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private slots:
    void mapScreen();
    void chitwanScreen();
    void kathmanduScreen();
    void khaptadScreen();
    void ABCScreen();
    void pokharaScreen();
    void bhaktapurScreen();
    void dhulikhelScreen();
    void nagarkotScreen();
    void kakaniScreen();
    void EBCScreen();
    void sagarmathaScreen();
    void lhotseScreen();
    void helambuScreen();
    void lumbiniScreen();
    void gorkhaScreen();
    void bandipurScreen();
    void janakpurScreen();
    void birgunjScreen();
    void illamScreen();
    void manangScreen();
    void mustangScreen();
    void tansenScreen();
    void damanScreen();
    void namcheScreen();
    void hileScreen();
    void shivapuriScreen();
    void ghorepaniScreen();
    void langtangScreen();
    void besisaharScreen();
    void jiriScreen();
    void chitlangScreen();
    void about();

    void searchPlaces();
    void enteredTriggered();

    QToolButton* getButton(QIcon x,QString s);
    QLabel* getCityImg(QPixmap x);
    QTextBrowser* getfile(QString p,QString t);

public:
    QListWidget* getPlaces;

private:

    QLineEdit *searchBar;

    QToolButton *gotoChitwan;
    QToolButton *gotoKathmandu;
    QToolButton *gotoKhaptad;
    QToolButton *gotoABC;
    QToolButton *gotoPokhara;
    QToolButton *gotoBhaktapur;
    QToolButton *gotoDhulikhel;
    QToolButton *gotoNagarkot;
    QToolButton *gotoKakani;
    QToolButton *gotoEBC;
    QToolButton *gotoSagarmatha;
    QToolButton *gotoLhotse;
    QToolButton *gotoHelambu;
    QToolButton *gotoLumbini;
    QToolButton *gotoGorkha;
    QToolButton *gotoBandipur;
    QToolButton *gotoJanakpur;
    QToolButton *gotoBirgunj;
    QToolButton *gotoIllam;
    QToolButton *gotoManang;
    QToolButton *gotoMustang;
    QToolButton *gotoTansen;
    QToolButton *gotoDaman;
    QToolButton *gotoNamche;
    QToolButton *gotoHile;
    QToolButton *gotoShivapuri;
    QToolButton *gotoGhorepani;
    QToolButton *gotoLangtang;
    QToolButton *gotoBesisahar;
    QToolButton *gotoJiri;
    QToolButton *gotoChitlang;
    QToolButton *gotoBack;
    QLabel *searchLabel;

    void createActions();
    void createMenus();
    void homeScreen();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *options;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *mapScreenAct;
    QAction *homeScreenAct;
    QImage *sourceImage;
    QGraphicsView *imageView;
    QGraphicsScene *imageScene;
    QLabel *icons[64][36];
};

#endif
