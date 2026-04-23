#ifndef GUARD_CAMP_H
#define GUARD_CAMP_H

// ============================================================
// Pokémon Daydream Version — Camp & Shelter System
// ============================================================

// Start the camp sequence at the player's current position.
// Called from ItemUseOutOfBattle_Bedroll() in item_use.c.
void Camp_StartCamp(void);

// Returns TRUE if the player can camp at the current tile.
// Checks metatile behaviour for soft-tile outdoor flag.
bool8 Camp_CanCampHere(void);

#endif // GUARD_CAMP_H
