#include "trap_room.h"

void Trap_room::enter_event(Explorer& explorer1)
{
    cout << "进入陷阱房间" << endl;usleep(100000);
    explorer1.SubLifeLos();
    if (explorer1.act_life_value() <= 0) return;
    explorer1.SubLifeGet();
    int act_life_value = explorer1.act_life_value();
    explorer1.SetActLifeValue(act_life_value - act_life_value / 10);
    cout << "触发事件，损失" << act_life_value / 10 << "点生命，造成持续损伤，当前生命" <<
    explorer1.PrintLifeValue() << endl;usleep(100000);
    explorer1.AddLifeLos();
}

void Trap_room::battle_event(Explorer& explorer1)
{
    Monster monster1(20, 20, 10, 0, 1);
    cout << "遇到怪物" << monster1.monster_indx() << monster1.PrintLifeValue() << endl;usleep(100000);
    cout << "战斗开始" << endl;usleep(100000);
    int damage;
    while (true) {
        damage = monster1.DamActLifeValue(explorer1);
        cout << "探险者攻击怪物" << monster1.monster_indx() << "，造成" << damage << "点伤害，怪物" <<
        monster1.monster_indx() << monster1.PrintLifeValue() << endl;usleep(100000);
        if (monster1.act_life_value() <= 0) {
            cout << "怪物" << monster1.monster_indx() << "死亡" << endl;usleep(100000);
            break;
        }
        damage = explorer1.DamActLifeValue(monster1);
        cout << "怪物" << monster1.monster_indx() << "攻击探险者，造成" << damage << "点伤害，探险者" <<
        explorer1.PrintLifeValue() << endl;usleep(100000);
        if (explorer1.act_life_value() <= 0) return;
    }
}

void Trap_room::result(Explorer& explorer1)
{
    ++num_trap_room;
    explorer1.AddExp(1);
}
