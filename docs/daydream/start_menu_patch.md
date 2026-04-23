# Pokémon Daydream Version — Start Menu Patch Instructions

## Overview

Two new entries must be added to the Start Menu:
- **WARDROBE** — between BAG and PLAYER
- **JOURNAL** — between PLAYER and SAVE

These are **manual edits** to `src/start_menu.c`.

---

## Step 1: Add new MENU_ACTION IDs to the enum

**File:** `src/start_menu.c`

**Find:**
```c
    MENU_ACTION_DEXNAV,
```

**Add after it:**
```c
    MENU_ACTION_WARDROBE,
    MENU_ACTION_JOURNAL,
```

---

## Step 2: Add new text strings

**File:** `src/start_menu.c` (or `src/strings.c` / `include/strings.h`)

Add:
```c
static const u8 gText_MenuWardrobe[] = _("WARDROBE");
static const u8 gText_MenuJournal[]  = _("JOURNAL");
```

---

## Step 3: Add entries to `sStartMenuItems[]`

**File:** `src/start_menu.c`

**Find:**
```c
    [MENU_ACTION_DEXNAV]  = {gText_MenuDexNav, {.u8_void = StartMenuDexNavCallback}},
```

**Add after it:**
```c
    [MENU_ACTION_WARDROBE] = {gText_MenuWardrobe, {.u8_void = StartMenuWardrobeCallback}},
    [MENU_ACTION_JOURNAL]  = {gText_MenuJournal,  {.u8_void = StartMenuJournalCallback}},
```

---

## Step 4: Add to `BuildNormalStartMenu()`

**File:** `src/start_menu.c`

**Find:**
```c
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
```

**Replace with:**
```c
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_WARDROBE);   // NEW: Wardrobe after BAG
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_JOURNAL);    // NEW: Journal after PLAYER
    AddStartMenuAction(MENU_ACTION_SAVE);
```

---

## Step 5: Add includes

**File:** `src/start_menu.c`

Add at the top:
```c
#include "wardrobe.h"
#include "quest_log_custom.h"
```

---

## Step 6: Callback declarations

The callbacks `StartMenuWardrobeCallback()` and `StartMenuJournalCallback()` are
already defined in:
- `src/daydream/wardrobe.c`
- `src/daydream/quest_log_custom.c`

Add forward declarations in `src/start_menu.c` if needed:
```c
static bool8 StartMenuWardrobeCallback(void);
static bool8 StartMenuJournalCallback(void);
```
