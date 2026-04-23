#ifndef GUARD_ITEMS_DAYDREAM_H
#define GUARD_ITEMS_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — New Item Data Entries
// Include in src/data/items.h after the last vanilla entry.
// ============================================================

#include "constants/items_daydream.h"

// ---- ITEM_DREAM_ANTLER ----
// Evolution item: use on Stantler to trigger Stagsomne evolution.
[ITEM_DREAM_ANTLER] =
{
    .name           = _("Dream Antler"),
    .itemId         = ITEM_DREAM_ANTLER,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "An antler shed by a\n"
        "dreaming stag. Use on\n"
        "Stantler to evolve it."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_EvoItem,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_COMEDY_MASK ----
// Evolution item: hold while levelling Mr. Mime to evolve.
[ITEM_COMEDY_MASK] =
{
    .name           = _("Comedy Mask"),
    .itemId         = ITEM_COMEDY_MASK,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "A mask that amplifies\n"
        "comedic timing. Hold\n"
        "while levelling Mr. Mime."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_EvoItem,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_COMFY_BEDROLL ----
// Trade-held item: trade Delcatty holding this to evolve.
[ITEM_COMFY_BEDROLL] =
{
    .name           = _("Comfy Bedroll"),
    .itemId         = ITEM_COMFY_BEDROLL,
    .price          = 2000,
    .description    = COMPOUND_STRING(
        "An incredibly soft bedroll.\n"
        "Trade a Delcatty holding\n"
        "this to evolve it."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_EvoItem,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_PET_TREAT ----
// Consumable: restores +20 Attention for one party Pokémon.
[ITEM_PET_TREAT] =
{
    .name           = _("Pet Treat"),
    .itemId         = ITEM_PET_TREAT,
    .price          = 200,
    .description    = COMPOUND_STRING(
        "A tasty treat that shows\n"
        "your Pokémon you care.\n"
        "Restores Attention."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_PetTreat,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_BIG_MEAL ----
// Consumable: restores +40 Hunger for one party Pokémon.
[ITEM_BIG_MEAL] =
{
    .name           = _("Big Meal"),
    .itemId         = ITEM_BIG_MEAL,
    .price          = 500,
    .description    = COMPOUND_STRING(
        "A hearty meal that fills\n"
        "a Pokémon right up.\n"
        "Restores Hunger."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_BigMeal,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_BEDROLL ----
// Key item: use on a soft outdoor tile to set up camp.
[ITEM_BEDROLL] =
{
    .name           = _("Bedroll"),
    .itemId         = ITEM_BEDROLL,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "A portable sleeping roll.\n"
        "Use outdoors to set up\n"
        "camp and rest."),
    .pocket         = POCKET_KEY_ITEMS,
    .type           = ITEM_USE_FIELD,
    .fieldUseFunc   = ItemUseOutOfBattle_Bedroll,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_OUTFIT_VOUCHER ----
// Key item: redeem at any Wardrobe shop for one free outfit.
[ITEM_OUTFIT_VOUCHER] =
{
    .name           = _("Outfit Voucher"),
    .itemId         = ITEM_OUTFIT_VOUCHER,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "A voucher redeemable at\n"
        "any Wardrobe shop for\n"
        "one free outfit."),
    .pocket         = POCKET_KEY_ITEMS,
    .type           = ITEM_USE_FIELD,
    .fieldUseFunc   = ItemUseOutOfBattle_OutfitVoucher,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_BREAD_BUNDLE ----
// Quest item: 5 loaves for the Bakery Run quest.
[ITEM_BREAD_BUNDLE] =
{
    .name           = _("Bread Bundle"),
    .itemId         = ITEM_BREAD_BUNDLE,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "Five fresh loaves from\n"
        "Patty's bakery. Deliver\n"
        "them before they cool."),
    .pocket         = POCKET_KEY_ITEMS,
    .type           = ITEM_USE_FIELD,
    .fieldUseFunc   = ItemUseOutOfBattle_CannotUse,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

// ---- ITEM_DREAM_STONE ----
// New evolution stone found in procgen dungeons.
// Used for future regional form evolutions (see TASKS.md §4.1).
[ITEM_DREAM_STONE] =
{
    .name           = _("Dream Stone"),
    .itemId         = ITEM_DREAM_STONE,
    .price          = 0,
    .description    = COMPOUND_STRING(
        "A stone that glows with\n"
        "residual dream energy.\n"
        "Triggers certain evolutions."),
    .pocket         = POCKET_ITEMS,
    .type           = ITEM_USE_PARTY_MENU,
    .fieldUseFunc   = ItemUseOutOfBattle_EvoItem,
    .battleUsage    = 0,
    .secondaryId    = 0,
},

#endif // GUARD_ITEMS_DAYDREAM_H
