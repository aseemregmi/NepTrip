#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
private slots:
    void mapScreen();
private:
     void homeScreen();
};

#endif // MAINWINDOW_H
