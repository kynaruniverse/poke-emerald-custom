# Pokémon Daydream — Changelog

All Daydream-specific changes live here, on top of the base fork of
`pokeemerald-expansion 1.15.1` (see `README.md`).

## [Unreleased]

### M1 — Fork + Branding (this commit)

- Branched off `master` → `daydream/main`.
- ROM header `TITLE` → `POKEDAYDREAM` (12 chars, GBA-header-safe).
- `GAME_CODE` kept at `BPEE` for now to preserve save/patch compatibility;
  will revisit if a unique save identity becomes desirable.
- Scaffolding for all signature systems added:
  - `include/wardrobe.h`
  - `include/pokemon_needs.h`
  - `include/quest_log_custom.h`
  - `include/procgen_dungeon.h`
  - `data/wardrobe/outfits.h`
  - `data/quests/quests.h`
  - `data/needs/config.h`
  - `src/daydream/daydream_init.c` (stub)
  - `src/daydream/README.md` (conventions)
- Docs:
  - `docs/Daydream_Design_Bible.md` (full design doc committed for team reference)
  - `docs/dialog_style.md` (comedy-pass conventions)

### Known gaps / next up

- **M2** — Region skeleton: 3 maps (Hush Harbor, Loafsbury, Route 2), opening
  scripts rewritten per `docs/dialog_style.md`.
- **M3** — Wardrobe MVP: implement `src/daydream/wardrobe.c`, start menu hook,
  save-block embed, paper-doll carousel UI, 2 outfit arts.
- Title-screen PNG rebrand (`graphics/title_screen/pokemon_logo.png`) is
  intentionally deferred to an art pass — the ROM will currently display the
  default logo but announce itself as `POKEDAYDREAM` in emulator menus.

## Build status (M1)

This environment does not ship devkitARM/agbcc. The scaffolding compiles
against the upstream headers cleanly as `.h` additions (no existing files
modified beyond `Makefile`). Local verification after pulling:

```bash
make -j$(nproc)          # classic
make modern -j$(nproc)   # modern gcc (recommended)
```
