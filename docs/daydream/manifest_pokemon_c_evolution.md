# Pokémon Daydream Version — Full Integration Manifest: Evolution Methods

This document provides **exact copy-paste instructions** for modifying `include/constants/pokemon.h` and `src/pokemon.c` to integrate the new Daydream evolution methods.

---

## 1. `include/constants/pokemon.h` — Add new `EvoType` constants

**File:** `include/constants/pokemon.h`

**Line Numbers:** Search for `enum EvolutionConditions`. This is typically around line 272-306.

**Find this block:**
```c
    IF_NATURE,                          // The Pokémon has a specific nature.
    IF_AMPED_NATURE,                    // The Pokémon has one of the following natures: Hardy, Brave, Adamant, Naughty, Docile, Impish, Lax, Hasty, Jolly, Naive, Rash, Sassy, or Quirky.
    IF_LOW_KEY_NATURE,                  // The Pokémon has one of the following natures: Lonely, Bold, Relaxed, Timid, Serious, Modest, Mild, Quiet, Bashful, Calm, Gentle, or Careful
```

**Replace the entire block with this:**
```c
    IF_NATURE,                          // The Pokémon has a specific nature.
    IF_AMPED_NATURE,                    // The Pokémon has one of the following natures: Hardy, Brave, Adamant, Naughty, Docile, Impish, Lax, Hasty, Jolly, Naive, Rash, Sassy, or Quirky.
    IF_LOW_KEY_NATURE,                  // The Pokémon has one of the following natures: Lonely, Bold, Relaxed, Timid, Serious, Modest, Mild, Quiet, Bashful, Calm, Gentle, or Careful
    // Pokémon Daydream additions
    EVO_LEVEL_NIGHT_FRIENDSHIP,         // Level up at night with high friendship
    EVO_LEVEL_SLEEP,                    // Level up while Pokémon has sleep status
    EVO_LEVEL_NEEDS_MAX,                // Level up with all Needs ≥ NEED_THRIVING
    EVO_LEVEL_IN_SPECIAL_MAP,           // Level up while in a specific map group
    EVO_TRADE_ITEM,                     // Trade while holding a specific item
    EVO_LEVEL_ITEM_HOLD,                // Level up while holding a specific item
```

**Required includes** at top of `include/constants/pokemon.h` (add if not present):
```c
#include "constants/map_sections.h" // For EVO_LEVEL_IN_SPECIAL_MAP
#include "constants/items.h"        // For EVO_TRADE_ITEM, EVO_LEVEL_ITEM_HOLD
```

---

## 2. `src/pokemon.c` — Implement new evolution methods in `GetEvolutionTargetSpecies()`

**File:** `src/pokemon.c`

**Line Numbers:** Search for `GetEvolutionTargetSpecies()`. This function contains a large `switch` statement for `evo->method`. The new cases should be added within this switch.

**Find this block** (within `GetEvolutionTargetSpecies()`, inside the `switch (evo->method)` statement, typically near `case EVO_LEVEL_NATURE:` or similar):
```c
        case EVO_LEVEL_NATURE:
            if (level >= evo->param && GetMonNature(mon) == evo->evoGetMonData)
                return evo->targetSpecies;
            break;
```

**Add this block immediately after it:**
```c
        case EVO_LEVEL_NIGHT_FRIENDSHIP: // Pokémon Daydream
            if (level >= evo->param && GetMonFriendshipScore(mon) >= FRIENDSHIP_200_TO_254 && IsNightTime())
                return evo->targetSpecies;
            break;

        case EVO_LEVEL_SLEEP: // Pokémon Daydream
            if (level >= evo->param && GetMonData(mon, MON_DATA_STATUS) & STATUS1_SLEEP)
                return evo->targetSpecies;
            break;

        case EVO_LEVEL_NEEDS_MAX: // Pokémon Daydream
            if (level >= evo->param &&
                GetNeedState(partyIndex, NEED_HUNGER)    >= NEED_THRIVING &&
                GetNeedState(partyIndex, NEED_ATTENTION) >= NEED_THRIVING &&
                GetNeedState(partyIndex, NEED_REST)      >= NEED_THRIVING)
                return evo->targetSpecies;
            break;

        case EVO_LEVEL_IN_SPECIAL_MAP: // Pokémon Daydream
            if (level >= evo->param && gMapHeader.regionMapSectionId == evo->param2)
                return evo->targetSpecies;
            break;

        case EVO_TRADE_ITEM: // Pokémon Daydream
            if (gSpecialVar_ItemId == evo->param)
                return evo->targetSpecies;
            break;

        case EVO_LEVEL_ITEM_HOLD: // Pokémon Daydream
            if (level >= evo->param && GetMonData(mon, MON_DATA_HELD_ITEM) == evo->param2)
                return evo->targetSpecies;
            break;
```

**Required includes** at top of `src/pokemon.c` (add if not present):
```c
#include "rtc.h"           // For IsNightTime()
#include "pokemon_needs.h" // For GetNeedState(), NEED_THRIVING
#include "fieldmap.h"      // For gMapHeader.regionMapSectionId
```

---

## 3. `src/data/pokemon/evolution.h` — Add Evolution Table Entries

**File:** `src/data/pokemon/evolution.h` (or equivalent evolution table file)

**Line Numbers:** Locate the `gEvolutionTable` array. Find each base species entry and add the corresponding evolution line.

### 3.1. Dunsparce → Lullsparce

**Find:** `[SPECIES_DUNSPARCE] = {`

**Add this entry:**
```c
[SPECIES_DUNSPARCE] =
{
    { EVO_LEVEL_NIGHT_FRIENDSHIP, 30, SPECIES_LULLSPARCE },
},
```

### 3.2. Stantler → Stagsomne

**Find:** `[SPECIES_STANTLER] = {`

**Add this entry:**
```c
[SPECIES_STANTLER] =
{
    { EVO_ITEM, ITEM_DREAM_ANTLER, SPECIES_STAGSOMNE },
},
```

### 3.3. Wobbuffet → Wobbusnore

**Find:** `[SPECIES_WOBBUFFET] = {`

**Add this entry:**
```c
[SPECIES_WOBBUFFET] =
{
    { EVO_LEVEL_SLEEP, 40, SPECIES_WOBBUSNORE },
},
```

### 3.4. Delcatty → Delcatnap

**Find:** `[SPECIES_DELCATTY] = {`

**Add this entry:**
```c
[SPECIES_DELCATTY] =
{
    { EVO_TRADE_ITEM, ITEM_COMFY_BEDROLL, SPECIES_DELCATNAP },
},
```

### 3.5. Spinda → Spindream

**Find:** `[SPECIES_SPINDA] = {`

**Add this entry:**
```c
[SPECIES_SPINDA] =
{
    { EVO_LEVEL_NEEDS_MAX, 36, SPECIES_SPINDREAM },
},
```

### 3.6. Mr. Mime → Mr. Mimic

**Find:** `[SPECIES_MR_MIME] = {`

**Add this entry:**
```c
[SPECIES_MR_MIME] =
{
    { EVO_LEVEL_ITEM_HOLD, ITEM_COMEDY_MASK, SPECIES_MR_MIMIC },
},
```

### 3.7. Snorlax → Snorpine

**Find:** `[SPECIES_SNORLAX] = {`

**Add this entry:**
```c
[SPECIES_SNORLAX] =
{
    { EVO_LEVEL_IN_SPECIAL_MAP, 50, MAPSEC_CINDERPINE }, // Assuming Cinderpine has a unique MAPSEC_ID
},
```

### 3.8. Drampa → Drampire

**Find:** `[SPECIES_DRAMPA] = {`

**Add this entry:**
```c
[SPECIES_DRAMPA] =
{
    { EVO_LEVEL_IN_SPECIAL_MAP, 50, MAPSEC_THE_HOLLOW }, // Assuming The Hollow has a unique MAPSEC_ID
},
```

**Note:** You will need to define `MAPSEC_CINDERPINE` and `MAPSEC_THE_HOLLOW` in `include/constants/map_sections.h` and assign them appropriate values once those maps are created in Porymap.
