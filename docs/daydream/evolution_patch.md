# Pokémon Daydream Version — Evolution Data Patch Instructions

## Overview

Add evolution entries for all 8 new Daydream evolutions.
These go in `src/data/pokemon/evolution.h` (or the equivalent evolution table).

---

## Evolution Table Entries

Find each base species entry and add the evolution line.

### 1. Dunsparce → Lullsparce

**Find** `[SPECIES_DUNSPARCE]` in the evolution table.

**Add:**
```c
[SPECIES_DUNSPARCE] =
{
    { EVO_LEVEL_NIGHT_FRIENDSHIP, 30, SPECIES_LULLSPARCE },
    // EVO_LEVEL_NIGHT_FRIENDSHIP: level up at night with high friendship
    // If this method doesn't exist, use EVO_FRIENDSHIP_NIGHT as fallback
},
```

### 2. Stantler → Stagsomne

**Find** `[SPECIES_STANTLER]`.

**Add:**
```c
[SPECIES_STANTLER] =
{
    { EVO_ITEM, ITEM_DREAM_ANTLER, SPECIES_STAGSOMNE },
},
```

### 3. Wobbuffet → Wobbusnore

**Find** `[SPECIES_WOBBUFFET]`.

**Add:**
```c
[SPECIES_WOBBUFFET] =
{
    { EVO_LEVEL_SLEEP, 40, SPECIES_WOBBUSNORE },
    // EVO_LEVEL_SLEEP: level up while the Pokémon has sleep status
    // If this method doesn't exist, use EVO_LEVEL as fallback at Lv.40
    // and document the sleep requirement as flavour text only.
},
```

### 4. Delcatty → Delcatnap

**Find** `[SPECIES_DELCATTY]`.

**Add:**
```c
[SPECIES_DELCATTY] =
{
    { EVO_TRADE_ITEM, ITEM_COMFY_BEDROLL, SPECIES_DELCATNAP },
},
```

### 5. Spinda → Spindream

**Find** `[SPECIES_SPINDA]`.

**Add:**
```c
[SPECIES_SPINDA] =
{
    { EVO_LEVEL_NEEDS_MAX, 36, SPECIES_SPINDREAM },
    // EVO_LEVEL_NEEDS_MAX: level up at Lv.36 with all Needs at MAX (80+)
    // If this method doesn't exist, use EVO_LEVEL_FRIENDSHIP as fallback.
},
```

### 6. Mr. Mime → Mr. Mimic

**Find** `[SPECIES_MR_MIME]`.

**Add:**
```c
[SPECIES_MR_MIME] =
{
    { EVO_LEVEL_ITEM_HOLD, ITEM_COMEDY_MASK, SPECIES_MR_MIMIC },
    // EVO_LEVEL_ITEM_HOLD: level up while holding the item
    // This is equivalent to EVO_TRADE_ITEM but triggered by level-up.
    // Use EVO_ITEM_HOLD if available, else EVO_ITEM.
},
```

### 7. Snorlax → Snorpine

**Find** `[SPECIES_SNORLAX]`.

**Add:**
```c
[SPECIES_SNORLAX] =
{
    { EVO_LEVEL_IN_SPECIAL_MAP, 50, SPECIES_SNORPINE },
    // EVO_LEVEL_IN_SPECIAL_MAP: level up at Lv.50 while in Cinderpine map group
    // If this method doesn't exist, use EVO_LEVEL at Lv.50 as fallback.
},
```

### 8. Drampa → Drampire

**Find** `[SPECIES_DRAMPA]`.

**Add:**
```c
[SPECIES_DRAMPA] =
{
    { EVO_LEVEL_IN_SPECIAL_MAP, 50, SPECIES_DRAMPIRE },
    // EVO_LEVEL_IN_SPECIAL_MAP: level up at Lv.50 while in The Hollow map group
},
```

---

## Custom Evolution Methods

If any of the above methods (`EVO_LEVEL_NIGHT_FRIENDSHIP`, `EVO_LEVEL_SLEEP`,
`EVO_LEVEL_NEEDS_MAX`, `EVO_LEVEL_IN_SPECIAL_MAP`) do not exist in the
expansion's `include/constants/pokemon.h`, they must be added.

**File:** `include/constants/pokemon.h`

**Find** the `EvoType` enum and add:
```c
EVO_LEVEL_SLEEP,             // Level up while Pokémon has sleep status
EVO_LEVEL_NEEDS_MAX,         // Level up with all Needs ≥ NEED_THRIVING
EVO_LEVEL_IN_SPECIAL_MAP,    // Level up while in a specific map group
```

**File:** `src/pokemon.c` — `GetEvolutionTargetSpecies()`

Add handling for each new method in the switch statement:
```c
case EVO_LEVEL_SLEEP:
    if (level >= criteria && GetMonData(mon, MON_DATA_STATUS) & STATUS1_SLEEP)
        return targetSpecies;
    break;

case EVO_LEVEL_NEEDS_MAX:
    if (level >= criteria &&
        GetNeedState(partyIndex, NEED_HUNGER)    >= NEED_THRIVING &&
        GetNeedState(partyIndex, NEED_ATTENTION) >= NEED_THRIVING &&
        GetNeedState(partyIndex, NEED_REST)      >= NEED_THRIVING)
        return targetSpecies;
    break;

case EVO_LEVEL_IN_SPECIAL_MAP:
    if (level >= criteria && gMapHeader.regionMapSectionId == criteria2)
        return targetSpecies;
    break;
```

---

## Learnset Additions

Each new species needs its own learnset. Until custom learnsets are created,
the base species learnsets are used (see `LEARNSETS(Dunsparce)` etc. in
`src/data/pokemon/species_info/daydream_evolutions.h`).

**Priority learnsets to add:**
1. Lullsparce — add MOVE_DAYDREAM_BEAM at Lv.40
2. Stagsomne — add MOVE_HUSH_HOOVES at Lv.38
3. Wobbusnore — add MOVE_PINE_SLUMBER at Lv.44 (flavour)
4. Delcatnap — add MOVE_KNEAD at Lv.36
5. Spindream — add MOVE_VIVID_SPIN at Lv.40
6. Mr. Mimic — add MOVE_DAYDREAM_BEAM at Lv.45
7. Snorpine — add MOVE_PINE_SLUMBER at Lv.52
8. Drampire — add MOVE_BEDTIME_STORY at Lv.55

Create `src/data/pokemon/level_up_learnsets/daydream_learnsets.h` with these entries.
