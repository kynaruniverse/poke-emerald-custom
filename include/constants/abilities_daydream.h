#ifndef GUARD_CONSTANTS_ABILITIES_DAYDREAM_H
#define GUARD_CONSTANTS_ABILITIES_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — New Ability Constants
// IDs begin after ABILITY_POISON_PUPPETEER (310).
// ============================================================

// ABILITY_DAYDREAM (311)
// Lullsparce's signature ability.
// At full HP, the holder skips one foe turn per battle
// (as if the foe used Splash). Triggers once per battle.
#define ABILITY_DAYDREAM        (ABILITY_POISON_PUPPETEER + 1)  // 311

// ABILITY_SWEET_DREAMS (312)
// Wobbusnore's signature ability.
// While the holder has a sleep status, it recovers 1/16 max HP
// at the end of each turn (stacks with Leftovers).
#define ABILITY_SWEET_DREAMS    (ABILITY_POISON_PUPPETEER + 2)  // 312

// ABILITY_PUNCHLINE (313)
// Mr. Mimic's signature ability.
// When the holder makes the foe flinch, it also confuses the foe.
// Comedy timing: lands harder when it lands at all.
#define ABILITY_PUNCHLINE       (ABILITY_POISON_PUPPETEER + 3)  // 313

// Total new abilities
#define ABILITIES_COUNT_DAYDREAM (ABILITY_PUNCHLINE + 1)

#endif // GUARD_CONSTANTS_ABILITIES_DAYDREAM_H
