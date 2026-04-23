#ifndef GUARD_QUEST_LOG_CUSTOM_H
#define GUARD_QUEST_LOG_CUSTOM_H

// =============================================================================
// Pokémon Daydream Version — Quest Log
// Design Bible: docs/Daydream_Design_Bible.md §2.5, §4.6
//
// Flag-backed state machine. Up to 8 steps per quest, packed into a byte.
// Named "custom" to avoid collision with vanilla FRLG quest_log_*.
// =============================================================================

#include "global.h"

#define QUEST_MAX_STEPS    8
#define QUEST_MAX_COUNT    128   // upper bound for Daydream

// ---- Step states -------------------------------------------------------------
#define QSTATE_NOT_STARTED 0xFF  // sentinel
#define QSTATE_STEP_0      0
#define QSTATE_STEP_1      1
#define QSTATE_STEP_2      2
#define QSTATE_STEP_3      3
#define QSTATE_STEP_4      4
#define QSTATE_STEP_5      5
#define QSTATE_STEP_6      6
#define QSTATE_STEP_7      7
#define QSTATE_COMPLETED   0xFE

// ---- Quest IDs ---------------------------------------------------------------
enum QuestId
{
    QUEST_BAKERY_RUN,
    QUEST_LOST_CAT,
    QUEST_LIGHTHOUSE,
    QUEST_MOSSREACH_WHISPERS,
    QUEST_STATIC_CITY_PHOTOSHOOT,
    QUEST_CINDERPINE_FIRE,
    QUEST_HOLLOW_PILGRIM,
    QUEST_INN_RECIPE,
    QUEST_TIBBS_NAP,
    QUEST_DREAM_ANTLER,
    QUEST_COMEDY_MASK,
    QUEST_WARDROBE_GAUNTLET,
    QUEST_NEEDS_MASTER,
    QUEST_PROCGEN_DEPTH,
    QUEST_OUTSIDER,
    QUEST_REGIONAL_FORMS,
    QUEST_GHOST_GREY,
    QUEST_STRIKE_BREAKER,
    QUEST_DAYDREAMER,
    QUEST_COUNT,
};

// ---- Reward payload ----------------------------------------------------------
struct QuestReward
{
    u16 item;
    u16 qty;
    u16 flag;   // optional flag to set on complete
};

// ---- Quest definition (const data) -------------------------------------------
struct QuestDef
{
    u16 id;
    const u8 *name;
    const u8 *giver;
    u8  steps;
    const u8 *stepText[QUEST_MAX_STEPS];
    struct QuestReward reward;
};

extern const struct QuestDef gDaydreamQuests[QUEST_COUNT];

// ---- Runtime state (lives inside SaveBlock1) ---------------------------------
// 4 bits per quest. 128 quests => 64 bytes.
struct QuestLogState
{
    u8 nibbles[QUEST_MAX_COUNT / 2];
};

// ---- Public API --------------------------------------------------------------
void QuestLog_Init(void);
u8   QuestLog_GetStep(u16 questId);                 // returns QSTATE_*
void QuestLog_Start(u16 questId);
void QuestLog_Advance(u16 questId);                 // step++ with clamp
void QuestLog_SetStep(u16 questId, u8 step);
void QuestLog_Complete(u16 questId);
bool8 QuestLog_IsCompleted(u16 questId);

// Script helpers (called from data/scripts/*.inc via callfunc).
void QuestScript_Peek(void);     // reads VAR_0x8000 -> writes VAR_RESULT
void QuestScript_Start(void);    // reads VAR_0x8000
void QuestScript_Advance(void);  // reads VAR_0x8000
void QuestScript_Complete(void); // reads VAR_0x8000

// Journal UI entry point.
void Task_OpenJournalFromStartMenu(u8 taskId);

#endif // GUARD_QUEST_LOG_CUSTOM_H
