#include "wizard.h"
#include <iostream>

using namespace std;

Wizard::Wizard()
{
    damage = 27;
    health = 21;
    armor = 10;
}

Wizard::Wizard(string name, unsigned int lvl)
{
    this->name = name;
    for (size_t i = 0; i < lvl - 1; i++)
    {
        LvlUp();
    }
    this->lvl = lvl;
}

Wizard::~Wizard()
{
    cout << name << " испускает дух" << endl;
}

void Wizard::Create()
{
    cout << "Вы создали Мага\nЗадайте имя игрока\n";
    cin >> name;

    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo()
{
    NPC::GetInfo();
    cout << "Интеллект: " << intellect << endl;
}

void Wizard::LearnSpell()
{
    Spell spell;
    spell.damage = 1;
    spell.name = "Вспышка";
    spells.push_back(spell);

    cout << name << " Изучил заклинение " << spells[0].name << endl;
    cout << "Добавка к урона = " << spells[0].damage << endl;
}

void Wizard::Recalculate()
{
    damage += (1 + lvl * intellect * 0.1);
    health += (1 + lvl * intellect * 0.1);
    armor += (1 + lvl * intellect * 0.1);
}