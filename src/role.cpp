#include "role.h"

int Role::AddActLifeValue(const int& act_life_value)
{
    if (act_life_value + act_life_value_ > max_life_value_) {
        auto tmp = act_life_value_;
        act_life_value_ = max_life_value_;
        return max_life_value_ - tmp;
    }
    else {
        act_life_value_ += act_life_value;
        return act_life_value;
    }
}

int Role::DamActLifeValue(Role& role1)
{
    int damage = role1.att_;
    SubActLifeValue(role1.att_);
    if (role1.weapon_type_ == 1) {
        damage += role1.weapon1_.att();
        SubActLifeValue(role1.weapon1_.att());
        role1.weapon1_.DecDur();
    }
    else if (role1.weapon_type_ == 2) {
        damage += role1.weapon1_.dur();
        SubActLifeValue(role1.weapon1_.dur());
        role1.weapon1_.DecDur();
    }
    else if (role1.weapon_type_ == 3) {
        damage += role1.weapon1_.att();
        SubActLifeValue(role1.weapon1_.att());
        role1.weapon1_.DecDur();
        unsigned seed = system_clock::now().time_since_epoch().count();
        default_random_engine gen(seed);
        uniform_int_distribution<int> dis(0, 1);
        if (dis(gen)) role1.weapon1_.DubAtt();
    }
    if (role1.weapon_type_ != 0 && role1.weapon1_.dur() == 0) {
        role1.weapon_type_ = 0;
        role1.weapon1_ = Weapon(0);
    }
    return damage;
}
