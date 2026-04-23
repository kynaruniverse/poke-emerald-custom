#ifndef GUARD_PROCGEN_DUNGEON_H
#define GUARD_PROCGEN_DUNGEON_H

// ============================================================
// Pokémon Daydream Version — Procedural Dungeon System
// Room-and-corridor generation on a fixed 32×32 tile buffer.
// Seed = (gameId XOR mapId XOR daySeed) for reproducibility.
// ============================================================

// --------------- Dungeon dimensions ---------------
#define PROC_W          32
#define PROC_H          32
#define MAX_ROOMS       8

// --------------- Tile type IDs ---------------
// These must match the tileset IDs used in the template map.
#define TILE_WALL       0x00
#define TILE_FLOOR      0x01
#define TILE_DOOR       0x02
#define TILE_STAIRS_UP  0x03
#define TILE_STAIRS_DN  0x04
#define TILE_CHEST      0x05

// --------------- Max dungeon floors ---------------
#define PROC_MAX_FLOORS 20

// --------------- Public API ---------------

// Generate a dungeon layout into the internal tile buffer.
// seed: deterministic seed (gameId ^ mapId ^ daySeed).
// Call before warp-in fade from field_screen_effect.c.
void GenerateProcDungeon(u32 seed);

// Blit the generated tile buffer onto the template map layout.
// Must be called after GenerateProcDungeon().
void BlitTilesToMap(void);

// Place wild encounter triggers in floor tiles.
void PlaceEncounterTriggers(void);

// Place the exit warp in the last room.
void PlaceExitWarp(void);

// Place a treasure chest in a random room (not the first or last).
void PlaceChest(void);

// Build the seed for the current dungeon entry.
// Uses gSaveBlock2Ptr->playerTrainerId, current map ID, and RTC day.
u32 BuildDungeonSeed(u8 mapId);

// Increment the current floor counter (VAR_PROCGEN_FLOOR).
void ProcDungeon_DescendFloor(void);

// Reset the floor counter on dungeon exit.
void ProcDungeon_Exit(void);

// Returns the current floor number (1-indexed).
u8 ProcDungeon_GetFloor(void);

#endif // GUARD_PROCGEN_DUNGEON_H
