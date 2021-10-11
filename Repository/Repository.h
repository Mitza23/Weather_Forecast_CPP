//
// Created by mitza on 24-May-21.
//

#ifndef T3_MITZA23_REPOSITORY_H
#define T3_MITZA23_REPOSITORY_H


#include <Interval.h>
#include <vector>

class Repository {
private:
    std::vector<Interval> list;
    std::vector<std::string> descriptions;
public:
    const std::vector<std::string> &getDescriptions() const;

public:
    Repository();

    std::vector<Interval> &getList();

    void addInterval(int start, int finish, int probability, std::string description);

    void readFromFile(std::string fileName);
};



#endif //T3_MITZA23_REPOSITORY_H
