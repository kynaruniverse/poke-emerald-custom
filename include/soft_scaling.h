#ifndef GUARD_SOFT_SCALING_H
#define GUARD_SOFT_SCALING_H

// ============================================================
// Pokémon Daydream Version — Soft Level Scaling
// ============================================================

// Scale a designer-assigned trainer Pokémon level based on
// the current VAR_STORY_TIER (0–10).
// Returns the scaled level (never below designerBase).
u8 ScaleLevel(u8 designerBase);

// Get / set / advance the story tier.
u16 GetStoryTier(void);
void SetStoryTier(u16 tier);
void AdvanceStoryTier(void);

#endif // GUARD_SOFT_SCALING_H
