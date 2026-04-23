#ifndef GUARD_SPECIES_INFO_DAYDREAM_EVOLUTIONS_H
#define GUARD_SPECIES_INFO_DAYDREAM_EVOLUTIONS_H

// ============================================================
// Pokémon Daydream Version — New Species Info Entries
// Include this file at the bottom of species_info.h after
// all gen_N_families.h includes.
//
// Sprite assets are placeholders (reuse Dunsparce/base sprites)
// until custom art is created. See TASKS.md §4.1 for art tasks.
// ============================================================

#include "constants/species_daydream.h"
#include "constants/abilities_daydream.h"
#include "constants/moves_daydream.h"

// ============================================================
// LULLSPARCE — Normal/Psychic — Dunsparce evolution
// Evolves from Dunsparce at Lv.30 with high friendship at night
// ============================================================
[SPECIES_LULLSPARCE] =
{
    .baseHP         = 100,
    .baseAttack     = 90,
    .baseDefense    = 80,
    .baseSpeed      = 65,
    .baseSpAttack   = 95,
    .baseSpDefense  = 80,
    .types          = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
    .catchRate      = 45,
    .expYield       = 184,
    .evYield_SpAttack = 2,
    .genderRatio    = PERCENT_FEMALE(50),
    .eggCycles      = 25,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_MEDIUM_FAST,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    .abilities      = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_DAYDREAM },
    .bodyColor      = BODY_COLOR_YELLOW,
    .speciesName    = _("Lullsparce"),
    .cryId          = CRY_DUNSPARCE,
    .natDexNum      = NATIONAL_DEX_LULLSPARCE,
    .categoryName   = _("Drowsy"),
    .height         = 18,
    .weight         = 250,
    .description    = COMPOUND_STRING(
        "It hums a single note that sends nearby\n"
        "Pokémon into vivid daydreams. At full\n"
        "health, its hum is so potent that foes\n"
        "forget to act entirely."),
    .pokemonScale   = 277,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    // Placeholder sprites — replace with custom art (see TASKS.md §4.1)
    .frontPic       = gMonFrontPic_Dunsparce,
    .frontPicSize   = MON_COORDS_SIZE(48, 48),
    .frontPicYOffset = 11,
    .backPic        = gMonBackPic_Dunsparce,
    .backPicSize    = MON_COORDS_SIZE(48, 48),
    .backPicYOffset = 4,
    .palette        = gMonPalette_Dunsparce,
    .shinyPalette   = gMonShinyPalette_Dunsparce,
    .iconSprite     = gMonIcon_Dunsparce,
    .iconPalIndex   = 0,
    LEARNSETS(Dunsparce),  // TODO: replace with LEARNSETS(Lullsparce)
},

// ============================================================
// STAGSOMNE — Normal/Fairy — Stantler evolution
// Evolves from Stantler using the Dream Antler item
// ============================================================
[SPECIES_STAGSOMNE] =
{
    .baseHP         = 95,
    .baseAttack     = 105,
    .baseDefense    = 85,
    .baseSpeed      = 90,
    .baseSpAttack   = 80,
    .baseSpDefense  = 85,
    .types          = MON_TYPES(TYPE_NORMAL, TYPE_FAIRY),
    .catchRate      = 35,
    .expYield       = 200,
    .evYield_Attack = 2,
    .genderRatio    = PERCENT_FEMALE(25),
    .eggCycles      = 20,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_SLOW,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    .abilities      = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER },
    .bodyColor      = BODY_COLOR_BROWN,
    .speciesName    = _("Stagsomne"),
    .cryId          = CRY_STANTLER,
    .natDexNum      = NATIONAL_DEX_STAGSOMNE,
    .categoryName   = _("Dream Stag"),
    .height         = 19,
    .weight         = 760,
    .description    = COMPOUND_STRING(
        "Its antlers resonate with dream energy.\n"
        "The sound of its hooves on soft earth\n"
        "silences the forest for miles around."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Stantler,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Stantler,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Stantler,
    .shinyPalette   = gMonShinyPalette_Stantler,
    .iconSprite     = gMonIcon_Stantler,
    .iconPalIndex   = 0,
    LEARNSETS(Stantler),
},

// ============================================================
// WOBBUSNORE — Psychic/Normal — Wobbuffet evolution
// Evolves from Wobbuffet by levelling up while asleep
// ============================================================
[SPECIES_WOBBUSNORE] =
{
    .baseHP         = 190,
    .baseAttack     = 40,
    .baseDefense    = 75,
    .baseSpeed      = 35,
    .baseSpAttack   = 40,
    .baseSpDefense  = 75,
    .types          = MON_TYPES(TYPE_PSYCHIC, TYPE_NORMAL),
    .catchRate      = 25,
    .expYield       = 210,
    .evYield_HP     = 3,
    .genderRatio    = PERCENT_FEMALE(50),
    .eggCycles      = 20,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_MEDIUM_FAST,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    .abilities      = { ABILITY_SHADOW_TAG, ABILITY_NONE, ABILITY_SWEET_DREAMS },
    .bodyColor      = BODY_COLOR_BLUE,
    .speciesName    = _("Wobbusnore"),
    .cryId          = CRY_WOBBUFFET,
    .natDexNum      = NATIONAL_DEX_WOBBUSNORE,
    .categoryName   = _("Snoring"),
    .height         = 15,
    .weight         = 350,
    .description    = COMPOUND_STRING(
        "It snores so loudly that its own snores\n"
        "wake it up, only for it to fall back\n"
        "asleep immediately. It heals while it\n"
        "sleeps, which is most of the time."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Wobbuffet,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Wobbuffet,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Wobbuffet,
    .shinyPalette   = gMonShinyPalette_Wobbuffet,
    .iconSprite     = gMonIcon_Wobbuffet,
    .iconPalIndex   = 0,
    LEARNSETS(Wobbuffet),
},

// ============================================================
// DELCATNAP — Normal/Fairy — Delcatty evolution
// Evolves from Delcatty when traded holding Comfy Bedroll
// ============================================================
[SPECIES_DELCATNAP] =
{
    .baseHP         = 80,
    .baseAttack     = 65,
    .baseDefense    = 75,
    .baseSpeed      = 95,
    .baseSpAttack   = 75,
    .baseSpDefense  = 80,
    .types          = MON_TYPES(TYPE_NORMAL, TYPE_FAIRY),
    .catchRate      = 30,
    .expYield       = 175,
    .evYield_Speed  = 2,
    .genderRatio    = PERCENT_FEMALE(75),
    .eggCycles      = 15,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_FAST,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
    .abilities      = { ABILITY_CUTE_CHARM, ABILITY_NORMALIZE, ABILITY_WONDER_SKIN },
    .bodyColor      = BODY_COLOR_PINK,
    .speciesName    = _("Delcatnap"),
    .cryId          = CRY_DELCATTY,
    .natDexNum      = NATIONAL_DEX_DELCATNAP,
    .categoryName   = _("Naptime"),
    .height         = 11,
    .weight         = 90,
    .description    = COMPOUND_STRING(
        "It kneads anything soft until it falls\n"
        "asleep mid-knead. It can restore its\n"
        "own health by kneading its own fur."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Delcatty,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Delcatty,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Delcatty,
    .shinyPalette   = gMonShinyPalette_Delcatty,
    .iconSprite     = gMonIcon_Delcatty,
    .iconPalIndex   = 0,
    LEARNSETS(Delcatty),
},

// ============================================================
// SPINDREAM — Normal/Psychic — Spinda evolution
// Evolves from Spinda at Lv.36 with all Needs maxed
// ============================================================
[SPECIES_SPINDREAM] =
{
    .baseHP         = 80,
    .baseAttack     = 80,
    .baseDefense    = 70,
    .baseSpeed      = 85,
    .baseSpAttack   = 90,
    .baseSpDefense  = 70,
    .types          = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
    .catchRate      = 45,
    .expYield       = 165,
    .evYield_SpAttack = 2,
    .genderRatio    = PERCENT_FEMALE(50),
    .eggCycles      = 15,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_FAST,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    .abilities      = { ABILITY_OWN_TEMPO, ABILITY_TANGLED_FEET, ABILITY_CONTRARY },
    .bodyColor      = BODY_COLOR_RED,
    .speciesName    = _("Spindream"),
    .cryId          = CRY_SPINDA,
    .natDexNum      = NATIONAL_DEX_SPINDREAM,
    .categoryName   = _("Dreaming"),
    .height         = 11,
    .weight         = 55,
    .description    = COMPOUND_STRING(
        "When all its needs are met, Spinda's\n"
        "spinning becomes so vivid it generates\n"
        "psychic visions in those who watch it."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Spinda,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Spinda,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Spinda,
    .shinyPalette   = gMonShinyPalette_Spinda,
    .iconSprite     = gMonIcon_Spinda,
    .iconPalIndex   = 0,
    LEARNSETS(Spinda),
},

// ============================================================
// MR_MIMIC — Psychic/Ghost — Mr. Mime evolution
// Evolves from Mr. Mime by levelling up holding Comedy Mask
// ============================================================
[SPECIES_MR_MIMIC] =
{
    .baseHP         = 55,
    .baseAttack     = 55,
    .baseDefense    = 75,
    .baseSpeed      = 100,
    .baseSpAttack   = 120,
    .baseSpDefense  = 110,
    .types          = MON_TYPES(TYPE_PSYCHIC, TYPE_GHOST),
    .catchRate      = 30,
    .expYield       = 215,
    .evYield_SpAttack = 2,
    .genderRatio    = PERCENT_FEMALE(50),
    .eggCycles      = 20,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_MEDIUM_FAST,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    .abilities      = { ABILITY_SOUNDPROOF, ABILITY_FILTER, ABILITY_PUNCHLINE },
    .bodyColor      = BODY_COLOR_PINK,
    .speciesName    = _("Mr. Mimic"),
    .cryId          = CRY_MR_MIME,
    .natDexNum      = NATIONAL_DEX_MR_MIMIC,
    .categoryName   = _("Comedian"),
    .height         = 14,
    .weight         = 560,
    .description    = COMPOUND_STRING(
        "It has mastered the art of mimicry to\n"
        "such a degree that its impressions\n"
        "cause genuine psychological distress.\n"
        "Its punchlines always land."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_MrMime,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_MrMime,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_MrMime,
    .shinyPalette   = gMonShinyPalette_MrMime,
    .iconSprite     = gMonIcon_MrMime,
    .iconPalIndex   = 0,
    LEARNSETS(MrMime),
},

// ============================================================
// SNORPINE — Normal/Grass — Snorlax evolution
// Evolves from Snorlax by levelling up in Cinderpine map
// ============================================================
[SPECIES_SNORPINE] =
{
    .baseHP         = 180,
    .baseAttack     = 120,
    .baseDefense    = 95,
    .baseSpeed      = 35,
    .baseSpAttack   = 75,
    .baseSpDefense  = 100,
    .types          = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
    .catchRate      = 15,
    .expYield       = 250,
    .evYield_HP     = 3,
    .genderRatio    = PERCENT_FEMALE(12),
    .eggCycles      = 40,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_SLOW,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
    .abilities      = { ABILITY_IMMUNITY, ABILITY_THICK_FAT, ABILITY_GLUTTONY },
    .bodyColor      = BODY_COLOR_GREEN,
    .speciesName    = _("Snorpine"),
    .cryId          = CRY_SNORLAX,
    .natDexNum      = NATIONAL_DEX_SNORPINE,
    .categoryName   = _("Sleeping Pine"),
    .height         = 22,
    .weight         = 5200,
    .description    = COMPOUND_STRING(
        "After sleeping under a pine tree for\n"
        "decades, pine needles have grown from\n"
        "its fur. It sleeps standing up now,\n"
        "indistinguishable from the forest."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Snorlax,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Snorlax,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Snorlax,
    .shinyPalette   = gMonShinyPalette_Snorlax,
    .iconSprite     = gMonIcon_Snorlax,
    .iconPalIndex   = 0,
    LEARNSETS(Snorlax),
},

// ============================================================
// DRAMPIRE — Dragon/Ghost — Drampa evolution
// Evolves from Drampa at Lv.50 in The Hollow map
// ============================================================
[SPECIES_DRAMPIRE] =
{
    .baseHP         = 90,
    .baseAttack     = 85,
    .baseDefense    = 80,
    .baseSpeed      = 70,
    .baseSpAttack   = 130,
    .baseSpDefense  = 100,
    .types          = MON_TYPES(TYPE_DRAGON, TYPE_GHOST),
    .catchRate      = 15,
    .expYield       = 240,
    .evYield_SpAttack = 3,
    .genderRatio    = PERCENT_FEMALE(50),
    .eggCycles      = 30,
    .friendship     = STANDARD_FRIENDSHIP,
    .growthRate     = GROWTH_SLOW,
    .eggGroups      = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
    .abilities      = { ABILITY_BERSERK, ABILITY_SAP_SIPPER, ABILITY_CLOUD_NINE },
    .bodyColor      = BODY_COLOR_GRAY,
    .speciesName    = _("Drampire"),
    .cryId          = CRY_DRAMPA,
    .natDexNum      = NATIONAL_DEX_DRAMPIRE,
    .categoryName   = _("Bedtime"),
    .height         = 30,
    .weight         = 1850,
    .description    = COMPOUND_STRING(
        "Deep in The Hollow, Drampa absorbs\n"
        "the residual dream energy until it\n"
        "becomes something else entirely.\n"
        "Its bedtime stories end badly."),
    .pokemonScale   = 256,
    .pokemonOffset  = 0,
    .trainerScale   = 256,
    .trainerOffset  = 0,
    .frontPic       = gMonFrontPic_Drampa,
    .frontPicSize   = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .backPic        = gMonBackPic_Drampa,
    .backPicSize    = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 0,
    .palette        = gMonPalette_Drampa,
    .shinyPalette   = gMonShinyPalette_Drampa,
    .iconSprite     = gMonIcon_Drampa,
    .iconPalIndex   = 0,
    LEARNSETS(Drampa),
},

#endif // GUARD_SPECIES_INFO_DAYDREAM_EVOLUTIONS_H
