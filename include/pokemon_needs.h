#ifndef GUARD_POKEMON_NEEDS_H
#define GUARD_POKEMON_NEEDS_H

// =============================================================================
// Pokémon Daydream Version — Needs Simulator
// Design Bible: docs/Daydream_Design_Bible.md §2.2, §4.3
//
// Three per-mon needs (0..100). Decay on overworld steps and battle end.
// Thresholds drive battle modifiers and flavor messages.
// =============================================================================

#include "global.h"

// ---- Need IDs ----------------------------------------------------------------
#define NEED_HUNGER     0
#define NEED_ATTENTION  1
#define NEED_REST       2
#define NEED_COUNT      3

// ---- Range / thresholds ------------------------------------------------------
#define NEED_MAX        100
#define NEED_THRIVING   80   // >= this: apply MAX effect
#define NEED_CONTENT    50   // >= this: neutral
#define NEED_RESTLESS   21   // >= this: minor penalty
#define NEED_SUFFERING  20   // <= this: apply MIN effect

// ---- State enum (returned by GetNeedState) -----------------------------------
enum NeedState
{
    NEED_STATE_SUFFERING,
    NEED_STATE_RESTLESS,
    NEED_STATE_CONTENT,
    NEED_STATE_THRIVING,
};

// ---- Public API --------------------------------------------------------------
void NeedsInitMon(struct Pokemon *mon);             // call after CreateMon
void NeedsTickOnStep(void);                         // overworld step hook
void NeedsTickOnBattleEnd(void);                    // battle end hook
u8   GetNeedState(struct Pokemon *mon, u8 need);    // enum NeedState
u8   GetNeedValue(struct Pokemon *mon, u8 need);
void FillNeed(struct Pokemon *mon, u8 need, u8 amount);
void PartyFillNeed(u8 need, u8 amount);             // used by camp/inn

// Battle-side modifiers (called from battle damage / accuracy / crit paths).
u32  ApplyNeedsDamageModifier(u32 dmg, struct Pokemon *attacker);
s8   GetNeedsAccuracyDelta(struct Pokemon *attacker, bool8 isFirstTurn);
u8   GetNeedsCritBonus(struct Pokemon *attacker);
bool8 NeedsShouldSkipFirstTurn(struct Pokemon *mon);

#endif // GUARD_POKEMON_NEEDS_H
