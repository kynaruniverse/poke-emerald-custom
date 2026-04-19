CeladonCity_Condominiums_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	famechecker FAMECHECKER_DAISY, 4
	setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_Meowth::
	.string "MEOWTH: (He looks like he's judging\n"
	.string "your fashion choices.) Meow.$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
	.string "I saw you eyeing that vending machine.\n"
	.string "300 yen for a lukewarm soda?\p"
	.string "In this economy? Absolutely not.\n"
	.string "Put your wallet away and take this.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
	.string "This TEA is so good it'll make you\n"
	.string "forget you're technically trespassing\l"
	.string "in a private residence.\p"
	.string "Stay hydrated, dearie!$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
	.string "Living with POKéMON is wonderful.\p"
	.string "MEOWTH is especially helpful.\n"
	.string "He 'finds' coins all over the city.\p"
	.string "I don't ask where they come from and\n"
	.string "he doesn't tell me. It's a system.$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
	.string "Oh, hello again, Champion!\n"
	.string "Did that TEA clear your sinuses?\p"
	.string "You're from PALLET TOWN, right?\p"
	.string "DAISY from over there is obsessed\n"
	.string "with my brewing skills.\p"
	.string "She spends half her inheritance at the\n"
	.string "DEPT. STORE just to try and copy me.\l"
	.string "Bless her heart.$"

CeladonCity_Condominiums_1F_Text_Clefairy::
	.string "CLEFAIRY: (She's practicing her\n"
	.string "stand-up routine.) Pi-pipi!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
	.string "NIDORAN♀: (She's suspiciously\n"
	.string "protective of the TV remote.) Kyaa!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
	.string "CELADON MANSION\n"
	.string "Manager's Suite - No Solicitors!$"

