#include "explorer.h"

void Explorer::AddExp(const int &exp_value)
{
    cout << "获得" << exp_value << "点经验，";
    if (act_exp_value_ + exp_value >= max_exp_value_) {
        SetActLifeValue(max_life_value_);
        cout << "生命恢复，当前生命" << PrintLifeValue() << "，";
    }
    act_exp_value_ = (act_exp_value_ + exp_value) % max_exp_value_;
    cout << "当前经验（" << act_exp_value_ << "/" << max_exp_value_  << "）" << endl;usleep(100000);
}

void Explorer::SubLifeLos()
{
    if (!life_los_.empty()) {
        auto life_los = 2 * static_cast<int>(life_los_.size());
        SubActLifeValue(life_los);
        cout << "持续损伤效果触发，失去" << life_los << "点生命，当前生命" << PrintLifeValue() << endl;usleep(100000);
        if (act_exp_value_ <= 0) return;
        for_each(life_los_.begin(), life_los_.end(), [](int& value){ --value; });
        if (life_los_[0] == 0) {
            life_los_.pop_front();
            cout << "持续损伤效果被移除" << endl;usleep(100000);
        }
    }
}

void Explorer::SubLifeGet()
{
    if (!life_get_.empty()) {
        auto life_get = 5 * static_cast<int>(life_get_.size());
        life_get = AddActLifeValue(life_get);
        cout << "持续恢复效果触发，获得" << life_get << "点生命，当前生命" << PrintLifeValue() << endl;usleep(100000);
        for_each(life_get_.begin(), life_get_.end(), [](int& value){ --value; });
        if (life_get_[0] == 0) {
            life_get_.pop_front();
            cout << "持续恢复效果被移除" << endl;usleep(100000);
        }
    }
}

void Explorer::ClrLifeLos()
{
    if (!life_los_.empty()) {
        life_los_.clear();
        cout << "持续损伤效果被移除" << endl;usleep(100000);
    }
}

void Explorer::ChaActLifeValue(Monster_leader& monster_leader1)
{
    if (!monster_leader1.st() && monster_leader1.act_life_value() <= 10) {
        monster_leader1.SetSt(true);
        auto life_value = monster_leader1.AddActLifeValue(20);
        cout << "怪物首领恢复生命" << life_value << "点，怪物首领" << monster_leader1.PrintLifeValue() << endl;
        usleep(100000);
    }
    else {
        auto damage = DamActLifeValue(monster_leader1);
        cout << "怪物首领攻击探险者，造成" << damage << "点伤害，探险者" << PrintLifeValue() << endl;usleep(100000);
        monster_leader1.IncAtt();
    }
}
