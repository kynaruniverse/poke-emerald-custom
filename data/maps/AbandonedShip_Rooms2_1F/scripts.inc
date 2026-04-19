AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro::
	.string "DAN: We’re hunting for loot, but\n"
	.string "finding a mark is even better!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat::
	.string "DAN: We couldn't even bag a win\n"
	.string "with the two-on-one? Peak.$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle::
	.string "DAN: This ship is empty, man. Someone\n"
	.string "already cleared the place out.$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons::
	.string "DAN: You’re rolling solo? You need\n"
	.string "backup if you want to step to us.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro::
	.string "KIRA: Oh? We were looking for\n"
	.string "something valuable to pocket.\p"
	.string "I guess your POKé BALLS will do!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat::
	.string "KIRA: You’re actually moving like that?$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle::
	.string "KIRA: Where is the real loot at?\p"
	.string "I already know what I’m spending\n"
	.string "the profit on when I find it!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons::
	.string "KIRA: Roll deep or don't roll at all.\n"
	.string "Come back when you have a squad.$"

AbandonedShip_Rooms2_1F_Text_KiraRegister::
	.string "KIRA: You’ve got me bare stressed!\n"
	.string "I’m putting you on my list for that!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro::
	.string "DAN: We’re still here looking for\n"
	.string "something to flip.\p"
	.string "The team’s leveled up, though.\n"
	.string "You ready for this round?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat::
	.string "DAN: Still on top of your game, eh?$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch::
	.string "DAN: No loot, no wins... this trip\n"
	.string "is a total waste, man.\p"
	.string "I want to bounce, but she’ll just\n"
	.string "start shouting if I say anything...$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons::
	.string "DAN: Where’s your team? We don't\n"
	.string "brawl with individuals.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro::
	.string "KIRA: Oh, it’s you again!\p"
	.string "Still trying to scavenge the same\n"
	.string "spot as us, I see.\p"
	.string "How about a wager? Loser has to\n"
	.string "clear out of this sector.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat::
	.string "KIRA: Lost again? No way.$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch::
	.string "KIRA: We aren't leaving until we\n"
	.string "find something worth our time!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons::
	.string "KIRA: Still rolling by yourself?\n"
	.string "Get some friends, then we'll talk.$"

AbandonedShip_Rooms2_1F_Text_JaniIntro::
	.string "I can't swim a lap, but I can\n"
	.string "certainly run a set!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat::
	.string "Safe... that went south fast.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle::
	.string "Creps are getting ruined in here.\n"
	.string "This ship is proper grimey.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro::
	.string "Staying sharp and looking out for\n"
	.string "your own—that’s the real prize!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat::
	.string "You’ve definitely got that\n"
	.string "inner shine, fam.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle::
	.string "In one of these rooms, I saw something\n"
	.string "flicker. Keep your eyes peeled.$"

