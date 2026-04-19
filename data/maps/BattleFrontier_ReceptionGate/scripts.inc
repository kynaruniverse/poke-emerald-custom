BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Yo! First time on the island?\n"
	.string "Slide over to the desk, please!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "This is it—the absolute peak of\n"
	.string "competitive battling!\l"
	.string "Welcome to the BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Since you’re new here, we gotta\n"
	.string "issue your FRONTIER PASS.\p"
	.string "Think of it as your VIP pass to\n"
	.string "every stadium on the island.\p"
	.string "There you go!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} obtained\n"
	.string "the FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} synced the TRAINER CARD\n"
	.string "with the FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Go out there and show 'em what\n"
	.string "you’re made of! Enjoy the grind!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Yo, if it isn't {PLAYER}{KUN}!\n"
	.string "You actually made it out here!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDE: Whoa! MR. SCOTT, sir!\n"
	.string "Good to see you, boss!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Man, it’s hype to see you\n"
	.string "here! I knew you'd show up.\p"
	.string "Take your time, soak in the vibes,\n"
	.string "and explore every corner.\p"
	.string "But mostly, I wanna see you dive\n"
	.string "into the pure chaos of battle.\p"
	.string "My crib is right here on the island,\n"
	.string "so pull up if you need anything!$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "I’m your go-to guide for all the\n"
	.string "insane facilities here at the FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "What’s the move? Which spot do\n"
	.string "you wanna hear about?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "The massive tower? That’s the\n"
	.string "icon of the whole FRONTIER.\p"
	.string "It’s got four different battle modes:\n"
	.string "SINGLE, DOUBLE, MULTI, and the\l"
	.string "high-stakes LINK MULTI BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "The DOME is that giant egg-looking\n"
	.string "building. Very high energy.\p"
	.string "They run Battle Tourneys there,\n"
	.string "where it's all about the hype.\p"
	.string "You can enter as a SINGLE player\n"
	.string "or bring a partner for DOUBLES.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "The PALACE is the red building\n"
	.string "chilling on the right side.\p"
	.string "It’s got two halls for SINGLE and\n"
	.string "DOUBLE BATTLES. It's all about trust!$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "The ARENA is that dojo-style spot\n"
	.string "right in the center-right area.\p"
	.string "They run a Set KO Tourney. You gotta\n"
	.string "be aggressive to win there!$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "The FACTORY is that big building\n"
	.string "closest to the gate here.\p"
	.string "That’s where the Battle Swap happens.\n"
	.string "You don't even use your own squad!\p"
	.string "They’ve got courses for both\n"
	.string "SINGLE and DOUBLE BATTLES.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "The PIKE is shaped like a SEVIPER.\n"
	.string "Can't miss it, center-left.\p"
	.string "It’s all about the Battle Choice.\n"
	.string "Pick a door and hope for the best!$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "The PYRAMID is that absolute unit\n"
	.string "towering over the island.\p"
	.string "The Battle Quest happens there.\n"
	.string "It’s a total survival mission.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "The RANKING HALL is tucked away\n"
	.string "near the BATTLE TOWER.\p"
	.string "That’s where we flex the records\n"
	.string "of the absolute legends who have\l"
	.string "crushed the FRONTIER challenges.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "The EXCHANGE CORNER is also near\n"
	.string "the BATTLE TOWER.\p"
	.string "Trade in those hard-earned Battle\n"
	.string "Points for some seriously cracked\l"
	.string "prizes and items.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "I’ll give you the lowdown on the\n"
	.string "ground rules that apply to every\l"
	.string "single stadium on the island.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "What’s the play? What do you\n"
	.string "wanna know?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Every challenge on the island has\n"
	.string "two settings: Level 50 and Open Level.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Level 50 is for the squad members\n"
	.string "capped at Level 50.\p"
	.string "Just a heads up—your opponents\n"
	.string "won't be scaling down. They'll be\l"
	.string "Level 50 minimum.\p"
	.string "It’s basically the entry point for\n"
	.string "newcomers to the FRONTIER.\p"
	.string "Start here to get your feet wet!$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Open Level is the wild west—no\n"
	.string "level caps for your POKéMON.\p"
	.string "Your opponents will scale up to\n"
	.string "match your highest level member.\p"
	.string "But they won't go lower than\n"
	.string "Level 60. No easy wins here!$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Most of your squad is good to go\n"
	.string "for any of these challenges.\p"
	.string "But EGGS and some legendary-tier\n"
	.string "monsters aren't allowed to play.\p"
	.string "Squad size depends on the building,\n"
	.string "but zero duplicates are allowed.\l"
	.string "No double-dipping on the same species!$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "When you step into a stadium, your\n"
	.string "squad can't be holding the same items.\p"
	.string "Switch it up! Make sure everyone is\n"
	.string "carrying something unique.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "I’m here to explain how your\n"
	.string "FRONTIER PASS works.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "What part of the PASS are we\n"
	.string "looking at?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "There are seven main stadiums\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Trainers who absolutely dominate\n"
	.string "earn Symbols from the Frontier Brains.\p"
	.string "To get one, you gotta go on massive\n"
	.string "win streaks and prove you're built\l"
	.string "different.\p"
	.string "It’s a brutal grind. Good luck!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "You can save one epic replay\n"
	.string "directly to your PASS.\p"
	.string "It could be a match against a friend\n"
	.string "over a link cable.\p"
	.string "Or a hype match from the island,\n"
	.string "though the PIKE and PYRAMID won't\l"
	.string "let you record their chaos.\p"
	.string "Just hit the record prompt after\n"
	.string "the battle finishes.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Battle Points (BP) are the currency\n"
	.string "for winners. Win big, get paid.\p"
	.string "Take that BP over to the EXCHANGE\n"
	.string "CORNER and get some elite loot.$"

