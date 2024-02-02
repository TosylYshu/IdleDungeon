#pragma once
#include <unordered_map>
#include "room.h"

class Weapon_room : public Room
{
public:
    inline static auto num_weapon_room = 0;
    inline static unordered_map<int, string> um{{1, "一"}, {2, "二"}, {3, "三"}};
    int act_life_value_;
    int weapon_type_;

public:
    Weapon_room()=default;
    void enter_event(Explorer&) override;
    void battle_event(Explorer&) override;
    void result(Explorer&) override;
    ~Weapon_room() override=default;
};
