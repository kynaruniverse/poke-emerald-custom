#ifndef GUARD_WARDROBE_H
#define GUARD_WARDROBE_H

// =============================================================================
// Pokémon Daydream Version — Wardrobe System
// Design Bible: docs/Daydream_Design_Bible.md §2.1, §4.2
//
// Five cosmetic outfit slots. Combos grant flavor effects only (no stat creep),
// with the exception of CAMP_SET which grants a small Rest-recovery bonus
// while camping (see src/pokemon_needs.c).
// =============================================================================

#include "global.h"

// ---- Slot IDs ----------------------------------------------------------------
#define OUTFIT_SLOT_HAT        0
#define OUTFIT_SLOT_TOP        1
#define OUTFIT_SLOT_BOTTOM     2
#define OUTFIT_SLOT_SHOES      3
#define OUTFIT_SLOT_ACCESSORY  4
#define OUTFIT_SLOT_COUNT      5

// ---- Outfit IDs (expand as art is added) -------------------------------------
// 0 is reserved as "none/default".
#define OUTFIT_NONE            0
// Hats
#define OUTFIT_BAKER_HAT       1
#define OUTFIT_NAP_CAP         2
#define OUTFIT_LIGHTHOUSE_HAT  3
// Tops
#define OUTFIT_APRON           16
#define OUTFIT_PAJAMA_TOP      17
#define OUTFIT_CAMP_JACKET     18
#define OUTFIT_STATIC_TEE      19
// Bottoms
#define OUTFIT_PAJAMA_PANTS    32
#define OUTFIT_CARGO_SHORTS    33
#define OUTFIT_WARM_LEGGINGS   34
// Shoes
#define OUTFIT_SLIPPERS        48
#define OUTFIT_HIKING_BOOTS    49
#define OUTFIT_SNOW_BOOTS      50
// Accessories
#define OUTFIT_COMEDY_MASK_ACC 64
#define OUTFIT_DREAM_PENDANT   65
#define OUTFIT_SCARF_MOSSY     66

#define OUTFIT_COUNT_MAX       128  // bitmap sized below covers 0..127

// ---- Per-save state ----------------------------------------------------------
// Embedded in SaveBlock2 (see include/global.h).
struct WardrobeState
{
    u8  equipped[OUTFIT_SLOT_COUNT];   // outfit ID per slot
    u32 unlockedBitmap[4];             // 128 outfit flags
    u8  activeSetId;                   // cached combo-set id, 0 if none
};

// ---- Combo / Set IDs (computed from equipped[]) ------------------------------
#define WARDROBE_SET_NONE      0
#define WARDROBE_SET_CAMP      1   // Camp Jacket + Hiking Boots + Nap Cap
#define WARDROBE_SET_BAKER     2   // Apron + Baker Hat
#define WARDROBE_SET_STATIC    3   // Static Tee + any City accessory
#define WARDROBE_SET_PAJAMA    4   // Pajama top + pants + slippers

// ---- Public API --------------------------------------------------------------
void  Wardrobe_Init(void);                          // boot/new-game default
bool8 Wardrobe_IsUnlocked(u8 outfitId);
void  Wardrobe_Unlock(u8 outfitId);
void  Wardrobe_Equip(u8 slot, u8 outfitId);
u8    Wardrobe_GetEquipped(u8 slot);
u8    Wardrobe_GetActiveSet(void);                  // recompute & return
u8    Wardrobe_CampRestBonus(void);                 // called by needs system

// Menu entry point (hooked from src/start_menu.c).
void  Task_OpenWardrobeFromStartMenu(u8 taskId);

#endif // GUARD_WARDROBE_H
