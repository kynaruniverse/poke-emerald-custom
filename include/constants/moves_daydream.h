#ifndef GUARD_CONSTANTS_MOVES_DAYDREAM_H
#define GUARD_CONSTANTS_MOVES_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — New Move Constants
// IDs begin after LAST_MAX_MOVE (MOVE_G_MAX_RAPID_FLOW).
// ============================================================

// MOVE_HUSH_HOOVES
// Stagsomne's signature move. Normal/Fairy-type physical move.
// Power: 90 | Acc: 100 | PP: 10
// Silences the target for 2 turns (prevents sound-based moves).
#define MOVE_HUSH_HOOVES        (LAST_MAX_MOVE + 1)

// MOVE_VIVID_SPIN
// Spindream's signature move. Normal/Psychic-type special move.
// Power: 80 | Acc: 95 | PP: 10
// Hits 2–5 times; each hit has a 10% chance to confuse.
#define MOVE_VIVID_SPIN         (LAST_MAX_MOVE + 2)

// MOVE_KNEAD
// Delcatnap's signature move. Normal/Fairy-type status move.
// PP: 10
// Restores 50% of the user's max HP and cures its own status.
#define MOVE_KNEAD              (LAST_MAX_MOVE + 3)

// MOVE_PINE_SLUMBER
// Snorpine's signature move. Normal/Grass-type physical move.
// Power: 100 | Acc: 90 | PP: 5
// User falls asleep for 1 turn after use (Rest-lite).
#define MOVE_PINE_SLUMBER       (LAST_MAX_MOVE + 4)

// MOVE_BEDTIME_STORY
// Drampire's signature move. Dragon/Ghost-type special move.
// Power: 110 | Acc: 85 | PP: 5
// Has a 30% chance to put the target to sleep.
#define MOVE_BEDTIME_STORY      (LAST_MAX_MOVE + 5)

// MOVE_DAYDREAM_BEAM
// Lullsparce's signature move. Normal/Psychic-type special move.
// Power: 95 | Acc: 100 | PP: 10
// 20% chance to make the target infatuated (if opposite gender).
#define MOVE_DAYDREAM_BEAM      (LAST_MAX_MOVE + 6)

// Total new moves
#define MOVES_COUNT_DAYDREAM    (MOVE_DAYDREAM_BEAM + 1)

#endif // GUARD_CONSTANTS_MOVES_DAYDREAM_H
