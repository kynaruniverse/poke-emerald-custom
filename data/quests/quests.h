#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H

// ============================================================
// Pokémon Daydream Version — Quest Definitions
// data/quests/quests.h
// ============================================================

#include "quest_log_custom.h"
#include "constants/items_daydream.h"

// Step text is defined in data/quests/text/<quest>.inc
// and included below.

// ---- Bakery Run ----
static const u8 sBakeryRun_Step1[] = _("Carry 5 loaves to the dock before they cool.");
static const u8 sBakeryRun_Step2[] = _("3 loaves delivered. Hurry!");
static const u8 sBakeryRun_Step3[] = _("All loaves delivered. Return to Patty.");

// ---- Lost Cat ----
static const u8 sLostCat_Step1[] = _("Find the missing Skitty somewhere in Loafsbury.");
static const u8 sLostCat_Step2[] = _("Skitty found! Return it to its owner.");

// ---- Tibbs Nap ----
static const u8 sTibbsNap_Step1[] = _("Challenge Tibb to a battle while he naps.");
static const u8 sTibbsNap_Step2[] = _("Win the battle. Don't wake him up.");

// ---- Camp Tutorial ----
static const u8 sCampTutorial_Step1[] = _("Find a soft-tile spot on Route 2.");
static const u8 sCampTutorial_Step2[] = _("Use the Bedroll to set up camp.");
static const u8 sCampTutorial_Step3[] = _("Cook a Berry at camp to restore Hunger.");

// ---- Lighthouse ----
static const u8 sLighthouse_Step1[] = _("Investigate the flickering light at Glasswake.");
static const u8 sLighthouse_Step2[] = _("Enter the lighthouse.");
static const u8 sLighthouse_Step3[] = _("Reach the top floor.");
static const u8 sLighthouse_Step4[] = _("Find the source of the flickering.");
static const u8 sLighthouse_Step5[] = _("Defeat what you find.");
static const u8 sLighthouse_Step6[] = _("Report back to the Keeper.");

// ---- Mossreach Whispers ----
static const u8 sMossreach_Step1[] = _("Find the first dreaming NPC in Mossreach.");
static const u8 sMossreach_Step2[] = _("Record the second dream.");
static const u8 sMossreach_Step3[] = _("Record the third dream. Something is wrong.");

// ---- Photoshoot ----
static const u8 sPhotoshoot_Step1[] = _("Equip a matching outfit set in Static City.");
static const u8 sPhotoshoot_Step2[] = _("Pose for the photographer.");

// ---- Cinderpine Fire ----
static const u8 sCinderpine_Step1[] = _("Keep the bonfire lit through the first wave.");
static const u8 sCinderpine_Step2[] = _("Second wave incoming. Hold the fire!");
static const u8 sCinderpine_Step3[] = _("Final wave. Don't let it go out.");

// ---- Hollow Pilgrim ----
static const u8 sHollowPilgrim_Step1[] = _("Agree to escort the old trainer.");
static const u8 sHollowPilgrim_Step2[] = _("Reach the halfway point of The Hollow.");
static const u8 sHollowPilgrim_Step3[] = _("Reach the exit. The old trainer is safe.");

// ---- Inn Recipe ----
static const u8 sInnRecipe_Step1[] = _("Collect a Oran Berry.");
static const u8 sInnRecipe_Step2[] = _("Collect a Sitrus Berry.");
static const u8 sInnRecipe_Step3[] = _("Collect a Lum Berry.");
static const u8 sInnRecipe_Step4[] = _("Collect a Rawst Berry. Return to the Innkeeper.");

// ---- Dream Antler ----
static const u8 sDreamAntler_Step1[] = _("Find the Dream Antler in the northern forest.");
static const u8 sDreamAntler_Step2[] = _("Give the Dream Antler to your Stantler.");

// ---- Comedy Mask ----
static const u8 sComedyMask_Step1[] = _("Win the comedy contest in Static City.");
static const u8 sComedyMask_Step2[] = _("Claim the Comedy Mask as your prize.");
static const u8 sComedyMask_Step3[] = _("Give the Comedy Mask to your Mr. Mime.");

// ---- Wardrobe Gauntlet ----
static const u8 sWardrobeGauntlet_Step1[] = _("Buy an outfit from the Loafsbury shop.");
static const u8 sWardrobeGauntlet_Step2[] = _("Buy an outfit from the Static City shop.");
static const u8 sWardrobeGauntlet_Step3[] = _("Buy an outfit from the Cinderpine shop.");

// ---- Needs Master ----
static const u8 sNeedsMaster_Step1[] = _("Get all 6 party Pokémon to MAX needs.");
static const u8 sNeedsMaster_Step2[] = _("Keep them all at MAX for a full in-game day.");

// ---- Procgen Depth ----
static const u8 sProcgenDepth_Step1[] = _("Enter any procgen dungeon.");
static const u8 sProcgenDepth_Step2[] = _("Reach floor 5.");
static const u8 sProcgenDepth_Step3[] = _("Reach floor 10. You've gone deep enough.");

// ---- Outsider ----
static const u8 sOutsider_Step1[] = _("Catch a Pokémon not native to Reverie.");

// ---- Regional Forms ----
static const u8 sRegionalForms_Step1[] = _("Catch the first Reverie regional form.");
static const u8 sRegionalForms_Step2[] = _("Catch the second Reverie regional form.");
static const u8 sRegionalForms_Step3[] = _("Catch the third Reverie regional form.");

// ---- Ghost Grey ----
static const u8 sGhostGrey_Step1[] = _("Investigate the grey house in Mossreach.");
static const u8 sGhostGrey_Step2[] = _("Find the source of the cold spots.");
static const u8 sGhostGrey_Step3[] = _("Confront what lives in the basement.");

// ---- Strike Breaker ----
static const u8 sStrikeBreaker_Step1[] = _("Find Champion Vex at Glasswake.");
static const u8 sStrikeBreaker_Step2[] = _("Convince Vex the region needs a Champion.");
static const u8 sStrikeBreaker_Step3[] = _("Defeat Vex in a battle to prove your point.");

// ---- Daydreamer ----
static const u8 sDaydreamer_Step1[] = _("Return to The Hollow after the credits.");
static const u8 sDaydreamer_Step2[] = _("Reach the deepest floor.");
static const u8 sDaydreamer_Step3[] = _("Defeat the Hollow's final manifestation.");

// ============================================================
// Quest definitions table
// ============================================================
const struct QuestDef sQuestDefs[] =
{
    // QUEST_NONE placeholder
    [QUEST_NONE] = {
        .id = QUEST_NONE,
        .name = COMPOUND_STRING("---"),
        .giver = COMPOUND_STRING("---"),
        .steps = 0,
    },

    [QUEST_BAKERY_RUN] = {
        .id = QUEST_BAKERY_RUN,
        .name = COMPOUND_STRING("A Yeasty Errand"),
        .giver = COMPOUND_STRING("Patty"),
        .steps = 3,
        .stepText = { sBakeryRun_Step1, sBakeryRun_Step2, sBakeryRun_Step3 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 1 },
    },

    [QUEST_LOST_CAT] = {
        .id = QUEST_LOST_CAT,
        .name = COMPOUND_STRING("Where's Whiskers?"),
        .giver = COMPOUND_STRING("Child"),
        .steps = 2,
        .stepText = { sLostCat_Step1, sLostCat_Step2 },
        .reward = { .item = ITEM_PET_TREAT, .qty = 3 },
    },

    [QUEST_TIBBS_NAP] = {
        .id = QUEST_TIBBS_NAP,
        .name = COMPOUND_STRING("Nap Champion"),
        .giver = COMPOUND_STRING("Tibb"),
        .steps = 2,
        .stepText = { sTibbsNap_Step1, sTibbsNap_Step2 },
        .reward = { .item = ITEM_BIG_MEAL, .qty = 2 },
    },

    [QUEST_CAMP_TUTORIAL] = {
        .id = QUEST_CAMP_TUTORIAL,
        .name = COMPOUND_STRING("Home Away From Home"),
        .giver = COMPOUND_STRING("Innkeeper"),
        .steps = 3,
        .stepText = { sCampTutorial_Step1, sCampTutorial_Step2, sCampTutorial_Step3 },
        .reward = { .item = ITEM_BEDROLL, .qty = 1 },
    },

    [QUEST_LIGHTHOUSE] = {
        .id = QUEST_LIGHTHOUSE,
        .name = COMPOUND_STRING("Light Out"),
        .giver = COMPOUND_STRING("Keeper"),
        .steps = 6,
        .stepText = { sLighthouse_Step1, sLighthouse_Step2, sLighthouse_Step3,
                      sLighthouse_Step4, sLighthouse_Step5, sLighthouse_Step6 },
        .reward = { .item = ITEM_DREAM_STONE, .qty = 1 },
    },

    [QUEST_MOSSREACH_WHISPERS] = {
        .id = QUEST_MOSSREACH_WHISPERS,
        .name = COMPOUND_STRING("Dream Catchers"),
        .giver = COMPOUND_STRING("Sage"),
        .steps = 3,
        .stepText = { sMossreach_Step1, sMossreach_Step2, sMossreach_Step3 },
        .reward = { .item = ITEM_DREAM_ANTLER, .qty = 1 },
    },

    [QUEST_PHOTOSHOOT] = {
        .id = QUEST_PHOTOSHOOT,
        .name = COMPOUND_STRING("Picture Perfect"),
        .giver = COMPOUND_STRING("Photographer"),
        .steps = 2,
        .stepText = { sPhotoshoot_Step1, sPhotoshoot_Step2 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 2 },
    },

    [QUEST_CINDERPINE_FIRE] = {
        .id = QUEST_CINDERPINE_FIRE,
        .name = COMPOUND_STRING("Keep It Burning"),
        .giver = COMPOUND_STRING("Camp Elder"),
        .steps = 3,
        .stepText = { sCinderpine_Step1, sCinderpine_Step2, sCinderpine_Step3 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 1 },
    },

    [QUEST_HOLLOW_PILGRIM] = {
        .id = QUEST_HOLLOW_PILGRIM,
        .name = COMPOUND_STRING("The Long Way Through"),
        .giver = COMPOUND_STRING("Old Trainer"),
        .steps = 3,
        .stepText = { sHollowPilgrim_Step1, sHollowPilgrim_Step2, sHollowPilgrim_Step3 },
        .reward = { .item = ITEM_DREAM_STONE, .qty = 2 },
    },

    [QUEST_INN_RECIPE] = {
        .id = QUEST_INN_RECIPE,
        .name = COMPOUND_STRING("The Perfect Stew"),
        .giver = COMPOUND_STRING("Innkeeper"),
        .steps = 4,
        .stepText = { sInnRecipe_Step1, sInnRecipe_Step2, sInnRecipe_Step3, sInnRecipe_Step4 },
        .reward = { .item = ITEM_BIG_MEAL, .qty = 5 },
    },

    [QUEST_DREAM_ANTLER] = {
        .id = QUEST_DREAM_ANTLER,
        .name = COMPOUND_STRING("The Dreaming Stag"),
        .giver = COMPOUND_STRING("Ranger"),
        .steps = 2,
        .stepText = { sDreamAntler_Step1, sDreamAntler_Step2 },
        .reward = { .item = ITEM_DREAM_ANTLER, .qty = 1 },
    },

    [QUEST_COMEDY_MASK] = {
        .id = QUEST_COMEDY_MASK,
        .name = COMPOUND_STRING("The Punchline"),
        .giver = COMPOUND_STRING("MC"),
        .steps = 3,
        .stepText = { sComedyMask_Step1, sComedyMask_Step2, sComedyMask_Step3 },
        .reward = { .item = ITEM_COMEDY_MASK, .qty = 1 },
    },

    [QUEST_WARDROBE_GAUNTLET] = {
        .id = QUEST_WARDROBE_GAUNTLET,
        .name = COMPOUND_STRING("Dressed to Impress"),
        .giver = COMPOUND_STRING("Fashion Judge"),
        .steps = 3,
        .stepText = { sWardrobeGauntlet_Step1, sWardrobeGauntlet_Step2, sWardrobeGauntlet_Step3 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 3 },
    },

    [QUEST_NEEDS_MASTER] = {
        .id = QUEST_NEEDS_MASTER,
        .name = COMPOUND_STRING("The Caring Trainer"),
        .giver = COMPOUND_STRING("Innkeeper"),
        .steps = 2,
        .stepText = { sNeedsMaster_Step1, sNeedsMaster_Step2 },
        .reward = { .item = ITEM_BIG_MEAL, .qty = 10 },
    },

    [QUEST_PROCGEN_DEPTH] = {
        .id = QUEST_PROCGEN_DEPTH,
        .name = COMPOUND_STRING("Going Deeper"),
        .giver = COMPOUND_STRING("Explorer"),
        .steps = 3,
        .stepText = { sProcgenDepth_Step1, sProcgenDepth_Step2, sProcgenDepth_Step3 },
        .reward = { .item = ITEM_DREAM_STONE, .qty = 3 },
    },

    [QUEST_OUTSIDER] = {
        .id = QUEST_OUTSIDER,
        .name = COMPOUND_STRING("Not From Around Here"),
        .giver = COMPOUND_STRING("Prof. Mim"),
        .steps = 1,
        .stepText = { sOutsider_Step1 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 1 },
    },

    [QUEST_REGIONAL_FORMS] = {
        .id = QUEST_REGIONAL_FORMS,
        .name = COMPOUND_STRING("Reverie Natives"),
        .giver = COMPOUND_STRING("Prof. Mim"),
        .steps = 3,
        .stepText = { sRegionalForms_Step1, sRegionalForms_Step2, sRegionalForms_Step3 },
        .reward = { .item = ITEM_DREAM_STONE, .qty = 2 },
    },

    [QUEST_GHOST_GREY] = {
        .id = QUEST_GHOST_GREY,
        .name = COMPOUND_STRING("Something Grey"),
        .giver = COMPOUND_STRING("Investigator"),
        .steps = 3,
        .stepText = { sGhostGrey_Step1, sGhostGrey_Step2, sGhostGrey_Step3 },
        .reward = { .item = ITEM_DREAM_STONE, .qty = 1 },
    },

    [QUEST_STRIKE_BREAKER] = {
        .id = QUEST_STRIKE_BREAKER,
        .name = COMPOUND_STRING("Back on the Clock"),
        .giver = COMPOUND_STRING("Union Rep"),
        .steps = 3,
        .stepText = { sStrikeBreaker_Step1, sStrikeBreaker_Step2, sStrikeBreaker_Step3 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 2 },
    },

    [QUEST_DAYDREAMER] = {
        .id = QUEST_DAYDREAMER,
        .name = COMPOUND_STRING("The Daydreamer"),
        .giver = COMPOUND_STRING("The Hollow"),
        .steps = 3,
        .stepText = { sDaydreamer_Step1, sDaydreamer_Step2, sDaydreamer_Step3 },
        .reward = { .item = ITEM_OUTFIT_VOUCHER, .qty = 5 },
    },
};

#endif // GUARD_QUESTS_H
