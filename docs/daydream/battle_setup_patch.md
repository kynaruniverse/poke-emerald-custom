# Pokémon Daydream Version — battle_setup.c Patch Instructions

## Overview

Hook `ScaleLevel()` into the trainer party creation so all trainer
Pokémon levels scale softly with story progression (VAR_STORY_TIER).

---

## Step 1: Add include

**File:** `src/battle_setup.c`

Add at the top:
```c
#include "soft_scaling.h"
```

---

## Step 2: Find the party level assignment

**File:** `src/battle_setup.c`

Search for where trainer party levels are assigned. It will look like:
```c
party[i].lvl = trainerMon->lvl;
```
or:
```c
SetMonData(&party[i], MON_DATA_LEVEL, &trainerMon->lvl);
```

---

## Step 3: Apply the scaling hook

**Replace:**
```c
party[i].lvl = trainerMon->lvl;
```

**With:**
```c
party[i].lvl = ScaleLevel(trainerMon->lvl);
```

If `SetMonData` is used:
```c
u8 scaledLevel = ScaleLevel(trainerMon->lvl);
SetMonData(&party[i], MON_DATA_LEVEL, &scaledLevel);
```

---

## Step 4: Advance story tier at gym/boss defeats

In each gym leader / boss defeat script, add:
```
special AdvanceStoryTier
```

Or in C, call `AdvanceStoryTier()` from the post-battle callback.

### Story tier advancement schedule

| Event | Tier |
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

## Step 5: Scaling formula reference

```c
// From src/daydream/soft_scaling.c
u8 ScaleLevel(u8 designerBase)
{
    u16 tier    = VarGet(VAR_STORY_TIER);
    u8  ceiling = 30 + (u8)(tier * 5);

    if (designerBase >= ceiling)
        return designerBase;

    return designerBase + (u8)((ceiling - designerBase) / 3);
}
```

**Examples:**
| Designer Level | Tier 0 | Tier 2 | Tier 5 | Tier 10 |
|---|---|---|---|---|
| 10 | 10 | 13 | 20 | 30 |
| 20 | 20 | 23 | 30 | 40 |
| 50 | 50 | 50 | 50 | 50 |
| 80 | 80 | 80 | 80 | 80 |

Levels at or above the ceiling are never reduced.
