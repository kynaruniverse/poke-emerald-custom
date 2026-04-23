#ifndef GUARD_PROCGEN_DUNGEON_H
#define GUARD_PROCGEN_DUNGEON_H

// =============================================================================
// Pokémon Daydream Version — Procedural Dungeons
// Design Bible: docs/Daydream_Design_Bible.md §2.4, §4.5
//
// Room-and-corridor generation on entry into a fixed template map.
// Seed = (gameId XOR mapId XOR daySeed). Cap rooms at 8 for GBA perf.
// =============================================================================

#include "global.h"

#define PROC_W           32
#define PROC_H           32
#define PROC_MAX_ROOMS   8

// Tile IDs (indices into the template's primary tileset — tune per tileset).
#define PROC_TILE_WALL   0x001
#define PROC_TILE_FLOOR  0x002
#define PROC_TILE_EXIT   0x003

// ---- Public API --------------------------------------------------------------
void  GenerateProcDungeon(u32 seed);
u32   ProcDungeon_MakeSeed(u16 mapId);    // combines gameId + mapId + day
void  ProcDungeon_OnWarpIn(void);         // field_screen_effect hook

// For unit tests / debug overlay.
u8    ProcDungeon_GetTile(u8 x, u8 y);

#endif // GUARD_PROCGEN_DUNGEON_H
