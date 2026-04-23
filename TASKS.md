# Pokémon Daydream Version — Outstanding Tasks

This document outlines all remaining work required to complete the Pokémon Daydream ROM hack. The core logic and data structures have been implemented in the `src/daydream/` directory, but several components require manual asset creation, UI window programming, or map layout design using external tools like Porymap.

---

## 1. Art Assets

### 1.1 Custom Pokémon Sprites
The 8 new Daydream evolutions currently use placeholder sprites (their base forms).
- **Description:** Create front, back, shiny, and icon sprites for all 8 new species.
- **Steps:**
  1. Draw 64x64 indexed (16-colour) sprites for: Lullsparce, Stagsomne, Wobbusnore, Delcatnap, Spindream, Mr. Mimic, Snorpine, Drampire.
  2. Save as `.png` files in `graphics/pokemon/<species>/`.
  3. Update `src/data/pokemon/species_info/daydream_evolutions.h` to point to the new `gMonFrontPic_<Species>` variables.
- **Dependencies:** Aseprite or similar indexed-colour image editor.

### 1.2 Wardrobe Paper-Doll UI Assets
The Wardrobe system requires a visual representation of the player character with modular clothing layers.
- **Description:** Create a base player sprite and individual clothing layer sprites for the Wardrobe menu.
- **Steps:**
  1. Draw a base character sprite (front-facing, menu size).
  2. Draw separate transparent `.png` layers for each outfit piece defined in `data/wardrobe/outfits.h` (Hats, Tops, Bottoms, Shoes, Accessories).
  3. Ensure all layers align perfectly with the base sprite.
- **Dependencies:** Indexed-colour image editor.

### 1.3 Item Icons
The 9 new Daydream items need inventory icons.
- **Description:** Create 24x24 item icons for the new items.
- **Steps:**
  1. Draw icons for: Dream Antler, Comedy Mask, Comfy Bedroll, Pet Treat, Big Meal, Bedroll, Outfit Voucher, Bread Bundle, Dream Stone.
  2. Save as `.png` in `graphics/items/`.
  3. Update `src/data/items_daydream.h` to reference the new icon pointers.

---

## 2. User Interface (UI) Programming

### 2.1 Wardrobe Menu Window
The Wardrobe menu currently displays a placeholder text box.
- **Description:** Build a full-screen UI for the Wardrobe system.
- **Steps:**
  1. In `src/daydream/wardrobe.c`, replace `Task_OpenWardrobeFromStartMenu` with a function that allocates a new window (`AddWindow`).
  2. Draw the base player sprite and overlay the currently equipped outfit layers using `OAM` sprites.
  3. Create a scrolling list menu on the right side to select slots (Hat, Top, etc.) and cycle through unlocked outfits (checking `Wardrobe_IsUnlocked`).
  4. Update `WardrobeState` when the player confirms a selection.
- **Dependencies:** `src/window.c`, `src/menu.c`, `src/sprite.c`.

### 2.2 Quest Journal Window
The Journal currently displays a placeholder text box with the active quest count.
- **Description:** Build a full-screen UI for the Quest Log.
- **Steps:**
  1. In `src/daydream/quest_log_custom.c`, replace `Task_OpenJournalFromStartMenu` with a window allocation function.
  2. Create a two-pane layout: left pane lists active/completed quests, right pane shows the current step text.
  3. Iterate through `sQuestDefs` and check `QuestLog_GetState()` to populate the list.
  4. Display the appropriate `stepText` string based on the current state.
- **Dependencies:** `src/window.c`, `src/menu.c`.

### 2.3 Needs Simulator UI
The Needs (Hunger, Attention, Rest) are tracked in RAM but not visible to the player.
- **Description:** Add a Needs display to the Pokémon Summary screen.
- **Steps:**
  1. Modify `src/pokemon_summary_screen.c`.
  2. Add a new page or overlay that reads `GetNeedValue(partyIndex, NEED_HUNGER)` etc.
  3. Draw three progress bars (0-100) using `DrawProgressBar` or custom graphics.
  4. Display the current state text (Thriving, Content, Restless, Suffering) based on `GetNeedState()`.

---

## 3. Map Design & Layouts

### 3.1 Town and Route Maps
The new region of Reverie requires custom maps.
- **Description:** Build the physical world of Daydream using Porymap.
- **Steps:**
  1. Open the project in Porymap.
  2. Design the following maps: Hush Harbor, Route 1 (Yawn Path), Loafsbury, Route 2 (Crumb Trail), Mossreach, Static City, Route 5 (Hum Highway), Cinderpine, Glasswake, The Hollow.
  3. Assign appropriate tilesets (e.g., foggy seaside for Hush Harbor, dense forest for Cinderpine).
  4. Place NPC objects and assign their scripts (e.g., `LoafsburyPatty`, `ProfMim_Intro`).
- **Dependencies:** Porymap.

### 3.2 Procgen Dungeon Template
The procedural dungeon system requires a blank template map.
- **Description:** Create the 32x32 template map for `GenerateProcDungeon()`.
- **Steps:**
  1. In Porymap, create a 32x32 map named `ProcDungeon_Template`.
  2. Fill it entirely with wall tiles.
  3. Note the exact tile IDs used for Wall, Floor, Door, Stairs Up, Stairs Down, and Chest.
  4. Update the `TILE_*` constants in `include/procgen_dungeon.h` to match these IDs.

---

## 4. Engine Hooks & Integration

### 4.1 Apply Manual Patch Instructions
Several core engine files require manual edits that cannot be safely automated via script without risking syntax errors.
- **Description:** Follow the markdown guides in `docs/daydream/` to patch the engine.
- **Steps:**
  1. Read and apply `docs/daydream/global_h_patch.md` to add the new save structs.
  2. Read and apply `docs/daydream/start_menu_patch.md` to add Wardrobe and Journal to the start menu.
  3. Read and apply `docs/daydream/option_menu_patch.md` to add the Perfect Stats toggle.
  4. Read and apply `docs/daydream/battle_setup_patch.md` to hook the soft scaling system.
  5. Read and apply `docs/daydream/field_control_avatar_patch.md` to hook the Needs step decay.
  6. Read and apply `docs/daydream/evolution_patch.md` to add the new evolution methods.
  7. Read and apply `docs/daydream/makefile_patch.md` to compile the new source files.

### 4.2 Procgen Dungeon Map Blitting
The `BlitTilesToMap()` function in `src/daydream/procgen_dungeon.c` is currently a stub.
- **Description:** Write the generated tile buffer to the active map layout.
- **Steps:**
  1. Access the current map's layout data via `gMapHeader.mapLayout->map`.
  2. Iterate through the 32x32 `sTiles` array.
  3. Overwrite the layout data with the corresponding metatile IDs.
  4. Call `DrawWholeMapView()` to refresh the screen.

### 4.3 Needs Simulator Battle Hooks
The Needs system requires hooks in the battle engine to apply damage and accuracy modifiers.
- **Description:** Apply the Needs modifiers during damage calculation and move execution.
- **Steps:**
  1. In `src/battle_util.c` (or `src/pokemon.c`), find the damage calculation function.
  2. Wrap the final damage value with `ApplyNeedsDamageModifier(damage, attackerPartyIndex)`.
  3. In the move execution loop, check `GetNeedState(attacker, NEED_ATTENTION)`. If `NEED_RESTLESS`, apply a -3% accuracy penalty to the first move.
  4. In the turn start loop, check `NeedsIsGroggy(attacker)`. If true, skip the turn and display a message ("{Mon} is too groggy to move!").

### 4.4 Perfect Stats EV Spread Table
The Perfect Stats option currently sets IVs to 31 but lacks a sensible EV spread.
- **Description:** Implement a per-species EV spread table for the Perfect Stats toggle.
- **Steps:**
  1. Create a new header `src/data/perfect_ev_spreads.h`.
  2. Define an array mapping each species ID to a 6-byte EV spread (e.g., 252 Atk / 252 Spe / 4 HP for physical sweepers).
  3. In `src/pokemon.c` `CreateMon()`, read this table and apply the EVs if `gSaveBlock2Ptr->optionsPerfectStats` is true.

---

## 5. Audio & Music

### 5.1 Custom BGM
The Daydream aesthetic relies heavily on its sleepy, lo-fi, acoustic soundtrack.
- **Description:** Compose and insert custom music tracks.
- **Steps:**
  1. Compose tracks for Hush Harbor, Loafsbury, The Hollow, and the Battle themes.
  2. Convert to `.mid` and insert using the `mid2agb` tool.
  3. Update `include/constants/songs.h` and the map headers to use the new tracks.
- **Dependencies:** MIDI sequencer, `mid2agb`.

---

*End of TASKS.md. Once these items are completed, the Pokémon Daydream ROM hack will be fully playable and feature-complete.*
