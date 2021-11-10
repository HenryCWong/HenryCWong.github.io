//
// Created by San Yeung on 11/8/21.
//

#include "Codemon.h"

Codemon::Codemon(const string name, const string type, const int level, const int hp){
    m_name = name;
    m_type = type,
    m_level = level;
    m_hp = hp;
}

bool Codemon::insertNewSkill(const Skill& skill){
    bool success = true;
    if(m_numSkillsOwned > (MAX_SKILL_SIZE-1))
        success = false;
    else
        m_skillList[m_numSkillsOwned++] = skill;
    return success;
}
