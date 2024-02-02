#include <iostream>
#include "explorer.h"
#include "room.h"
#include "trap_room.h"
#include "normal_room.h"
#include "weapon_room.h"
#include "lead_room.h"
#include "campsite.h"

using namespace std;

int main(int argc, char** argv) {
    Explorer explorer1(100,100,10,0,0,10);
    Room* room1;

    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> num100_dis(1, 100);
    while (true) {
        room1 = nullptr;
        auto prob = num100_dis(gen);
        if (prob <= 10) room1 = new Campsite();
        else if (prob <= 65) room1 = new Normal_room();
        else if (prob <= 80) room1 = new Trap_room();
        else if (prob <= 90) room1 = new Lead_room();
        else room1 = new Weapon_room();
        room1->enter_event(explorer1);
        if (explorer1.act_life_value() <= 0) break;
        room1->battle_event(explorer1);
        if (explorer1.act_life_value() <= 0) break;
        room1->result(explorer1);
        delete room1;
    }

    cout << "探险者死亡，共走过" << Trap_room::num_trap_room+Normal_room::num_normal_room+Weapon_room::num_weapon_room+
    Lead_room::num_lead_room+Campsite::num_campsite << "个房间，普通房间：" << Normal_room::num_normal_room <<
    "，陷阱房间：" << Trap_room::num_trap_room << "，武器房间：" << Weapon_room::num_weapon_room << "，首领房间：" <<
    Lead_room::num_lead_room << "，营地：" << Campsite::num_campsite << "" << endl;usleep(100000);

    return 0;
}
