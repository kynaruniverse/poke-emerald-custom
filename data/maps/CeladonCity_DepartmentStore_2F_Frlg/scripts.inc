CeladonCity_DepartmentStore_2F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message CeladonCity_DepartmentStore_2F_Text_ShopWelcome
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox CeladonCity_DepartmentStore_2F_Text_ShopGoodbye
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message CeladonCity_DepartmentStore_2F_Text_ShopWelcome
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox CeladonCity_DepartmentStore_2F_Text_ShopGoodbye
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM45
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_Text_ShopWelcome::
	.string "Safe, what you looking for? Man’s\n"
	.string "got the piff supplies on deck.$"

CeladonCity_DepartmentStore_2F_Text_ShopGoodbye::
	.string "Safe. Don't be a stranger in these\n"
	.string "bits, yeah?$"

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
	.string "This SUPER REPEL is peak, fam.\n"
	.string "Keeps the dead-out mons away so\l"
	.string "you can walk the ends in peace.\p"
	.string "Trust me, it’s bare stronger than\n"
	.string "that basic stuff.$"

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
	.string "If you’re heading out to the long\n"
	.string "grass, you need that REVIVE.\p"
	.string "Don't let your team get caught\n"
	.string "slipping, get me?$"

CeladonCity_DepartmentStore_2F_Text_FloorSign::
	.string "Only the finest gear for the mandem!\p"
	.string "2F: TRAINER'S MARKET - NO PAGANS$"

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
	.string "We got this bredrin LANCE who\n"
	.string "steps through sometimes.\p"
	.string "Man only ever buys capes.\p"
	.string "I’m thinking... does he have a\n"
	.string "hundred of the same fit at home?\l"
	.string "That’s a mad style, still.$"

