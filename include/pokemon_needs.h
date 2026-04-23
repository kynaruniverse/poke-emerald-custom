#ifndef GUARD_POKEMON_NEEDS_H
#define GUARD_POKEMON_NEEDS_H

// ============================================================
// Pokémon Daydream Version — Needs Simulator
// Three needs per party Pokémon: HUNGER, ATTENTION, REST.
// Each is a u8 0–100. Stored in struct Pokemon (not BoxPokemon)
// to avoid save-block bloat; reset to 80 on box deposit.
// ============================================================

// --------------- Need IDs ---------------
#define NEED_HUNGER     0
#define NEED_ATTENTION  1
#define NEED_REST       2
#define NEED_COUNT      3

// --------------- Thresholds ---------------
#define NEED_MAX        100
#define NEED_THRIVING   80   // ≥80: Thriving — apply bonus
#define NEED_CONTENT    50   // 50–79: Content — neutral
#define NEED_RESTLESS   21   // 21–49: Restless — -3% first-move accuracy
#define NEED_SUFFERING  20   // ≤20: Suffering — apply penalty

// --------------- Default / init value ---------------
#define NEED_DEFAULT    80

// --------------- Decay rates (steps between 1-point decay) ---------------
// Stored as power-of-2 divisors: actual threshold = (1 << divisor).
// Hunger:    1 per 256 steps  → divisor 8
// Attention: 1 per 512 steps  → divisor 9
// Rest:      1 per 128 steps  → divisor 7
#define NEED_HUNGER_STEP_DIVISOR    8
#define NEED_ATTENTION_STEP_DIVISOR 9
#define NEED_REST_STEP_DIVISOR      7

// --------------- Battle decay (per battle exit) ---------------
#define NEED_HUNGER_BATTLE_DECAY    5
#define NEED_ATTENTION_BATTLE_DECAY 3
#define NEED_REST_BATTLE_DECAY      8

// --------------- Item fill amounts ---------------
#define NEED_PET_TREAT_ATTENTION    20
#define NEED_BIG_MEAL_HUNGER        40
#define NEED_CAMP_REST_FILL         50
#define NEED_CAMP_HUNGER_FILL       30   // from cooking a berry at camp
#define NEED_INN_REST_FILL          100  // full rest at an inn

// --------------- Damage modifier percentages ---------------
// Applied in ApplyNeedsDamageModifier() in battle_util.c
#define NEED_HUNGER_BONUS_PCT       105  // +5% damage when Thriving
#define NEED_HUNGER_PENALTY_PCT     90   // -10% damage when Suffering

// --------------- Accuracy modifier (first move, Restless) ---------------
// Applied as a -3% accuracy debuff on the first move of a battle turn.
#define NEED_RESTLESS_ACC_PENALTY   3

// --------------- Groggy wake chance (REST Suffering) ---------------
// 25% chance to skip the first turn of battle.
#define NEED_GROGGY_CHANCE          25

// --------------- Struct (stored per-mon in RAM, not save) ---------------
// NOTE: These fields are appended to struct Pokemon in pokemon.h.
// They are NOT in BoxPokemon to avoid save-block overflow.
// On box deposit, they are discarded; on withdraw, set to NEED_DEFAULT.
// See pokemon.c CreateMon() and load_save.c migration.

// --------------- Public API ---------------

// Tick needs decay on each overworld step.
// Call from TryStartStepCountScript() in field_control_avatar.c.
void NeedsTickOnStep(void);

// Tick needs decay when a battle ends.
// Call from BattleMainCB2() or equivalent in battle_main.c.
void NeedsTickOnBattleEnd(void);

// Get the need state enum for a party Pokémon.
// Returns NEED_THRIVING, NEED_CONTENT, NEED_RESTLESS, or NEED_SUFFERING.
u8 GetNeedState(u8 partyIndex, u8 need);

// Get the raw need value (0–100) for a party Pokémon.
u8 GetNeedValue(u8 partyIndex, u8 need);

// Fill a need by amount (clamped to NEED_MAX).
void FillNeed(u8 partyIndex, u8 need, u8 amount);

// Fill all needs for all party Pokémon (used by Pokémon Center).
void FillAllNeeds(u8 amount);

// Apply damage modifier based on attacker's Hunger need.
// Returns modified damage value.
u32 ApplyNeedsDamageModifier(u32 dmg, u8 attackerPartyIndex);

// Returns TRUE if the Pokémon is Groggy (REST Suffering, first-turn skip).
bool8 NeedsIsGroggy(u8 partyIndex);

// Initialise all needs for a newly created party Pokémon.
void NeedsInitMon(u8 partyIndex);

#endif // GUARD_POKEMON_NEEDS_H
