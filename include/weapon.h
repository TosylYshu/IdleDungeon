#pragma once

class Weapon
{
private:
    int att_;
    int dur_;

public:
    explicit Weapon(int weapon_type);

    [[nodiscard]] int att() const { return att_; }

    [[nodiscard]] int dur() const { return dur_; }

    void DubAtt() { att_ *= 2; }

    void DecDur() { --dur_; }

    ~Weapon()=default;

};
