AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething::
	.string "Allow it! What you doing lurking 'round\n"
	.string "the ends? TEAM AQUA business only.\p"
	.string "The BIG MAN ain't here. He’s out\n"
	.string "securing the bag.\p"
	.string "… …\n"
	.string "Where'd he go?\p"
	.string "Allow it! You think I'm gonna dry him\n"
	.string "out to some random like you?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe::
	.string "What? What?\n"
	.string "You rolling with TEAM MAGMA?\p"
	.string "I heard them man are trying to wake\n"
	.string "some beast at their base.\p"
	.string "But where's their spot even at?$"

AquaHideout_1F_Text_BossWentToJackASubmarine::
	.string "Move from here! What you want with\n"
	.string "TEAM AQUA?\p"
	.string "The BOSS is busy! He’s gone to jack\n"
	.string "a submarine for the crew.\p"
	.string "… …\n"
	.string "Where'd he go?\p"
	.string "Safe... like I'm gonna give you the\n"
	.string "location just like that. Jog on.$"

AquaHideout_1F_Text_BossIsOnRoute122::
	.string "Yo, back up! What you want with\n"
	.string "TEAM AQUA?\p"
	.string "BOSS is moving. He’s headed to\n"
	.string "MT. PYRE on ROUTE 122.\p"
	.string "… …\n"
	.string "Why'd he go?\p"
	.string "I ain't saying nothing. You're proper\n"
	.string "nosey, you know that?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney::
	.string "What's the motive?\n"
	.string "You one of those MAGMA jokers?\p"
	.string "I heard MAGMA are chasing some\n"
	.string "crazy POKéMON at MT. CHIMNEY.\p"
	.string "Wonder what that beast even looks like.$"

AquaHideout_1F_Text_BossIsInSlateportCity::
	.string "Safe... what you want with the mandem?\p"
	.string "BOSS is on road. He’s making a moves\n"
	.string "down in SLATEPORT CITY.\p"
	.string "… …\n"
	.string "Why?\p"
	.string "You ask too many questions, fam.\n"
	.string "Get lost.$"

AquaHideout_1F_Text_Grunt1Intro::
	.string "Yo! Who's this random in the base?\n"
	.string "Spotting a snitch!$"

AquaHideout_1F_Text_Grunt1Defeat::
	.string "Rah…\n"
	.string "I’m finished!$"

AquaHideout_1F_Text_Grunt1PostBattle::
	.string "I took the L for the gang, but I\n"
	.string "held the line long enough.$"

