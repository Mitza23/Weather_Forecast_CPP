//
// Created by mitza on 24-May-21.
//

#include "BetterBox.h"

BetterBox::BetterBox(std::string d) : QCheckBox(QString::fromStdString(d)), description{d}{

}

const std::string &BetterBox::getDescription() const {
    return description;
}

void BetterBox::setDescription(const std::string &description) {
    BetterBox::description = description;
}

void BetterBox::clicked(int state) {
    emit boxChanged(description, this->checkState());
}
