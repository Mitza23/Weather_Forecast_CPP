//
// Created by mitza on 24-May-21.
//

#include "Interval.h"

using namespace std;

Interval::Interval(int start, int finish, int probability, const std::string &description) : start(start),
                                                                                             finish(finish),
                                                                                             probability(probability),
                                                                                             description(description) {}

int Interval::getStart() const {
    return start;
}

void Interval::setStart(int start) {
    Interval::start = start;
}

int Interval::getFinish() const {
    return finish;
}

void Interval::setFinish(int finish) {
    Interval::finish = finish;
}

int Interval::getProbability() const {
    return probability;
}

void Interval::setProbability(int probability) {
    Interval::probability = probability;
}

const std::string &Interval::getDescription() const {
    return description;
}

void Interval::setDescription(const std::string &description) {
    Interval::description = description;
}

std::string Interval::toString() {
    string result = to_string(start) + string(" ") + to_string(finish) + string(" ") + to_string(probability) +
            string(" ") + description;
    return result;
}
