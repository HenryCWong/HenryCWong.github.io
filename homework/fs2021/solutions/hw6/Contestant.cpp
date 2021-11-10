//
// Created by San Yeung on 11/8/21.
//

#include "Contestant.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Contestant::Contestant(){
    cout << "What's your name, contestant?" << endl;
    getline(cin, m_name);
    m_numCodemonsOwned = 0;
    m_numItemsOwned = 0;
    m_openPocketIndex = 0;
    m_openBackpackIndex = 0;
}

Contestant::Contestant(string name){
m_name = name;
m_numCodemonsOwned = 0;
m_numItemsOwned = 0;
m_openPocketIndex = 0;
m_openBackpackIndex = 0;
}

bool Contestant::insertNewCodemon(const Codemon& newCodemon){
    bool success = true;
    if(m_openPocketIndex > (POCKET_SIZE-1))
        success = false;
    else
        m_pocket[m_openPocketIndex++] = newCodemon;
    return success;
}

bool Contestant::insertNewItem(const Item& newItem){
    bool success = true;
    if(m_openBackpackIndex > (BACKPACK_SIZE-1))
        success = false;
    else
        m_backpack[m_openBackpackIndex++] = newItem;
    return success;
}

void Contestant::prepare(){
    cout << "Let's prepare you for the combat, contestant " << m_name << "!" << endl;
    char codemonChoice;
    do{
        cout << "Do you want to add a new Codemon? (y/n)" << endl;
        cin >> codemonChoice;
        if(codemonChoice == 'y'){
            cout << "Name of the Codemon?" << endl;
            cin >> m_pocket[m_numCodemonsOwned].m_name;
            cout << "The Codemon's type?" << endl;
            cin >> m_pocket[m_numCodemonsOwned].m_type;
            cout << "The Codemon's level?" << endl;
            cin >> m_pocket[m_numCodemonsOwned].m_level;
            cout << "The Codemon's HP?" << endl;
            cin >> m_pocket[m_numCodemonsOwned].m_hp;

            char skillChoice;
            do{
                cout << "Do you want to add a new skill for this Codemon? (y/n)" << endl;
                cin >> skillChoice;
                if(skillChoice == 'y'){
                    string skillName;
                    int skillDmg;
                    cout << "Name of the skill?" << endl;
                    cin >> skillName;
                    cout << "The skill's base damage?" << endl;
                    cin >> skillDmg;
                    m_pocket[m_numCodemonsOwned].insertNewSkill(Skill(skillName, skillDmg));
                }
            } while(skillChoice != 'n');

            m_numCodemonsOwned++;
        }
    } while(codemonChoice != 'n');

    char itemChoice;
    do{
        cout << "Do you want to add a new item? (y/n)" << endl;
        cin >> itemChoice;
        if(itemChoice == 'y'){
            cout << "Name of the item?" << endl;
            cin.ignore(100, '\n');
            getline(cin, m_backpack[m_numItemsOwned].m_name);
            cout << "Purpose of the item?" << endl;
            getline(cin, m_backpack[m_numItemsOwned].m_purpose);
            cout << "Duration effect of the item?" << endl;
            cin >> m_backpack[m_numItemsOwned].m_effectDuration;
            m_numItemsOwned++;
        }
    } while(itemChoice != 'n');
}

void Contestant::print() const {
    cout << "Contestant name: " << m_name << endl;
    cout << "Number of Codemons owned: " << m_numCodemonsOwned << endl;
    if(m_numCodemonsOwned > 0){
        cout << "Pocket list:" << endl;
        for(int i=0; i<m_numCodemonsOwned; i++){
            cout << "\t\t" << i+1 << ") " << m_pocket[i].m_name << endl;
        }
    }
    if(m_numItemsOwned > 0){
        cout << "Backpack list:" << endl;
        for(int i=0; i<m_numItemsOwned; i++){
            cout << "\t\t" << i+1 << ") " << m_backpack[i].m_name << endl;
        }
    }
}

void skillLookUp(const Contestant contestants[], const int SIZE){
    char lookUpChoice;
    do{
        cout << "Hello, do you want to look up a skill? (y/n)" << endl;
        cin >> lookUpChoice;
        if(lookUpChoice == 'y'){
            cout << "What skill do you want to look up?" << endl;
            string skillToLookUp;
            cin.ignore(100, '\n');
            getline(cin, skillToLookUp);
            bool firstTime = true;
            int listCounter = 1;
            for(int i=0; i<SIZE; i++){
                for(int j=0; j<POCKET_SIZE; j++){
                    for(int k=0; k<MAX_SKILL_SIZE; k++){
                        if(contestants[i].m_pocket[j].getSkill(k).getMName() == skillToLookUp){
                            if(firstTime){
                                cout << "Skill name: " << skillToLookUp << endl;
                                cout << "Base damage: " << contestants[i].m_pocket[j].getSkill(k).getMBaseDmg() << endl;
                                cout << "Acquired by: " << endl;
                                firstTime = false;
                            }
                            cout << "\t\t" << listCounter++ << ") " << contestants[i].m_pocket[j].getName()
                                 << " (" << contestants[i].m_name << ")" << endl;
                        }
                    }
                }
            }
        }
    } while (lookUpChoice!='n');
}