//
// Created by San Yeung on 11/8/21.
//

#ifndef FS2021_CS1570_HW6_CODEMON_H
#define FS2021_CS1570_HW6_CODEMON_H

#include "Skill.h"

const int MAX_SKILL_SIZE = 6;

class Codemon{
    friend class Contestant;
public:
    Codemon(){}
    Codemon(const string name, const string type, const int level, const int hp);
    bool insertNewSkill(const Skill& skill);
    const Skill getSkill(const int index) const { return m_skillList[index]; }
    const string getName() const {return m_name;}
private:
    string m_name;
    string m_type;
    int m_level;
    int m_hp;
    int m_numSkillsOwned = 0;
    Skill m_skillList[MAX_SKILL_SIZE];
};

#endif //FS2021_CS1570_HW6_CODEMON_H
