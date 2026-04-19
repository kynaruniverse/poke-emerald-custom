CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "Listen, I’m the one coding the ends.\n"
	.string "One wrong line and the whole ends\l"
	.string "get dashed, you get me?\p"
	.string "Man’s really out here making sure\n"
	.string "the map don't glitch out.$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "I’m the one making everything look\n"
	.string "cold. I designed your whole fit!\p"
	.string "You’re looking proper sharp because\n"
	.string "I put in the work. Lowkey iconic.$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "I’m the one who wrote the script.\n"
	.string "I decided you were the main man!\p"
	.string "I even gave that old man in Viridian\n"
	.string "too much juice so he’d block the way.\l"
	.string "Pure jokes, innit?$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
	.string "Safe, I’m the big boss designer.\n"
	.string "I built this whole bits from scratch.\p"
	.string "You think you’re a top boy?\n"
	.string "Go catch every single mon in the\l"
	.string "ends and come holla at me.$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "Mad! You’ve actually done it!\n"
	.string "You’ve bagged every single mon!\l"
	.string "Real talk, that’s legendary.\p"
	.string "Take this certificate. Let everyone\n"
	.string "know you’re the realest!$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "The screen is moving bare fast.\n"
	.string "It’s the source code for the ends.\l"
	.string "Don't touch it, you’ll tech the game!$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "Man’s on his break playing games\n"
	.string "instead of working. Movin' lazy!$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "It’s the script for the final scene.\n"
	.string "Don't look, man! You'll bait out\l"
	.string "the whole ending!$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "GAME FREAK HQ\n"
	.string "Authorized Man dem Only$"

