BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "I know exactly what POKéMON are\l"
	.string "thinking, swear down!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON, fam?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Boo!\n"
	.string "You’re proper tight!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it’s always ready for\n"
	.string "a scrap! It’ll keep swinging even\l"
	.string "if it’s caught a few bangs!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it loves the scrap!\n"
	.string "But if there’s too much beef,\l"
	.string "it starts moving proper shook!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it loves a scrap!\n"
	.string "But if it catches too many bangs,\l"
	.string "it starts acting sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it’s all about protecting\n"
	.string "itself! But if it catches enough bangs,\l"
	.string "it’s gonna hit back hard!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it’s always looking out\n"
	.string "for itself! It’s moving shook whether\l"
	.string "there’s beef or not!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it’s all about self-care!\n"
	.string "But if it gets caught in too much beef,\l"
	.string "it starts acting proper sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it loves being sneaky!\n"
	.string "But if it gets hit with the bangs,\l"
	.string "it’s gonna start swinging back!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it loves acting sneaky!\n"
	.string "But if it takes too many bangs,\l"
	.string "it starts moving proper shook!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it’s all about the\n"
	.string "sneaky vibes! It stays sneaky even\l"
	.string "if it’s caught a lot of beef!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Don't be silly! That EGG is just\n"
	.string "sleeping! I can't talk to it, fam!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "How charming!\n"
	.string "That little lady claims she’s got\l"
	.string "the POKéMON thinking on lock!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "I’ve got a feeling that little girl\n"
	.string "is dropping some proper gems.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "I know a secret!\p"
	.string "That little girl spends bare time\n"
	.string "playing at the red house!$"

