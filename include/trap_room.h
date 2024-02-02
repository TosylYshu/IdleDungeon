#pragma once
#include "room.h"

class Trap_room : public Room
{
public:
    inline static auto num_trap_room = 0;

public:
    Trap_room()=default;
    void enter_event(Explorer&) override;
    void battle_event(Explorer&) override;
    void result(Explorer&) override;
    ~Trap_room() override=default;
};
