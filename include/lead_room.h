#pragma once
#include "room.h"

class Lead_room : public Room
{
public:
    inline static auto num_lead_room = 0;

public:
    Lead_room()=default;
    void enter_event(Explorer&) override;
    void battle_event(Explorer&) override;
    void result(Explorer&) override;
    ~Lead_room() override=default;
};
