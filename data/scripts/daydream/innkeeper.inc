@ ============================================================
@ Pokémon Daydream Version — The Innkeeper NPC Script
@ data/scripts/daydream/innkeeper.inc
@
@ The Innkeeper sells Bedrolls, gives Rest tips, and gives
@ the Camp Tutorial quest. Staying at the Inn fully restores
@ the REST need for all party Pokémon.
@ ============================================================

Innkeeper_Main::
    lock
    faceplayer
    goto_if_set FLAG_INNKEEPER_MET, Innkeeper_Return
    @ First meeting
    msgbox Innkeeper_FirstMeet, MSGBOX_DEFAULT
    setflag FLAG_INNKEEPER_MET
    @ Give camp tutorial quest
    setvar VAR_ACTIVE_QUEST_ID, QUEST_CAMP_TUTORIAL
    special QuestStart
    giveitem ITEM_BEDROLL, 1
    msgbox Innkeeper_GiveBedroll, MSGBOX_DEFAULT
    release
    end

Innkeeper_Return::
    msgbox Innkeeper_WelcomeBack, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq Innkeeper_Rest
    msgbox Innkeeper_Goodbye, MSGBOX_DEFAULT
    release
    end

Innkeeper_Rest::
    @ Fully restore REST for all party Pokémon
    special NeedsFillAllRest
    @ Heal HP at Pokémon Center too
    special HealPlayerParty
    msgbox Innkeeper_Rested, MSGBOX_DEFAULT
    release
    end

@ ---- Text ----

Innkeeper_FirstMeet:
    .string "Innkeeper: You look exhausted.\n"
    .string "Most people do, around here.\n"
    .string "Take this bedroll. Use it outdoors\n"
    .string "when you need to rest.$"

Innkeeper_GiveBedroll:
    .string "Innkeeper: Soft ground only.\n"
    .string "The Pokémon will thank you.$"

Innkeeper_WelcomeBack:
    .string "Innkeeper: Back already?\n"
    .string "Want to rest? It's free.$"

Innkeeper_Rested:
    .string "Innkeeper: Good.\n"
    .string "You all look better.$"

Innkeeper_Goodbye:
    .string "Innkeeper: Suit yourself.\n"
    .string "The beds will be here.$"
