#ifndef GUARD_CONSTANTS_VARS_DAYDREAM_H
#define GUARD_CONSTANTS_VARS_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — Custom Variable Definitions
// Uses VAR_UNUSED_0x40FD–0x40FF (3 free slots in vanilla).
// For more vars, reclaim unused vanilla vars or use scripted
// vars in the 0x8000+ range for temporary quest state.
// ============================================================

// VAR_STORY_TIER (0x40FD)
// Tracks overall story progression. Range: 0–10.
// Tier 0 = fresh start; Tier 10 = post-credits.
// Used by ScaleLevel() in battle_setup.c for soft scaling.
#define VAR_STORY_TIER              0x40FD

// VAR_PROCGEN_FLOOR (0x40FE)
// Tracks the current floor depth inside a procgen dungeon.
// Reset to 0 on dungeon exit. Used by quest QUEST_PROCGEN_DEPTH.
#define VAR_PROCGEN_FLOOR           0x40FE

// VAR_QUEST_TEMP (0x40FF)
// General-purpose temporary quest variable.
// Reused across quests; only valid during a single quest step.
#define VAR_QUEST_TEMP              0x40FF

// Scripted vars (0x8000 range) for quest state machines
// These are volatile and not saved; use flags for persistence.
#define VAR_QUEST_RESULT            VAR_0x8000  // QSTATE_* value
#define VAR_ACTIVE_QUEST_ID         VAR_0x8001  // current quest being started
#define VAR_NEEDS_DISPLAY_MON       VAR_0x8002  // party index for needs UI

#endif // GUARD_CONSTANTS_VARS_DAYDREAM_H
