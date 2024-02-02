#include "lead_room.h"

void Lead_room::enter_event(Explorer& explorer1)
{
    cout << "进入首领房间" << endl;usleep(100000);
    explorer1.SubLifeLos();
    if (explorer1.act_life_value() <= 0) return;
    explorer1.SubLifeGet();
    explorer1.AddActLifeValue(20);
    cout << "生命恢复，当前生命" << explorer1.PrintLifeValue() << endl;usleep(100000);
    explorer1.ClrLifeLos();
}

void Lead_room::battle_event(Explorer& explorer1)
{
    Monster_leader monster_leader1(40, 40, 15, 0, false);
    while (true) {
        auto damage = monster_leader1.DamActLifeValue(explorer1);
        cout << "探险者攻击怪物首领，造成" << damage << "点伤害，怪物首领" << monster_leader1.PrintLifeValue() << endl;usleep(100000);
        if (monster_leader1.act_life_value() <= 0) {
            cout << "怪物首领死亡" << endl;usleep(100000);
            break;
        }
        explorer1.ChaActLifeValue(monster_leader1);
        if (explorer1.act_life_value() <= 0) return;
    }
}

void Lead_room::result(Explorer& explorer1)
{
    ++num_lead_room;
    explorer1.AddExp(5);
}
