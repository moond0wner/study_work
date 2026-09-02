#include <iostream>
#include "GameClasses.h"
#include "BaseClasses.h"
#include "Evil.h"
#include <fstream> 
using namespace std;

enum class ValueQuality
{
    �����, �������, ������, ����������, ����������� 
};

struct Treasure
{
    Treasure() = default;
    string name{ "������" };
    ValueQuality quality = ValueQuality::����������;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::�����:
            cout << "�������� ������\n";
            break;
        case ValueQuality::�������:
            cout << "�������� �����������\n";
            break;
        case ValueQuality::������:
            cout << "�������� �������\n";
            break;
        case ValueQuality::����������:
            cout << "�������� ������\n";
            break;
        case ValueQuality::�����������:
            cout << "�������� ���������\n";
            break;
        default:
            break;
        }
    }
}; 

struct �loth : Treasure 
{
    �loth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "�����", "��������", "����", "���������", "����" };
    string site{NULL};
    unsigned short armor{ 1 };
};

enum class CharacterType {
    UNKNOWN = 0,
    WARRIOR,
    WIZARD,
    PALADIN
};

enum class EnemyType {
    ����������_������ = 1,
    �������_������,
    ��������_�_�����_�����,
    ������_�������,
    ��������_����,
};

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
};

// ������� ��� �������� ����������
unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::WARRIOR:
        return make_unique<Warrior>();
        break;
    case CharacterType::WIZARD:
        return make_unique<Wizard>();
        break;
    case CharacterType::PALADIN:
        return make_unique<Paladin>();
        break;
    default:
        invalid_argument("����������� ��� ���������");
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player* player = new Player();

    cout << "������, ������\n������� � ������ � �������� � ����\n�� ������� ���?\n\t1 - ����� ��������,\n\t2 - ���������\n";
    if (TestChoise(2, "�������� �� ������, ������� �����"))
    {
        cout << "�������� � ����� �������\n\t1 - ����\n\t2 - ���������\n\t3 - �������\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, "������ ��� �� ���� � ����� �����\n�� ��� �� �� ���������"))
        {
            case 1:
                character = CreateCharacter(CharacterType::WARRIOR);
                break;
            case 2: 
                character = CreateCharacter(CharacterType::WIZARD);
                break;
            case 3: 
                character = CreateCharacter(CharacterType::PALADIN);
                break;
        }
        player->Create(move(character));
    }
    else
    {
        ifstream loadSystem("save.txt", ios::binary);
        if (!loadSystem.is_open())
        {
            cout << "����� � �������� ��������\n������ � ����� ������� ������������ ����������\n";
        }
        else
        {
            //���������� ��������
        }
    }

    //������� ����

    cout << "������� ��������� ���?\n\t1 - ��������� ����\n\t2 - ����������\n";
    if (TestChoise(2, "����� ����� ������������ � ��������\n������� ���� �����"))
    {
        if (player->Save()) {
            cout << "���� ������� ���������!\n";
        }
        else {
            cout << "������ ����������.\n";
        }
    }
    return 0;
}