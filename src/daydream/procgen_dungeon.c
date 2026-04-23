// ============================================================
// Pokémon Daydream Version — Procedural Dungeon Implementation
// src/daydream/procgen_dungeon.c
// ============================================================

#include "global.h"
#include "procgen_dungeon.h"
#include "random.h"
#include "script.h"
#include "vars.h"
#include "constants/vars_daydream.h"
#include "constants/flags_daydream.h"

// ---- Internal tile buffer ----
static u8 sTiles[PROC_H][PROC_W];

// ---- Room centre tracking ----
static u8 sCx[MAX_ROOMS];
static u8 sCy[MAX_ROOMS];
static u8 sRoomCount;

// ---- Internal helpers ----

static void CarveRoom(u8 x, u8 y, u8 w, u8 h)
{
    u8 yy, xx;
    for (yy = y; yy < y + h && yy < PROC_H; yy++)
        for (xx = x; xx < x + w && xx < PROC_W; xx++)
            sTiles[yy][xx] = TILE_FLOOR;
}

static void CarveCorridor(u8 x1, u8 y1, u8 x2, u8 y2)
{
    // Horizontal then vertical L-shaped corridor
    while (x1 != x2)
    {
        if (x1 < PROC_W) sTiles[y1][x1] = TILE_FLOOR;
        x1 += (x2 > x1) ? 1 : -1;
    }
    while (y1 != y2)
    {
        if (y1 < PROC_H) sTiles[y1][x1] = TILE_FLOOR;
        y1 += (y2 > y1) ? 1 : -1;
    }
}

// ---- Public API ----

u32 BuildDungeonSeed(u8 mapId)
{
    u32 gameId = *(u32 *)gSaveBlock2Ptr->playerTrainerId;
    // Use a simple day counter from play time as the day seed
    u32 daySeed = (u32)gSaveBlock2Ptr->playTimeHours / 24;
    return gameId ^ ((u32)mapId << 16) ^ daySeed;
}

void GenerateProcDungeon(u32 seed)
{
    u8 i;
    SeedRng2(seed);
    memset(sTiles, TILE_WALL, sizeof(sTiles));
    sRoomCount = 0;

    for (i = 0; i < MAX_ROOMS; i++)
    {
        u8 w = 4 + (Random2() % 5);   // 4–8 tiles wide
        u8 h = 4 + (Random2() % 4);   // 4–7 tiles tall
        u8 x = 1 + (Random2() % (PROC_W - w - 2));
        u8 y = 1 + (Random2() % (PROC_H - h - 2));

        CarveRoom(x, y, w, h);
        sCx[i] = x + w / 2;
        sCy[i] = y + h / 2;

        if (i > 0)
            CarveCorridor(sCx[i - 1], sCy[i - 1], sCx[i], sCy[i]);

        sRoomCount++;
    }

    // Mark entry in first room centre
    sTiles[sCy[0]][sCx[0]] = TILE_STAIRS_UP;
    // Mark exit in last room centre
    sTiles[sCy[MAX_ROOMS - 1]][sCx[MAX_ROOMS - 1]] = TILE_STAIRS_DN;
}

void BlitTilesToMap(void)
{
    // TODO: Write sTiles into the template map's layout buffer.
    // This requires access to the map layout API (gMapHeader.layout).
    // See TASKS.md §4.5 for full implementation steps.
    // Placeholder: no-op until map layout blitting is wired up.
    (void)sTiles;
}

void PlaceEncounterTriggers(void)
{
    // TODO: Place coord-event triggers on TILE_FLOOR tiles in rooms 2–7.
    // Each trigger should call the procgen wild encounter table.
    // See TASKS.md §4.5.
}

void PlaceExitWarp(void)
{
    // The exit warp is already placed as TILE_STAIRS_DN in GenerateProcDungeon.
    // TODO: Wire the TILE_STAIRS_DN tile to a warp event that calls
    // ProcDungeon_DescendFloor() and re-generates the next floor.
    // See TASKS.md §4.5.
}

void PlaceChest(void)
{
    // Place a chest in a random middle room (not first or last).
    u8 roomIdx;
    if (sRoomCount < 3)
        return;
    roomIdx = 1 + (Random2() % (sRoomCount - 2));
    sTiles[sCy[roomIdx]][sCx[roomIdx]] = TILE_CHEST;
}

void ProcDungeon_DescendFloor(void)
{
    u16 floor = VarGet(VAR_PROCGEN_FLOOR);
    floor++;
    VarSet(VAR_PROCGEN_FLOOR, floor);

    // Check quest progress for QUEST_PROCGEN_DEPTH
    if (floor >= 5)
    {
        // Advance quest step 2 if at step 1
        // (Full quest hook — see quest_log_custom.c)
    }
    if (floor >= 10)
    {
        FlagSet(FLAG_QUEST_PROCGEN_DEPTH_DONE);
    }

    // Re-generate the dungeon with a new seed for the new floor
    GenerateProcDungeon(BuildDungeonSeed((u8)floor));
    BlitTilesToMap();
    PlaceEncounterTriggers();
    PlaceExitWarp();
    PlaceChest();
}

void ProcDungeon_Exit(void)
{
    VarSet(VAR_PROCGEN_FLOOR, 0);
}

u8 ProcDungeon_GetFloor(void)
{
    return (u8)VarGet(VAR_PROCGEN_FLOOR);
}
