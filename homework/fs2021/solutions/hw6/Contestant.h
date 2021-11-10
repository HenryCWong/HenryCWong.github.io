//
// Created by San Yeung on 11/8/21.
//

#ifndef FS2021_CS1570_HW6_CONTESTANT_H
#define FS2021_CS1570_HW6_CONTESTANT_H

#include "Codemon.h"
#include "Item.h"

const int POCKET_SIZE = 10;
const int BACKPACK_SIZE = 20;

class Contestant{
public:
    Contestant();
    Contestant(string name);
    bool insertNewCodemon(const Codemon& newCodemon);
    bool insertNewItem(const Item& newItem);
    void prepare(); // populate contestant info
    void print() const;
    friend void skillLookUp(const Contestant contestants[], const int SIZE);
private:
    string m_name;
    int m_numCodemonsOwned;
    int m_numItemsOwned;
    int m_openPocketIndex;
    int m_openBackpackIndex;
    Codemon m_pocket[POCKET_SIZE];
    Item m_backpack[BACKPACK_SIZE];
};

/*
 * Desc: This function looks up a skill for the user among all the contestants' codemons
 * Pre: None
 * Post: If a matching skill is found, relevant info will be printed out. The user is allowed to look up skills as many
 *          times they want.
 */
void skillLookUp(const Contestant contestants[], const int SIZE);

#endif //FS2021_CS1570_HW6_CONTESTANT_H
