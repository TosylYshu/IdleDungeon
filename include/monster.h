#pragma once
#include "role.h"

class Monster : public Role
{
private:
    int monster_indx_;

public:
    Monster(int act_life_value, int max_life_value, int att, int weapon_type, int monster_indx) :
    Role(act_life_value, max_life_value, att, weapon_type), monster_indx_(monster_indx) {

    }

    [[nodiscard]] int monster_indx() const { return monster_indx_; }

    ~Monster()=default;
};
