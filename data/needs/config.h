#ifndef GUARD_NEEDS_CONFIG_H
#define GUARD_NEEDS_CONFIG_H

// ============================================================
// Pokémon Daydream Version — Needs Simulator Tuning Constants
// Centralised here so balance changes don't require hunting
// through multiple source files.
// ============================================================

// ---- Decay rates ----
// How many steps between each 1-point decay.
// Stored as power-of-2 thresholds: threshold = (1 << divisor).
// Increase divisor to slow decay; decrease to speed it up.
#define NEEDS_HUNGER_STEP_DECAY_DIVISOR     8   // 1 per 256 steps
#define NEEDS_ATTENTION_STEP_DECAY_DIVISOR  9   // 1 per 512 steps
#define NEEDS_REST_STEP_DECAY_DIVISOR       7   // 1 per 128 steps

// ---- Battle decay (per battle exit) ----
#define NEEDS_HUNGER_BATTLE_DECAY           5
#define NEEDS_ATTENTION_BATTLE_DECAY        3
#define NEEDS_REST_BATTLE_DECAY             8

// ---- Threshold table ----
// Range        State       Modifier
// 80–100       Thriving    Apply MAX effect
// 50–79        Content     Neutral
// 21–49        Restless    -3% accuracy on first move
// 0–20         Suffering   Apply MIN effect

// ---- Hunger effects ----
#define NEEDS_HUNGER_BONUS_PERCENT          105  // +5% damage dealt
#define NEEDS_HUNGER_PENALTY_PERCENT        90   // -10% damage dealt

// ---- Attention effects ----
// Thriving: +1 stage to first-turn move accuracy (not yet implemented)
// Suffering: disobedience checks at -20 friendship equivalent

// ---- Rest effects ----
// Thriving: +5% crit rate
// Suffering: 25% chance to skip first turn (Groggy)
#define NEEDS_REST_CRIT_BONUS_PERCENT       5
#define NEEDS_GROGGY_SKIP_CHANCE            25

// ---- Fill amounts by source ----
#define NEEDS_FILL_PET_TREAT_ATTENTION      20
#define NEEDS_FILL_BIG_MEAL_HUNGER          40
#define NEEDS_FILL_CAMP_REST                50
#define NEEDS_FILL_CAMP_COOK_HUNGER         30
#define NEEDS_FILL_INN_REST                 100
#define NEEDS_FILL_POKEMON_CENTER_REST      80
#define NEEDS_FILL_POKEMON_CENTER_HUNGER    30

// ---- Default value on init ----
#define NEEDS_DEFAULT_VALUE                 80

#endif // GUARD_NEEDS_CONFIG_H
