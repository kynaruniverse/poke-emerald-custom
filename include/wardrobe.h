#ifndef GUARD_WARDROBE_H
#define GUARD_WARDROBE_H

// ============================================================
// Pokémon Daydream Version — Wardrobe System
// Public API, slot IDs, outfit IDs, and data structures.
// ============================================================

// --------------- Outfit Slot IDs ---------------
#define OUTFIT_SLOT_HAT         0
#define OUTFIT_SLOT_TOP         1
#define OUTFIT_SLOT_BOTTOM      2
#define OUTFIT_SLOT_SHOES       3
#define OUTFIT_SLOT_ACCESSORY   4
#define OUTFIT_SLOT_COUNT       5

// --------------- Outfit IDs ---------------
// 0 = no outfit equipped in that slot (default sprite)
#define OUTFIT_NONE             0

// Hats
#define OUTFIT_BAKER_HAT        1
#define OUTFIT_CAMP_HAT         2
#define OUTFIT_NEON_VISOR       3
#define OUTFIT_PINE_BEANIE      4
#define OUTFIT_HOLLOW_HOOD      5

// Tops
#define OUTFIT_APRON            1
#define OUTFIT_CAMP_TOP         2
#define OUTFIT_NEON_JACKET      3
#define OUTFIT_PINE_VEST        4
#define OUTFIT_HOLLOW_CLOAK     5

// Bottoms
#define OUTFIT_DEFAULT_BOTTOM   1
#define OUTFIT_CAMP_PANTS       2
#define OUTFIT_NEON_SHORTS      3
#define OUTFIT_PINE_TROUSERS    4
#define OUTFIT_HOLLOW_ROBE      5

// Shoes
#define OUTFIT_DEFAULT_SHOES    1
#define OUTFIT_CAMP_BOOTS       2
#define OUTFIT_NEON_SNEAKERS    3
#define OUTFIT_PINE_BOOTS       4
#define OUTFIT_HOLLOW_SLIPPERS  5

// Accessories
#define OUTFIT_NONE_ACC         0
#define OUTFIT_BREAD_BADGE      1
#define OUTFIT_DREAM_PENDANT    2
#define OUTFIT_PINE_CONE_PIN    3
#define OUTFIT_HOLLOW_MASK      4

// Total outfit IDs per slot (expand as art is added)
#define OUTFIT_COUNT_PER_SLOT   6

// --------------- Camp Set Bonus ---------------
// Wearing OUTFIT_CAMP_TOP + OUTFIT_CAMP_BOTTOM + OUTFIT_CAMP_BOOTS
// grants a +10 Rest recovery bonus while camping.
#define CAMP_SET_REST_BONUS     10

// --------------- WardrobeState struct ---------------
// Stored in SaveBlock2. 5 bytes equipped + 8 bytes bitmap = 13 bytes.
struct WardrobeState
{
    u8 equipped[OUTFIT_SLOT_COUNT];  // currently equipped outfit per slot
    u32 unlockedBitmap[2];           // bitfield: up to 64 outfit IDs unlocked
};

// --------------- Outfit metadata ---------------
struct OutfitDef
{
    u8 id;
    u8 slot;
    const u8 *name;
    const u8 *source;   // "Quest", "Shop", "Dungeon", etc.
};

// --------------- Public API ---------------

// Initialise wardrobe to defaults (all OUTFIT_NONE, bitmap zeroed).
void Wardrobe_Init(struct WardrobeState *state);

// Unlock an outfit by ID. Sets the corresponding bit in unlockedBitmap.
void Wardrobe_Unlock(struct WardrobeState *state, u8 outfitId);

// Check whether an outfit is unlocked.
bool8 Wardrobe_IsUnlocked(const struct WardrobeState *state, u8 outfitId);

// Equip an outfit in the given slot. Does nothing if not unlocked.
void Wardrobe_Equip(struct WardrobeState *state, u8 slot, u8 outfitId);

// Get the currently equipped outfit for a slot.
u8 Wardrobe_GetEquipped(const struct WardrobeState *state, u8 slot);

// Returns TRUE if the full Camp Set is equipped (Top + Bottom + Shoes).
bool8 Wardrobe_IsCampSetEquipped(const struct WardrobeState *state);

// Open the Wardrobe menu (called from start menu callback).
void Task_OpenWardrobeFromStartMenu(u8 taskId);

// Start-menu callback dispatcher.
bool8 StartMenuWardrobeCallback(void);

#endif // GUARD_WARDROBE_H
