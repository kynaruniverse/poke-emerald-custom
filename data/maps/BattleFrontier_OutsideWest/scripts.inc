BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "BATTLE DOME\n"
	.string "Where superstars are born and\l"
	.string "legends never fold!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "BATTLE FACTORY\n"
	.string "Real talent doesn't need its own\l"
	.string "squad. Rent the best, be the best!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "BATTLE PIKE\n"
	.string "Three doors. One fate. Trust your gut!$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Yo! Trying to catch the ferry?\n"
	.string "Let me see that TICKET real quick.$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} is empty-handed…\p"
	.string "Major yikes, mate.\p"
	.string "No TICKET, no entry. That’s just\n"
	.string "how the boat floats.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Sick! You’re all cleared for takeoff!\p"
	.string "So, where are we heading?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "SLATEPORT CITY? Say less!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "LILYCOVE CITY? Say less!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "No worries. Catch us next time!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Hop on and get comfy. We’re\n"
	.string "heading out soon.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Alright then, where’s the move?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "I’m the undisputed GOAT back home,\n"
	.string "but here? I’m getting absolutely\l"
	.string "clapped! It’s humbling, man.$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "I was ready to walk in and run\n"
	.string "these facilities as soon as I landed.\p"
	.string "But that ferry ride? Rough vibes.\n"
	.string "Urrrrp… Everything is spinning…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "This isn't your average tourist spot.\n"
	.string "SCOTT only invites the real ones.\p"
	.string "If you're here, you’ve got talent.\n"
	.string "Most people don't even know this\l"
	.string "island exists on the map.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Yo, bro…\p"
	.string "You sure we can really jump into\n"
	.string "battles without bringing our own squad?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "I’m like, 90% sure it’s fine.\p"
	.string "I think…\p"
	.string "Remember that absolute unit at the\n"
	.string "front? He said he’d hook us up!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "The BATTLE FACTORY is wild. You just\n"
	.string "show up and borrow a cracked team.\p"
	.string "But for real… who’s the one actually\n"
	.string "grinding the EVs for these rentals?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "I’m lowkey terrified of the PIKE\n"
	.string "because it looks like a giant snake…\p"
	.string "B-but I didn't come this far to fold!\n"
	.string "I’m gonna conquer it! Probably!\l"
	.string "…*Shudder*…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Rock, paper, scissors! Quick!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Get in! I won!\n"
	.string "The PIKE challenge is calling my name!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Pain.\n"
	.string "I lost.\p"
	.string "Luck clearly isn't on my side today.\n"
	.string "I’ll try again tomorrow when the\l"
	.string "energy is better.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "I’m probably the only person on this\n"
	.string "entire island who’d rather catch a\l"
	.string "fish than a catch an L in battle.\p"
	.string "Wait… you can't even hook anything\n"
	.string "here? That’s a total buzzkill.$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "I’m not leaving this facility until\n"
	.string "I’ve got a Symbol. Grinding starts now.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Eyeing the BATTLE DOME, are you?\p"
	.string "Best of luck. I hope we both climb\n"
	.string "the ranks and end up facing off!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "So this is the DOME? I’m not letting\n"
	.string "some posh GENTLEMAN outplay me!\p"
	.string "Now… if I could just find the door.$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Hard to believe this place was just\n"
	.string "empty ocean not too long ago.\p"
	.string "Now look at it! Unreal. I need to\n"
	.string "bring my mum down to see this.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Finally! The BATTLE FRONTIER!\p"
	.string "With my looks and my skills, I’m\n"
	.string "definitely gonna be the main event!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "*Munch, munch…*\p"
	.string "This square is full of people who\n"
	.string "look like they mean business.\p"
	.string "*Munch, munch…*$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "*Crunch, munch…*\p"
	.string "I met this older girl at the PIKE\n"
	.string "the other day.\p"
	.string "She had these eyes, man… absolutely\n"
	.string "terrifying. Pure menace.\p"
	.string "*Crunch, munch…*\p"
	.string "She just snapped: “Stop eating!”\n"
	.string "Then she absolutely decked me.\p"
	.string "Core memory unlocked. Properly scary.\p"
	.string "*Crunch, munch…*$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Please! You’re reaching!\p"
	.string "Last time I cheered, we definitely\n"
	.string "had a moment. Sparks everywhere!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Whaaaaaat?!\n"
	.string "Delusional!\p"
	.string "He only looked because I was sitting\n"
	.string "right there being the loudest!\p"
	.string "The DOME ACE was 100% looking at me!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Zip it! Both of you!\p"
	.string "Fair-weather fans need to go cheer\n"
	.string "for some random GYM LEADER!\p"
	.string "The DOME ACE is my one and only!\n"
	.string "Total icon status!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Those girls fighting over there…\p"
	.string "Hard to believe, but they used to\n"
	.string "be top-tier TRAINERS themselves.\p"
	.string "Famous, tough, the whole package.\p"
	.string "But they got absolutely smoked by a\n"
	.string "certain TRAINER in a tournament.\p"
	.string "Instead of being mad, they became\n"
	.string "totally obsessed. Total stans.\p"
	.string "Now they just spend every day\n"
	.string "simping for their idol at the DOME.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "I heard a whisper that there’s a\n"
	.string "POKéMON with a crazy long tail\l"
	.string "hiding somewhere on this island.\p"
	.string "It’s gotta be adorable, right?\p"
	.string "Battling can wait. I’m on a mission\n"
	.string "to find that cutie!$"

