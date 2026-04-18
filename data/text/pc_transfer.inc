gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} was sent to\n"
	.string "SOMEONE'S PC.\p"
	.string "It’s stashed in\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} was sent to\n"
#if IS_FRLG
	.string "BILL'S PC.\p"
#else
	.string "LANETTE'S PC.\p"
#endif
	.string "It’s stashed in\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "BOX “{STR_VAR_3}” on\n"
	.string "SOMEONE'S PC was rammed.\p"
	.string "{STR_VAR_2} was moved to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "BOX “{STR_VAR_3}” on\n"
#if IS_FRLG
	.string "BILL'S PC was rammed.\p"
#else
	.string "LANETTE'S PC was rammed.\p"
#endif
	.string "{STR_VAR_2} was moved to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} was sent to\n"
	.string "{B_PC_CREATOR_NAME} PC.\p"
	.string "It’s stashed in\n"
	.string "BOX “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} copped\n"
	.string "the {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "No space left for POKéMON!\p"
	.string "The BOXES are full—you can’t\n"
	.string "fit any more of the squad in!$"

gText_NicknameThisPokemon::
	.string "You wanna give a nickname to\n"
	.string "this {STR_VAR_1}?$"

