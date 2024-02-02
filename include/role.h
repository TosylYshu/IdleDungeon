#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <unistd.h>
#include "weapon.h"

using namespace std;
using namespace chrono;

class Role
{
protected:
    int act_life_value_;
    int max_life_value_;
    int att_;
    int weapon_type_;
    Weapon weapon1_;

public:
    Role(int act_life_value, int max_life_value, int att, int weapon_type) : act_life_value_(act_life_value),
    max_life_value_(max_life_value), att_(att), weapon_type_(weapon_type),weapon1_(weapon_type) {

    }

    [[nodiscard]] int act_life_value() const { return act_life_value_; }

    void SetActLifeValue(const int& act_life_value) { act_life_value_ = act_life_value; }

    int AddActLifeValue(const int& act_life_value);

    void SubActLifeValue(const int& act_life_value) { act_life_value_ -= act_life_value; }

    int DamActLifeValue(Role&);

    [[nodiscard]] int max_life_value() const { return max_life_value_; }

    [[nodiscard]] string PrintLifeValue() const { return "（"+ to_string(act_life_value_)+"/"+ to_string(max_life_value_)+"）"; };

    [[nodiscard]] int att() const { return att_; }

    [[nodiscard]] int weapon_type() const { return weapon_type_; }

    void SetWeaponType(const int& weapon_type) { weapon_type_ = weapon_type; }

    void SetWeapon1(const Weapon& weapon1) { weapon1_ = weapon1; }

    ~Role()=default;
};
