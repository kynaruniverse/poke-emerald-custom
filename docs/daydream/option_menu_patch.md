# Pokémon Daydream Version — Option Menu Patch Instructions

## Overview

Add a **"PERFECT STATS"** toggle to the Options menu.
When ON, every wild and gift Pokémon is generated with 31 IVs and a sensible EV spread.

---

## Step 1: Add new MENUITEM to the enum

**File:** `src/option_menu.c`

**Find:**
```c
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
```

**Replace with:**
```c
    MENUITEM_FRAMETYPE,
    MENUITEM_PERFECT_STATS,   // NEW
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
```

---

## Step 2: Add task data alias

**File:** `src/option_menu.c`

**Find:**
```c
#define tWindowFrameType data[6]
```

**Add after:**
```c
#define tPerfectStats    data[7]
```

---

## Step 3: Add YPOS constant

**File:** `src/option_menu.c`

**Find:**
```c
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)
```

**Add after:**
```c
#define YPOS_PERFECT_STATS (MENUITEM_PERFECT_STATS * 16)
```

---

## Step 4: Add text strings

**File:** `src/option_menu.c`

Add near the other option text strings:
```c
static const u8 gText_PerfectStatsOn[]  = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_PerfectStatsOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
```

---

## Step 5: Add to `sOptionMenuItemsNames[]`

**File:** `src/option_menu.c`

**Find:**
```c
    [MENUITEM_FRAMETYPE]   = COMPOUND_STRING("FRAME"),
    [MENUITEM_CANCEL]      = COMPOUND_STRING("CANCEL"),
```

**Replace with:**
```c
    [MENUITEM_FRAMETYPE]    = COMPOUND_STRING("FRAME"),
    [MENUITEM_PERFECT_STATS]= COMPOUND_STRING("PERFECT STATS"),   // NEW
    [MENUITEM_CANCEL]       = COMPOUND_STRING("CANCEL"),
```

---

## Step 6: Add ProcessInput and DrawChoices functions

**File:** `src/option_menu.c`

Add these two functions:
```c
static u8 PerfectStats_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;
    return selection;
}

static void PerfectStats_DrawChoices(u8 selection)
{
    DrawOptionMenuChoice(selection ? gText_PerfectStatsOn : gText_PerfectStatsOff,
                         176, YPOS_PERFECT_STATS, selection);
}
```

---

## Step 7: Wire into the input/draw switch

**File:** `src/option_menu.c`

In `Task_OptionMenuProcessInput()`, add:
```c
case MENUITEM_PERFECT_STATS:
    gTasks[taskId].tPerfectStats = PerfectStats_ProcessInput(gTasks[taskId].tPerfectStats);
    PerfectStats_DrawChoices(gTasks[taskId].tPerfectStats);
    break;
```

In `DrawOptionMenuTexts()`, add:
```c
PerfectStats_DrawChoices(gTasks[taskId].tPerfectStats);
```

---

## Step 8: Load and save the setting

**File:** `src/option_menu.c`

In the **load** section (where other options are read from SaveBlock2):
```c
gTasks[taskId].tPerfectStats = gSaveBlock2Ptr->optionsPerfectStats;
```

In the **save** section (Task_OptionMenuSave):
```c
gSaveBlock2Ptr->optionsPerfectStats = gTasks[taskId].tPerfectStats;
```

---

## Step 9: Apply in `src/pokemon.c` `CreateMon()`

**File:** `src/pokemon.c`

In `CreateMon()` or `CreateBoxMon()`, after the personality/OT setup:
```c
// Pokémon Daydream: Perfect Stats mode
if (gSaveBlock2Ptr->optionsPerfectStats)
{
    u8 i, iv = 31;
    for (i = 0; i < NUM_STATS; i++)
        SetBoxMonData(&mon->box, MON_DATA_HP_IV + i, &iv);
    // Apply a sensible 252/252/4 EV spread based on species stats
    // TODO: implement per-species EV spread table (see TASKS.md §4.4)
}
```
