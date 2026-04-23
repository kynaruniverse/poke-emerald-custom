#ifndef GUARD_DAYDREAM_QUESTS_H
#define GUARD_DAYDREAM_QUESTS_H

// =============================================================================
// Pokémon Daydream Version — Quest definitions
// Pulled in by src/quest_log_custom.c.  Step text is placeholder until the
// full comedy-dialog pass (M9).
// =============================================================================

#include "quest_log_custom.h"
#include "constants/items.h"

// Placeholder item IDs — replace with real ones when added to src/data/items.h.
#ifndef ITEM_OUTFIT_VOUCHER
#define ITEM_OUTFIT_VOUCHER ITEM_NONE
#endif
#ifndef ITEM_DREAM_ANTLER
#define ITEM_DREAM_ANTLER ITEM_NONE
#endif
#ifndef ITEM_COMEDY_MASK
#define ITEM_COMEDY_MASK ITEM_NONE
#endif
#ifndef ITEM_BEDROLL
#define ITEM_BEDROLL ITEM_NONE
#endif

const struct QuestDef gDaydreamQuests[QUEST_COUNT] =
{
    [QUEST_BAKERY_RUN] =
    {
        .id = QUEST_BAKERY_RUN,
        .name  = (const u8 *)"A Yeasty Errand",
        .giver = (const u8 *)"Patty",
        .steps = 3,
        .stepText =
        {
            (const u8 *)"Carry 5 loaves to the dock before they cool.",
            (const u8 *)"3 loaves delivered. Hurry!",
            (const u8 *)"All loaves delivered. Return to Patty.",
        },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 1, .flag = 0 },
    },
    [QUEST_LOST_CAT] =
    {
        .id = QUEST_LOST_CAT,
        .name  = (const u8 *)"Skitty Business",
        .giver = (const u8 *)"Loafsbury Kid",
        .steps = 2,
        .stepText =
        {
            (const u8 *)"Find the Skitty hiding in Loafsbury alleys.",
            (const u8 *)"Return the Skitty to its owner.",
        },
        .reward = { .item = ITEM_NONE, .qty = 0, .flag = 0 },
    },
    [QUEST_LIGHTHOUSE] =
    {
        .id = QUEST_LIGHTHOUSE,
        .name  = (const u8 *)"Light Out",
        .giver = (const u8 *)"Keeper",
        .steps = 6,
        .stepText =
        {
            (const u8 *)"Investigate the flickering Glasswake lighthouse.",
            (const u8 *)"Climb to the second floor.",
            (const u8 *)"The bulbs keep... whispering.",
            (const u8 *)"Reach the top. Something is up there.",
            (const u8 *)"Confront whatever this is.",
            (const u8 *)"Report back to the Keeper.",
        },
        .reward = { .item = ITEM_NONE, .qty = 0, .flag = 0 },
    },
    [QUEST_CINDERPINE_FIRE] =
    {
        .id = QUEST_CINDERPINE_FIRE,
        .name  = (const u8 *)"Keep the Fire",
        .giver = (const u8 *)"Camp Elder",
        .steps = 4,
        .stepText =
        {
            (const u8 *)"Pitch camp at the Cinderpine clearing.",
            (const u8 *)"Survive the first wind wave.",
            (const u8 *)"Survive the second wave.",
            (const u8 *)"Dawn. You did it.",
        },
        .reward = { .item = ITEM_BEDROLL, .qty = 1, .flag = 0 },
    },
    [QUEST_DREAM_ANTLER] =
    {
        .id = QUEST_DREAM_ANTLER,
        .name  = (const u8 *)"Antler Hunt",
        .giver = (const u8 *)"Prof. Mim",
        .steps = 3,
        .stepText =
        {
            (const u8 *)"Track a Stantler through Yawn Path.",
            (const u8 *)"Retrieve a fallen Dream Antler.",
            (const u8 *)"Return to Prof. Mim.",
        },
        .reward = { .item = ITEM_DREAM_ANTLER, .qty = 1, .flag = 0 },
    },
    [QUEST_COMEDY_MASK] =
    {
        .id = QUEST_COMEDY_MASK,
        .name  = (const u8 *)"Bit Part",
        .giver = (const u8 *)"Static City Comic",
        .steps = 2,
        .stepText =
        {
            (const u8 *)"Do one open-mic night. Do NOT die.",
            (const u8 *)"Claim your Comedy Mask.",
        },
        .reward = { .item = ITEM_COMEDY_MASK, .qty = 1, .flag = 0 },
    },

    // --- stubs for remaining quests (fill in during M5/M9) -------------------
    [QUEST_MOSSREACH_WHISPERS]     = { .id = QUEST_MOSSREACH_WHISPERS,     .name = (const u8 *)"Whispers in the Moss",     .giver = (const u8 *)"Mossreach Elder", .steps = 3 },
    [QUEST_STATIC_CITY_PHOTOSHOOT] = { .id = QUEST_STATIC_CITY_PHOTOSHOOT, .name = (const u8 *)"Strike a Pose",             .giver = (const u8 *)"Photographer",    .steps = 3 },
    [QUEST_HOLLOW_PILGRIM]         = { .id = QUEST_HOLLOW_PILGRIM,         .name = (const u8 *)"The Last Pilgrim",          .giver = (const u8 *)"Old Trainer",     .steps = 4 },
    [QUEST_INN_RECIPE]             = { .id = QUEST_INN_RECIPE,             .name = (const u8 *)"Secret Recipe",             .giver = (const u8 *)"Innkeeper",       .steps = 2 },
    [QUEST_TIBBS_NAP]              = { .id = QUEST_TIBBS_NAP,              .name = (const u8 *)"Nap Battle",                .giver = (const u8 *)"Tibb",            .steps = 1 },
    [QUEST_WARDROBE_GAUNTLET]      = { .id = QUEST_WARDROBE_GAUNTLET,      .name = (const u8 *)"Fit Check",                 .giver = (const u8 *)"Static Stylist",  .steps = 5 },
    [QUEST_NEEDS_MASTER]           = { .id = QUEST_NEEDS_MASTER,           .name = (const u8 *)"Perfect Day",               .giver = (const u8 *)"Self",            .steps = 1 },
    [QUEST_PROCGEN_DEPTH]          = { .id = QUEST_PROCGEN_DEPTH,          .name = (const u8 *)"Floor 10",                  .giver = (const u8 *)"Dungeon Notice",  .steps = 1 },
    [QUEST_OUTSIDER]               = { .id = QUEST_OUTSIDER,               .name = (const u8 *)"Outsider",                  .giver = (const u8 *)"Prof. Mim",       .steps = 1 },
    [QUEST_REGIONAL_FORMS]         = { .id = QUEST_REGIONAL_FORMS,         .name = (const u8 *)"Three of a Kind",           .giver = (const u8 *)"Prof. Mim",       .steps = 3 },
    [QUEST_GHOST_GREY]             = { .id = QUEST_GHOST_GREY,             .name = (const u8 *)"Grey Ghosts",               .giver = (const u8 *)"Mossreach Elder", .steps = 4 },
    [QUEST_STRIKE_BREAKER]         = { .id = QUEST_STRIKE_BREAKER,         .name = (const u8 *)"Strike Breaker",            .giver = (const u8 *)"Champion Vex",    .steps = 5 },
    [QUEST_DAYDREAMER]             = { .id = QUEST_DAYDREAMER,             .name = (const u8 *)"Daydreamer",                .giver = (const u8 *)"The Hollow",      .steps = 1 },
};

#endif // GUARD_DAYDREAM_QUESTS_H
