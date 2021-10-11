//
// Created by mitza on 24-May-21.
//

#include "Repository/Repository.h"
#include "UI/MainWindow.h"
#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char** argv){
    QApplication a(argc, argv);
    Repository repo;
    repo.readFromFile("input.txt");
    auto window = new MainWindow(repo);
    window->show();
    return a.exec();
}
