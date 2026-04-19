AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner::
	.string "I’m out here doing shifts for STERN,\n"
	.string "but this place is a bin.\p"
	.string "He’s onto me about some SCANNER thing,\n"
	.string "but I haven't seen a thing. Stressful.$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner::
	.string "Wait, you actually found it?\p"
	.string "Listen, do me a solid and take that\n"
	.string "to STERN yourself, yeah?\p"
	.string "I’m gonna stay here and... uh... keep\n"
	.string "investigating. Definitely not napping.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus::
	.string "The S.S. CACTUS. Ancient tech, fam.\n"
	.string "Proper old school.$"

