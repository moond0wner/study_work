#include <iostream>
#include <memory>
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"
#include "player.h"

using namespace std;

int main()
{
    Player player;
    cout << "Присядь путник у костра и расскажи кто ты" << endl;
    cout << "\t1 - воин\n\t2 - маг \n\t3 - паладин" << endl;
    short choise = 0;
    cin >> choise;

    switch (choise)
    {
        case 1:
            player.Create(make_unique<Warrior>());
            break;
        case 2:
            player.Create(make_unique<Wizard>());
            break;
        case 3:
            player.Create(make_unique<Paladin>());
            break;
        default:
            cout << "Таких героев еще не было в наших краях" << endl;
            break;
    }

    cout << endl;
    cout << "Информация о персонаже" << endl;
    player.GetInfo();

    return 0;
}