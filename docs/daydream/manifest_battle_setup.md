# Pokémon Daydream Version — Full Integration Manifest: Battle Setup

This document provides **exact copy-paste instructions** for modifying `src/battle_setup.c` to integrate the new Soft Level Scaling system for trainer Pokémon.

---

## 1. `src/battle_setup.c` — Add Required Include

**File:** `src/battle_setup.c`

**Line Numbers:** Add this near other includes, typically around line 1-50.

**Find this block** (or similar existing includes):
```c
#include "fishing.h"
```

**Replace the entire block with this:**
```c
#include "fishing.h"
#include "soft_scaling.h" // Pokémon Daydream: Soft Level Scaling
```

---

## 2. `src/battle_setup.c` — Apply Soft Scaling to Trainer Pokémon Levels

**File:** `src/battle_setup.c`

**Line Numbers:** Search for `CreateTrainerParty` or `FillTrainerParty`. The level assignment usually happens within a loop. The exact line numbers may vary, but the pattern `party[i].lvl = trainerMon->lvl;` or `SetMonData(&party[i], MON_DATA_LEVEL, &trainerMon->lvl);` is key.

**Find this block** (within a function like `CreateTrainerParty` or `FillTrainerParty`, inside a loop that iterates through `i`):
```c
        party[i].lvl = trainerMon->lvl;
```

**Replace the entire block with this:**
```c
        party[i].lvl = ScaleLevel(trainerMon->lvl); // Pokémon Daydream: Apply soft level scaling
```

**If your codebase uses `SetMonData` for level assignment, find this pattern:**
```c
        SetMonData(&party[i], MON_DATA_LEVEL, &trainerMon->lvl);
```

**And replace it with this:**
```c
        u8 scaledLevel = ScaleLevel(trainerMon->lvl); // Pokémon Daydream: Apply soft level scaling
        SetMonData(&party[i], MON_DATA_LEVEL, &scaledLevel);
```

---

## 3. Advance Story Tier at Gym/Boss Defeats

This step involves modifying event scripts (usually `.s` or `.inc` files) or C functions that handle post-battle logic for Gym Leaders and other major boss trainers. The goal is to call `AdvanceStoryTier()` after each significant victory.

**Example for a script file (e.g., `data/scripts/events/gym_leader_brock.inc`):**

**Find this block** (after the trainer battle is won and any victory text is displayed):
```asm
    msgbox gText_BrockVictory, MSGBOX_DEFAULT
    release
    end
```

**Replace the entire block with this:**
```asm
    msgbox gText_BrockVictory, MSGBOX_DEFAULT
    special AdvanceStoryTier // Pokémon Daydream: Advance story progression
    release
    end
```

**Example for a C function (e.g., a post-battle callback in `src/battle_tower.c` or similar):**

**Find this block** (within the function, after battle outcome processing):
```c
    // Existing post-battle logic
    // ...
```

**Add this line:**
```c
    AdvanceStoryTier(); // Pokémon Daydream: Advance story progression
```

### Story Tier Advancement Schedule

Apply `special AdvanceStoryTier` or `AdvanceStoryTier()` after the player defeats each major boss:

| Event | Resulting Story Tier |
|---|---|
| Defeat first gym (Loafsbury) | 1 |
| Defeat second gym (Mossreach) | 2 |
| Defeat third gym (Static City) | 3 |
| Defeat fourth gym (Cinderpine) | 4 |
| Defeat fifth gym (Glasswake) | 5 |
| Defeat sixth gym (The Hollow) | 6 |
| Defeat seventh gym | 7 |
| Defeat eighth gym | 8 |
| Defeat Elite Four | 9 |
| Defeat Champion Vex | 10 |

---

## 4. `src/pokemon.c` — Apply Perfect Stats in `CreateMon()`

**File:** `src/pokemon.c`

**Line Numbers:** Search for `CreateMon()` or `CreateBoxMon()`. The IV/EV setting should occur after the Pokémon's basic data (species, level, personality) has been set, but before it's added to the party or box.

**Find this block** (or similar, after initial Pokémon creation):
```c
    // Existing IV/EV initialization or random generation
    // ...
```

**Add this block after any default IV/EV generation, but before the function returns:**
```c
    // Pokémon Daydream: Perfect Stats mode
    if (gSaveBlock2Ptr->optionsPerfectStats)
    {
        u8 i, iv = 31;
        for (i = 0; i < NUM_STATS; i++)
            SetBoxMonData(&mon->box, MON_DATA_HP_IV + i, &iv);
        // Apply a sensible 252/252/4 EV spread based on species stats
        // TODO: implement per-species EV spread table (see TASKS.md §4.4)
        // For now, you might want to set a default EV spread here, e.g.:
        // u16 ev = 252;
        // SetBoxMonData(&mon->box, MON_DATA_ATK_EV, &ev);
        // SetBoxMonData(&mon->box, MON_DATA_SPATK_EV, &ev);
        // ev = 4;
        // SetBoxMonData(&mon->box, MON_DATA_HP_EV, &ev);
    }
```

**Required includes** at top of `src/pokemon.c` (add if not present):
```c
#include "global.h" // For gSaveBlock2Ptr
```
