#ifndef GUARD_DAYDREAM_WARDROBE_OUTFITS_H
#define GUARD_DAYDREAM_WARDROBE_OUTFITS_H

// =============================================================================
// Pokémon Daydream Version — Outfit metadata table
// Pulled in by src/wardrobe.c.
// =============================================================================

#include "wardrobe.h"
#include "constants/items.h"

enum OutfitSource
{
    OUTFIT_SRC_GIFT,       // story quest reward
    OUTFIT_SRC_SHOP,       // buyable
    OUTFIT_SRC_DUNGEON,    // procgen reward
    OUTFIT_SRC_HIDDEN,     // exploration/secret
};

struct OutfitInfo
{
    u8   id;
    u8   slot;
    u8   source;
    u16  costMoney;
    const u8 *name;
    const u8 *description;
};

// Text defined in data/wardrobe/outfits_text.inc (to be created alongside art).
// This table is the source of truth for shop inventories and the Wardrobe UI.
static const struct OutfitInfo gOutfitInfo[] =
{
    // --- Hats ---
    { OUTFIT_BAKER_HAT,       OUTFIT_SLOT_HAT,       OUTFIT_SRC_GIFT,    0,    NULL, NULL },
    { OUTFIT_NAP_CAP,         OUTFIT_SLOT_HAT,       OUTFIT_SRC_SHOP,    400,  NULL, NULL },
    { OUTFIT_LIGHTHOUSE_HAT,  OUTFIT_SLOT_HAT,       OUTFIT_SRC_HIDDEN,  0,    NULL, NULL },
    // --- Tops ---
    { OUTFIT_APRON,           OUTFIT_SLOT_TOP,       OUTFIT_SRC_GIFT,    0,    NULL, NULL },
    { OUTFIT_PAJAMA_TOP,      OUTFIT_SLOT_TOP,       OUTFIT_SRC_SHOP,    500,  NULL, NULL },
    { OUTFIT_CAMP_JACKET,     OUTFIT_SLOT_TOP,       OUTFIT_SRC_SHOP,    1200, NULL, NULL },
    { OUTFIT_STATIC_TEE,      OUTFIT_SLOT_TOP,       OUTFIT_SRC_SHOP,    800,  NULL, NULL },
    // --- Bottoms ---
    { OUTFIT_PAJAMA_PANTS,    OUTFIT_SLOT_BOTTOM,    OUTFIT_SRC_SHOP,    500,  NULL, NULL },
    { OUTFIT_CARGO_SHORTS,    OUTFIT_SLOT_BOTTOM,    OUTFIT_SRC_SHOP,    700,  NULL, NULL },
    { OUTFIT_WARM_LEGGINGS,   OUTFIT_SLOT_BOTTOM,    OUTFIT_SRC_SHOP,    900,  NULL, NULL },
    // --- Shoes ---
    { OUTFIT_SLIPPERS,        OUTFIT_SLOT_SHOES,     OUTFIT_SRC_GIFT,    0,    NULL, NULL },
    { OUTFIT_HIKING_BOOTS,    OUTFIT_SLOT_SHOES,     OUTFIT_SRC_SHOP,    1500, NULL, NULL },
    { OUTFIT_SNOW_BOOTS,      OUTFIT_SLOT_SHOES,     OUTFIT_SRC_DUNGEON, 0,    NULL, NULL },
    // --- Accessories ---
    { OUTFIT_COMEDY_MASK_ACC, OUTFIT_SLOT_ACCESSORY, OUTFIT_SRC_GIFT,    0,    NULL, NULL },
    { OUTFIT_DREAM_PENDANT,   OUTFIT_SLOT_ACCESSORY, OUTFIT_SRC_HIDDEN,  0,    NULL, NULL },
    { OUTFIT_SCARF_MOSSY,     OUTFIT_SLOT_ACCESSORY, OUTFIT_SRC_SHOP,    600,  NULL, NULL },
};

#define OUTFIT_INFO_COUNT (sizeof(gOutfitInfo) / sizeof(gOutfitInfo[0]))

// --- Combo / Set detection ----------------------------------------------------
// Each entry: required outfit IDs per slot (OUTFIT_NONE = "any").
struct OutfitSet
{
    u8 id;
    u8 req[OUTFIT_SLOT_COUNT];
    const u8 *name;
};

static const struct OutfitSet gOutfitSets[] =
{
    { WARDROBE_SET_CAMP,   { OUTFIT_NAP_CAP,   OUTFIT_CAMP_JACKET, OUTFIT_NONE,       OUTFIT_HIKING_BOOTS, OUTFIT_NONE           }, NULL },
    { WARDROBE_SET_BAKER,  { OUTFIT_BAKER_HAT, OUTFIT_APRON,       OUTFIT_NONE,       OUTFIT_NONE,         OUTFIT_NONE           }, NULL },
    { WARDROBE_SET_STATIC, { OUTFIT_NONE,      OUTFIT_STATIC_TEE,  OUTFIT_NONE,       OUTFIT_NONE,         OUTFIT_SCARF_MOSSY    }, NULL },
    { WARDROBE_SET_PAJAMA, { OUTFIT_NAP_CAP,   OUTFIT_PAJAMA_TOP,  OUTFIT_PAJAMA_PANTS, OUTFIT_SLIPPERS,   OUTFIT_NONE           }, NULL },
};

#define OUTFIT_SET_COUNT (sizeof(gOutfitSets) / sizeof(gOutfitSets[0]))

#endif // GUARD_DAYDREAM_WARDROBE_OUTFITS_H
