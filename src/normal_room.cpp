#include "normal_room.h"

void Normal_room::enter_event(Explorer& explorer1)
{
    cout << "进入普通房间" << endl;usleep(100000);
    explorer1.SubLifeLos();
    if (explorer1.act_life_value() <= 0) return;
    explorer1.SubLifeGet();
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> dis(1, 100);
    auto prob = dis(gen);
    if (prob <= 10) {
        auto life_value = explorer1.AddActLifeValue(10);
        cout << "触发事件，回复" << life_value << "点生命，获得持续恢复效果，当前生命" << explorer1.PrintLifeValue() << endl;
        usleep(100000);
        explorer1.AddLifeGet();
    }
}

void Normal_room::battle_event(Explorer& explorer1)
{
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> num3_dis(1, 3);
    uniform_int_distribution<int> num81_dis(60, 140);
    num_monsters_ = num3_dis(gen);
    vector<Monster> monsters;
    vector<int> indices(num_monsters_);
    vector<bool> st(num_monsters_, true);
    cout << "遇到";
    for (int i = 0; i < num_monsters_; ++i) {
        auto prob = num81_dis(gen);
        monsters.emplace_back(10*prob/100,10*prob/100,5*prob/100,0,i+1);
        indices[i] = i;
        cout << "怪物" << i + 1 << monsters[i].PrintLifeValue();
    }
    sort(indices.begin(), indices.end(), [&](int a, int b){ return monsters[a].att() < monsters[b].att(); });
    vector<vector<int>> Cluster{{indices[0]}};
    for (int i = 0, j = 0; i < num_monsters_ - 1; ++i) {
        if (monsters[indices[i]].att() == monsters[indices[i+1]].att()) Cluster[j].emplace_back(indices[i+1]);
        else {
            ++j;
            Cluster.push_back({indices[i+1]});
        }
    }
    cout << endl;usleep(100000);
    cout << "战斗开始" << endl;usleep(100000);
    int damage;
    while (true) {
        uniform_int_distribution<int> num_dis(1, static_cast<int>(Cluster[Cluster.size()-1].size()));
        auto& indx = Cluster[Cluster.size()-1][Cluster[Cluster.size()-1].size()-num_dis(gen)];
        damage = monsters[indx].DamActLifeValue(explorer1);
        cout << "探险者攻击怪物" << monsters[indx].monster_indx() << "，造成" <<
        damage << "点伤害，怪物" << monsters[indx].monster_indx() <<
        monsters[indx].PrintLifeValue() << endl;usleep(100000);
        if (monsters[indx].act_life_value() <= 0) {
            st[indx] = false;
            cout << "怪物" << monsters[indx].monster_indx() << "死亡" << endl;usleep(100000);
            if (Cluster[Cluster.size()-1].size() > 1)
                swap(indx, Cluster[Cluster.size()-1][Cluster[Cluster.size()-1].size()-1]);
            Cluster[Cluster.size()-1].pop_back();
            if (Cluster[Cluster.size()-1].empty()) Cluster.pop_back();
            if (Cluster.empty()) break;
        }
        for (int i = 0; i < num_monsters_; ++i) {
            if (st[i]) {
                damage = explorer1.DamActLifeValue(monsters[i]);
                cout << "怪物" << monsters[i].monster_indx() << "攻击探险者，造成" << damage << "点伤害，探险者" <<
                explorer1.PrintLifeValue() << endl;usleep(100000);
                if (explorer1.act_life_value() <= 0) return;
            }
        }
    }
}

void Normal_room::result(Explorer& explorer1)
{
    ++num_normal_room;
    explorer1.AddExp(num_monsters_);
}
