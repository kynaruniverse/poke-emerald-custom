// ============================================================
// Pokémon Daydream Version — New Ability Battle Effects
// src/daydream/ability_effects.c
//
// Hook points in battle_util.c / battle_main.c:
//
// ABILITY_DAYDREAM:
//   In the "on turn start" loop, check if the holder is at
//   full HP and the ability hasn't triggered yet this battle.
//   If so, set the foe's chosen move to MOVE_SPLASH for this
//   turn and set a per-battle flag.
//   Hook: ABILITYEFFECT_ON_TURN_START or equivalent.
//
// ABILITY_SWEET_DREAMS:
//   In the "end of turn" loop, if the holder has STATUS1_SLEEP,
//   heal 1/16 max HP (same as Poison Heal logic but for sleep).
//   Hook: ABILITYEFFECT_ENDTURN.
//
// ABILITY_PUNCHLINE:
//   After a flinch is applied to the foe, also apply confusion.
//   Hook: after SetMoveEffect(MOVE_EFFECT_FLINCH, ...).
// ============================================================

#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "battle_main.h"
#include "pokemon.h"
#include "random.h"
#include "constants/abilities_daydream.h"
#include "constants/moves.h"
#include "constants/battle_move_effects.h"

// ---- ABILITY_DAYDREAM ----
// Per-battle trigger flag (one bit per battler).
static u8 sDaydreamTriggered = 0;

// Call at the start of each battle to reset the trigger.
void AbilityDaydream_ResetBattle(void)
{
    sDaydreamTriggered = 0;
}

// Call at the start of each turn for each battler.
// battler: the battler index of the Daydream holder.
// Returns TRUE if the foe's move should be suppressed this turn.
bool8 AbilityDaydream_TryTrigger(u8 battler)
{
    u8 bit = (1 << battler);
    u16 maxHP, currentHP;

    // Already triggered this battle for this battler
    if (sDaydreamTriggered & bit)
        return FALSE;

    maxHP    = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_MAX_HP);
    currentHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP);

    if (currentHP < maxHP)
        return FALSE;

    // Trigger: suppress foe's move this turn
    sDaydreamTriggered |= bit;
    return TRUE;
}

// ---- ABILITY_SWEET_DREAMS ----
// Call at end of turn for battlers with this ability.
// Returns the HP to restore (0 if not applicable).
u16 AbilitySweetDreams_EndTurnHeal(u8 battler)
{
    u32 status = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_STATUS);
    u16 maxHP;

    if (!(status & STATUS1_SLEEP))
        return 0;

    maxHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_MAX_HP);
    return maxHP / 16;  // 1/16 max HP
}

// ---- ABILITY_PUNCHLINE ----
// Call after a flinch effect is applied to the target.
// target: the battler index of the flinched target.
// Returns TRUE if confusion was applied.
bool8 AbilityPunchline_ApplyConfusion(u8 attacker, u8 target)
{
    // Only trigger if the attacker has ABILITY_PUNCHLINE
    if (GetBattlerAbility(attacker) != ABILITY_PUNCHLINE)
        return FALSE;

    // Apply confusion to the target if not already confused
    if (gBattleMons[target].status2 & STATUS2_CONFUSION)
        return FALSE;

    gBattleMons[target].status2 |= STATUS2_CONFUSION_TURN(4);
    return TRUE;
}
