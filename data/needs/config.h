#ifndef GUARD_DAYDREAM_NEEDS_CONFIG_H
#define GUARD_DAYDREAM_NEEDS_CONFIG_H

// =============================================================================
// Pokémon Daydream Version — Needs Simulator tuning values
// Single place for designers to twist knobs. Pulled in by src/pokemon_needs.c.
// =============================================================================

#include "pokemon_needs.h"

// ---- Decay pacing ------------------------------------------------------------
// Values represent "1 point lost per N steps". Bigger = slower decay.
#define NEEDS_HUNGER_STEPS_PER_POINT      256
#define NEEDS_ATTENTION_STEPS_PER_POINT   512
#define NEEDS_REST_STEPS_PER_POINT        128

// Points lost per battle end (applied once when the battle screen exits).
#define NEEDS_HUNGER_BATTLE_COST          5
#define NEEDS_ATTENTION_BATTLE_COST       3
#define NEEDS_REST_BATTLE_COST            8

// ---- Fill amounts ------------------------------------------------------------
#define NEEDS_FILL_PET_TREAT       20   // +Hunger
#define NEEDS_FILL_BIG_MEAL        60   // +Hunger
#define NEEDS_FILL_BERRY_GENERIC   15   // +Hunger
#define NEEDS_FILL_PET_ACTION      20   // +Attention
#define NEEDS_FILL_TALK_ACTION     10   // +Attention
#define NEEDS_FILL_CAMP_REST       50   // +Rest
#define NEEDS_FILL_CAMP_COOK       30   // +Hunger (if cooked at camp)
#define NEEDS_FILL_INN_REST        100  // +Rest (to max)
#define NEEDS_FILL_CENTER_REST     100  // +Rest (to max)

// ---- Battle modifier deltas (percent or stage) -------------------------------
#define NEEDS_HUNGER_THRIVE_DMG_PCT   105  // *1.05x
#define NEEDS_HUNGER_SUFFER_DMG_PCT   90   // *0.90x
#define NEEDS_ATTENTION_THRIVE_ACC    10   // +10 accuracy first-move
#define NEEDS_ATTENTION_RESTLESS_ACC  (-3)
#define NEEDS_REST_THRIVE_CRIT_STAGE  1    // +1 crit stage
#define NEEDS_REST_SUFFER_SKIP_PCT    25   // 25% chance skip first turn

// ---- Wardrobe interaction ----------------------------------------------------
#define NEEDS_CAMP_SET_BONUS_REST     10   // +10 additional Rest when Camp Set worn

#endif // GUARD_DAYDREAM_NEEDS_CONFIG_H
