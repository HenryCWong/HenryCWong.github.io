//
// Created by San Yeung on 11/8/21.
//

#ifndef FS2021_CS1570_HW6_ITEM_H
#define FS2021_CS1570_HW6_ITEM_H

#include <string>

using std::string;

class Item{
    friend class Contestant;
public:
    Item(){}
    Item(const string name, const string purpose, const int duration);
private:
    string m_name;
    string m_purpose;
    int m_effectDuration;
};

#endif //FS2021_CS1570_HW6_ITEM_H
