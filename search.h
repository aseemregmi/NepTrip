#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <QDebug>
#include <QApplication>
#include <fstream>
#include <QString>
#include <vector>

using namespace std;

vector <QString> search(QString query){
    string myQuery = query.toStdString();

    string path = ":/Files/places.txt";

    cout << path;

    string line;

    vector <QString> matches;

    ifstream reader("C:/Users/Aseem Regmi/NepTrip/files/places.txt");

    while(!reader.eof()){
        getline(reader,line);
        if (QString::fromStdString(line).toLower().trimmed().indexOf(query.toLower().trimmed()) != -1){
            matches.push_back(QString::fromStdString(line));
        }
    }

    reader.close();

    return matches;
}



#endif // SEARCH_H
