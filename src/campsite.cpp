#include "campsite.h"

void Campsite::enter_event(Explorer& explorer1)
{
    cout << "进入营地" << endl;usleep(100000);
    explorer1.SetActLifeValue(explorer1.max_life_value());
    cout << "生命恢复，当前生命" << explorer1.PrintLifeValue() << endl;usleep(100000);
}

void Campsite::battle_event(Explorer& explorer1)
{

}

void Campsite::result(Explorer& explorer1)
{
    ++num_campsite;
}
