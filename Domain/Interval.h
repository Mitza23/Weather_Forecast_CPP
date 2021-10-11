//
// Created by mitza on 24-May-21.
//

#ifndef T3_MITZA23_INTERVAL_H
#define T3_MITZA23_INTERVAL_H


#include <string>

class Interval {
private:
    int start, finish, probability;
    std::string description;
public:
    int getStart() const;

    void setStart(int start);

    int getFinish() const;

    void setFinish(int finish);

    int getProbability() const;

    void setProbability(int probability);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    Interval(int start, int finish, int probability, const std::string &description);

    std::string toString();
};


#endif //T3_MITZA23_INTERVAL_H
