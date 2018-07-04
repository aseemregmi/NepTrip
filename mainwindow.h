
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    // Slots for 77 districts

    //void dangScreen();
    //void salyanScreen();
    //void bankeScreen();
    //void kanchanpurScreen()

    void chitwanScreen();
    void kathmanduScreen();

    //About Dialog Box
    void about();

private:
    void createActions();
    void createMenus();
    void homeScreen();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *optionsMenu;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *mapScreenAct;
    QAction *homeAct;
};

#endif
