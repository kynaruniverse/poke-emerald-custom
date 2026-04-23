@ ============================================================
@ Pokémon Daydream Version — Camp Script
@ data/scripts/daydream/camp.inc
@
@ Called from ItemUseOutOfBattle_Bedroll() via Camp_StartCamp().
@ Handles the cook submenu and sleep cycle.
@ ============================================================

Camp_Main::
    @ This script is called after the pitch animation completes.
    @ The C-side Task_CampPitchAnim handles the menu directly.
    @ This script is a fallback for script-driven camp events.
    msgbox Camp_SetupText, MSGBOX_DEFAULT
    special NeedsFillAllRest
    special HealPlayerParty
    end

Camp_Cook::
    @ Called when player selects COOK at camp.
    @ Checks for a berry in the bag and consumes it.
    checkitemtype ITEM_ORAN_BERRY
    compare VAR_RESULT, 1
    goto_if_eq Camp_CookBerry
    checkitemtype ITEM_SITRUS_BERRY
    compare VAR_RESULT, 1
    goto_if_eq Camp_CookBerry
    msgbox Camp_NoBerries, MSGBOX_DEFAULT
    end

Camp_CookBerry::
    removeitem ITEM_ORAN_BERRY, 1
    special NeedsFillAllHunger
    msgbox Camp_CookedText, MSGBOX_DEFAULT
    end

@ ---- Text ----

Camp_SetupText:
    .string "Camp set up!\n"
    .string "The party rested well.$"

Camp_NoBerries:
    .string "No berries to cook with.$"

Camp_CookedText:
    .string "Cooked a meal!\n"
    .string "The party's Hunger improved.$"
