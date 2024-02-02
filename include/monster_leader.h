#pragma once
#include "role.h"

class Monster_leader : public Role
{
private:
    bool st_;

public:
    Monster_leader(int act_life_value, int max_life_value, int att, int weapon_type, bool st) :
            Role(act_life_value, max_life_value, att, weapon_type), st_(st) {
        cout << "遇到怪物首领" << PrintLifeValue() << endl;usleep(100000);
    }

    void IncAtt() { ++att_; }

    [[nodiscard]] bool st() const { return st_; }

    void SetSt(const bool& st) { st_ = st; }

    ~Monster_leader()=default;
};
