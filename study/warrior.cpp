#include "warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior()
{
    damage = 20;
    health = 30;
    armor = 15;
}

Warrior::Warrior(string name, unsigned int lvl)
{
    this->name = name;
    for (size_t i = 0; i < lvl - 1; i++)
    {
        LvlUp();
    }
    this->lvl = lvl;
}

Warrior::~Warrior()
{
    cout << name << " пал смертью храбрых" << endl;
}

void Warrior::Create()
{
    cout << "Вы создали война\nЗадайте имя игрока\n";
    cin >> name;

    GetWeapon();
}

void Warrior::GetInfo()
{
    NPC::GetInfo();
    cout << "Сила " << strength << endl;
}

Weapon& Warrior::GetWeapon()
{
    if (weapons.empty()) {
        Weapon weapon;
        weapon.damage = 1;
        weapon.name = "Кулаки";
        weapons.push_back(weapon);

        cout << name << " взял в руки оружие " << weapons[0].name << endl;
        cout << "Добавка к урона = " << weapons[0].damage << endl;
    }

    return weapons.back();
}

void Warrior::Recalculate()
{
    damage += (1 + lvl * strength * 0.1);
    health += (1 + lvl * strength * 0.1);
    armor += (1 + lvl * strength * 0.1);
}