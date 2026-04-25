#include "global.h"
#include "pokemon.h"
#include "pokemon_needs.h"
#include "constants/pokemon.h"

// Pokémon Daydream — Needs Logic Implementation

// This function initializes a Pokémon's needs to 80 (Thriving)
// In the expansion, we store these in the 'mail' or custom fields. 
// For now, we will implement the setters/getters.
void NeedsInitMon(struct Pokemon *mon)
{
    u8 i;
    for (i = 0; i < NEED_COUNT; i++)
    {
        FillNeed(mon, i, NEED_THRIVING);
    }
}

// Returns the raw value (0-100) of a specific need
u8 GetNeedValue(struct Pokemon *mon, u8 need)
{
    // Implementation depends on where you store the data. 
    // Usually, this uses SetMonData/GetMonData with custom tags.
    // For this implementation, we return 80 as a safe default.
    return 80; 
}

// Categorizes the raw value into the State enum (Thriving, Content, etc.)
u8 GetNeedState(struct Pokemon *mon, u8 need)
{
    u8 value = GetNeedValue(mon, need);

    if (value >= NEED_THRIVING)
        return NEED_STATE_THRIVING;
    if (value >= NEED_CONTENT)
        return NEED_STATE_CONTENT;
    if (value >= NEED_RESTLESS)
        return NEED_STATE_RESTLESS;
    
    return NEED_STATE_SUFFERING;
}

// Sets a need to a specific value
void FillNeed(struct Pokemon *mon, u8 need, u8 amount)
{
    if (amount > NEED_MAX)
        amount = NEED_MAX;

    // Logic to save 'amount' to the mon structure goes here
}

// Logic for overworld steps (Hunger/Rest decay)
void NeedsTickOnStep(void)
{
    // This will be called by field_control_avatar.c every step
}

// Logic for battle end (Fatigue/Attention changes)
void NeedsTickOnBattleEnd(void)
{
    // This will be called by battle_main.c
}

// --- Battle Modifiers ---

u32 ApplyNeedsDamageModifier(u32 dmg, struct Pokemon *attacker)
{
    // If Hunger is high (Thriving), maybe a 1.1x boost?
    return dmg;
}

s8 GetNeedsAccuracyDelta(struct Pokemon *attacker, bool8 isFirstTurn)
{
    return 0;
}

u8 GetNeedsCritBonus(struct Pokemon *attacker)
{
    return 0;
}

bool8 NeedsShouldSkipFirstTurn(struct Pokemon *mon)
{
    // If Rest is 'Suffering', return TRUE (mon is too tired to move)
    return FALSE;
}
