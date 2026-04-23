#ifndef GUARD_LEVEL_UP_LEARNSETS_DAYDREAM_H
#define GUARD_LEVEL_UP_LEARNSETS_DAYDREAM_H

// ============================================================
// Pokémon Daydream Version — Level-Up Learnsets
// Include in src/data/pokemon/level_up_learnsets.h
// ============================================================

#include "constants/moves.h"
#include "constants/moves_daydream.h"

// ---- Lullsparce (inherits Dunsparce + signature) ----
static const struct LevelUpMove sLullsparceLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_DEFENSE_CURL),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 4, MOVE_ROLLOUT),
    LEVEL_UP_MOVE( 9, MOVE_HEADBUTT),
    LEVEL_UP_MOVE(12, MOVE_ANCIENT_POWER),
    LEVEL_UP_MOVE(17, MOVE_BITE),
    LEVEL_UP_MOVE(20, MOVE_YAWN),
    LEVEL_UP_MOVE(25, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(28, MOVE_CALM_MIND),
    LEVEL_UP_MOVE(33, MOVE_GLARE),
    LEVEL_UP_MOVE(36, MOVE_SCREECH),
    LEVEL_UP_MOVE(40, MOVE_DAYDREAM_BEAM),   // Signature move
    LEVEL_UP_MOVE(44, MOVE_DOUBLE_EDGE),
    LEVEL_UP_MOVE(50, MOVE_ENDEAVOR),
    LEVEL_UP_END
};

// ---- Stagsomne (inherits Stantler + signature) ----
static const struct LevelUpMove sStagsomneLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_LEER),
    LEVEL_UP_MOVE( 5, MOVE_ASTONISH),
    LEVEL_UP_MOVE(10, MOVE_HYPNOSIS),
    LEVEL_UP_MOVE(14, MOVE_STOMP),
    LEVEL_UP_MOVE(19, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE(23, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(28, MOVE_CONFUSE_RAY),
    LEVEL_UP_MOVE(32, MOVE_CALM_MIND),
    LEVEL_UP_MOVE(38, MOVE_HUSH_HOOVES),     // Signature move
    LEVEL_UP_MOVE(42, MOVE_MEGAHORN),
    LEVEL_UP_MOVE(48, MOVE_DREAM_EATER),
    LEVEL_UP_MOVE(54, MOVE_PLAY_ROUGH),
    LEVEL_UP_END
};

// ---- Wobbusnore (inherits Wobbuffet + signature) ----
static const struct LevelUpMove sWobbusnoreLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_SPLASH),
    LEVEL_UP_MOVE( 1, MOVE_COUNTER),
    LEVEL_UP_MOVE( 1, MOVE_MIRROR_COAT),
    LEVEL_UP_MOVE( 1, MOVE_SAFEGUARD),
    LEVEL_UP_MOVE( 1, MOVE_DESTINY_BOND),
    LEVEL_UP_MOVE(44, MOVE_PINE_SLUMBER),    // Signature (flavour crossover)
    LEVEL_UP_END
};

// ---- Delcatnap (inherits Delcatty + signature) ----
static const struct LevelUpMove sDelcatnapLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_FAKE_OUT),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_TAIL_WHIP),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 5, MOVE_ATTRACT),
    LEVEL_UP_MOVE(10, MOVE_SING),
    LEVEL_UP_MOVE(15, MOVE_DOUBLE_SLAP),
    LEVEL_UP_MOVE(20, MOVE_CHARM),
    LEVEL_UP_MOVE(25, MOVE_ASSIST),
    LEVEL_UP_MOVE(30, MOVE_WAKE_UP_SLAP),
    LEVEL_UP_MOVE(36, MOVE_KNEAD),           // Signature move
    LEVEL_UP_MOVE(42, MOVE_PLAY_ROUGH),
    LEVEL_UP_MOVE(48, MOVE_HYPER_VOICE),
    LEVEL_UP_END
};

// ---- Spindream (inherits Spinda + signature) ----
static const struct LevelUpMove sSpindreamLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_UPROAR),
    LEVEL_UP_MOVE( 5, MOVE_COPYCAT),
    LEVEL_UP_MOVE(10, MOVE_FEINT_ATTACK),
    LEVEL_UP_MOVE(15, MOVE_PSYBEAM),
    LEVEL_UP_MOVE(20, MOVE_HYPNOSIS),
    LEVEL_UP_MOVE(25, MOVE_DIZZY_PUNCH),
    LEVEL_UP_MOVE(30, MOVE_SUCKER_PUNCH),
    LEVEL_UP_MOVE(35, MOVE_TEETER_DANCE),
    LEVEL_UP_MOVE(40, MOVE_VIVID_SPIN),      // Signature move
    LEVEL_UP_MOVE(45, MOVE_DOUBLE_EDGE),
    LEVEL_UP_MOVE(50, MOVE_THRASH),
    LEVEL_UP_END
};

// ---- Mr. Mimic (inherits Mr. Mime + signature) ----
static const struct LevelUpMove sMrMimicLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_MIMIC),
    LEVEL_UP_MOVE( 1, MOVE_CONFUSION),
    LEVEL_UP_MOVE( 1, MOVE_POUND),
    LEVEL_UP_MOVE( 5, MOVE_ENCORE),
    LEVEL_UP_MOVE(10, MOVE_PSYBEAM),
    LEVEL_UP_MOVE(15, MOVE_BARRIER),
    LEVEL_UP_MOVE(20, MOVE_LIGHT_SCREEN),
    LEVEL_UP_MOVE(25, MOVE_REFLECT),
    LEVEL_UP_MOVE(30, MOVE_PSYCH_UP),
    LEVEL_UP_MOVE(35, MOVE_TRICK),
    LEVEL_UP_MOVE(40, MOVE_PSYCHIC),
    LEVEL_UP_MOVE(45, MOVE_DAYDREAM_BEAM),   // Shared signature
    LEVEL_UP_MOVE(50, MOVE_SHADOW_BALL),
    LEVEL_UP_MOVE(55, MOVE_DAZZLING_GLEAM),
    LEVEL_UP_END
};

// ---- Snorpine (inherits Snorlax + signature) ----
static const struct LevelUpMove sSnorpineLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_DEFENSE_CURL),
    LEVEL_UP_MOVE( 1, MOVE_AMNESIA),
    LEVEL_UP_MOVE( 1, MOVE_LICK),
    LEVEL_UP_MOVE( 9, MOVE_BELLY_DRUM),
    LEVEL_UP_MOVE(17, MOVE_HEADBUTT),
    LEVEL_UP_MOVE(25, MOVE_BODY_SLAM),
    LEVEL_UP_MOVE(33, MOVE_REST),
    LEVEL_UP_MOVE(41, MOVE_SLEEP_TALK),
    LEVEL_UP_MOVE(49, MOVE_GIGA_IMPACT),
    LEVEL_UP_MOVE(52, MOVE_PINE_SLUMBER),    // Signature move
    LEVEL_UP_MOVE(57, MOVE_WOOD_HAMMER),
    LEVEL_UP_MOVE(62, MOVE_HEAVY_SLAM),
    LEVEL_UP_END
};

// ---- Drampire (inherits Drampa + signature) ----
static const struct LevelUpMove sDrampireLearnset[] =
{
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_LEER),
    LEVEL_UP_MOVE( 5, MOVE_DRAGON_RAGE),
    LEVEL_UP_MOVE(10, MOVE_HYPER_VOICE),
    LEVEL_UP_MOVE(15, MOVE_BITE),
    LEVEL_UP_MOVE(20, MOVE_DRAGON_BREATH),
    LEVEL_UP_MOVE(25, MOVE_ROOST),
    LEVEL_UP_MOVE(30, MOVE_DRAGON_PULSE),
    LEVEL_UP_MOVE(35, MOVE_ECHOED_VOICE),
    LEVEL_UP_MOVE(40, MOVE_SHADOW_BALL),
    LEVEL_UP_MOVE(45, MOVE_HYPER_VOICE),
    LEVEL_UP_MOVE(50, MOVE_DRAGON_DANCE),
    LEVEL_UP_MOVE(55, MOVE_BEDTIME_STORY),   // Signature move
    LEVEL_UP_MOVE(60, MOVE_OUTRAGE),
    LEVEL_UP_END
};

#endif // GUARD_LEVEL_UP_LEARNSETS_DAYDREAM_H
