@ ============================================================
@ Pokémon Daydream Version — Loafsbury Patty NPC Script
@ data/scripts/daydream/loafsbury_patty.inc
@
@ Patty is the baker in Loafsbury. She gives the player the
@ Bakery Run quest (QUEST_BAKERY_RUN) and the Apron outfit.
@ ============================================================

LoafsburyPatty::
    lock
    faceplayer
    @ Check if quest is already complete
    goto_if_set FLAG_QUEST_BAKERY_RUN_DONE, LoafsburyPatty_Done
    @ Check current quest state
    setvar VAR_ACTIVE_QUEST_ID, QUEST_BAKERY_RUN
    special QuestPeek
    compare VAR_QUEST_RESULT, QSTATE_NOT_STARTED
    goto_if_eq LoafsburyPatty_Offer
    compare VAR_QUEST_RESULT, QSTATE_STEP_2
    goto_if_eq LoafsburyPatty_Step2
    compare VAR_QUEST_RESULT, QSTATE_STEP_3
    goto_if_eq LoafsburyPatty_Complete
    @ Mid-quest reminder
    msgbox LoafsburyPatty_Reminder, MSGBOX_DEFAULT
    release
    end

LoafsburyPatty_Offer:
    msgbox LoafsburyPatty_OfferText, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq LoafsburyPatty_Decline
    @ Start the quest
    setvar VAR_ACTIVE_QUEST_ID, QUEST_BAKERY_RUN
    special QuestStart
    giveitem ITEM_BREAD_BUNDLE, 5
    msgbox LoafsburyPatty_QuestStarted, MSGBOX_DEFAULT
    release
    end

LoafsburyPatty_Step2:
    msgbox LoafsburyPatty_Step2Text, MSGBOX_DEFAULT
    special QuestAdvance
    release
    end

LoafsburyPatty_Complete:
    msgbox LoafsburyPatty_CompleteText, MSGBOX_DEFAULT
    setvar VAR_ACTIVE_QUEST_ID, QUEST_BAKERY_RUN
    special QuestComplete
    setflag FLAG_QUEST_BAKERY_RUN_DONE
    @ Unlock the Apron outfit
    special WardrobeUnlockApron
    giveitem ITEM_OUTFIT_VOUCHER, 1
    release
    end

LoafsburyPatty_Done:
    msgbox LoafsburyPatty_DoneText, MSGBOX_DEFAULT
    release
    end

LoafsburyPatty_Decline:
    msgbox LoafsburyPatty_DeclineText, MSGBOX_DEFAULT
    release
    end

@ ---- Text ----

LoafsburyPatty_OfferText:
    .string "Patty: Oh good, you're here.\n"
    .string "Five loaves need to reach the dock\n"
    .string "before they go cold. You look like\n"
    .string "someone with nothing better to do.\n"
    .string "Take the job?$"

LoafsburyPatty_QuestStarted:
    .string "Patty: Don't dawdle. Bread waits\n"
    .string "for no one.$"

LoafsburyPatty_Reminder:
    .string "Patty: The dock. The loaves.\n"
    .string "Still waiting.$"

LoafsburyPatty_Step2Text:
    .string "Patty: Three down. Two to go.\n"
    .string "Move it!$"

LoafsburyPatty_CompleteText:
    .string "Patty: All five. On time. Barely.\n"
    .string "Here — take the apron. You've\n"
    .string "earned the look, at least.$"

LoafsburyPatty_DoneText:
    .string "Patty: The dock thanks you.\n"
    .string "Probably.$"

LoafsburyPatty_DeclineText:
    .string "Patty: Fine. The loaves will\n"
    .string "get cold. That's on you.$"
