
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
    QToolButton* getButton(QIcon x,QString s);
    QLabel* getCityImg(QPixmap x);
    QTextBrowser* getfile(QString p,QString t);

private:
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader,m_TableHeader1;


    void createActions();
    void createMenus();
    void homeScreen();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *back;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *mapScreenAct;
    QImage *sourceImage;
    QGraphicsView *imageView;
    QGraphicsScene *imageScene;
};

#endif
