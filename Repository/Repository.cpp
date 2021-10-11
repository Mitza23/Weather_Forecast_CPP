//
// Created by mitza on 24-May-21.
//

#include <fstream>
#include <iostream>
#include "Repository.h"

using namespace std;

Repository::Repository(): list{std::vector<Interval>()} {

}

std::vector<Interval> &Repository::getList() {
    return list;
}

void Repository::readFromFile(std::string fileName) {
    ifstream fi(fileName);
    while(!fi.eof()){
        int start, finish, probability;
        string description;
        fi>>start>>finish>>probability>>description;
        addInterval(start, finish, probability, description);
    }
}

void Repository::addInterval(int start, int finish, int probability, std::string description) {
    auto i = Interval(start, finish, probability, description);
    list.push_back(i);
    bool found = false;
    for(auto d: descriptions){
        if(d == description)
            found = true;
    }
    if(!found)
        descriptions.push_back(description);
}

const vector<std::string> &Repository::getDescriptions() const {
    return descriptions;
}
