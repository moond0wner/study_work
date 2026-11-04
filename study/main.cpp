#include <iostream>
#include <memory>
#include <limits>
#include "player.h"
#include "type_character.h"
#include "weapon_qualitiy.h"
#include "game_state.h"
#include "character_factory.h"

using namespace std;

void ClearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Всегда ровно один Enter. Буфер гарантированно пуст после ClearInput,
// поэтому getline просто ждёт новую строку.
void WaitEnter() {
    cout << "\nНажмите Enter, чтобы продолжить...";
    ClearInput();
    string dummy;
    getline(cin, dummy);
 
}

void PrintMenu() {
    cout << "\n\tМеню:\n";
    cout << "1. Сюжет\n";
    cout << "2. Характеристики\n";
    cout << "3. Выход\n\n";
    cout << "Выберите действие: ";
}

bool CreatePlayer(Player &player) {
    short choice = 0; 
    
    cout << "Присядь, путник, к нашему костру.\n";
    cout << "Поведай, кто ты и каким путем идешь по этому миру?\n";
    cout << "\t1 - Воин\n";
    cout << "\t2 - Маг\n";
    cout << "\t3 - Паладин\n\n";
    cout << "Твой выбор: ";

    if (!(cin >> choice)) {
        ClearInput();
        cout << "Ошибка: неверный ввод\n";
        return false;
    }

    if (choice < 1 || choice > 3) {
        ClearInput();
        cout << "Таких героев еще не было в наших краях...\n";
        return false;
    }

    auto playerChoice = static_cast<TypeCharacter>(choice);
    auto newCharacter = CreateCharacter(playerChoice);
    if (!newCharacter) {
        cout << "Таких героев еще не было в наших краях...\n";
        return false;
    }

    player.Create(move(newCharacter));

    cout << "\nНастало время выбрать, каким качеством обладает твое снаряжение.\n";
    cout << "\t1 - обычное\n";
    cout << "\t2 - необычное\n";
    cout << "\t3 - редкое\n";
    cout << "\t4 - эпическое\n";
    cout << "\t5 - легендарное\n";
    cout << "Так выбери же: ";

    if (!(cin >> choice)) {
        ClearInput();
        cout << "Ошибка: неверный ввод\n";
        return false;
    }

    if (choice < 1 || choice > 5) {
        ClearInput();
        cout << "Такого качества не существует в этом мире\n";
        return false;
    }

    switch (static_cast<WeaponQuality>(choice)) {
        case WeaponQuality::common:
            cout << "Ты выбрал обычное оружие. Ничего особенного\n";
            break;
        case WeaponQuality::uncommon:
            cout << "Ты выбрал необычное оружие. Слегка светится в темноте\n";
            break;
        case WeaponQuality::rare:
            cout << "Ты выбрал редкое оружие. О нем ходят слухи в тавернах, такое ведь не везде достанешь\n";
            break;
        case WeaponQuality::epic:
            cout << "Ты выбрал эпическое оружие. Создано искусным мастером\n";
            break;
        case WeaponQuality::legendary:
            cout << "Ты выбрал легендарное оружие. Оружие богов\n";
            break;
    }


    cout << "\nВот кто встал на твой путь:\n";
    player.GetInfo();
    WaitEnter();
    
    return true;
}


int main()
{
    Player player;
    GameState state = GameState{GameState::CharacterCreation};

    
    short choice = 0;

    while (state != GameState::Exit) {
        switch (state) {
            case GameState::CharacterCreation:
                if (!CreatePlayer(player)) {
                    cout << "Попробуйте создать заново\n\n";
                } else { 
                    state = GameState::MainMenu;
                }
                break;
            case GameState::MainMenu:
                PrintMenu();
                
                if (!(cin >> choice)) {
                    ClearInput();
                    cout << "Ошибка: неверный ввод\n";
                    break;
                }

                switch (choice) {
                    case 1:
                        state = GameState::Story;
                        break;
                    case 2:
                        state = GameState::CharacterInfo;
                        break;
                    case 3: 
                        state = GameState::Exit;
                        break;
                    default:
                        cout << "Ошибка: неверный пункт меню! Введите 1, 2 или 3\n";
                        break;
                }
                break;
             case GameState::Story:
                    cout << "\t\tСюжет:\n";
                    cout << "Путник поднялся с места, поправил экипировку и направился к заброшенным руинам.\n";
                    cout << "Впереди завывал холодный ветер, предвещая скорую схватку с порождениями тьмы...\n";
                    WaitEnter();
                    state = GameState::MainMenu;
                    break;
            case GameState::CharacterInfo:
                if (player.GetCharacter() == nullptr) {
                    cout << "Сначала создайте персонажа\n";
                } else {
                    cout << "\t\tХарактеристики:\n";
                    player.GetInfo();
                }
                WaitEnter();
                state = GameState::MainMenu;
                break;
            case GameState::Exit:
                break;
        }
    }
}