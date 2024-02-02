#pragma once
#include "room.h"

class Normal_room : public Room
{
public:
    inline static auto num_normal_room = 0;
    int num_monsters_;

public:
    Normal_room()=default;
    void enter_event(Explorer&) override;
    void battle_event(Explorer&) override;
    void result(Explorer&) override;
    ~Normal_room() override=default;
};
