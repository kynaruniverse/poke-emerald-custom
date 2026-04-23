// =============================================================================
// Pokémon Daydream Version — boot-time init
//
// Called from the new-game / continue paths so each Daydream subsystem can
// seed its runtime state. Individual systems are stubbed until their
// milestones land (M3+).
// =============================================================================

#include "global.h"
// #include "wardrobe.h"
// #include "pokemon_needs.h"
// #include "quest_log_custom.h"

void Daydream_Init(void)
{
    // Wardrobe_Init();
    // QuestLog_Init();
    // Needs: initialized per-mon in CreateBoxMon (M4).
}

void Daydream_OnContinue(void)
{
    // Hook for one-shot post-load migrations that can't live in load_save.c.
}
