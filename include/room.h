#pragma once
#include <iostream>
#include <unistd.h>
#include "monster.h"
#include "monster_leader.h"
#include "explorer.h"

using namespace std;

class Room
{
public:
    Room()=default;
    virtual void enter_event(Explorer&) = 0;
    virtual void battle_event(Explorer&) = 0;
    virtual void result(Explorer&) = 0;
    virtual ~Room()=default;
};
