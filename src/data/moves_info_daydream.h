#ifndef GUARD_MOVES_INFO_DAYDREAM_H
#define GUARD_MOVES_INFO_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — New Move Data Entries
// Include in src/data/moves_info.h after the last vanilla entry.
// ============================================================

#include "constants/moves_daydream.h"

// ---- MOVE_HUSH_HOOVES ----
// Normal/Fairy physical. Silences target for 2 turns.
[MOVE_HUSH_HOOVES] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("HushHooves", "Hush Hooves"),
    .description    = COMPOUND_STRING(
        "Strikes with dream-laden\n"
        "hooves. Silences the foe\n"
        "for 2 turns."),
    .effect         = EFFECT_HIT,
    .power          = 90,
    .type           = TYPE_FAIRY,
    .accuracy       = 100,
    .pp             = 10,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_PHYSICAL,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_SILENCE,  // TODO: add MOVE_EFFECT_SILENCE to battle_move_effects.h
            .chance     = 100,
        }
    ),
},

// ---- MOVE_VIVID_SPIN ----
// Normal/Psychic special. Hits 2–5 times; 10% confuse per hit.
[MOVE_VIVID_SPIN] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("VividSpin", "Vivid Spin"),
    .description    = COMPOUND_STRING(
        "Spins in vivid patterns.\n"
        "Hits 2-5 times. May\n"
        "confuse the target."),
    .effect         = EFFECT_MULTI_HIT,
    .power          = 25,
    .type           = TYPE_PSYCHIC,
    .accuracy       = 95,
    .pp             = 10,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_SPECIAL,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance     = 10,
        }
    ),
},

// ---- MOVE_KNEAD ----
// Normal/Fairy status. Restores 50% HP and cures status.
[MOVE_KNEAD] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("Knead", "Knead"),
    .description    = COMPOUND_STRING(
        "Kneads its own fur to\n"
        "restore half its HP and\n"
        "cure any status ailment."),
    .effect         = EFFECT_ROOST,  // Reuse Roost effect as base; extend for status cure
    .power          = 0,
    .type           = TYPE_FAIRY,
    .accuracy       = 0,
    .pp             = 10,
    .target         = MOVE_TARGET_USER,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_STATUS,
    .healingMove     = TRUE,
},

// ---- MOVE_PINE_SLUMBER ----
// Normal/Grass physical. User falls asleep for 1 turn after use.
[MOVE_PINE_SLUMBER] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("PineSlumber", "Pine Slumber"),
    .description    = COMPOUND_STRING(
        "A powerful strike. The\n"
        "user falls into a brief\n"
        "slumber afterward."),
    .effect         = EFFECT_HIT,
    .power          = 100,
    .type           = TYPE_GRASS,
    .accuracy       = 90,
    .pp             = 5,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_PHYSICAL,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_SLEEP,
            .self       = TRUE,
            .chance     = 100,
        }
    ),
},

// ---- MOVE_BEDTIME_STORY ----
// Dragon/Ghost special. 30% chance to put target to sleep.
[MOVE_BEDTIME_STORY] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("BedtimeStory", "Bedtime Story"),
    .description    = COMPOUND_STRING(
        "Tells a haunting tale.\n"
        "May put the target to\n"
        "sleep."),
    .effect         = EFFECT_HIT,
    .power          = 110,
    .type           = TYPE_GHOST,
    .accuracy       = 85,
    .pp             = 5,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_SPECIAL,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance     = 30,
        }
    ),
},

// ---- MOVE_DAYDREAM_BEAM ----
// Normal/Psychic special. 20% infatuation chance.
[MOVE_DAYDREAM_BEAM] =
{
    .name           = HANDLE_EXPANDED_MOVE_NAME("DaydreamBeam", "Daydream Beam"),
    .description    = COMPOUND_STRING(
        "Fires a beam of dream\n"
        "energy. May cause\n"
        "infatuation."),
    .effect         = EFFECT_HIT,
    .power          = 95,
    .type           = TYPE_PSYCHIC,
    .accuracy       = 100,
    .pp             = 10,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = DAMAGE_CATEGORY_SPECIAL,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_ATTRACT,
            .chance     = 20,
        }
    ),
},

#endif // GUARD_MOVES_INFO_DAYDREAM_H
