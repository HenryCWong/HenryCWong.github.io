//
// Created by San Yeung on 11/8/21.
//

#ifndef FS2021_CS1570_HW6_SKILL_H
#define FS2021_CS1570_HW6_SKILL_H

#include <string>

using std::string;

class Skill{
public:
    Skill(){}
    Skill(const string name, const int dmg):m_name(name), m_baseDmg(dmg){}
    void setMName(const string &mName) { m_name = mName; }
    void setMBaseDmg(int mBaseDmg) { m_baseDmg = mBaseDmg; }
    const string &getMName() const { return m_name; }
    const int &getMBaseDmg() const { return m_baseDmg; }
private:
    string m_name;
    int m_baseDmg;
};

#endif //FS2021_CS1570_HW6_SKILL_H
