// ============================================================
// Pokémon Daydream Version — Item Use Functions
// src/daydream/item_use_daydream.c
//
// New item use callbacks for Daydream items.
// Wire these into src/item_use.c's sItemUseRoutines[] table.
// ============================================================

#include "global.h"
#include "item_use.h"
#include "item.h"
#include "pokemon.h"
#include "pokemon_needs.h"
#include "camp.h"
#include "wardrobe.h"
#include "task.h"
#include "menu.h"
#include "window.h"
#include "text.h"
#include "main.h"
#include "strings.h"
#include "bag.h"
#include "constants/items_daydream.h"

// ---- ITEM_PET_TREAT ----
// Restores +20 Attention for the selected party Pokémon.
bool8 ItemUseOutOfBattle_PetTreat(u8 taskId)
{
    u8 partyIndex = gLastFieldPokeMenuOpened;
    if (!GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES))
    {
        ShowFieldMessage(COMPOUND_STRING("No Pokémon to give the treat to."));
        return FALSE;
    }
    FillNeed(partyIndex, NEED_ATTENTION, NEEDS_FILL_PET_TREAT_ATTENTION);
    RemoveBagItem(ITEM_PET_TREAT, 1);
    ShowFieldMessage(COMPOUND_STRING("{STR_VAR_1} enjoyed the treat!\nAttention restored."));
    return TRUE;
}

// ---- ITEM_BIG_MEAL ----
// Restores +40 Hunger for the selected party Pokémon.
bool8 ItemUseOutOfBattle_BigMeal(u8 taskId)
{
    u8 partyIndex = gLastFieldPokeMenuOpened;
    if (!GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES))
    {
        ShowFieldMessage(COMPOUND_STRING("No Pokémon to feed."));
        return FALSE;
    }
    FillNeed(partyIndex, NEED_HUNGER, NEEDS_FILL_BIG_MEAL_HUNGER);
    RemoveBagItem(ITEM_BIG_MEAL, 1);
    ShowFieldMessage(COMPOUND_STRING("{STR_VAR_1} ate the big meal!\nHunger restored."));
    return TRUE;
}

// ---- ITEM_BEDROLL ----
// Use on a soft outdoor tile to set up camp.
bool8 ItemUseOutOfBattle_Bedroll(u8 taskId)
{
    if (!Camp_CanCampHere())
    {
        ShowFieldMessage(COMPOUND_STRING("You can't camp here.\nFind a softer spot."));
        return FALSE;
    }
    Camp_StartCamp();
    return TRUE;
}

// ---- ITEM_OUTFIT_VOUCHER ----
// Placeholder: opens a message. Full shop integration in TASKS.md.
bool8 ItemUseOutOfBattle_OutfitVoucher(u8 taskId)
{
    ShowFieldMessage(COMPOUND_STRING(
        "Outfit Voucher!\n"
        "Redeem at any Wardrobe shop\n"
        "for one free outfit."));
    return TRUE;
}
