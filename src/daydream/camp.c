// ============================================================
// Pokémon Daydream Version — Camp & Shelter System
// src/daydream/camp.c
//
// The player uses ITEM_BEDROLL on a soft-tile outdoor square.
// This triggers a 5-second animation, restores REST +50 for
// the whole party, and offers an optional cook submenu.
// ============================================================

#include "global.h"
#include "camp.h"
#include "pokemon_needs.h"
#include "wardrobe.h"
#include "task.h"
#include "menu.h"
#include "window.h"
#include "text.h"
#include "main.h"
#include "field_effect.h"
#include "item.h"
#include "bag.h"
#include "strings.h"
#include "constants/items.h"
#include "constants/items_daydream.h"
#include "constants/flags_daydream.h"

// ---- Camp state ----
#define CAMP_STATE_PITCH_ANIM   0
#define CAMP_STATE_MENU         1
#define CAMP_STATE_COOK         2
#define CAMP_STATE_DONE         3

// ---- Camp menu options ----
static const u8 sCampMenuOptions[][16] = {
    _("REST"),
    _("COOK"),
    _("PACK UP"),
};
#define CAMP_MENU_REST    0
#define CAMP_MENU_COOK    1
#define CAMP_MENU_PACK_UP 2

// ---- Internal helpers ----

static void ApplyCampRestBonus(void)
{
    u8 i, bonus = NEED_CAMP_REST_FILL;
    // Camp Set bonus: +10 extra REST if wearing the full set
    if (Wardrobe_IsCampSetEquipped(&gSaveBlock2Ptr->wardrobe))
        bonus += CAMP_SET_REST_BONUS;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;
        FillNeed(i, NEED_REST, bonus);
    }
}

static void ApplyCampCookBonus(void)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;
        FillNeed(i, NEED_HUNGER, NEED_CAMP_HUNGER_FILL);
    }
}

// ---- Task: camp menu ----

static void Task_CampMenuInput(u8 taskId)
{
    s8 selection;
    if (JOY_NEW(A_BUTTON))
    {
        selection = Menu_GetCursorPos();
        switch (selection)
        {
        case CAMP_MENU_REST:
            ApplyCampRestBonus();
            ClearDialogWindowAndFrame(0, TRUE);
            ShowFieldMessage(COMPOUND_STRING("The party rested at camp!"));
            gTasks[taskId].data[0] = CAMP_STATE_DONE;
            break;
        case CAMP_MENU_COOK:
            // Check for any berry in bag
            if (GetBagItemQuantity(ITEM_ORAN_BERRY) > 0 ||
                GetBagItemQuantity(ITEM_SITRUS_BERRY) > 0 ||
                GetBagItemQuantity(ITEM_LUM_BERRY) > 0)
            {
                // Remove one berry (prefer Oran)
                if (GetBagItemQuantity(ITEM_ORAN_BERRY) > 0)
                    RemoveBagItem(ITEM_ORAN_BERRY, 1);
                else if (GetBagItemQuantity(ITEM_SITRUS_BERRY) > 0)
                    RemoveBagItem(ITEM_SITRUS_BERRY, 1);
                else
                    RemoveBagItem(ITEM_LUM_BERRY, 1);
                ApplyCampCookBonus();
                ShowFieldMessage(COMPOUND_STRING("Cooked a meal! The party's Hunger improved."));
            }
            else
            {
                ShowFieldMessage(COMPOUND_STRING("No berries to cook with."));
            }
            gTasks[taskId].data[0] = CAMP_STATE_DONE;
            break;
        case CAMP_MENU_PACK_UP:
        default:
            ClearDialogWindowAndFrame(0, TRUE);
            gTasks[taskId].data[0] = CAMP_STATE_DONE;
            break;
        }
    }
    if (JOY_NEW(B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        gTasks[taskId].data[0] = CAMP_STATE_DONE;
    }
    if (gTasks[taskId].data[0] == CAMP_STATE_DONE)
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

static void Task_CampPitchAnim(u8 taskId)
{
    // TODO: Play a proper 5-second field animation (see TASKS.md §4.7).
    // For now, immediately transition to the camp menu.
    gTasks[taskId].data[0] = CAMP_STATE_MENU;
    gTasks[taskId].func = Task_CampMenuInput;
    // Show the camp menu
    ShowFieldMessage(COMPOUND_STRING("Camp set up!\nWhat would you like to do?"));
    // TODO: Replace ShowFieldMessage with a proper menu window.
}

// ---- Public API ----

void Camp_StartCamp(void)
{
    FlagSet(FLAG_CAMP_TUTORIAL_DONE);
    CreateTask(Task_CampPitchAnim, 0);
}

bool8 Camp_CanCampHere(void)
{
    // TODO: Check current metatile behaviour for soft-tile outdoor flag.
    // For now, always return TRUE (permissive; tighten in map data).
    return TRUE;
}
