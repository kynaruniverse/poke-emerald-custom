BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We’re just out here to keep an eye\n"
	.string "on our grandson.\p"
	.string "But since we’ve made the trip, we\n"
	.string "reckoned we’d pick up some bits to\l"
	.string "take home as souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Love, what do you reckon to this?\n"
	.string "Wouldn't this be a top gift?\p"
	.string "It's… PRO… TE… IN?\n"
	.string "Sounds like a proper treat, don't it?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "Bare facilities in the BATTLE FRONTIER\n"
	.string "don't let you use items while you're\l"
	.string "in a scrap.\p"
	.string "That rule makes the whole thing\n"
	.string "way more peak than it already is!$"

