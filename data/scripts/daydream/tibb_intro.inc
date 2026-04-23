@ ============================================================
@ Pokémon Daydream Version — Tibb Rival Intro Script
@ data/scripts/daydream/tibb_intro.inc
@
@ Tibb challenges the player to a 'who can nap longest' contest.
@ He loses. Then he challenges you to a battle.
@ ============================================================

Tibb_Intro::
    lock
    faceplayer
    goto_if_set FLAG_TIBB_INTRO_DONE, Tibb_PostIntro
    msgbox Tibb_Line1, MSGBOX_DEFAULT
    msgbox Tibb_Line2, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Tibb_Decline
    @ Tibb loses the nap contest immediately
    msgbox Tibb_Line3, MSGBOX_DEFAULT
    @ Tibb challenges to a battle
    trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_TIBB_1, 0, Tibb_Intro_BattleText, Tibb_Intro_DefeatText
    msgbox Tibb_Line4, MSGBOX_DEFAULT
    setflag FLAG_TIBB_INTRO_DONE
    release
    end

Tibb_Decline:
    msgbox Tibb_DeclineText, MSGBOX_DEFAULT
    release
    end

Tibb_PostIntro:
    msgbox Tibb_PostIntroText, MSGBOX_DEFAULT
    release
    end

@ ---- Text ----

Tibb_Line1:
    .string "Tibb: Oh. You're up.\n"
    .string "I've been awake for six minutes.\n"
    .string "Personal record.$"

Tibb_Line2:
    .string "Tibb: Nap contest. First one to\n"
    .string "fall asleep wins. You in?$"

Tibb_Line3:
    .string "Tibb: ...I'm already awake again.\n"
    .string "That doesn't count.\n"
    .string "Let's just battle.$"

Tibb_Intro_BattleText:
    .string "Tibb: I'm not actually tired.$"

Tibb_Intro_DefeatText:
    .string "Tibb: Okay. You're better at\n"
    .string "being awake than me. For now.$"

Tibb_Line4:
    .string "Tibb: I'll get you next time.\n"
    .string "Probably while you're napping.$"

Tibb_DeclineText:
    .string "Tibb: Coward. Or just tired.\n"
    .string "Same thing, really.$"

Tibb_PostIntroText:
    .string "Tibb: Still going, huh.$"
