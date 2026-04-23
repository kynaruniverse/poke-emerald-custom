#ifndef GUARD_QUEST_LOG_CUSTOM_H
#define GUARD_QUEST_LOG_CUSTOM_H

// ============================================================
// Pokémon Daydream Version — Quest Log System
// Flag-backed state machine. Each quest has up to 8 steps.
// State is stored in a packed array inside SaveBlock1.
// 4 bits per quest × 256 quests = 128 bytes.
// ============================================================

// --------------- Quest IDs ---------------
enum QuestId
{
    QUEST_NONE = 0,

    // Act I
    QUEST_BAKERY_RUN,           // Deliver 5 loaves before they cool
    QUEST_LOST_CAT,             // Find a Skitty in Loafsbury alleys
    QUEST_TIBBS_NAP,            // Beat rival in battle while he naps
    QUEST_CAMP_TUTORIAL,        // Camp tutorial on Route 2

    // Act II
    QUEST_LIGHTHOUSE,           // Investigate flickering lights at Glasswake
    QUEST_MOSSREACH_WHISPERS,   // Record three NPC dreams (horror)
    QUEST_PHOTOSHOOT,           // Wardrobe combo unlock in Static City
    QUEST_CINDERPINE_FIRE,      // Keep camp lit through three waves
    QUEST_HOLLOW_PILGRIM,       // Escort old trainer through The Hollow
    QUEST_INN_RECIPE,           // Collect 4 berries for the Innkeeper
    QUEST_DREAM_ANTLER,         // Triggers Stantler → Stagsomne chain
    QUEST_COMEDY_MASK,          // Triggers Mr. Mime → Mr. Mimic chain

    // Act III / Completionist
    QUEST_WARDROBE_GAUNTLET,    // Own one outfit from each shop
    QUEST_NEEDS_MASTER,         // Keep all 6 party mons at MAX needs for 1 day
    QUEST_PROCGEN_DEPTH,        // Reach floor 10 of any procgen dungeon
    QUEST_OUTSIDER,             // Catch a non-Reverie native
    QUEST_REGIONAL_FORMS,       // Catch all three Reverie regional forms
    QUEST_GHOST_GREY,           // Paranormal investigation in Mossreach
    QUEST_STRIKE_BREAKER,       // Convince Champion Vex to return
    QUEST_DAYDREAMER,           // Beat the post-credits Hollow boss

    QUEST_COUNT,
};

// --------------- Quest state values (4 bits, 0–15) ---------------
#define QSTATE_NOT_STARTED  0
#define QSTATE_STEP_1       1
#define QSTATE_STEP_2       2
#define QSTATE_STEP_3       3
#define QSTATE_STEP_4       4
#define QSTATE_STEP_5       5
#define QSTATE_STEP_6       6
#define QSTATE_STEP_7       7
#define QSTATE_STEP_8       8
#define QSTATE_COMPLETE     15

// --------------- Quest reward struct ---------------
struct QuestReward
{
    u16 item;
    u8  qty;
};

// --------------- Quest definition struct ---------------
struct QuestDef
{
    u8  id;
    const u8 *name;
    const u8 *giver;
    u8  steps;
    const u8 *stepText[8];
    struct QuestReward reward;
};

// --------------- Save state (128 bytes) ---------------
// 4 bits per quest, packed two-per-byte.
// quest N: byte = N/2, nibble = N%2 (low = even, high = odd).
struct QuestLogState
{
    u8 packed[128];  // supports up to 256 quests
};

// --------------- Public API ---------------

// Get the current state of a quest (QSTATE_* value).
u8 QuestLog_GetState(u8 questId);

// Set the state of a quest.
void QuestLog_SetState(u8 questId, u8 state);

// Start a quest (set to QSTATE_STEP_1).
void QuestLog_Start(u8 questId);

// Advance a quest to the next step.
void QuestLog_Advance(u8 questId);

// Mark a quest as complete (QSTATE_COMPLETE).
void QuestLog_Complete(u8 questId);

// Returns TRUE if the quest is complete.
bool8 QuestLog_IsComplete(u8 questId);

// Returns TRUE if the quest has been started (state > NOT_STARTED).
bool8 QuestLog_IsStarted(u8 questId);

// Open the Journal UI from the start menu.
bool8 StartMenuJournalCallback(void);

// Task to open the journal.
void Task_OpenJournalFromStartMenu(u8 taskId);

// Pointer to the quest definitions table (defined in data/quests/quests.h).
extern const struct QuestDef sQuestDefs[];

#endif // GUARD_QUEST_LOG_CUSTOM_H
