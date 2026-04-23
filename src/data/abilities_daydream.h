#ifndef GUARD_ABILITIES_DAYDREAM_H
#define GUARD_ABILITIES_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — New Ability Data Entries
// Include in src/data/abilities.h after the last vanilla entry.
//
// Behaviour is implemented in src/daydream/ability_effects.c.
// ============================================================

#include "constants/abilities_daydream.h"

// ---- ABILITY_DAYDREAM ----
// At full HP, the holder causes one foe to skip its turn
// (as if the foe used Splash). Triggers once per battle.
[ABILITY_DAYDREAM] =
{
    .name = COMPOUND_STRING("Daydream"),
    .description = COMPOUND_STRING(
        "At full HP, makes one\n"
        "foe skip a turn."),
},

// ---- ABILITY_SWEET_DREAMS ----
// While the holder has sleep status, it recovers 1/16 max HP
// at the end of each turn.
[ABILITY_SWEET_DREAMS] =
{
    .name = COMPOUND_STRING("Sweet Dreams"),
    .description = COMPOUND_STRING(
        "Restores HP each turn\n"
        "while asleep."),
},

// ---- ABILITY_PUNCHLINE ----
// When the holder causes a foe to flinch, it also confuses
// that foe. Comedy timing.
[ABILITY_PUNCHLINE] =
{
    .name = COMPOUND_STRING("Punchline"),
    .description = COMPOUND_STRING(
        "Flinching foes also\n"
        "become confused."),
},

#endif // GUARD_ABILITIES_DAYDREAM_H
