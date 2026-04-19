AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro::
	.string "What you looking at? You got a problem\n"
	.string "with me bringing my inner tube?\l"
	.string "Mind your business, fam!$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat::
	.string "Allow it, you actually caught me\n"
	.string "off guard there.$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle::
	.string "Hard to move correctly when you're\n"
	.string "clutching onto a tube, you get me?$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere::
	.string "This spot is moving, you know?\n"
	.string "Feels like anything could happen in\l"
	.string "a wreck like this. Proper hype!$"

