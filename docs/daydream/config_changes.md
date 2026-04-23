# Pokémon Daydream Version — Expansion Config Flag Changes

This document lists all changes made to `include/config/` files.
Apply these changes manually to the respective config headers.

## `include/config/battle.h`

```c
// Already GEN_LATEST in this fork — no changes needed for:
// B_EXP_CATCH, B_SPLIT_EXP, B_SCALED_EXP, B_CRIT_CHANCE, etc.

// Ensure EXP share is Gen 6+ style (already set):
// #define B_EXP_SHARE_ITEM  GEN_6  // verify this is set
```

## `include/config/overworld.h`

Change:
```c
#define OW_FOLLOWERS_ENABLED  FALSE
```
To:
```c
#define OW_FOLLOWERS_ENABLED  TRUE   // Pairs nicely with Needs Simulator
```

## `include/config/pokemon.h`

Verify these are set (they should be at GEN_LATEST already):
```c
#define P_NEW_EVOS_IN_REGIONAL_DEX  TRUE  // Allow Daydream evos in regional dex
```

## `include/config/species_enabled.h`

Ensure all gen families are enabled:
```c
#define P_FAMILY_DUNSPARCE  TRUE
#define P_FAMILY_STANTLER   TRUE
#define P_FAMILY_WOBBUFFET  TRUE
#define P_FAMILY_DELCATTY   TRUE
#define P_FAMILY_SPINDA     TRUE
#define P_FAMILY_MR_MIME    TRUE
#define P_FAMILY_SNORLAX    TRUE
#define P_FAMILY_DRAMPA     TRUE
```

## `Makefile`

Change the ROM title:
```makefile
# From:
TITLE        ?= POKEMON EMER
# To:
TITLE        ?= POKEMON DREAM
```

## `include/config/save.h`

Consider freeing unused save blocks to make room for Daydream data:
```c
#define FREE_MYSTERY_EVENT_BUFFERS  TRUE   // Frees 1104 bytes
#define FREE_ENIGMA_BERRY           TRUE   // Frees 52 bytes
#define FREE_LINK_BATTLE_RECORDS    TRUE   // Frees 88 bytes
```
**Total freed: ~1244 bytes** — enough for WardrobeState (13 bytes) + QuestLogState (128 bytes) + future expansion.
