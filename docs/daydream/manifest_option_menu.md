# Pokémon Daydream Version — Full Integration Manifest: Option Menu

This document provides **exact copy-paste instructions** for modifying `src/option_menu.c` to integrate the new "PERFECT STATS" toggle into the in-game Options menu.

---

## 1. `src/option_menu.c` — Add task data alias

**File:** `src/option_menu.c`

**Line Numbers:** Approximately lines 19-25 (near other `tMenuSelection` aliases).

**Find this block:**
```c
#define tWindowFrameType data[6]
```

**Replace the entire block with this:**
```c
#define tWindowFrameType data[6]
#define tPerfectStats    data[7] // Pokémon Daydream: Perfect IVs/EVs toggle
```

---

## 2. `src/option_menu.c` — Add new `MENUITEM` ID to the enum

**File:** `src/option_menu.c`

**Line Numbers:** Approximately lines 27-37 (inside the `enum`).

**Find this block:**
```c
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
```

**Replace the entire block with this:**
```c
    MENUITEM_FRAMETYPE,
    MENUITEM_PERFECT_STATS,   // Pokémon Daydream: Perfect IVs/EVs toggle
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
```

---

## 3. `src/option_menu.c` — Add YPOS constant

**File:** `src/option_menu.c`

**Line Numbers:** Approximately lines 45-50 (near other `YPOS_` constants).

**Find this block:**
```c
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)
```

**Replace the entire block with this:**
```c
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)
#define YPOS_PERFECT_STATS (MENUITEM_PERFECT_STATS * 16) // Pokémon Daydream
```

---

## 4. `src/option_menu.c` — Add new text strings

**File:** `src/option_menu.c`

**Line Numbers:** Approximately lines 75-89 (near other `gText_` strings).

**Find this block:**
```c
static const u8 gText_ButtonTypeNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
static const u8 gText_ButtonTypeLR[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
static const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
```

**Replace the entire block with this:**
```c
static const u8 gText_ButtonTypeNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
static const u8 gText_ButtonTypeLR[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
static const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
static const u8 gText_PerfectStatsOn[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");    // Pokémon Daydream
static const u8 gText_PerfectStatsOff[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");   // Pokémon Daydream
```

---

## 5. `src/option_menu.c` — Add entry to `sOptionMenuItemsNames[]`

**File:** `src/option_menu.c`

**Line Numbers:** Approximately lines 95-104 (inside `sOptionMenuItemsNames`).

**Find this block:**
```c
    [MENUITEM_FRAMETYPE]   = COMPOUND_STRING("FRAME"),
    [MENUITEM_CANCEL]      = COMPOUND_STRING("CANCEL"),
```

**Replace the entire block with this:**
```c
    [MENUITEM_FRAMETYPE]    = COMPOUND_STRING("FRAME"),
    [MENUITEM_PERFECT_STATS]= COMPOUND_STRING("PERFECT STATS"),   // Pokémon Daydream
    [MENUITEM_CANCEL]       = COMPOUND_STRING("CANCEL"),
```

---

## 6. `src/option_menu.c` — Add ProcessInput and DrawChoices functions

**File:** `src/option_menu.c`

**Line Numbers:** Add these two new functions after `static void ButtonMode_DrawChoices(u8 selection);` (approximately line 68).

**Add this block:**
```c
// Pokémon Daydream: Perfect Stats toggle
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

## 7. `src/option_menu.c` — Wire into `Task_OptionMenuProcessInput()`

**File:** `src/option_menu.c`

**Line Numbers:** Search for `Task_OptionMenuProcessInput()`. This is typically around line 300-400, inside the `switch (gTasks[taskId].tMenuSelection)` statement.

**Find this block:**
```c
        case MENUITEM_FRAMETYPE:
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);
            FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
            break;
```

**Replace the entire block with this:**
```c
        case MENUITEM_FRAMETYPE:
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);
            FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
            break;
        case MENUITEM_PERFECT_STATS: // Pokémon Daydream
            gTasks[taskId].tPerfectStats = PerfectStats_ProcessInput(gTasks[taskId].tPerfectStats);
            PerfectStats_DrawChoices(gTasks[taskId].tPerfectStats);
            break;
```

---

## 8. `src/option_menu.c` — Wire into `DrawOptionMenuTexts()`

**File:** `src/option_menu.c`

**Line Numbers:** Search for `DrawOptionMenuTexts()`. This is typically around line 260-280.

**Find this block:**
```c
    FrameType_DrawChoices(gSaveBlock2Ptr->optionsWindowFrameType);
```

**Replace the entire block with this:**
```c
    FrameType_DrawChoices(gSaveBlock2Ptr->optionsWindowFrameType);
    PerfectStats_DrawChoices(gSaveBlock2Ptr->optionsPerfectStats); // Pokémon Daydream
```

---

## 9. `src/option_menu.c` — Load the setting in `CB2_InitOptionMenu()`

**File:** `src/option_menu.c`

**Line Numbers:** Search for `CB2_InitOptionMenu()`. This is typically around line 240-252, inside `case 10:`.

**Find this block:**
```c
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
```

**Replace the entire block with this:**
```c
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tPerfectStats = gSaveBlock2Ptr->optionsPerfectStats; // Pokémon Daydream
```

---

## 10. `src/option_menu.c` — Save the setting in `Task_OptionMenuSave()`

**File:** `src/option_menu.c`

**Line Numbers:** Search for `Task_OptionMenuSave()`. This is typically around line 450-460.

**Find this block:**
```c
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
```

**Replace the entire block with this:**
```c
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
    gSaveBlock2Ptr->optionsPerfectStats = gTasks[taskId].tPerfectStats; // Pokémon Daydream
```
