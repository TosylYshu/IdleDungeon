#pragma once
#include "role.h"
#include "monster_leader.h"

class Explorer : public Role
{
private:
    int act_exp_value_;
    int max_exp_value_;
    deque<int> life_los_;
    deque<int> life_get_;

public:
    Explorer(int act_life_value, int max_life_value, int att, int weapon_type, int act_exp_value, int max_exp_value) :
    Role(act_life_value, max_life_value, att, weapon_type),
    act_exp_value_(act_exp_value), max_exp_value_(max_exp_value){

    }

    void AddExp(const int& exp_value);

    void AddLifeLos() { life_los_.emplace_back(5); }

    void AddLifeGet() { life_get_.emplace_back(2); }

    void SubLifeLos();

    void SubLifeGet();

    void ClrLifeLos();

    void ChaActLifeValue(Monster_leader&);

    ~Explorer()=default;
};
