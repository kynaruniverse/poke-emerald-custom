BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "BATTLE TOWER\n"
	.string "Keep that streak alive and prove\l"
	.string "you're the main character!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "BATTLE PALACE\n"
	.string "Where POKéMON let their heart\l"
	.string "do the talking!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "BATTLE ARENA\n"
	.string "Knockout vibes only. Bring the heat!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "BATTLE PYRAMID\n"
	.string "The ultimate trek. Watch your step!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "FRONTIER RANKING HALL\n"
	.string "Where the GOATs are etched in stone!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BP EXCHANGE\n"
	.string "Turn those wins into some drippy gear!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Madness!\n"
	.string "The scale of this place is wild!\p"
	.string "The BATTLE TOWER just hits different.\n"
	.string "It’s on another level, fam.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "The goal is simple: total domination\n"
	.string "of the LEAGUE and the FRONTIER.\p"
	.string "And once I’ve secured the bag…\p"
	.string "I’m finally gonna ask MIMI next door\n"
	.string "if she wants to link up properly!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "The PYRAMID is too much, man!\n"
	.string "I can’t even reach the summit!\p"
	.string "Since the stairs are a myth, maybe\n"
	.string "I can just parkour up the side…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "The shadows call to me…\n"
	.string "Yes… The BATTLE PYRAMID is the only\l"
	.string "place dark enough for my soul…\p"
	.string "Care to join me in a descent into\n"
	.string "utter and absolute despair, mortal?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "I haven't slept in a week, just grinding\n"
	.string "to build the most cracked team ever!\p"
	.string "We aren't losing. Period.\n"
	.string "The ARENA isn't ready for this heat!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Did SCOTT scout you too? What's\n"
	.string "the deal with that man?\p"
	.string "Everyone says he’s got an eye for\n"
	.string "talent, but honestly…\p"
	.string "I’ve never actually seen him throw\n"
	.string "a POKé BALL in my life.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "You’ve got this, little king!\p"
	.string "If you clutch this win, I’m cooking up\n"
	.string "the finest gourmet treats in Hoenn!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON’s head is empty…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "People say I'm doing too much,\n"
	.string "but I just care, okay?!\p"
	.string "Your hat is wonky! Fix it!\n"
	.string "Litter on the floor?! Not on my watch!\l"
	.string "And look at the time! Dinnertime!\p"
	.string "I don't think I can handle the PALACE…\n"
	.string "just watching is stressy vibes!$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "I might look like a regular nan now,\n"
	.string "but I once smoked a GYM LEADER.\p"
	.string "Maybe it's time for one last ride\n"
	.string "back to the top. What you reckon?$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "I'm lightning on two wheels, and I\n"
	.string "bring that same energy to the field.\p"
	.string "If you blink, you’ll miss the part\n"
	.string "where I win!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "I’m actually way better than my\n"
	.string "dad at POKéMON. Facts.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Go on then, princess!\n"
	.string "Secure those dubs for your old man!\p"
	.string "You’ve got your mother’s fighting\n"
	.string "spirit, so just go out and dominate!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Grinded all the way here because I\n"
	.string "heard the BATTLE ARENA had a proper\l"
	.string "stunning girl running the show.\p"
	.string "Instead of a baddie, do you know\n"
	.string "what I actually found?\p"
	.string "A bunch of sweaty, shouting dudes\n"
	.string "doing bare martial arts! Too much!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "I see this proper VIP-looking old\n"
	.string "gentleman heading in there sometimes.\p"
	.string "His POKéMON are absolute units!\n"
	.string "He seems like a legend, honestly.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Yo, have you heard the legend?\n"
	.string "The Legend of the BATTLE PYRAMID?\p"
	.string "When a trainer with zero fear reaches\n"
	.string "for the peak, a god among men appears!\p"
	.string "Never heard that one?\n"
	.string "Standard, really! I just made it up!\p"
	.string "The meaning? Who knows, fam!\n"
	.string "That’s for you to figure out!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Nah, mate! No way!\n"
	.string "I haven't taken an L in years!\p"
	.string "But I just got absolutely folded!\n"
	.string "Zero chance! Done out here!\p"
	.string "And now they’re saying I’m mid?!\n"
	.string "Absolute violation!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "This poor lad ran into a literal\n"
	.string "demon in the BATTLE TOWER.\p"
	.string "Now he’s just… broken.\p"
	.string "Watch yourself in there, kid. The\n"
	.string "TOWER don't play fair.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Get in!\n"
	.string "Finally got the BP for the shop!\p"
	.string "Time to buy another massive plushie\n"
	.string "for the collection!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Yeah, safe! Okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I’m tryna be the GOAT and have my\n"
	.string "name on that wall for the eternity.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "As long as you're with me, I'm\n"
	.string "invincible.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Oh, darling, you’re just perfect!\p"
	.string "I can't take the suspense anymore!\p"
	.string "Let’s hit the MULTI BATTLE ROOM\n"
	.string "right now!\p"
	.string "When we step into the BATTLE SALON,\n"
	.string "our chemistry is gonna be a cheat code.\p"
	.string "Everyone else is just gonna crumble\n"
	.string "before us, darling! Facts!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "The BATTLE FRONTIER isn’t just about\n"
	.string "raw power and muscle.\p"
	.string "It seems people with all sorts of\n"
	.string "unique talents were invited.\p"
	.string "That man SCOTT…\p"
	.string "I suspect this whole place is just\n"
	.string "one piece of a much larger plan…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Pardon me, young traveler.\n"
	.string "Are your eyes still sharp?\p"
	.string "There’s a weird tree up ahead, and\n"
	.string "to my old eyes, it’s doing a little jig.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Pardon me, young traveler.\n"
	.string "Is your memory still working?\p"
	.string "I have a weird feeling there used to\n"
	.string "be a proper strange tree right here.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "I…\n"
	.string "I saw it with my own eyes!\p"
	.string "There was a proper sticky POKéMON\n"
	.string "with a long tail just hanging out!\p"
	.string "It was hiding under a rock, just\n"
	.string "staring at me like I owed it money!$"

