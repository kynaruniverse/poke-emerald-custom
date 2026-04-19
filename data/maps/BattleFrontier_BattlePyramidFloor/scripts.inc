BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFacility_TrainerBattle_PlaceholderText:
	.string "Yo, this is just a test message, fam.$"

gText_BattlePyramidConfirmRest::
	.string "Your BATTLE PYRAMID quest is gonna\n"
	.string "be saved so you can hop off.\l"
	.string "Is that cool with you?$"

gText_BattlePyramidConfirmRetire::
	.string "You sure you wanna dead your\n"
	.string "PYRAMID quest right now?$"

BattlePyramid_Text_ExitHintUp1::
	.string "The exit's in that direction,\n"
	.string "trust: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "The exit's in that direction,\n"
	.string "trust: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "The exit's in that direction,\n"
	.string "trust: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "The exit's in that direction,\n"
	.string "trust: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "The exit on this floor is up\n"
	.string "that way: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft2::
	.string "The exit on this floor is up\n"
	.string "that way: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight2::
	.string "The exit on this floor is up\n"
	.string "that way: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown2::
	.string "The exit on this floor is up\n"
	.string "that way: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp3::
	.string "The exit is over\n"
	.string "that {UP_ARROW} way, fam.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way, fam.$"

BattlePyramid_Text_ExitHintRight3::
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way, fam.$"

BattlePyramid_Text_ExitHintDown3::
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way, fam.$"

BattlePyramid_Text_ExitHintUp4::
	.string "On this floor, the exit's somewhere\n"
	.string "up in the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "On this floor, the exit's somewhere\n"
	.string "up in the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight4::
	.string "On this floor, the exit's somewhere\n"
	.string "up in the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown4::
	.string "On this floor, the exit's somewhere\n"
	.string "up in the {DOWN_ARROW} direction.$"

BattlePyramid_Text_ExitHintUp5::
	.string "The exit?\n"
	.string "It’s that {UP_ARROW} way, keep moving.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "The exit?\n"
	.string "It’s that {LEFT_ARROW} way, keep moving.$"

BattlePyramid_Text_ExitHintRight5::
	.string "The exit?\n"
	.string "It’s that {RIGHT_ARROW} way, keep moving.$"

BattlePyramid_Text_ExitHintDown5::
	.string "The exit?\n"
	.string "It’s that {DOWN_ARROW} way, keep moving.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Turns out the exit is up in the\n"
	.string "{UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Turns out the exit is up in the\n"
	.string "{LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Turns out the exit is up in the\n"
	.string "{RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Turns out the exit is up in the\n"
	.string "{DOWN_ARROW} direction.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still eight bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still seven bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still six bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still five bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still four bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still three bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There’s still two bits left to\n"
	.string "find around here.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "You looking for gear?\p"
	.string "There’s only one bit left to\n"
	.string "be found.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "You looking for gear?\p"
	.string "There ain't nothing left to find,\n"
	.string "it’s all gone!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s eight items lying around\n"
	.string "this place.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s seven items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s six items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s five items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s four items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s three items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s two items left lying around\n"
	.string "this place.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There’s just one item left lying\n"
	.string "around here.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Since you won, I'll let you in on\n"
	.string "the secrets!\p"
	.string "There ain't nothing left lying\n"
	.string "around here, fam.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s eight bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s seven bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s six bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s five bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s four bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s three bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s two bits left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there’s only one bit left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "How’s your stash looking?\p"
	.string "I reckon there's no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "Stay safe out here!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s eight more items\n"
	.string "on the ground.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s seven more items\n"
	.string "on the ground.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s six more items\n"
	.string "on the ground.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s five more items\n"
	.string "on the ground.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s four more items\n"
	.string "on the ground.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s three more items\n"
	.string "on the ground.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s two more items\n"
	.string "on the ground.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s only one more item\n"
	.string "on the ground.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "You’re strong, so I’ll give you a tip!\p"
	.string "Looks like there’s no more items\n"
	.string "on the ground at all.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "eight bits to find…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "seven bits to find…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "six bits to find…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "five bits to find…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "four bits to find…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "three bits to find…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "two bits to find…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "only one bit to find…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "On this floor, I heard there’s\n"
	.string "nothing left to find…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s eight more items\n"
	.string "on this floor.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s seven more items\n"
	.string "on this floor.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s six more items\n"
	.string "on this floor.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s five more items\n"
	.string "on this floor.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s four more items\n"
	.string "on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s three more items\n"
	.string "on this floor.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s two more items\n"
	.string "on this floor.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s only one more item\n"
	.string "on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "You collected any gear yet?\p"
	.string "I think there’s no more items\n"
	.string "left on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still seven tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still six tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still five tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still four tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still three tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still two tough\n"
	.string "TRAINERS left besides me!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "But there’s still one tough\n"
	.string "TRAINER left besides me!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "You were proper legendary!\p"
	.string "There ain't no one left who\n"
	.string "can touch you!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s seven TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s six TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s five TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s four TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s three TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s two TRAINERS left!\n"
	.string "Someone’s gonna humble you!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s one TRAINER left!\n"
	.string "I’m sure you’re gonna get humbled!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "This is peak!\p"
	.string "But there’s no more TRAINERS left\n"
	.string "to step up to you!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s seven more TRAINERS\n"
	.string "on this floor. Can you run them all?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s six more TRAINERS\n"
	.string "on this floor. Can you run them all?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s five more TRAINERS\n"
	.string "on this floor. Can you run them all?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s four more TRAINERS\n"
	.string "on this floor. Can you run them all?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s three more TRAINERS\n"
	.string "on this floor. Can you run them all?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s two more TRAINERS\n"
	.string "on this floor. Can you run them both?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "But there’s still one more TRAINER\n"
	.string "on this floor. Can you handle it?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "That’s proper impressive!\p"
	.string "You’ve cleared out every single\n"
	.string "TRAINER on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "seven TRAINERS left on this floor.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "six TRAINERS left on this floor.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "five TRAINERS left on this floor.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "four TRAINERS left on this floor.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "three TRAINERS left on this floor.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Maybe you can sweep through the\n"
	.string "two TRAINERS left on this floor.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Maybe you can finish the sweep with\n"
	.string "the one TRAINER left on this floor.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "There ain't a single person left who\n"
	.string "can touch you now…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the seven experts left.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the six experts left.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the five experts left.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the four experts left.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the three experts left.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the two experts left.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "You might actually have what it takes\n"
	.string "to beat the one expert left.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Your skills are peak, no lie.\p"
	.string "There are no more TRAINERS here\n"
	.string "with any chance of beating you.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "seven TRAINERS that are left?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "six TRAINERS that are left?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "five TRAINERS that are left?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "four TRAINERS that are left?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "three TRAINERS that are left?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "two TRAINERS that are left?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Can you keep winning against the\n"
	.string "last TRAINER remaining?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "There ain't no TRAINERS left that\n"
	.string "can even take you on now…$"


