//
// Created by mitza on 24-May-21.
//

#include <QVBoxLayout>
#include <iostream>
#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow(Repository &repository) : repo{repository}{
    displayRepo = Repository{repo};
    initGUI();
    connectSlotsAndSignals();
    populateList();
}

void MainWindow::initGUI() {
    QVBoxLayout* layout = new QVBoxLayout{this};
    listWidget = new QListWidget();
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    resetButton = new QPushButton("&Reset");
    sliderLabel = new QLabel();
    layout->addWidget(listWidget);
    layout->addWidget(slider);
    layout->addWidget(sliderLabel);
    for(auto d: repo.getDescriptions()){
        auto box = new BetterBox(d);
        box->setCheckState(Qt::Checked);
        filterChecks.push_back(box);
        layout->addWidget(box);
        QObject::connect(box, &QCheckBox::stateChanged, box, &BetterBox::clicked);
        QObject::connect(box, &BetterBox::boxChanged,this, &MainWindow::filterBox);
    }
    layout->addWidget(resetButton);
}

void MainWindow::connectSlotsAndSignals() {
//    QObject::connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(populateList()));
    QObject::connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetSlider()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(filterList(int)));
}

void MainWindow::populateList() {
    listWidget->clear();
    for(auto t: displayRepo.getList()){
        listWidget->addItem(QString::fromStdString(t.toString()));
    }
}

void MainWindow::updateValue(int val) {
    sliderLabel->setText(QString::fromStdString(to_string(val)));
    value = val;
}

bool MainWindow::fitsDescription(string d){
    for(BetterBox* t :filterChecks)
        if(t->checkState() == Qt::Checked && t->getDescription() == d)
            return true;
    return false;
}

void MainWindow::filterList(int val) {
    displayRepo.getList().clear();
    for (auto t: repo.getList()) {
        if (t.getProbability() <= val && fitsDescription(t.getDescription())) {
            displayRepo.addInterval(t.getStart(), t.getFinish(), t.getProbability(), t.getDescription());
        }
    }
//    for(int i = 0 ; i < displayRepo.getList().size() ; i++){
//        if(displayRepo.getList()[i].getProbability() > val){
//            displayRepo.getList().erase(displayRepo.getList().begin() + i);
//        }
//    }
    populateList();
}

void MainWindow::resetSlider() {
    slider->setValue(100);
    sliderLabel->setText(QString::fromStdString(to_string(100)));
    for(auto c: filterChecks){
        c->setCheckState(Qt::Checked);
    }
}

void MainWindow::filterBox(std::string d, Qt::CheckState s) {
    if(s == Qt::Checked) {
        for (auto t: repo.getList()) {
            if (t.getDescription() == d && t.getProbability() <= value) {
                displayRepo.addInterval(t.getStart(), t.getFinish(), t.getProbability(), t.getDescription());
            }
        }
    }
    else {
        for (int i = 0 ; i <  displayRepo.getList().size() ; i++) {
            if ( displayRepo.getList()[i].getDescription() == d) {
                displayRepo.getList().erase( displayRepo.getList().begin() + i);
//                cout << "deleted" << endl;
            }
        }
        for (int i = 0 ; i <  displayRepo.getList().size() ; i++) {
            if ( displayRepo.getList()[i].getDescription() == d) {
                displayRepo.getList().erase( displayRepo.getList().begin() + i);
//                cout << "deleted" << endl;
            }
        }
    }
//    cout << d << endl;
//    for(auto t: displayRepo.getList())
//        cout << t.toString() << endl;
//    cout << endl << endl;
    populateList();
}
