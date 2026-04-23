# src/daydream/

This directory is the home of all Daydream-specific C source files, kept
**separate from upstream pokeemerald-expansion files wherever possible** so
that future RHH merges (1.16+) stay painless.

## Files planned

| File                          | Milestone | Purpose                                             |
|-------------------------------|-----------|-----------------------------------------------------|
| `wardrobe.c`                  | M3        | State, sprite swap, save hooks, carousel UI.        |
| `pokemon_needs.c`             | M4        | Decay tick, fill fns, battle modifier hooks.        |
| `quest_log_custom.c`          | M5        | State machine, journal UI, script helpers.          |
| `procgen_dungeon.c`           | M6        | Room/corridor generator + blitter.                  |
| `camp.c`                      | M4        | Bedroll field effect, cook submenu.                 |
| `soft_scaling.c`              | M8        | `ScaleLevel()` helper used by `battle_setup.c`.     |
| `daydream_init.c`             | M1        | Boot-time init hook for all Daydream systems.       |

## Touch-with-care (upstream) files

These are unavoidable hooks; keep the delta minimal and comment `// Daydream:`.

- `src/start_menu.c`         — insert WARDROBE, JOURNAL actions
- `src/party_menu.c`         — insert Care tab (needs bars + Pet/Feed/Rest)
- `src/overworld.c`          — call `NeedsTickOnStep()`
- `src/battle_main.c`        — call `NeedsTickOnBattleEnd()`
- `src/battle_util.c`        — needs damage / accuracy / crit / skip hooks
- `src/battle_setup.c`       — wrap trainer levels with `ScaleLevel()`
- `src/pokemon.c`            — init needs in `CreateBoxMon`, perfect-stats option
- `src/load_save.c`          — save-version migration for needs + wardrobe
- `src/event_object_movement.c` — outfit-driven player gfx selection
- `src/item_use.c`           — `ItemUseOutOfBattle_Bedroll()`
- `src/option_menu.c`        — Perfect IV/EV toggle
- `include/global.h`         — embed WardrobeState, QuestLogState, save version bump
- `include/pokemon.h`        — add `hunger`, `attention`, `rest` to BoxPokemon

## Style conventions

- New flags: `FLAG_DAYDREAM_*` in a dedicated block in `include/constants/flags.h`.
- New vars:  `VAR_DAYDREAM_*` (plus `VAR_STORY_TIER`).
- All text: `COMPOUND_STRING(...)` for inline.
- Do not add `#include` paths outside `include/`, `data/`, or `src/daydream/`
  unless strictly necessary.
