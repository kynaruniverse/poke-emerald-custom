# Pokémon Daydream Version — Full Integration Manifest: Makefile

This document provides **exact copy-paste instructions** for modifying the `Makefile` to update the ROM title and integrate all new Daydream source files into the build process.

---

## 1. `Makefile` — Update ROM Title and Game Code

**File:** `Makefile`

**Line Numbers:** Approximately lines 1-4.

**Find this block:**
```makefile
GAME_VERSION ?= EMERALD
TITLE        ?= POKEMON EMER
GAME_CODE    ?= BPEE
BUILD_NAME   ?= emerald
```

**Replace the entire block with this:**
```makefile
GAME_VERSION ?= EMERALD
TITLE        ?= POKEMON DAYDREAM
GAME_CODE    ?= BPED
BUILD_NAME   ?= daydream
```

---

## 2. `Makefile` — Add Daydream Source Files to `C_SOURCES`

**File:** `Makefile`

**Line Numbers:** Search for `C_SOURCES`. This variable lists all `.c` files to be compiled. The exact location will vary, but it's usually around lines 300-400, or in an included `src.mk` file.

**Find this block** (or similar, typically at the end of a `C_SOURCES` list):
```makefile
C_SOURCES += \
	src/util.c \
	src/window.c
```

**Replace the entire block with this:**
```makefile
C_SOURCES += \
	src/util.c \
	src/window.c \
	src/daydream/wardrobe.c \
	src/daydream/pokemon_needs.c \
	src/daydream/quest_log_custom.c \
	src/daydream/procgen_dungeon.c \
	src/daydream/soft_scaling.c \
	src/daydream/camp.c \
	src/daydream/ability_effects.c \
	src/daydream/item_use_daydream.c
```

**Note:** If your `C_SOURCES` list is in a separate file (e.g., `src.mk`), you will need to apply this change there instead of directly in `Makefile`.

---

## 3. `Makefile` — Add Daydream Include Directories

**File:** `Makefile`

**Line Numbers:** Search for `INCLUDE_DIRS`. This variable lists all directories where header files are located. It's usually around line 149.

**Find this block:**
```makefile
INCLUDE_DIRS := include
```

**Replace the entire block with this:**
```makefile
INCLUDE_DIRS := include \
	include/constants \
	include/config \
	include/daydream
```

**Note:** The `include/daydream` directory was created to house the new Daydream-specific header files. This ensures the compiler can find them.
