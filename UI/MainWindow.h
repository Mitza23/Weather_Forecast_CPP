//
// Created by mitza on 24-May-21.
//

#ifndef T3_MITZA23_MAINWINDOW_H
#define T3_MITZA23_MAINWINDOW_H


#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <BetterBox.h>
#include "../Repository/Repository.h"

class MainWindow : public QWidget{
    Q_OBJECT
private:
    Repository& repo;
    Repository displayRepo;
    //graphical elements
    QListWidget* listWidget;
    QSlider* slider;
    QPushButton* resetButton;
    QLabel* sliderLabel;
    std::vector<BetterBox*> filterChecks;

    int value;

    void initGUI();

    void connectSlotsAndSignals();

    bool fitsDescription(std::string d);

public:
    MainWindow(Repository& repository);

public slots:
    void populateList();

    void updateValue(int val);

    void filterList(int val);

    void resetSlider();

    void filterBox(std::string d, Qt::CheckState s);
};


#endif //T3_MITZA23_MAINWINDOW_H
