# Pokémon Daydream Version — global.h Patch Instructions

## Overview

Two structs in `include/global.h` need new fields for Daydream systems.
These are **manual edits** — apply them carefully to avoid breaking save compatibility.
After editing, bump `SAVE_VERSION` in `src/save.c` (or equivalent).

---

## 1. Add `WardrobeState` to `struct SaveBlock2`

**File:** `include/global.h`

**Find** (near end of `struct SaveBlock2`):
```c
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
}; // sizeof=0xF2C
```

**Replace with:**
```c
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
    // Pokémon Daydream additions
    struct WardrobeState wardrobe;      // 13 bytes: 5 equipped + 8 bitmap
    u8 optionsPerfectStats:1;           // 1 bit: Perfect IVs/EVs toggle
    u8 saveBlockPadding:7;              // padding
}; // sizeof updated
```

**Required includes** at top of `global.h`:
```c
#include "wardrobe.h"
```

---

## 2. Add `QuestLogState` to `struct SaveBlock1`

**File:** `include/global.h`

**Find** (near end of `struct SaveBlock1`, before the closing `};`):
```c
    /*0x3???*/ struct WaldaPhrase waldaPhrase;
```

**Add after it:**
```c
    // Pokémon Daydream additions
    struct QuestLogState questLog;      // 128 bytes: 4 bits × 256 quests
```

**Required includes** at top of `global.h`:
```c
#include "quest_log_custom.h"
```

---

## 3. Save Migration in `src/load_save.c`

Add this migration block in the save-load function, after the existing save version check:

```c
// Pokémon Daydream save migration
// If loading a save from before Daydream was added, initialise new fields.
if (loadedSaveVersion < SAVE_VERSION_DAYDREAM_1)
{
    u8 i;
    // Initialise Needs to 80 (not 0) for all party Pokémon
    // (Needs are stored in RAM, not save — this is a belt-and-suspenders default)
    for (i = 0; i < PARTY_SIZE; i++)
        NeedsInitMon(i);

    // Zero-fill wardrobe (no outfits unlocked)
    memset(&gSaveBlock2Ptr->wardrobe, 0, sizeof(struct WardrobeState));

    // Zero-fill quest log (no quests started)
    memset(&gSaveBlock1Ptr->questLog, 0, sizeof(struct QuestLogState));

    // Default Perfect Stats to OFF
    gSaveBlock2Ptr->optionsPerfectStats = 0;
}
```

**Define the version constant** in `src/save.c` (or `include/constants/save.h`):
```c
#define SAVE_VERSION_DAYDREAM_1  2  // increment from current version
```

---

## 4. Save Block Size Budget Check

Before shipping, verify the save block sizes are within GBA limits:

| Block | Vanilla Size | Daydream Addition | New Size | Limit |
|---|---|---|---|---|
| SaveBlock1 | ~0x3??? | +128 bytes (QuestLogState) | check | 0x3D70 |
| SaveBlock2 | 0xF2C | +14 bytes (WardrobeState + 1 byte) | 0xF3A | 0xF2C+free |

**Recommendation:** Free `FREE_MYSTERY_EVENT_BUFFERS`, `FREE_ENIGMA_BERRY`, and `FREE_LINK_BATTLE_RECORDS` in `include/config/save.h` to reclaim ~1244 bytes.
