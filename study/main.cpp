#include <iostream>
#include <memory>
#include <limits>
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"
#include "player.h"
#include "type_character.h"

using namespace std;

void ClearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main()
{
    Player player;
    short choice = 0;
    
    cout << "Присядь, путник, к нашему костру." << endl;
    cout << "Поведай, кто ты и каким путем идешь по этому миру?" << endl;
    cout << "\t1 - Воин\n";
    cout << "\t2 - Маг\n";
    cout << "\t3 - Паладин" << endl;
    cout << "Твой выбор: ";

    if (!(cin >> choice)) {
        ClearInput();
        cout << "Ошибка: неверный ввод\n";
        return 1;
    }

    if (choice < 1 || choice > 3) {
        cout << "Таких героев еще не было в наших краях..." << endl;
        return 1;
    }

    switch (static_cast<TypeCharacter>(choice))
    {
        case TypeCharacter::warrior:
            player.Create(make_unique<Warrior>());
            break;
        case TypeCharacter::wizard:
            player.Create(make_unique<Wizard>());
            break;
        case TypeCharacter::paladin:
            player.Create(make_unique<Paladin>());
            break;
    }

    cout << endl;
    cout << "Вот кто встал на твой путь:" << endl;
    player.GetInfo();

    cout << "Настало время выбрать, каким качеством обладает твое снаряжение.\n";
    cout << "\t1 - обычное\n";
    cout << "\t2 - необычное\n";
    cout << "\t3 - редкое\n";
    cout << "\t4 - эпическое\n";
    cout << "\t5 - легендарное\n";
    cout << "Так выбери же: ";

    if (!(cin >> choice)) {
        ClearInput();
        cout << "Ошибка: неверный ввод\n";
        return 1;
    }

    if (choice < 1 || choice > 5) {
         cout << "Такого качества не существует в этом мире" << endl;
         return 1;
    }


    switch (static_cast<WeaponQuality>(choice))
    {
        case WeaponQuality::common:
            cout << "Ты выбрал обычное оружие. Ничего особенного" << endl;
            break;
        case WeaponQuality::uncommon:
            cout << "Ты выбрал необычное оружие. Слегка светится в темноте" << endl;
            break;
        case WeaponQuality::rare:
            cout << "Ты выбрал редкое оружие. О нем ходят слухи в тавернах, такое ведь не везде достанешь" << endl;
            break;
        case WeaponQuality::epic:
            cout << "Ты выбрал эпическое оружие. Создано искуссным мастером" << endl;
            break;
        case WeaponQuality::legendary:
            cout << "Ты выбрал легендарное оружие. Оружие богов." << endl;
            break;
    }
    return 0;
}