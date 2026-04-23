// ============================================================
// Pokémon Daydream Version — Soft Level Scaling
// src/daydream/soft_scaling.c
//
// ScaleLevel() wraps trainer party level generation.
// Hook into CreateNPCTrainerPartyForTrainer() in battle_setup.c:
//   party[i].level = ScaleLevel(designerLevel);
// ============================================================

#include "global.h"
#include "soft_scaling.h"
#include "script.h"
#include "constants/vars_daydream.h"

// ---- Scaling formula ----
// tier 0: keeps base level
// Each tier adds ~10% of (ceiling - base) toward (30 + tier*5).
// Designer base is never reduced — scaling only raises.
//
// Example at tier 3 (ceiling = 45):
//   base 20 → 20 + (45-20)/3 = 20 + 8 = 28
//   base 50 → 50 (already above ceiling, unchanged)

u8 ScaleLevel(u8 designerBase)
{
    u16 tier    = VarGet(VAR_STORY_TIER);
    u8  ceiling = 30 + (u8)(tier * 5);

    if (designerBase >= ceiling)
        return designerBase;

    return designerBase + (u8)((ceiling - designerBase) / 3);
}

// ---- Story tier helpers ----

u16 GetStoryTier(void)
{
    return VarGet(VAR_STORY_TIER);
}

void SetStoryTier(u16 tier)
{
    if (tier > 10)
        tier = 10;
    VarSet(VAR_STORY_TIER, tier);
}

void AdvanceStoryTier(void)
{
    u16 current = VarGet(VAR_STORY_TIER);
    if (current < 10)
        VarSet(VAR_STORY_TIER, current + 1);
}
