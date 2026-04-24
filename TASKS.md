# Pokémon Daydream Version — Enhanced Implementation Guide

This document serves as a comprehensive guide for completing the Pokémon Daydream ROM hack. While the core logic and data structures for new systems (Wardrobe, Needs, Quests, Soft Scaling, Procgen Dungeons) have been implemented in the `src/daydream/` directory, several critical components require manual asset creation, UI window programming, and map layout design using external tools like Porymap. This guide provides detailed descriptions and instructions for each outstanding task, ensuring a clear path to a fully realized Pokémon Daydream experience.

---

## 1. Art Assets: Visuals for New Pokémon, Outfits, and Items

This section details the creation of all graphical assets required for the Pokémon Daydream experience. Each asset needs to be designed to fit the existing Pokémon Emerald art style while conveying the unique aesthetic and comedic tone of the Daydream world. All sprites should be 16-color indexed PNGs, adhering to GBA specifications.

### 1.1 Custom Pokémon Sprites (8 New Evolutions)

The 8 new Daydream evolutions currently use placeholder sprites (their base forms). Custom sprites are essential to bring these unique Pokémon to life.

**Task:** Create front, back, shiny, and icon sprites for all 8 new species.

**Detailed Descriptions & Visual Cues:**

*   **Lullsparce (Normal/Psychic):** Evolves from Dunsparce. Imagine a Dunsparce that has fully embraced its sleepy nature. It should be larger, perhaps with more flowing, cloud-like wings or a body that resembles a soft, plush pillow. Its eyes might be half-closed, perpetually drowsy, with subtle psychic energy (perhaps a faint, swirling aura or a third eye motif) emanating from its head or tail. The shiny version could feature pastel blues or purples, enhancing the dream-like quality.
*   **Stagsomne (Normal/Fairy):** Evolves from Stantler. This evolution should emphasize grace and a whimsical, dream-like quality. Stagsomne could have larger, more ornate antlers that appear to be made of polished wood or even crystal, perhaps adorned with small, glowing fairy lights or flowers. Its fur might be softer, with subtle iridescent highlights. Its posture should be elegant and serene, perhaps with a gentle, floating quality. Shiny could be silver/white with blue/pink accents.
*   **Wobbusnore (Psychic/Normal):** Evolves from Wobbuffet. A Wobbuffet that has achieved peak relaxation. Wobbusnore should be significantly larger and rounder, almost like a giant, plush beanbag chair. Its tail might be even more prominent, perhaps with a small, sleepy face on it. It could have a contented, almost comatose expression, with a slight drool or a tiny snore bubble. The shiny version might be a deeper, richer blue or purple.
*   **Delcatnap (Normal/Fairy):** Evolves from Delcatty. This Pokémon should embody ultimate comfort and luxury. Delcatnap could have even fluffier, more elaborate fur, perhaps resembling a silk robe or a cloud. Its tail might be a large, soft cushion, and its ears could be adorned with delicate, dreamcatcher-like elements. Its expression should be one of blissful slumber or serene contentment. Shiny could be a soft gold or cream color.
*   **Spindream (Normal/Psychic):** Evolves from Spinda. Spindream should visually represent a mind lost in a vivid dream. Its spots could swirl and shift, creating an optical illusion, or perhaps glow faintly. Its eyes might be wide and unfocused, gazing into an unseen world. It could have a slightly ethereal or translucent quality, as if it's not entirely present. The shiny version could have inverted or neon-colored spots.
*   **Mr. Mimic (Psychic/Ghost):** Evolves from Mr. Mime. This evolution should lean into the comedic and slightly unsettling aspects of mime. Mr. Mimic could have a more exaggerated, almost cartoonish, yet slightly eerie appearance. Its hands might be larger, emphasizing its miming abilities, and its facial expression could be a frozen, unsettling smile. Ghostly wisps or chains could subtly emanate from its body. Shiny could be a monochrome palette, like an old silent film.
*   **Snorpine (Normal/Grass):** Evolves from Snorlax. A Snorlax that has become one with nature. Snorpine should have moss, small branches, or even tiny pine trees growing on its body, particularly on its belly or back. Its fur could be green or brown, blending with forest elements. It should still look incredibly comfortable and sleepy, perhaps with a small bird or squirrel nesting on its belly. Shiny could have autumn-colored foliage.
*   **Drampire (Dragon/Ghost):** Evolves from Drampa. This evolution should be majestic yet melancholic, embodying ancient wisdom and a touch of spectral sorrow. Drampire could have more elongated, flowing features, with a mane that resembles wisps of smoke or fog. Its eyes might glow with an otherworldly light, and its scales could have a muted, ancient quality. Ghostly chains or ethereal wings could be subtle additions. Shiny could be a dark, regal purple or deep blue.

**Steps for Asset Creation:**
1.  **Design:** Create concept art for each of the 8 evolutions, focusing on their unique characteristics and type combinations.
2.  **Sprite Art:** Draw 64x64 pixel art for each Pokémon:
    *   `front.png`: The sprite displayed when the Pokémon is sent out or in the summary screen.
    *   `back.png`: The sprite displayed when the player's Pokémon is in battle.
    *   `icon.png`: A small 32x32 pixel icon for the party menu and PC.
3.  **Palette Creation:** Create `normal.pal` and `shiny.pal` (16-color palettes) for each Pokémon.
4.  **Footprint:** Design a unique `footprint.png` for each new species.
5.  **Integration:**
    *   Save all `.png` and `.pal` files in `graphics/pokemon/<species_name>/` (e.g., `graphics/pokemon/lullsparce/`).
    *   Update `src/data/pokemon/species_info/daydream_evolutions.h` to point to the new `gMonFrontPic_<Species>`, `gMonBackPic_<Species>`, `gMonPalette_<Species>`, `gMonShinyPalette_<Species>`, `gMonIcon_<Species>`, and `gMonFootprint_<Species>` variables.

**Dependencies:** Aseprite, Photoshop, GIMP, or similar indexed-color image editor. Familiarity with GBA sprite limitations.

### 1.2 Wardrobe Paper-Doll UI Assets

The Wardrobe system allows players to customize their character's appearance. This requires a base player sprite and modular clothing layers.

**Task:** Create a base player sprite and individual clothing layer sprites for the Wardrobe menu.

**Detailed Descriptions & Visual Cues:**

*   **Base Player Sprite:** A neutral, front-facing player character (both male and female versions) in a default underwear/undershirt. This will be the canvas upon which all other outfit pieces are layered. It should be rendered at a size appropriate for a menu display, likely around 64x64 or 80x80 pixels, similar to existing trainer sprites in the summary screen.
*   **Outfit Pieces (Examples):**
    *   **Hats:** `OUTFIT_BAKER_HAT` (a classic white baker's toque), `OUTFIT_SLEEP_CAP` (a striped nightcap with a pom-pom), `OUTFIT_EXPLORER_HAT` (a wide-brimmed safari hat).
    *   **Tops:** `OUTFIT_APRON` (a simple white apron with a small flour stain), `OUTFIT_PAJAMAS_TOP` (a comfy, striped pajama shirt), `OUTFIT_ADVENTURER_VEST` (a utility vest with many pockets).
    *   **Bottoms:** `OUTFIT_PAJAMAS_BOTTOM` (matching striped pajama pants), `OUTFIT_CARGO_SHORTS` (practical shorts for exploration).
    *   **Shoes:** `OUTFIT_SLIPPERS` (fuzzy animal-themed slippers), `OUTFIT_HIKING_BOOTS` (sturdy, worn boots).
    *   **Accessories:** `OUTFIT_EYEMASK` (a simple black sleep mask), `OUTFIT_BACKPACK` (a small, worn backpack).

Each outfit piece should be a separate transparent PNG layer that can be overlaid onto the base player sprite. Ensure consistent sizing and alignment so that all pieces fit together seamlessly.

**Steps for Asset Creation:**
1.  **Base Sprite:** Draw male and female base player sprites.
2.  **Layered Outfits:** For each outfit item defined in `data/wardrobe/outfits.h`, create a separate sprite layer. These layers should only contain the clothing item itself, with transparent backgrounds.
3.  **Integration:**
    *   Save these `.png` files in `graphics/object_events/pics/people/<outfit_name>/`.
    *   The game engine will dynamically combine these layers based on the player's equipped wardrobe.

**Dependencies:** Indexed-color image editor. Understanding of sprite layering and transparency.

### 1.3 Item Icons (9 New Items)

The 9 new Daydream items need unique inventory icons to distinguish them in menus and the bag.

**Task:** Create 24x24 pixel art item icons for the new items.

**Detailed Descriptions & Visual Cues:**

*   **Dream Antler:** A polished, slightly glowing antler, perhaps with a soft, ethereal light around it. (Evolution item for Stantler).
*   **Comedy Mask:** A classic theatrical comedy mask, perhaps with a slightly worn or cracked appearance to hint at its age. (Evolution item for Mr. Mime).
*   **Comfy Bedroll:** A tightly rolled sleeping bag or bedroll, perhaps tied with a ribbon, suggesting comfort. (Evolution item for Delcatty).
*   **Pet Treat:** A small, bone-shaped or star-shaped biscuit, perhaps with a sparkle effect. (Needs consumable).
*   **Big Meal:** A hearty, steaming bowl of stew or a large sandwich, looking very appetizing. (Needs consumable).
*   **Bedroll:** A more rugged, practical rolled-up sleeping bag, suitable for camping. (Camp key item).
*   **Outfit Voucher:** A small, decorative ticket or coupon, perhaps with a clothing icon on it.
*   **Bread Bundle:** A small, tied bundle of freshly baked bread loaves. (Quest item).
*   **Dream Stone:** A smooth, iridescent gemstone that shimmers with soft, shifting colors, like a nebula. (Evolution item/quest reward).

**Steps for Asset Creation:**
1.  **Design:** Create 24x24 pixel art icons for each of the 9 items.
2.  **Integration:**
    *   Save these `.png` files in `graphics/items/`.
    *   Update `src/data/items_daydream.h` to reference the new icon pointers.

**Dependencies:** Indexed-color image editor.

---

## 2. User Interface (UI) Programming

This section outlines the tasks for implementing the graphical user interfaces for the new systems. These UIs need to be intuitive and visually consistent with the existing Pokémon Emerald UI.

### 2.1 Wardrobe Menu Window

The Wardrobe menu currently displays a placeholder text box. It needs a fully functional UI.

**Task:** Build a full-screen UI for the Wardrobe system, accessible from the Start Menu.

**Detailed UI Layout & Functionality:**

*   **Entry Point:** When `MENU_ACTION_WARDROBE` is selected from the Start Menu, a new full-screen window should open.
*   **Layout:** The screen should be divided into two main sections:
    *   **Left Pane (Paper-Doll Preview):** Display the player character (male/female, based on `gSaveBlock2Ptr->playerGender`) using the base player sprite. Overlay the currently equipped outfit pieces dynamically. This pane should update in real-time as the player cycles through options.
    *   **Right Pane (Selection List):** A scrollable list of `OUTFIT_SLOT` categories (Hat, Top, Bottom, Shoes, Accessory). When a slot is selected, a horizontal carousel or sub-menu appears, allowing the player to cycle through all `unlockedBitmap` outfits for that slot.
*   **Interaction:**
    *   **DPAD Up/Down:** Navigate between `OUTFIT_SLOT` categories in the right pane.
    *   **DPAD Left/Right:** Cycle through unlocked outfits within the currently selected slot. The left pane (paper-doll) should update immediately to show the preview.
    *   **A Button:** Confirm selection for a slot, equipping the chosen item. If no item is selected, it might confirm the entire outfit change and close the menu.
    *   **B Button:** Cancel current selection or exit the Wardrobe menu without saving changes.
*   **Data Handling:** The UI must read from and write to `gSaveBlock2Ptr->wardrobe.equipped[]` and check `gSaveBlock2Ptr->wardrobe.unlockedBitmap[]` to determine available options.

**Steps for Implementation:**
1.  **Window Creation:** In `src/daydream/wardrobe.c`, replace the placeholder `Task_OpenWardrobeFromStartMenu` with a function that allocates a new full-screen window using `AddWindow` and sets up the UI elements.
2.  **Sprite Rendering:** Implement logic to draw the base player sprite and dynamically overlay the equipped outfit pieces using `OAM` sprites. This will involve iterating through `gSaveBlock2Ptr->wardrobe.equipped` and drawing the corresponding `graphics/object_events/pics/people/` sprites.
3.  **Menu Logic:** Create the scrolling list for slots and the horizontal carousel for outfit selection. This will likely involve using existing menu functions from `src/menu.c` or creating custom drawing routines.
4.  **Input Handling:** Implement input processing for DPAD and A/B buttons to navigate the menu and update the `wardrobe.equipped` array.
5.  **Save Integration:** Ensure that changes made in the Wardrobe menu are saved to `gSaveBlock2Ptr->wardrobe` when the player exits the menu.

**Dependencies:** `src/window.c`, `src/menu.c`, `src/sprite.c`, `src/event_object_movement.c` (for player sprite rendering logic).

### 2.2 Quest Journal Window

The Journal currently displays a placeholder text box. It needs a functional UI to track quests.

**Task:** Build a full-screen UI for the Quest Log, accessible from the Start Menu.

**Detailed UI Layout & Functionality:**

*   **Entry Point:** When `MENU_ACTION_JOURNAL` is selected from the Start Menu, a new full-screen window should open.
*   **Layout:** The screen should be divided into two main sections:
    *   **Left Pane (Quest List):** A scrollable list displaying all quests defined in `data/quests/quests.h`. Each entry should show the quest name and a status indicator (e.g., 
    *   `Active`, `Completed`, `Failed`).
    *   **Right Pane (Quest Details):** Displays the selected quest's detailed information, including:
        *   Quest Name
        *   Giver Name
        *   Current Step Description (from `stepText` array in `data/quests/quests.h`)
        *   Reward (if applicable)
*   **Interaction:**
    *   **DPAD Up/Down:** Navigate between quests in the left pane.
    *   **A Button:** Select a quest to view its details in the right pane.
    *   **B Button:** Exit the Quest Journal.

**Steps for Implementation:**
1.  **Window Creation:** In `src/daydream/quest_log_custom.c`, replace the placeholder `Task_OpenJournalFromStartMenu` with a function that allocates a new full-screen window and sets up the UI elements.
2.  **Quest List Rendering:** Implement logic to draw the scrollable list of quests in the left pane. This will involve iterating through `sQuests` (from `data/quests/quests.h`) and using `QuestLog_GetState()` to determine and display the status of each quest.
3.  **Quest Detail Rendering:** When a quest is selected, display its name, giver, current step text, and reward in the right pane. Ensure the text wraps correctly within the window boundaries.
4.  **Input Handling:** Implement input processing for DPAD and A/B buttons to navigate the quest list and view details.

**Dependencies:** `src/window.c`, `src/menu.c`.

### 2.3 Needs Simulator UI

The Needs (Hunger, Attention, Rest) are tracked in RAM but are not visible to the player. Integrating this into the Pokémon Summary screen provides crucial feedback.

**Task:** Add a Needs display to the Pokémon Summary screen.

**Detailed UI Layout & Functionality:**

*   **Location:** A new page or a dedicated section on an existing page within the Pokémon Summary screen (e.g., the 
"Care" tab).
*   **Layout:** Three horizontal progress bars (0-100) representing Hunger, Attention, and Rest. Each bar should have a label and a visual indicator of its current state (e.g., color-coded: Green for Thriving, Yellow for Content, Orange for Restless, Red for Suffering).
*   **Interaction:**
    *   **DPAD Left/Right:** Navigate between Pokémon in the party. The Needs display should update to reflect the currently selected Pokémon.
    *   **A Button:** Select a Need to view more details or interact with it (e.g., feed a Pet Treat or Big Meal, play with the Pokémon, or set up camp).
    *   **B Button:** Exit the Needs display or return to the previous screen.

**Steps for Implementation:**
1.  **UI Integration:** Modify `src/pokemon_summary_screen.c` to add a new page or section for the Needs display. This will involve creating new UI elements (progress bars, labels, state indicators) and positioning them correctly on the screen.
2.  **Data Retrieval:** Implement logic to read the current values of Hunger, Attention, and Rest for the selected Pokémon using `GetNeedValue(partyIndex, NEED_HUNGER)`, etc.
3.  **Visual Representation:** Draw the progress bars and state indicators based on the retrieved values. Use `DrawProgressBar` or custom graphics to create the visual representation.
4.  **Interaction Handling:** Implement input processing for DPAD and A/B buttons to navigate between Pokémon and interact with the Needs display.
5.  **Action Integration:** Connect the "Feed," "Play," and "Rest" actions to the corresponding items (Pet Treat, Big Meal, Comfy Bedroll) or interactions (e.g., setting up camp).

**Dependencies:** `src/pokemon_summary_screen.c`, `src/pokemon_needs.c`, `src/item_use.c`.

---

## 3. Map Design & Layouts

This section details the creation of the physical world of Reverie, including towns, routes, and the procedural dungeon template. All map design should be done using Porymap.

### 3.1 Town and Route Maps

The new region of Reverie requires custom maps to bring its unique locations to life.

**Task:** Build the physical world of Daydream using Porymap.

**Detailed Map Descriptions & Visual Cues:**

*   **Hush Harbor (Start Town):** A sleepy, foggy seaside town. The architecture should be quaint and slightly weathered, with cobblestone streets and small, cozy houses. The color palette should feature muted blues, grays, and soft greens. Key locations include the player's home and Prof. Mim's lab (which might look slightly disorganized and filled with dream-related research equipment).
*   **Route 1 (Yawn Path):** A gentle, sloping path with tall, swaying grasses. The environment should feel peaceful and inviting, perhaps with soft, warm lighting. This is where the player encounters their first wild Pokémon and learns about the Needs system.
*   **Loafsbury:** A bustling town known for its bakeries. The air should seem thick with the smell of fresh bread. The architecture could feature warm, earthy tones (browns, oranges, yellows) and perhaps some subtle bakery-themed decorations (e.g., signs shaped like loaves of bread). This is where the player encounters the first Wardrobe shop and the "A Yeasty Errand" quest.
*   **Route 2 (Crumb Trail):** A forest path with scattered breadcrumbs (perhaps a visual motif or actual items to collect). The environment should be slightly more dense and mysterious than Route 1, with dappled sunlight filtering through the trees. This route leads to the first optional procedural dungeon entry.
*   **Mossreach:** Overgrown ruins reclaimed by nature. The architecture should be ancient and crumbling, covered in moss and vines. The color palette should be dominated by deep greens and earthy browns. This location introduces the horror-arc kickoff NPC and has a slightly eerie, quiet atmosphere.
*   **Static City:** A comedic mega-city with neon lights and a slightly chaotic layout. The architecture should be modern and perhaps a bit exaggerated, with towering buildings and bright, flashing signs. This is the hub for the Quest board and a Battle Tower-lite facility.
*   **Route 5 (Hum Highway):** A path running alongside power lines, with a constant, low hum in the background. The environment might be slightly more industrial or barren, with sparse vegetation and a focus on the electrical infrastructure. This route serves as a shortcut into the northern map.
*   **Cinderpine:** A volcanic pine forest. The environment should feature dark, charred earth, towering pine trees, and perhaps occasional small, harmless volcanic vents or ash falls. The color palette should include deep reds, oranges, and blacks. This location serves as the camp and shelter tutorial.
*   **Glasswake:** A frozen lake town. The architecture should be sturdy and insulated, perhaps with ice sculptures or frozen fountains. The color palette should be dominated by icy blues, whites, and pale grays. This location is where late-game evolutions trigger and features the horror-arc midpoint (the lighthouse).
*   **The Hollow:** The endgame procedural mega-dungeon. The entrance should be imposing and mysterious, perhaps a dark cave or a swirling vortex. The interior (generated procedurally) should feel alien and unsettling, with strange architecture and a sense of deep, ancient power. This is where outsider Pokémon and regional forms are found.

**Steps for Map Creation:**
1.  **Porymap Setup:** Open the project in Porymap.
2.  **Map Creation:** For each location listed above, create a new map folder under `data/maps/<MapName>/` (e.g., `data/maps/HushHarbor/`). This folder should contain `header.inc`, `scripts.inc`, `text.inc`, and `map.json`.
3.  **Layout Design:** Create the physical layout for each map under `data/layouts/<LayoutName>/` (e.g., `data/layouts/HushHarbor/`). This includes designing the terrain, placing buildings, and setting up the overall structure. Save the layout data as `border.bin`, `map.bin`, and `layout.json`.
4.  **Tileset Assignment:** Assign appropriate tilesets to each map to achieve the desired visual aesthetic (e.g., foggy seaside for Hush Harbor, dense forest for Cinderpine).
5.  **Object Placement:** Place NPC objects, items, and interactive elements (e.g., signs, doors) on the maps. Assign the corresponding scripts (e.g., `LoafsburyPatty`, `ProfMim_Intro`) to these objects.
6.  **Connections:** Wire the connections between maps in `connections.inc` to ensure seamless transitions between locations.
7.  **Encounters:** Add wild Pokémon encounters for each route and dungeon in `src/data/wild_encounters.json`.

**Dependencies:** Porymap.

### 3.2 Procgen Dungeon Template

The procedural dungeon system requires a blank template map to serve as the canvas for the generated layouts.

**Task:** Create the 32x32 template map for `GenerateProcDungeon()`.

**Detailed Description & Visual Cues:**

*   **Template Map:** A completely blank 32x32 map filled entirely with wall tiles. This map will be dynamically overwritten by the procedural generation algorithm.
*   **Tileset:** The tileset used for this template should contain the necessary tiles for the procedural dungeons (e.g., walls, floors, doors, stairs up, stairs down, chests). The specific visual style of these tiles can vary depending on the dungeon's theme (e.g., ancient ruins, icy caverns, volcanic tunnels).

**Steps for Implementation:**
1.  **Map Creation:** In Porymap, create a new 32x32 map named `ProcDungeon_Template`.
2.  **Fill with Walls:** Fill the entire map with the designated wall tile from the chosen tileset.
3.  **Tile ID Identification:** Note the exact tile IDs used for Wall, Floor, Door, Stairs Up, Stairs Down, and Chest in the chosen tileset.
4.  **Constant Update:** Update the `TILE_*` constants in `include/procgen_dungeon.h` to match the identified tile IDs. This ensures the procedural generation algorithm uses the correct tiles when building the dungeon.

**Dependencies:** Porymap.

---

## 4. Engine Hooks & Integration

This section details the manual code edits required to integrate the new systems into the core Pokémon Emerald engine. These edits are crucial for the systems to function correctly.

### 4.1 Apply Manual Patch Instructions

Several core engine files require manual edits that cannot be safely automated via script without risking syntax errors. Detailed markdown guides have been provided for each necessary patch.

**Task:** Follow the markdown guides in `docs/daydream/` to patch the engine.

**Detailed Instructions:**

1.  **Save Blocks (`global.h`):** Read and apply `docs/daydream/manifest_global_h_save_c.md`. This patch adds the new `WardrobeState`, `NeedsState`, and `QuestLogState` structs to `SaveBlock1` and `SaveBlock2`, ensuring player progress is saved correctly.
2.  **Start Menu (`start_menu.c`):** Read and apply `docs/daydream/manifest_start_menu.md`. This patch adds the "WARDROBE" and "JOURNAL" options to the Start Menu, allowing players to access these new systems.
3.  **Option Menu (`option_menu.c`):** Read and apply `docs/daydream/manifest_option_menu.md`. This patch adds the "Perfect Stats" toggle to the Options menu, allowing players to enable or disable this feature.
4.  **Soft Scaling (`battle_setup.c`):** Read and apply `docs/daydream/manifest_battle_setup.md`. This patch hooks the `ScaleLevel()` function into the trainer party creation logic, ensuring opponent levels scale dynamically based on story progression.
5.  **Needs Decay (`field_control_avatar.c`):** Read and apply `docs/daydream/manifest_field_control_avatar.md`. This patch hooks the `NeedsTickOnStep()` function into the player's movement logic, causing Needs to decay over time as the player explores the world.
6.  **Evolution Methods (`pokemon.c`):** Read and apply `docs/daydream/manifest_pokemon_c_evolution.md`. This patch adds the logic for the 6 new Daydream evolution methods (e.g., `EVO_LEVEL_NIGHT_FRIENDSHIP`, `EVO_LEVEL_SLEEP`) to the `GetEvolutionTargetSpecies()` function.
7.  **Build System (`Makefile`):** Read and apply `docs/daydream/manifest_makefile.md`. This patch updates the ROM title to "POKEMON DAYDREAM" and includes all the new `src/daydream/*.c` files in the compilation process.

**Dependencies:** Text editor, C programming knowledge.

### 4.2 Procgen Dungeon Map Blitting

The `BlitTilesToMap()` function in `src/daydream/procgen_dungeon.c` is currently a stub. It needs to be implemented to write the generated tile buffer to the active map layout.

**Task:** Write the generated tile buffer to the active map layout.

**Detailed Instructions:**

1.  **Access Layout Data:** In `src/daydream/procgen_dungeon.c`, within the `BlitTilesToMap()` function, access the current map's layout data via `gMapHeader.mapLayout->map`.
2.  **Iterate and Overwrite:** Iterate through the 32x32 `sTiles` array (which contains the procedurally generated dungeon layout). For each tile, overwrite the corresponding metatile ID in the layout data (`gMapHeader.mapLayout->map`) with the value from `sTiles`.
3.  **Refresh Screen:** After overwriting the layout data, call `DrawWholeMapView()` to refresh the screen and display the newly generated dungeon layout.

**Dependencies:** C programming knowledge, understanding of the Pokémon Emerald map rendering system.

### 4.3 Needs Simulator Battle Hooks

The Needs system requires hooks in the battle engine to apply damage and accuracy modifiers based on the Pokémon's current Needs state.

**Task:** Apply the Needs modifiers during damage calculation and move execution.

**Detailed Instructions:**

1.  **Damage Calculation:** In `src/battle_util.c` (or `src/pokemon.c`), locate the damage calculation function (e.g., `CalculateBaseDamage`). Wrap the final calculated damage value with a call to `ApplyNeedsDamageModifier(damage, attackerPartyIndex)`. This function (defined in `src/daydream/pokemon_needs.c`) will adjust the damage based on the attacker's Hunger level (e.g., +5% damage if Thriving, -10% damage if Suffering).
2.  **Accuracy Modifier:** In the move execution loop (likely in `src/battle_script_commands.c` or similar), check the attacker's Attention level using `GetNeedState(attacker, NEED_ATTENTION)`. If the state is `NEED_RESTLESS` (or lower), apply a -3% accuracy penalty to the first move used in the battle.
3.  **Turn Skipping (Groggy):** In the turn start loop (likely in `src/battle_main.c` or similar), check if the attacker is groggy using a custom function (e.g., `NeedsIsGroggy(attacker)`). This function should return true if the Pokémon's Rest level is critically low. If true, skip the Pokémon's turn and display a message (e.g., "{Mon} is too groggy to move!").

**Dependencies:** C programming knowledge, understanding of the Pokémon Emerald battle engine.

### 4.4 Perfect Stats EV Spread Table

The Perfect Stats option currently sets IVs to 31 but lacks a sensible EV spread. A per-species EV spread table is needed to provide appropriate stat boosts.

**Task:** Implement a per-species EV spread table for the Perfect Stats toggle.

**Detailed Instructions:**

1.  **Create Header:** Create a new header file `src/data/perfect_ev_spreads.h`.
2.  **Define Table:** Define an array mapping each species ID to a 6-byte EV spread. For example, a physical sweeper might have an EV spread of 252 Attack, 252 Speed, and 4 HP.
    ```c
    // Example structure
    struct PerfectEVSpread {
        u8 hp;
        u8 atk;
        u8 def;
        u8 speed;
        u8 spatk;
        u8 spdef;
    };

    const struct PerfectEVSpread gPerfectEVSpreads[NUM_SPECIES] = {
        [SPECIES_BULBASAUR] = { .hp = 4, .atk = 0, .def = 0, .speed = 252, .spatk = 252, .spdef = 0 },
        // ... entries for all species
    };
    ```
3.  **Apply EVs:** In `src/pokemon.c`, within the `CreateMon()` function, read this table and apply the corresponding EVs if `gSaveBlock2Ptr->optionsPerfectStats` is true. Use `SetMonData()` to set the EV values for the newly created Pokémon.

**Dependencies:** C programming knowledge, understanding of Pokémon stats and competitive EV spreads.

---

## 5. Audio & Music

This section details the creation and integration of custom music tracks to establish the unique atmosphere of the Daydream world.

### 5.1 Custom BGM

The Daydream aesthetic relies heavily on its sleepy, lo-fi, acoustic soundtrack. Custom music is essential to set the tone for the different locations and encounters.

**Task:** Compose and insert custom music tracks.

**Detailed Descriptions & Visual Cues:**

*   **Hush Harbor Theme:** A slow, gentle acoustic guitar melody with soft, atmospheric pads. It should evoke the feeling of waking up on a foggy, peaceful morning.
*   **Loafsbury Theme:** A slightly more upbeat, cheerful tune, perhaps featuring a light piano or accordion melody. It should feel warm and bustling, like a busy bakery.
*   **The Hollow Theme:** A dark, ambient track with low, resonant drones and occasional unsettling, dissonant chords. It should create a sense of unease and ancient mystery.
*   **Battle Theme (Standard):** A more energetic track, but still maintaining the lo-fi, acoustic aesthetic. It shouldn't be overly aggressive or intense, but rather a lively, rhythmic tune.
*   **Battle Theme (Boss/Horror):** A tense, driving track with heavier percussion and perhaps some distorted or reversed elements to heighten the sense of danger and urgency.

**Steps for Implementation:**
1.  **Composition:** Compose the music tracks using a MIDI sequencer or digital audio workstation (DAW). Ensure the compositions adhere to the limitations of the GBA sound engine (e.g., limited channels, specific instrument samples).
2.  **Conversion:** Convert the composed tracks to `.mid` format. Use the `mid2agb` tool (included in the `tools/` directory) to convert the `.mid` files into a format compatible with the Pokémon Emerald sound engine (`.s` assembly files).
3.  **Integration:**
    *   Place the converted `.s` files in the appropriate directory (e.g., `sound/songs/`).
    *   Update `include/constants/songs.h` to define new song IDs for the custom tracks.
    *   Update the map headers (`data/maps/<MapName>/header.inc`) to use the new song IDs for the respective locations.
    *   Update the battle music logic (likely in `src/battle_main.c` or similar) to use the new battle themes.

**Dependencies:** MIDI sequencer/DAW, `mid2agb` tool, understanding of the GBA sound engine.

---

*End of TASKS.md. Once these items are completed, the Pokémon Daydream ROM hack will be fully playable and feature-complete.*
