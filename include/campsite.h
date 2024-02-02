#pragma once
#include "room.h"

class Campsite : public Room
{
public:
    inline static auto num_campsite = 0;

public:
    Campsite()=default;
    void enter_event(Explorer&) override;
    void battle_event(Explorer&) override;
    void result(Explorer&) override;
    ~Campsite() override=default;
};
