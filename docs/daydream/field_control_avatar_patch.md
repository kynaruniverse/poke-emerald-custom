# Pokémon Daydream Version — field_control_avatar.c Patch Instructions

## Overview

Hook `NeedsTickOnStep()` into the overworld step counter so Needs
decay naturally as the player walks.

---

## Step 1: Add include

**File:** `src/field_control_avatar.c`

Add at the top:
```c
#include "pokemon_needs.h"
```

---

## Step 2: Find `TryStartStepCountScript()`

**File:** `src/field_control_avatar.c`

Search for:
```c
static void TryStartStepCountScript(void)
```

---

## Step 3: Add the Needs tick call

**Find** (inside `TryStartStepCountScript`, near the end):
```c
    IncrementGameStat(GAME_STAT_STEPS);
```

**Add after it:**
```c
    NeedsTickOnStep();   // Pokémon Daydream: decay Needs on each step
```

---

## Step 4: Hook `NeedsTickOnBattleEnd()` in battle_main.c

**File:** `src/battle_main.c`

**Find** the function that runs after a battle ends and returns to the field.
It is typically `BattleMainCB2()` or the callback set when `gMain.callback1` transitions.

**Add:**
```c
#include "pokemon_needs.h"
```

And in the post-battle cleanup:
```c
NeedsTickOnBattleEnd();   // Pokémon Daydream: decay Needs after each battle
```

---

## Step 5: Hook `FillAllNeeds()` in the Pokémon Center heal

**File:** `src/field_specials.c` (or wherever `HealPlayerParty` is called from)

**Find** the Pokémon Center nurse heal function. After the HP/status restore:
```c
FillNeed(i, NEED_REST, NEEDS_FILL_POKEMON_CENTER_REST);
FillNeed(i, NEED_HUNGER, NEEDS_FILL_POKEMON_CENTER_HUNGER);
```

Or use the convenience function:
```c
// Partial fill (not full — full fill is reserved for the Inn)
FillAllNeeds(NEEDS_FILL_POKEMON_CENTER_REST);
```

---

## Step 6: Hook `NeedsInitMon()` in `CreateMon()`

**File:** `src/pokemon.c`

**Find** `CreateMon()` and after the Pokémon is fully initialised:
```c
// Pokémon Daydream: initialise Needs for newly created party Pokémon
// (only for party slots, not box)
// NeedsInitMon() is called separately when a mon is withdrawn from box.
```

The actual call happens in the party-management code when a Pokémon is
added to the party (not box). See `src/pokemon_storage_system.c`.
