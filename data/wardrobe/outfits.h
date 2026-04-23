#ifndef GUARD_WARDROBE_OUTFITS_H
#define GUARD_WARDROBE_OUTFITS_H

// ============================================================
// Pokémon Daydream Version — Outfit Metadata Table
// data/wardrobe/outfits.h
//
// Each entry defines: id, slot, name, source.
// Used by the Wardrobe UI to display outfit names and origins.
// ============================================================

#include "wardrobe.h"

// ---- Hat outfits ----
static const struct OutfitDef sHatOutfits[] =
{
    { OUTFIT_BAKER_HAT,   OUTFIT_SLOT_HAT, COMPOUND_STRING("Baker Hat"),   COMPOUND_STRING("Quest: A Yeasty Errand") },
    { OUTFIT_CAMP_HAT,    OUTFIT_SLOT_HAT, COMPOUND_STRING("Camp Hat"),    COMPOUND_STRING("Quest: Home Away From Home") },
    { OUTFIT_NEON_VISOR,  OUTFIT_SLOT_HAT, COMPOUND_STRING("Neon Visor"),  COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_BEANIE, OUTFIT_SLOT_HAT, COMPOUND_STRING("Pine Beanie"), COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_HOOD, OUTFIT_SLOT_HAT, COMPOUND_STRING("Hollow Hood"), COMPOUND_STRING("Dungeon: The Hollow") },
};

// ---- Top outfits ----
static const struct OutfitDef sTopOutfits[] =
{
    { OUTFIT_APRON,        OUTFIT_SLOT_TOP, COMPOUND_STRING("Apron"),        COMPOUND_STRING("Quest: A Yeasty Errand") },
    { OUTFIT_CAMP_TOP,     OUTFIT_SLOT_TOP, COMPOUND_STRING("Camp Top"),     COMPOUND_STRING("Quest: Home Away From Home") },
    { OUTFIT_NEON_JACKET,  OUTFIT_SLOT_TOP, COMPOUND_STRING("Neon Jacket"),  COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_VEST,    OUTFIT_SLOT_TOP, COMPOUND_STRING("Pine Vest"),    COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_CLOAK, OUTFIT_SLOT_TOP, COMPOUND_STRING("Hollow Cloak"), COMPOUND_STRING("Dungeon: The Hollow") },
};

// ---- Bottom outfits ----
static const struct OutfitDef sBottomOutfits[] =
{
    { OUTFIT_DEFAULT_BOTTOM, OUTFIT_SLOT_BOTTOM, COMPOUND_STRING("Default"),       COMPOUND_STRING("Default") },
    { OUTFIT_CAMP_PANTS,     OUTFIT_SLOT_BOTTOM, COMPOUND_STRING("Camp Pants"),    COMPOUND_STRING("Quest: Home Away From Home") },
    { OUTFIT_NEON_SHORTS,    OUTFIT_SLOT_BOTTOM, COMPOUND_STRING("Neon Shorts"),   COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_TROUSERS,  OUTFIT_SLOT_BOTTOM, COMPOUND_STRING("Pine Trousers"), COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_ROBE,    OUTFIT_SLOT_BOTTOM, COMPOUND_STRING("Hollow Robe"),   COMPOUND_STRING("Dungeon: The Hollow") },
};

// ---- Shoes outfits ----
static const struct OutfitDef sShoeOutfits[] =
{
    { OUTFIT_DEFAULT_SHOES,  OUTFIT_SLOT_SHOES, COMPOUND_STRING("Default"),      COMPOUND_STRING("Default") },
    { OUTFIT_CAMP_BOOTS,     OUTFIT_SLOT_SHOES, COMPOUND_STRING("Camp Boots"),   COMPOUND_STRING("Quest: Home Away From Home") },
    { OUTFIT_NEON_SNEAKERS,  OUTFIT_SLOT_SHOES, COMPOUND_STRING("Neon Sneakers"),COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_BOOTS,     OUTFIT_SLOT_SHOES, COMPOUND_STRING("Pine Boots"),   COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_SLIPPERS,OUTFIT_SLOT_SHOES, COMPOUND_STRING("Hollow Slippers"),COMPOUND_STRING("Dungeon: The Hollow") },
};

// ---- Accessory outfits ----
static const struct OutfitDef sAccessoryOutfits[] =
{
    { OUTFIT_BREAD_BADGE,   OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Bread Badge"),   COMPOUND_STRING("Quest: A Yeasty Errand") },
    { OUTFIT_DREAM_PENDANT, OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Dream Pendant"), COMPOUND_STRING("Quest: The Dreaming Stag") },
    { OUTFIT_PINE_CONE_PIN, OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Pine Cone Pin"), COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_MASK,   OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Hollow Mask"),   COMPOUND_STRING("Dungeon: The Hollow") },
};

// ---- Shop inventories ----
// Each shop sells specific outfit IDs.

// Loafsbury Wardrobe Shop
static const u8 sLoafsburyShopInventory[] =
{
    OUTFIT_APRON,
    OUTFIT_BAKER_HAT,
    OUTFIT_BREAD_BADGE,
    0xFF,  // terminator
};

// Static City Wardrobe Shop
static const u8 sStaticCityShopInventory[] =
{
    OUTFIT_NEON_JACKET,
    OUTFIT_NEON_VISOR,
    OUTFIT_NEON_SHORTS,
    OUTFIT_NEON_SNEAKERS,
    0xFF,
};

// Cinderpine Wardrobe Shop
static const u8 sCinderpineShopInventory[] =
{
    OUTFIT_PINE_VEST,
    OUTFIT_PINE_BEANIE,
    OUTFIT_PINE_TROUSERS,
    OUTFIT_PINE_BOOTS,
    OUTFIT_PINE_CONE_PIN,
    0xFF,
};

#endif // GUARD_WARDROBE_OUTFITS_H
