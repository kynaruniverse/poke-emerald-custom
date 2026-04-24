# Pokémon Daydream Version — Full Integration Manifest: Save Blocks & Save Migration

This document provides **exact copy-paste instructions** for modifying `include/global.h` and `src/save.c` to integrate the new Daydream save data structures and implement save migration.

---

## 1. `include/global.h` — Add `WardrobeState` to `struct SaveBlock2`

**File:** `include/global.h`

**Line Numbers:** Approximately lines 584-622 (may vary slightly based on your fork).

**Find this block:**
```c
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
}; // sizeof=0xF2C
```

**Replace the entire block with this:**
```c
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
    // Pokémon Daydream additions
    struct WardrobeState wardrobe;      // 13 bytes: 5 equipped + 8 bitmap
    u8 optionsPerfectStats:1;           // 1 bit: Perfect IVs/EVs toggle
    u8 saveBlockPadding:7;              // padding to align to byte
}; // sizeof updated
```

**Required includes** at top of `global.h` (add if not present, typically around line 20-30):
```c
#include "wardrobe.h"
```

---

## 2. `include/global.h` — Add `QuestLogState` to `struct SaveBlock1`

**File:** `include/global.h`

**Line Numbers:** Approximately lines 1091-1209 (may vary slightly based on your fork).

**Find this block** (near the end of `struct SaveBlock1`, before the closing `};`):
```c
    /*0x3???*/ struct WaldaPhrase waldaPhrase;
```

**Replace the entire block with this:**
```c
    /*0x3???*/ struct WaldaPhrase waldaPhrase;
    // Pokémon Daydream additions
    struct QuestLogState questLog;      // 128 bytes: 4 bits × 256 quests
```

**Required includes** at top of `global.h` (add if not present, typically around line 20-30):
```c
#include "quest_log_custom.h"
```

---

## 3. `src/save.c` — Define `SAVE_VERSION_DAYDREAM_1`

**File:** `src/save.c`

**Line Numbers:** Search for `SAVE_VERSION_1` or similar version definitions.

**Find this block:**
```c
#define SAVE_VERSION_1  1
```

**Replace the entire block with this:**
```c
#define SAVE_VERSION_1           1
#define SAVE_VERSION_DAYDREAM_1  2  // Increment from current version
```

---

## 4. `src/save.c` — Implement Save Migration

**File:** `src/save.c`

**Line Numbers:** Search for `LoadSaveBlock2()` or `TryLoadSaveFile()` and locate the section where `gSaveBlock2Ptr` is initialized or migrated. This is typically after a version check.

**Find this block** (inside `TryLoadSaveFile()` or a similar save loading function, after existing version checks):
```c
    // If loading a save from before the current version, initialise new fields.
    if (loadedSaveVersion < SAVE_VERSION_1)
    {
        // ... existing migration code ...
    }
```

**Add this block immediately after the existing migration `if` statement:**
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

**Required includes** at top of `src/save.c` (add if not present):
```c
#include "pokemon_needs.h"
#include "wardrobe.h"
#include "quest_log_custom.h"
```

---

## 5. `include/config/save.h` — Free up Save Space

**File:** `include/config/save.h`

**Line Numbers:** Locate the `FREE_` defines.

**Find this block:**
```c
#define FREE_MYSTERY_EVENT_BUFFERS  FALSE
#define FREE_ENIGMA_BERRY           FALSE
#define FREE_LINK_BATTLE_RECORDS    FALSE
```

**Replace the entire block with this:**
```c
#define FREE_MYSTERY_EVENT_BUFFERS  TRUE   // Frees 1104 bytes
#define FREE_ENIGMA_BERRY           TRUE   // Frees 52 bytes
#define FREE_LINK_BATTLE_RECORDS    TRUE   // Frees 88 bytes
```

This frees approximately 1244 bytes, which is sufficient for the new `WardrobeState` (13 bytes) and `QuestLogState` (128 bytes) and provides room for future expansion.
