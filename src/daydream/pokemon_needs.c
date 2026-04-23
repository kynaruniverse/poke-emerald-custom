// ============================================================
// Pokémon Daydream Version — Needs Simulator Implementation
// src/daydream/pokemon_needs.c
// ============================================================

#include "global.h"
#include "pokemon.h"
#include "pokemon_needs.h"
#include "random.h"

// ---- Per-need step accumulator (not saved — resets on power-off) ----
static u16 sStepAccum[NEED_COUNT];

// ---- Per-mon needs storage ----
// Stored in a parallel array to gPlayerParty.
// Indexed by party slot 0–5. Reset to NEED_DEFAULT on init.
// NOTE: These are NOT saved in BoxPokemon. On box deposit they are lost;
// on withdraw or CreateMon they are set to NEED_DEFAULT.
static u8 sPartyNeeds[PARTY_SIZE][NEED_COUNT];

// ---- Groggy flag: set on battle entry if REST is Suffering ----
static bool8 sGroggyFlags[PARTY_SIZE];

// ---- Internal helpers ----

static u8 ClampNeed(s16 value)
{
    if (value < 0)   return 0;
    if (value > NEED_MAX) return NEED_MAX;
    return (u8)value;
}

// ---- Public API ----

void NeedsInitMon(u8 partyIndex)
{
    u8 n;
    if (partyIndex >= PARTY_SIZE)
        return;
    for (n = 0; n < NEED_COUNT; n++)
        sPartyNeeds[partyIndex][n] = NEED_DEFAULT;
    sGroggyFlags[partyIndex] = FALSE;
}

u8 GetNeedValue(u8 partyIndex, u8 need)
{
    if (partyIndex >= PARTY_SIZE || need >= NEED_COUNT)
        return NEED_DEFAULT;
    return sPartyNeeds[partyIndex][need];
}

u8 GetNeedState(u8 partyIndex, u8 need)
{
    u8 v = GetNeedValue(partyIndex, need);
    if (v >= NEED_THRIVING)  return NEED_THRIVING;
    if (v >= NEED_CONTENT)   return NEED_CONTENT;
    if (v >= NEED_RESTLESS)  return NEED_RESTLESS;
    return NEED_SUFFERING;
}

void FillNeed(u8 partyIndex, u8 need, u8 amount)
{
    if (partyIndex >= PARTY_SIZE || need >= NEED_COUNT)
        return;
    sPartyNeeds[partyIndex][need] = ClampNeed((s16)sPartyNeeds[partyIndex][need] + amount);
}

void FillAllNeeds(u8 amount)
{
    u8 i, n;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;
        for (n = 0; n < NEED_COUNT; n++)
            FillNeed(i, n, amount);
    }
}

void NeedsTickOnStep(void)
{
    static const u8 sDivisors[NEED_COUNT] = {
        NEED_HUNGER_STEP_DIVISOR,
        NEED_ATTENTION_STEP_DIVISOR,
        NEED_REST_STEP_DIVISOR,
    };
    u8 n, i;

    for (n = 0; n < NEED_COUNT; n++)
    {
        sStepAccum[n]++;
        if (sStepAccum[n] >= (1u << sDivisors[n]))
        {
            sStepAccum[n] = 0;
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
                    continue;
                if (sPartyNeeds[i][n] > 0)
                    sPartyNeeds[i][n]--;
            }
        }
    }
}

void NeedsTickOnBattleEnd(void)
{
    static const u8 sBattleDecay[NEED_COUNT] = {
        NEED_HUNGER_BATTLE_DECAY,
        NEED_ATTENTION_BATTLE_DECAY,
        NEED_REST_BATTLE_DECAY,
    };
    u8 n, i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
            continue;
        for (n = 0; n < NEED_COUNT; n++)
        {
            s16 newVal = (s16)sPartyNeeds[i][n] - sBattleDecay[n];
            sPartyNeeds[i][n] = ClampNeed(newVal);
        }
        // Set groggy flag if REST is Suffering after the battle
        sGroggyFlags[i] = (sPartyNeeds[i][NEED_REST] <= NEED_SUFFERING);
    }
}

u32 ApplyNeedsDamageModifier(u32 dmg, u8 attackerPartyIndex)
{
    u8 hunger;
    if (attackerPartyIndex >= PARTY_SIZE)
        return dmg;
    hunger = sPartyNeeds[attackerPartyIndex][NEED_HUNGER];
    if (hunger >= NEED_THRIVING)
        return (dmg * NEED_HUNGER_BONUS_PCT) / 100;
    if (hunger <= NEED_SUFFERING)
        return (dmg * NEED_HUNGER_PENALTY_PCT) / 100;
    return dmg;
}

bool8 NeedsIsGroggy(u8 partyIndex)
{
    if (partyIndex >= PARTY_SIZE)
        return FALSE;
    if (!sGroggyFlags[partyIndex])
        return FALSE;
    // 25% random chance to actually skip
    return ((Random() % 100) < NEED_GROGGY_CHANCE);
}
