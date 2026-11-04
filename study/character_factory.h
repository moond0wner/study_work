#pragma once

#include <memory>
#include "NPC.h"
#include "type_character.h"

std::unique_ptr<NPC>CreateCharacter(TypeCharacter character);