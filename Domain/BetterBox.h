//
// Created by mitza on 24-May-21.
//

#ifndef T3_MITZA23_BETTERBOX_H
#define T3_MITZA23_BETTERBOX_H


#include <QCheckBox>

class BetterBox : public QCheckBox{
    Q_OBJECT
private:
    std::string description;
public:
    BetterBox(std::string d);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

signals:
    void boxChanged(std::string d, Qt::CheckState s);
public slots:
    void clicked(int state);
};


#endif //T3_MITZA23_BETTERBOX_H
