# Pokémon Daydream Version — Full Integration Manifest: Field Control & Needs Hooks

This document provides **exact copy-paste instructions** for modifying `src/field_control_avatar.c`, `src/battle_main.c`, and `src/field_specials.c` to integrate the Needs system's step decay, battle decay, and Pokémon Center healing.

---

## 1. `src/field_control_avatar.c` — Add Required Include

**File:** `src/field_control_avatar.c`

**Line Numbers:** Add this near other includes, typically around line 1-40.

**Find this block** (or similar existing includes):
```c
#include "wild_encounter.h"
#include "constants/event_bg.h"
```

**Replace the entire block with this:**
```c
#include "wild_encounter.h"
#include "pokemon_needs.h" // Pokémon Daydream: Needs system
#include "constants/event_bg.h"
```

---

## 2. `src/field_control_avatar.c` — Hook `NeedsTickOnStep()`

**File:** `src/field_control_avatar.c`

**Line Numbers:** Search for `TryStartStepCountScript()`. This is typically around line 75 or within `ProcessPlayerFieldInput()` (around line 180-190).

**Find this block** (inside `ProcessPlayerFieldInput`, within the `if (input->tookStep)` block):
```c
        IncrementGameStat(GAME_STAT_STEPS);
        IncrementBirthIslandRockStepCount();
```

**Replace the entire block with this:**
```c
        IncrementGameStat(GAME_STAT_STEPS);
        IncrementBirthIslandRockStepCount();
        NeedsTickOnStep();   // Pokémon Daydream: decay Needs on each step
```

---

## 3. `src/battle_main.c` — Hook `NeedsTickOnBattleEnd()`

**File:** `src/battle_main.c`

**Line Numbers:** Add include near other includes. Search for `BattleMainCB2()` or the function that handles post-battle cleanup and returns to the field. This is typically where `SetMainCallback2(CB2_ReturnToField)` is called.

**Add this include** at the top of `src/battle_main.c`:
```c
#include "pokemon_needs.h" // Pokémon Daydream: Needs system
```

**Find this block** (within the post-battle cleanup logic, before returning to the field):
```c
    SetMainCallback2(CB2_ReturnToField);
```

**Replace the entire block with this:**
```c
    NeedsTickOnBattleEnd(); // Pokémon Daydream: decay Needs after each battle
    SetMainCallback2(CB2_ReturnToField);
```

---

## 4. `src/field_specials.c` — Hook `FillAllNeeds()` in Pokémon Center Heal

**File:** `src/field_specials.c` (or the file containing `HealPlayerParty` or the Pokémon Center nurse script)

**Line Numbers:** Search for the function that handles healing at a Pokémon Center. This is typically `HealPlayerParty()` or a related script function.

**Find this block** (within the Pokémon Center healing logic, after HP/status restore):
```c
    HealPlayerParty(); // Example, actual function call may vary
```

**Replace the entire block with this:**
```c
    HealPlayerParty(); // Example, actual function call may vary
    // Pokémon Daydream: Partially fill Needs at Pokémon Center
    FillAllNeeds(NEEDS_FILL_POKEMON_CENTER_REST); // This fills all needs to a certain threshold
```

**Add this include** at the top of `src/field_specials.c`:
```c
#include "pokemon_needs.h" // Pokémon Daydream: Needs system
```

---

## 5. `src/pokemon.c` — Hook `NeedsInitMon()` in `CreateMon()`

**File:** `src/pokemon.c`

**Line Numbers:** Search for `CreateMon()` or `CreateBoxMon()`. The `NeedsInitMon()` call should happen after the Pokémon is fully initialized, but only for Pokémon added to the *party*, not just stored in the box.

**Find this block** (after a new Pokémon is created and its basic data is set, but before it's potentially moved to a box):
```c
    // Existing post-creation logic
    // ...
```

**Add this block after the Pokémon is fully initialized and assigned to a party slot (if applicable):**
```c
    // Pokémon Daydream: initialise Needs for newly created party Pokémon
    // NeedsInitMon() is called separately when a mon is withdrawn from box.
    // This hook should be placed where a Pokémon is first given to the player
    // or added to the active party.
    // Example (if 'mon' is directly added to party): NeedsInitMon(partyIndex);
```

**Note:** The most robust place for `NeedsInitMon()` is often in the party management functions (e.g., `src/pokemon_storage_system.c` when a Pokémon is withdrawn from the PC or received as a gift directly into the party) rather than `CreateMon()` itself, as `CreateMon()` is also used for box Pokémon. For now, this is a conceptual placement; the exact location will depend on your project's specific party management flow. You may need to search for functions like `GiveMonToPlayer()` or `AddMonToParty()`.

**Add this include** at the top of `src/pokemon.c`:
```c
#include "pokemon_needs.h" // Pokémon Daydream: Needs system
```
