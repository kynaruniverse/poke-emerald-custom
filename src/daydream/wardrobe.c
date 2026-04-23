// ============================================================
// Pokémon Daydream Version — Wardrobe System Implementation
// src/daydream/wardrobe.c
// ============================================================

#include "global.h"
#include "wardrobe.h"
#include "task.h"
#include "menu.h"
#include "window.h"
#include "text.h"
#include "palette.h"
#include "bg.h"
#include "sprite.h"
#include "main.h"
#include "strings.h"
#include "start_menu.h"
#include "constants/flags_daydream.h"

// ---- Outfit metadata table ----
// Populated as art and quests are added. Names are compile-time strings.
static const struct OutfitDef sOutfitDefs[] =
{
    // Tops
    { OUTFIT_APRON,        OUTFIT_SLOT_TOP,       COMPOUND_STRING("Apron"),         COMPOUND_STRING("Quest: Bakery Run") },
    { OUTFIT_CAMP_TOP,     OUTFIT_SLOT_TOP,       COMPOUND_STRING("Camp Top"),      COMPOUND_STRING("Quest: Camp Tutorial") },
    { OUTFIT_NEON_JACKET,  OUTFIT_SLOT_TOP,       COMPOUND_STRING("Neon Jacket"),   COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_VEST,    OUTFIT_SLOT_TOP,       COMPOUND_STRING("Pine Vest"),     COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_CLOAK, OUTFIT_SLOT_TOP,       COMPOUND_STRING("Hollow Cloak"),  COMPOUND_STRING("Dungeon: The Hollow") },
    // Hats
    { OUTFIT_BAKER_HAT,    OUTFIT_SLOT_HAT,       COMPOUND_STRING("Baker Hat"),     COMPOUND_STRING("Quest: Bakery Run") },
    { OUTFIT_CAMP_HAT,     OUTFIT_SLOT_HAT,       COMPOUND_STRING("Camp Hat"),      COMPOUND_STRING("Quest: Camp Tutorial") },
    { OUTFIT_NEON_VISOR,   OUTFIT_SLOT_HAT,       COMPOUND_STRING("Neon Visor"),    COMPOUND_STRING("Shop: Static City") },
    { OUTFIT_PINE_BEANIE,  OUTFIT_SLOT_HAT,       COMPOUND_STRING("Pine Beanie"),   COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_HOOD,  OUTFIT_SLOT_HAT,       COMPOUND_STRING("Hollow Hood"),   COMPOUND_STRING("Dungeon: The Hollow") },
    // Accessories
    { OUTFIT_BREAD_BADGE,  OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Bread Badge"),   COMPOUND_STRING("Quest: Bakery Run") },
    { OUTFIT_DREAM_PENDANT,OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Dream Pendant"), COMPOUND_STRING("Quest: Dream Antler") },
    { OUTFIT_PINE_CONE_PIN,OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Pine Cone Pin"), COMPOUND_STRING("Shop: Cinderpine") },
    { OUTFIT_HOLLOW_MASK,  OUTFIT_SLOT_ACCESSORY, COMPOUND_STRING("Hollow Mask"),   COMPOUND_STRING("Dungeon: The Hollow") },
};

#define OUTFIT_DEF_COUNT ARRAY_COUNT(sOutfitDefs)

// ---- Core API ----

void Wardrobe_Init(struct WardrobeState *state)
{
    u8 i;
    for (i = 0; i < OUTFIT_SLOT_COUNT; i++)
        state->equipped[i] = OUTFIT_NONE;
    state->unlockedBitmap[0] = 0;
    state->unlockedBitmap[1] = 0;
}

void Wardrobe_Unlock(struct WardrobeState *state, u8 outfitId)
{
    if (outfitId == OUTFIT_NONE || outfitId >= 64)
        return;
    if (outfitId < 32)
        state->unlockedBitmap[0] |= (1u << outfitId);
    else
        state->unlockedBitmap[1] |= (1u << (outfitId - 32));
    // Set the corresponding flag so scripts can check it
    FlagSet(FLAG_OUTFIT_APRON + (outfitId - 1));
}

bool8 Wardrobe_IsUnlocked(const struct WardrobeState *state, u8 outfitId)
{
    if (outfitId == OUTFIT_NONE)
        return TRUE;
    if (outfitId >= 64)
        return FALSE;
    if (outfitId < 32)
        return (state->unlockedBitmap[0] >> outfitId) & 1;
    else
        return (state->unlockedBitmap[1] >> (outfitId - 32)) & 1;
}

void Wardrobe_Equip(struct WardrobeState *state, u8 slot, u8 outfitId)
{
    if (slot >= OUTFIT_SLOT_COUNT)
        return;
    if (!Wardrobe_IsUnlocked(state, outfitId))
        return;
    state->equipped[slot] = outfitId;
}

u8 Wardrobe_GetEquipped(const struct WardrobeState *state, u8 slot)
{
    if (slot >= OUTFIT_SLOT_COUNT)
        return OUTFIT_NONE;
    return state->equipped[slot];
}

bool8 Wardrobe_IsCampSetEquipped(const struct WardrobeState *state)
{
    return (state->equipped[OUTFIT_SLOT_TOP]    == OUTFIT_CAMP_TOP   &&
            state->equipped[OUTFIT_SLOT_BOTTOM] == OUTFIT_CAMP_PANTS &&
            state->equipped[OUTFIT_SLOT_SHOES]  == OUTFIT_CAMP_BOOTS);
}

// ---- Menu stub ----
// Full paper-doll UI requires custom window/sprite work (see TASKS.md).
// This stub opens a placeholder message and returns to the field.

static void Task_WardrobeMenuClose(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

void Task_OpenWardrobeFromStartMenu(u8 taskId)
{
    // TODO: Replace with full paper-doll UI (see TASKS.md §2.2).
    // For now, display a placeholder message so the menu entry works.
    StringCopy(gStringVar1, COMPOUND_STRING("WARDROBE"));
    StringCopy(gStringVar2, COMPOUND_STRING("(Full UI pending — see TASKS.md)"));
    ShowFieldMessage(COMPOUND_STRING("WARDROBE\nFull outfit UI coming soon!"));
    gTasks[taskId].func = Task_WardrobeMenuClose;
}

bool8 StartMenuWardrobeCallback(void)
{
    CreateTask(Task_OpenWardrobeFromStartMenu, 0);
    return TRUE;
}
