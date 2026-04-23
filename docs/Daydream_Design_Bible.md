# Pokémon Daydream Version — Design Bible

> Full design & implementation plan, v0.1 (Pre-production). Built on
> `pokeemerald-expansion 1.15.1`. The canonical version of this document is
> also committed as `Daydream_Design_Bible.docx` in this folder.

---

## Part 1 — Game Design Bible

### 1.1 High concept & tone

Pokémon Daydream Version is a comedy-forward, slice-of-life full overhaul of
pokeemerald-expansion. The world is open but dangerous: no badge gates, soft
level scaling, and a day-to-day loop about caring for your team — feeding
them, giving them attention, finding shelter — as much as battling. Warm,
weird, self-aware, with a horror-adjacent side arc as counterweight.

**Pillars**

- Comedy first. Every NPC line earns its existence.
- Open but dangerous. Go anywhere; every direction is a real choice.
- Care, not grind. Perfect IV/EV mode removes the chore; Needs adds the heart.
- Discovery over hand-holding.
- Lifestyle layer via Wardrobe + camp + needs.

### 1.2 Region — Reverie

Crescent peninsula, loop-based map. You can circuit the region without ever
passing a gym.

| Town / Route                  | Vibe                                | Anchor                               |
|-------------------------------|-------------------------------------|--------------------------------------|
| Hush Harbor (start)           | Sleepy seaside, foggy mornings      | Player home, Prof. Mim's lab         |
| Route 1 — Yawn Path           | Coastal grass, lazy slopes          | First wild mons, Needs intro         |
| Loafsbury                     | Bakery town, always smells of bread | First Wardrobe shop                  |
| Route 2 — Crumb Trail         | Forest, breadcrumb scatter art      | Optional procgen dungeon entry       |
| Mossreach                     | Overgrown ruins, sage greens        | Horror-arc kickoff NPC               |
| Static City                   | Comedic mega-city, neon             | Quest board hub, Battle Tower-lite   |
| Route 5 — Hum Highway         | Power lines, cicada drone           | Shortcut to north map                |
| Cinderpine                    | Volcanic pine forest                | Camp & shelter tutorial              |
| Glasswake                     | Frozen lake town                    | Late-game evolution triggers         |
| The Hollow                    | Endgame procgen mega-dungeon        | Outsider mons, regional forms        |

### 1.3 Story beats

~20 main quests, 12-textbox cutscene cap, three-act comedic spine: **Wake Up
→ The Region Tries to Quit → Wake Everyone Up.** See full beat list in the
.docx.

### 1.4 Cast

| Character       | Role                  | Notes                                                |
|-----------------|-----------------------|------------------------------------------------------|
| Dream (player)  | Protagonist           | Customizable; canonically chronically tired.         |
| Prof. Mim       | Professor             | Studies dreams & Pokémon sleep states.               |
| Tibb            | Rival                 | Earnest, sleepy, surprisingly competent late-game.   |
| Director Hush   | Antagonist (Team Snooze) | Believes the world deserves a long break.        |
| Champion Vex    | Champion, on strike   | Returns for final battle if convinced.               |
| The Innkeeper   | Recurring NPC         | Sells Bedrolls.                                      |
| Patty           | Loafsbury baker       | Wardrobe & food vendor.                              |

### 1.5 Pokédex plan

Gen 1–9 via expansion, Reverie dex ~250 curated. **8 new evolutions:**

| Base       | New Evo      | Method                            | Type             | Signature                                       |
|------------|--------------|-----------------------------------|------------------|-------------------------------------------------|
| Dunsparce  | Lullsparce   | Lv30 + high friendship at night   | Normal/Psychic   | Ability: Daydream (skip one foe turn at full HP)|
| Stantler   | Stagsomne    | Use Dream Antler                  | Normal/Fairy     | Move: Hush Hooves                                |
| Wobbuffet  | Wobbusnore   | Level up while asleep             | Psychic/Normal   | Ability: Sweet Dreams (+1/16 HP while asleep)    |
| Delcatty   | Delcatnap    | Trade holding Comfy Bedroll       | Normal/Fairy     | Move: Knead                                      |
| Spinda     | Spindream    | Lv36, Needs all maxed             | Normal/Psychic   | Move: Vivid Spin                                 |
| Mr. Mime   | Mr. Mimic    | Level up holding Comedy Mask      | Psychic/Ghost    | Ability: Punchline                               |
| Snorlax    | Snorpine     | Level up in Cinderpine map        | Normal/Grass     | Move: Pine Slumber                               |
| Drampa     | Drampire     | Lv50 in The Hollow                | Dragon/Ghost     | Move: Bedtime Story                              |

---

## Part 2 — Signature systems (summary)

- **2.1 Wardrobe** — 5 cosmetic slots. See `include/wardrobe.h`, `data/wardrobe/outfits.h`.
- **2.2 Needs** — Hunger/Attention/Rest, 0..100. See `include/pokemon_needs.h`, `data/needs/config.h`.
- **2.3 Soft scaling** — `VAR_STORY_TIER`, `ScaleLevel()` in `battle_setup.c`.
- **2.4 Procgen dungeons** — 32×32 tile buffer, ≤8 rooms. See `include/procgen_dungeon.h`.
- **2.5 Quest log** — 4 bits/quest in `SaveBlock1`. See `include/quest_log_custom.h`, `data/quests/quests.h`.
- **2.6 Camp & shelter** — Bedroll field effect + cook submenu.
- **2.7 Trimmed dialog** — See `docs/dialog_style.md`.

---

## Part 3 — Repo & build

```bash
git clone <this repo> daydream
cd daydream
git checkout daydream/main
# Install devkitARM + agbcc per upstream INSTALL.md
make modern -j$(nproc)
```

Branch strategy: `daydream/main` trunk, `daydream/feat/<system>` per system,
`daydream/upstream-merge/<version>` for future RHH merges.

---

## Part 4 — File-by-file changelist

See full table in `Daydream_Design_Bible.docx`. Current scaffolding map:

| System       | Headers                               | Data                         | Src (planned)                      |
|--------------|---------------------------------------|------------------------------|------------------------------------|
| Wardrobe     | `include/wardrobe.h`                  | `data/wardrobe/outfits.h`    | `src/daydream/wardrobe.c` (M3)     |
| Needs        | `include/pokemon_needs.h`             | `data/needs/config.h`        | `src/daydream/pokemon_needs.c` (M4)|
| Quests       | `include/quest_log_custom.h`          | `data/quests/quests.h`       | `src/daydream/quest_log_custom.c` (M5) |
| Procgen      | `include/procgen_dungeon.h`           | —                            | `src/daydream/procgen_dungeon.c` (M6) |
| Camp         | (uses needs + wardrobe headers)       | —                            | `src/daydream/camp.c` (M4)         |
| Soft scaling | (in battle_setup.c patch)             | —                            | `src/daydream/soft_scaling.c` (M8) |

---

## Part 5 — Roadmap

| M  | Goal                                    | Done when                                   |
|----|-----------------------------------------|---------------------------------------------|
| M1 | Fork + build + new title                | ROM boots, title says POKEDAYDREAM          |
| M2 | Region skeleton (3 maps, intro)         | Hush Harbor → Loafsbury → Route 2 walkable  |
| M3 | Wardrobe MVP                            | 2 outfits equip & persist; sprite swaps     |
| M4 | Needs MVP + battle hook                 | Bars decay, items refill, battle delta seen |
| M5 | Quest log + 5 side quests               | Journal, quests advance, rewards give out   |
| M6 | Procgen dungeon prototype               | Differs per entry                           |
| M7 | 8 new evolutions + dex pass             | All 8 triggers work                         |
| M8 | Soft scaling + remove gates             | Walk anywhere; trainer levels scale         |
| M9 | Polish, comedy pass, horror arc         | All cutscenes ≤12 boxes; horror playable    |
| M10| Beta + balance                          | 3+ testers full playthrough                 |

---

## Part 6 — Appendices (highlights)

- **A. Save compat** — Bump `SAVE_VERSION`, zero-fill new fields, default
  Needs to **80** (not 0) on first migration. See stub in `src/daydream/`.
- **B. Config flags to set:** `B_EXP_SHARE_ITEM = GEN_6`, `I_EV_LIMIT_RAISE
  = TRUE`, `P_NEW_EVOS_FROM_GEN_9 = TRUE`, `OW_FOLLOWERS_ENABLED = TRUE`.
- **C. Risks:** Save bloat (pack 3 needs into 1 byte if tight); upstream
  merge conflicts in `start_menu.c`/`party_menu.c` (keep deltas minimal);
  GBA procgen perf (cap rooms, cache per floor).
