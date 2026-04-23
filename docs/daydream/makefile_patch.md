# Pokémon Daydream Version — Makefile Patch Instructions

## 1. ROM Title

**File:** `Makefile`

**Find:**
```makefile
TITLE        ?= POKEMON EMER
```

**Replace with:**
```makefile
TITLE        ?= POKEMON DREAM
```

---

## 2. Game Code

**File:** `Makefile`

**Find:**
```makefile
GAME_CODE    ?= BPEE
```

**Replace with:**
```makefile
GAME_CODE    ?= BPDD
```

---

## 3. New Source Files

Add the following to the `SRCS` list (or equivalent `C_SRCS` variable) in `Makefile`:

```makefile
src/daydream/wardrobe.c \
src/daydream/pokemon_needs.c \
src/daydream/quest_log_custom.c \
src/daydream/procgen_dungeon.c \
src/daydream/soft_scaling.c \
src/daydream/camp.c \
src/daydream/ability_effects.c \
src/daydream/item_use_daydream.c \
```

---

## 4. Include Path

Ensure `include/` is in the include path (it should already be):
```makefile
INCLUDES     := -I include
```

---

## 5. New Constants Headers

The following headers are included transitively via the new `.c` files,
but verify they are reachable:

- `include/constants/species_daydream.h`
- `include/constants/abilities_daydream.h`
- `include/constants/moves_daydream.h`
- `include/constants/items_daydream.h`
- `include/constants/flags_daydream.h`
- `include/constants/vars_daydream.h`

---

## 6. Data Files

The following data headers are included by the source files above.
They do not need separate Makefile entries but must exist at the paths listed:

- `src/data/pokemon/species_info/daydream_evolutions.h`
- `src/data/pokemon/level_up_learnsets/daydream_learnsets.h`
- `src/data/abilities_daydream.h`
- `src/data/moves_info_daydream.h`
- `src/data/items_daydream.h`
- `data/wardrobe/outfits.h`
- `data/quests/quests.h`
- `data/needs/config.h`
