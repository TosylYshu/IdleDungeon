#include "weapon.h"

Weapon::Weapon(int weapon_type)
{
    if (weapon_type == 1) {
        att_ = 4;
        dur_ = 6;
    }
    else if (weapon_type == 2) {
        att_ = 0;
        dur_ = 6;
    }
    else if (weapon_type == 3) {
        att_ = 1;
        dur_ = 6;
    }
    else {
        att_ = 0;
        dur_ = 0;
    }
}
