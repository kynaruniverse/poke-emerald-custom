# Pokémon Daydream Version — Full Integration Manifest: Start Menu

This document provides **exact copy-paste instructions** for modifying `src/start_menu.c` to integrate the new Wardrobe and Journal options into the in-game Start Menu.

---

## 1. `src/start_menu.c` — Add Required Includes

**File:** `src/start_menu.c`

**Line Numbers:** Approximately lines 1-50 (add these near other includes).

**Find this block** (or similar existing includes):
```c
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"
```

**Replace the entire block with this:**
```c
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "wardrobe.h"          // Pokémon Daydream: Wardrobe system
#include "quest_log_custom.h"  // Pokémon Daydream: Quest Log system
```

---

## 2. `src/start_menu.c` — Add new `MENU_ACTION` IDs

**File:** `src/start_menu.c`

**Line Numbers:** Approximately lines 55-72 (inside the `enum MENU_ACTION`).

**Find this block:**
```c
    MENU_ACTION_DEXNAV,
```

**Replace the entire block with this:**
```c
    MENU_ACTION_DEXNAV,
    MENU_ACTION_WARDROBE,    // Pokémon Daydream: Wardrobe menu
    MENU_ACTION_JOURNAL,     // Pokémon Daydream: Quest Journal
```

---

## 3. `src/start_menu.c` — Add new Text Strings

**File:** `src/start_menu.c`

**Line Numbers:** Search for `static const u8 gText_MenuDexNav[]`. Add these new strings nearby.

**Find this block:**
```c
static const u8 gText_MenuDexNav[]   = _("DEXNAV");
```

**Replace the entire block with this:**
```c
static const u8 gText_MenuDexNav[]   = _("DEXNAV");
static const u8 gText_MenuWardrobe[] = _("WARDROBE"); // Pokémon Daydream
static const u8 gText_MenuJournal[]  = _("JOURNAL");  // Pokémon Daydream
```

---

## 4. `src/start_menu.c` — Add Callback Declarations

**File:** `src/start_menu.c`

**Line Numbers:** Approximately lines 99-113 (near other `static bool8 StartMenu...Callback` declarations).

**Find this block:**
```c
static bool8 StartMenuDebugCallback(void);
static bool8 StartMenuDexNavCallback(void);
```

**Replace the entire block with this:**
```c
static bool8 StartMenuDebugCallback(void);
static bool8 StartMenuDexNavCallback(void);
static bool8 StartMenuWardrobeCallback(void); // Pokémon Daydream
static bool8 StartMenuJournalCallback(void);  // Pokémon Daydream
```

---

## 5. `src/start_menu.c` — Add entries to `sStartMenuItems[]`

**File:** `src/start_menu.c`

**Line Numbers:** Search for `static const struct StartMenuItem sStartMenuItems[]`. This is typically around line 130-150.

**Find this block:**
```c
    [MENU_ACTION_DEXNAV]  = {gText_MenuDexNav, {.u8_void = StartMenuDexNavCallback}},
```

**Replace the entire block with this:**
```c
    [MENU_ACTION_DEXNAV]   = {gText_MenuDexNav,   {.u8_void = StartMenuDexNavCallback}},
    [MENU_ACTION_WARDROBE] = {gText_MenuWardrobe, {.u8_void = StartMenuWardrobeCallback}}, // Pokémon Daydream
    [MENU_ACTION_JOURNAL]  = {gText_MenuJournal,  {.u8_void = StartMenuJournalCallback}},  // Pokémon Daydream
```

---

## 6. `src/start_menu.c` — Add to `BuildNormalStartMenu()`

**File:** `src/start_menu.c`

**Line Numbers:** Search for `BuildNormalStartMenu()`. This is typically around line 290-350.

**Find this block:**
```c
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
```

**Replace the entire block with this:**
```c
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_WARDROBE);   // Pokémon Daydream: Wardrobe after BAG
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_JOURNAL);    // Pokémon Daydream: Journal after PLAYER
    AddStartMenuAction(MENU_ACTION_SAVE);
```
