#include "weapon_room.h"

void Weapon_room::enter_event(Explorer& explorer1)
{
    cout << "进入武器房间" << endl;usleep(100000);
    explorer1.SubLifeLos();
    if (explorer1.act_life_value() <= 0) return;
    explorer1.SubLifeGet();
    act_life_value_ = explorer1.act_life_value();
}

void Weapon_room::battle_event(Explorer& explorer1)
{
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> num3_dis(1, 3);
    Monster monster1(40, 40, 4, num3_dis(gen), 1);
    cout << "遇到怪物" << monster1.monster_indx() << monster1.PrintLifeValue() << endl;usleep(100000);
    weapon_type_ = monster1.weapon_type();
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

void Weapon_room::result(Explorer& explorer1)
{
    ++num_weapon_room;
    explorer1.AddExp(2);
    explorer1.SetActLifeValue(act_life_value_);
    cout << "生命恢复，当前生命" << explorer1.PrintLifeValue() << endl;usleep(100000);
    explorer1.SetWeaponType(weapon_type_);
    explorer1.SetWeapon1(Weapon(weapon_type_));
    cout << "获得武器" << um[weapon_type_] << endl;usleep(100000);
}
