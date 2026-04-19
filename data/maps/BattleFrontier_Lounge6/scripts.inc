BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Yo, check my {STR_VAR_2}.\n"
	.string "You seen one of these before?\l"
	.string "It’s proper cute and the vibes are calm.\p"
	.string "I’d be proud to trade this little one,\n"
	.string "straight up.\p"
	.string "You wanna swap a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Ayy, it’s adorable!\n"
	.string "Safe for that!\l"
	.string "I promise I’ll look after it properly.\p"
	.string "Make sure you’re good to\n"
	.string "my {STR_VAR_2} as well, yeah?$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Ah, my bad!\n"
	.string "I’m not looking for anything\l"
	.string "except a {STR_VAR_1}, fam.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, you’re not feeling it?\n"
	.string "That’s calm.\l"
	.string "Swing by again if you change your mind.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Giggle!\n"
	.string "This SKITTY is way cuter than I\l"
	.string "even thought. I’m gassed!$"

