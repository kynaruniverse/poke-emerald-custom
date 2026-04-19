CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "So, you are the one they call {PLAYER}?\n"
	.string "The whispers of your grace in battle\l"
	.string "have reached even these depths.\p"
	.string "I am WALLACE. I seek the truth\n"
	.string "hidden within the ripples of time.\p"
	.string "Once, I held the mantle of the\n"
	.string "SOOTOPOLIS GYM LEADER, but duty\l"
	.string "called me to a higher purpose.\p"
	.string "I have left the GYM in the masterful\n"
	.string "hands of my mentor, JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "The titans GROUDON and KYOGRE…\n"
	.string "their clash threatens to unravel\l"
	.string "the very fabric of Hoenn.\p"
	.string "Yet, legends speak of a third\n"
	.string "super-ancient power.\p"
	.string "An emerald sovereign that dwells\n"
	.string "among the stars: RAYQUAZA.\p"
	.string "It was RAYQUAZA who descended in\n"
	.string "eons past to silence the warring\l"
	.string "elements and bring peace.\p"
	.string "But alas… even I cannot see through\n"
	.string "the clouds to its current rest…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}, I implore you…\n"
	.string "Do you know where the sky lord\l"
	.string "RAYQUAZA slumbers?\p"
	.string "If you have seen the way, lead me.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: The CAVE OF ORIGIN?\p"
	.string "My dear Trainer, look around you.\n"
	.string "We stand within its heart already!\p"
	.string "Please, search your spirit. Where\n"
	.string "else would the Dragon of Heaven go?$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "A place of spirits, yes… but when\n"
	.string "I spoke with the caretaker there,\l"
	.string "she offered no such omen.\p"
	.string "She is a woman of deep honesty;\n"
	.string "she would not mask the truth from me.\p"
	.string "{PLAYER}, take a deep breath and\n"
	.string "search your memories once more.$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Gone? Your memory has\n"
	.string "faded like mist on the water?\p"
	.string "This is a grave tragedy…\n"
	.string "Surely some spark remains?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: The SKY PILLAR!\p"
	.string "Of course! The ancient spire that\n"
	.string "pierces the celestial veil!\p"
	.string "{PLAYER}, the stars have aligned!\n"
	.string "I shall make for the SKY PILLAR\l"
	.string "with the swiftness of the tide!$"

