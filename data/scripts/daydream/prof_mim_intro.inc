@ ============================================================
@ Pokémon Daydream Version — Prof. Mim Intro Script
@ data/scripts/daydream/prof_mim_intro.inc
@
@ Daydream-style: 4 textboxes maximum. No hand-holding.
@ The player overslept the ceremony. The good starters are gone.
@ ============================================================

ProfMim_Intro::
    lock
    faceplayer
    goto_if_set FLAG_PROF_MIM_INTRO_DONE, ProfMim_PostIntro
    msgbox ProfMim_Line1, MSGBOX_DEFAULT
    msgbox ProfMim_Line2, MSGBOX_DEFAULT
    @ Player picks from the 'leftovers' box
    special ShowStarterSelectionMenu
    @ After selection:
    msgbox ProfMim_Line3, MSGBOX_DEFAULT
    setflag FLAG_PROF_MIM_INTRO_DONE
    setflag FLAG_SYS_POKEMON_GET
    release
    end

ProfMim_PostIntro:
    msgbox ProfMim_PostIntroText, MSGBOX_DEFAULT
    release
    end

@ ---- Text (Daydream-style: short, dry, comedic) ----

ProfMim_Line1:
    .string "Prof. Mim: You're late.$"

ProfMim_Line2:
    .string "Prof. Mim: The good starters got\n"
    .string "picked yesterday. Box's by the door.$"

@ (Player picks starter here)

ProfMim_Line3:
    .string "Prof. Mim: Try not to nap on\n"
    .string "Route 1. Try.$"

ProfMim_PostIntroText:
    .string "Prof. Mim: Still here?$"
