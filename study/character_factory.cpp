#include "character_factory.h"
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"

using namespace std;

unique_ptr<NPC>CreateCharacter(TypeCharacter character) {
    switch(character) {
        case TypeCharacter::warrior:
            return make_unique<Warrior>();
        case TypeCharacter::wizard:
            return make_unique<Wizard>();
        case TypeCharacter::paladin:
            return make_unique<Paladin>();
        default:
            return nullptr;
    }
}