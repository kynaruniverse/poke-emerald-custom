BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Go find a partner from the\n"
	.string "mandem gathered in this room.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, you haven't linked with a\n"
	.string "partner for your tag team yet.\p"
	.string "You wanna stop moving to them and\n"
	.string "head back to the front desk?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Safe. Go find a partner from the\n"
	.string "TRAINERS chilling over there.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Safe for picking a partner.\p"
	.string "I’ll show you to the MULTI BATTLE\n"
	.string "ROOM now. Let’s get moving.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Call me {STR_VAR_3}, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Yo, {STR_VAR_1} told me to bring\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Let’s link up as a team, man.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Mad! Love for that.\n"
	.string "I’m gonna go register us now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "I really wanted to roll with\n"
	.string "you, {PLAYER}... Peak.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} student.\n"
	.string "The name’s {STR_VAR_3}. Wagwan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "I got the drop from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Let’s form a tag team, innit.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Respect! Love for that.\n"
	.string "I’ll get us registered quick-time!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, I was hoping we could\n"
	.string "be a proper duo. No worries.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Um, I’m {STR_VAR_3}, and I’m\n"
	.string "{STR_VAR_1}’s no. {STR_VAR_2} apprentice.\p"
	.string "*Snivel*\p"
	.string "Sorry! This whole vibe is\n"
	.string "making me proper emotional...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} gave me some gems, so I got\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "*Snivel*\n"
	.string "Please, please don't bait me out! Team up!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Wait, serious? You will?\n"
	.string "That’s peng! That’s sick! Awoooh!\p"
	.string "I’m sorry... I’m just so gassed\n"
	.string "I’m literally crying...\p"
	.string "I’ll go register right now.\n"
	.string "Don't move! I’ll be back!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, but... b-but...\n"
	.string "Sob... Everything’s peak!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Wagwan! I’m {STR_VAR_3}!\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} told me the squad was fire.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Looking proper, yeah?\p"
	.string "So come on then!\n"
	.string "Let’s be a legendary tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Get in! Proper sick!\n"
	.string "I’m gonna go register us, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Allow it! Why not?\n"
	.string "I wanted to roll with you, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "I’m {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the big man {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "I asked {STR_VAR_3} for the blueprints.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that’s my duo.\p"
	.string "Yo, you wanna link up and\n"
	.string "run this tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Safe! Love for that.\n"
	.string "I’ll register us straight away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, I was proper hoping to\n"
	.string "join you in a duo...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um... I’m proper happy that you’d\n"
	.string "even take the time to chat to me.\p"
	.string "I’m {STR_VAR_3}.\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gave me the drop.\n"
	.string "I’m proper grateful for it.\p"
	.string "I got a team with one {STR_VAR_2}\n"
	.string "holding {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I’m asking a lot, innit...\p"
	.string "You probably don't wanna roll,\n"
	.string "but can I be your partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Serious? I can’t believe it!\n"
	.string "You’re actually gonna let me roll?!\l"
	.string "I... I won’t let you down, fam!\p"
	.string "If it’s really calm, I’ll go register\n"
	.string "right this second!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh... I knew I wasn't\n"
	.string "built like that...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Yo, I’m {STR_VAR_3}.\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} told me this squad\n"
	.string "was pure fire:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "and one {STR_VAR_2} that knows\n"
	.string "the ways of {STR_VAR_1}.\p"
	.string "Not bad, yeah?\n"
	.string "Wanna team up with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Safe, glad to roll with you!\n"
	.string "Don't mess up the vibes, yeah?\l"
	.string "I’m gonna go register now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Huh? Why you airing me?\n"
	.string "You don't know talent when you see it!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "I’m {STR_VAR_3} and I’m a TRIATHLETE.\n"
	.string "I’m busy every day with jogging,\l"
	.string "gym, and spitting bars.\p"
	.string "I’m also {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Check what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of work into the squad,\n"
	.string "even though I’m moving 24/7.\p"
	.string "Let’s link up and give\n"
	.string "it a go! It’ll be sick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Safe, that’s the spirit!\n"
	.string "Hold tight while I go register us, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "I took time out of my busy\n"
	.string "schedule for this! Allow it, man!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hiya!\n"
	.string "What’s the vibe?\p"
	.string "I’m {STR_VAR_3}, {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice. Nice to meet ya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Listen, listen! You gotta hear about\n"
	.string "the POKéMON {STR_VAR_3} suggested.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I raised them proper, you know!\p"
	.string "So, wanna team up?\n"
	.string "I’m sure it’ll be a madness!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, I think this will be jokes!\n"
	.string "I’ll go register us!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, you’re moving moist!\n"
	.string "I come highly recommended, you know.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Allow me to introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I’m currently {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "I took the advice of {STR_VAR_3}\n"
	.string "and built a team with\l"
	.string "one {STR_VAR_2} with {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Let’s team up and do this properly.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh... I’m proper happy with that!\n"
	.string "I promise to give you my best!\p"
	.string "I’ll go register us now.\n"
	.string "Wait here, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "I was hoping we could roll together,\n"
	.string "{PLAYER}... It’s cool.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! You actually spoke to me!\n"
	.string "I’m proper gassed!\p"
	.string "I’m {STR_VAR_3}! I’m {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "On {STR_VAR_3}’s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can we roll together?\n"
	.string "I really wanna be your tag-partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! I’m proper buzzing!\n"
	.string "Thank you so much!\l"
	.string "I’ll go register us straight away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! You’re bare cold, man!\n"
	.string "But that just makes you cooler...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yoo! I’m {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3} is the name! Safe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Sick squad, innit?\n"
	.string "You’re gonna team with me, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Safe, excellent!\n"
	.string "I’ll get the registration done quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "You’re moving proper calculated, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Yo! Safe! Bad news, fam! The BATTLE\n"
	.string "TOWER is getting shut down today!\p"
	.string "… … … … … …\n"
	.string "Just joking, man! Psycho!\p"
	.string "Mandem call me {STR_VAR_3}, so you can too!\n"
	.string "I’m {STR_VAR_1}’s 1,000th apprentice!\l"
	.string "Actually, I’m only no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gave me the blueprints.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I got ten of each in the bag!\l"
	.string "Nah, just joking—only one of each!\p"
	.string "Wagwan then?\n"
	.string "Wanna link up and move to the ops?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Wheeeee! Safe for that!\n"
	.string "I’ll give you a free POKéMON as thanks!\p"
	.string "Psych! Just joking again! But I’m really\n"
	.string "gonna go register us now, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Wow, you’re moving bare cold! I’m gonna\n"
	.string "have to bun down the BATTLE TOWER!\p"
	.string "Standard, I’m joking! Relax!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Yo, I’m rockin’ and a-rollin’!\n"
	.string "POKéMON, I be controllin’!\p"
	.string "I’m {STR_VAR_3}, the rappin’ SAILOR.\n"
	.string "Check the flow, I’m a heavy scaler!\p"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Don't sleep on me, I’m the relentless!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, caught the wave with pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our link-up we should commemorate,\n"
	.string "with a tag-team dub to celebrate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hey, hey, I’m feeling your vibe!\n"
	.string "I’ll register us, then we ride!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Yo, {PLAYER}, you’re moving cold!\n"
	.string "You’re missing out on the gold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo!\n"
	.string "Wait, don’t dash! I was just having fun!\p"
	.string "Wagwan! I’m {STR_VAR_3}!\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} gave me the drop.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did pick.\p"
	.string "So, what you saying?\n"
	.string "Come on, make it happen!\p"
	.string "Please, I’m proper begging you!\n"
	.string "Don't leave me out here looking blue!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Get in! Luck is on my side!\n"
	.string "I’m proper gassed right now!\p"
	.string "Before we jump into the mix,\n"
	.string "I’ll go get the registration fixed!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "You’re airing me? Serious?\n"
	.string "{PLAYER}, you’re making me frown!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "*Cough!*\p"
	.string "Sorry fam, I’ve got a proper cold.\n"
	.string "The POKéMON are fine, though.\p"
	.string "Name’s {STR_VAR_3}, {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice. *Cough!*$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "I took {STR_VAR_3}’s advice to heart\n"
	.string "and built a squad with\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I was training them out in the ends\n"
	.string "even when it was raining sideways.\p"
	.string "Probably why I’m feeling under\n"
	.string "the weather, innit.\p"
	.string "Anyway, that’s me. You wanna\n"
	.string "be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Respect, I appreciate the love!\n"
	.string "*Cough, cough!*\l"
	.string "Hold tight while I go register us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, you’re good? Safe.\n"
	.string "{PLAYER}, I thought we’d be a vibe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hello there!\n"
	.string "This is all a bit nerve-racking.\p"
	.string "I’m {STR_VAR_3}.\n"
	.string "I’m the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} said this team was peng--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I’m feeling a bit self-conscious,\n"
	.string "but will you let me join you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, gosh, thank you!\n"
	.string "I’m proper shy, but I’ll do my best!\p"
	.string "I’ll go get the registration done.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, please don’t say no!\n"
	.string "I already feel like a spare part…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "I am {STR_VAR_3}, and that’s the truth.\n"
	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} recommended this squad.\p"
	.string "Since the advice sounded legit,\n"
	.string "I decided to bring along\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I’d like you to accept\n"
	.string "me as your tag-team partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "You’ll actually roll with me?\n"
	.string "I was worried it’d be peak otherwise.\p"
	.string "But since you’re down, it’s calm.\n"
	.string "I’ll go register the both of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Why you refusing, though?\n"
	.string "Is this your idea of a joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "I’m {STR_VAR_1}, and I’m a LASS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "I’ve got one {STR_VAR_2} that\n"
	.string "uses {STR_VAR_1} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "That’s what I’m rocking with.\p"
	.string "Wanna be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Safe for that!\n"
	.string "I’ll go do the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "You don’t wanna roll with me?\n"
	.string "You’re gonna regret that later!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Wagwan!\p"
	.string "I’m YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Wanna know what I’ve got?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You’ll be my tag-team partner,\n"
	.string "won’t you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Get in!\n"
	.string "I’ll go and register us, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Allow it! If we teamed up,\n"
	.string "we would’ve been unstoppable!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo!\n"
	.string "I’m HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Check what I’ve got in the bag.\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Proper solid, eh?\n"
	.string "Wanna form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Safe! Yahoo!\n"
	.string "I’ll go do the registering, then.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Pity. I would’ve liked to smash\n"
	.string "it with you by my side.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Do you know what I’ve been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Wanna link up for a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Wonderful! Good choice.\n"
	.string "I’ll get the registration done now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "How disappointing!\p"
	.string "The two of us together--we would’ve\n"
	.string "been the elite duo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\p"
	.string "You know the face?\n"
	.string "I’m {STR_VAR_1} the FISHERMAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "I’ve got a squad with one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, what’s the word?\n"
	.string "Will you battle at my side?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Good, good!\n"
	.string "Leave it to me, fam!\p"
	.string "I’ll go and register us now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Peak. We matched up perfectly, too…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "A pleasure to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "I should very much like us to partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "I suspect you’ll regret not\n"
	.string "having me as your partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "I’m TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "What I’m rocking…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That’s my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Cheers! Nice one.\n"
	.string "I’ll go register at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "The two of us together, we would’ve\n"
	.string "been proper tough for certain!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya!\n"
	.string "I’m BUG CATCHER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Check out the squad!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you wanna form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Gotcha! Safe.\p"
	.string "I’ll go do the registration stuff\n"
	.string "at the counter.$"

BattleFrontier_BugCatcherReject::
	.string "Aww, my POKéMON are proper fire.\n"
	.string "I hope you don’t regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Good day!\n"
	.string "I’m SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "What I’ve been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don’t you think?\n"
	.string "Wanna link up for a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Thank you very much!\n"
	.string "I’ll go get the registration done.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "That’s a shame…\p"
	.string "I was hoping I could learn\n"
	.string "the ropes as your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Let me tell you who I am!\n"
	.string "I’m RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Guess what I’ve got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I’m willing to offer you the chance\n"
	.string "to roll in a tag team with me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Smart move!\p"
	.string "I’ll finish up the registration\n"
	.string "process quick-time!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "You’d turn me of all people down?\n"
	.string "You’ll regret that decision for sure!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "I am BLACK BELT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "I will go register forthwith!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "I see… I hope for a chance\n"
	.string "next time we meet in the ends…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hi there!\n"
	.string "I’m {STR_VAR_1}, and I’m a TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "I’ll tell you what I’ve got.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "Can I please be on your tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Safe! Thank you!\n"
	.string "I’ll go register us now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "If we’d become partners, we could\n"
	.string "have been proper strong!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Greetings…\n"
	.string "I am HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Love for that…\n"
	.string "I’ll go put us on the system…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "I proper wanted to link up…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Safe, you good? I’m {STR_VAR_1},\n"
	.string "I’m out here breeding POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "I’ve got some proper fire ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What’s the word?\n"
	.string "You wanna link up as a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Respect for that!\p"
	.string "I’ll go sort the registration,\n"
	.string "just hold tight right here!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "I was proper looking forward to\n"
	.string "rolling with you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Yo, wagwan!\n"
	.string "I’m TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Wanna know what I’m running with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Wanna be in a tag team, fam?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Proper sick!\p"
	.string "I’ll be quick and get the registration\n"
	.string "all sorted!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "The two of us would’ve been on top.\n"
	.string "It’s peak, man…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Safe, g! My name’s {STR_VAR_1}!\n"
	.string "I’m a TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "I’m hitting the roads with this team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, innit?\n"
	.string "We should roll as a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Safe! Get in!\n"
	.string "I’ll go register us in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "I really wanted to hop on this\n"
	.string "tag team with you, fam…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "I’m BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "I’ve been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "You feeling that combo?\n"
	.string "How about you and me join up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Safe! Love for that!\p"
	.string "I’ll get the registration done\n"
	.string "straight away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "I thought we’d be a proper\n"
	.string "legendary tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "I’m TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "I’ve been pedalling with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be a proper duo.\n"
	.string "Wouldn’t that be sick?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Safe, nice one!\p"
	.string "I’ll go register us right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Allow it! We would’ve been the\n"
	.string "toughest tag team on the block!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Who, me?\n"
	.string "I’m TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Check what I’ve got with me:\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yo, you’re gonna team up\n"
	.string "with me, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Safe! Safe!\p"
	.string "I’ll go register!\n"
	.string "Let’s be proper elite together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "My POKéMON are built different…\n"
	.string "Sad you don’t wanna team up, man.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey!\n"
	.string "Call me GUITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Check out my entourage, fam!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Wild, innit? We’ll have to\n"
	.string "make some noise as a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Safe! Right on!\n"
	.string "I’ll sort the paperwork now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "My POKéMON are proper heavy metal!\n"
	.string "You’re missing out, I’m telling you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Pleasure to meet you.\n"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Might I ask you to join me in a\n"
	.string "tag-team arrangement, old boy?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, I thank you for your trust.\n"
	.string "I shall proceed with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity, then.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Wagwan, I’m {STR_VAR_1},\n"
	.string "and I’m a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "I’ve got one {STR_VAR_2} that\n"
	.string "knows the move {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "You like the look of that?\n"
	.string "Why don’t you be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Safe for that!\n"
	.string "I’ll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "My POKéMON are top tier…\n"
	.string "Pity you can’t see the vision.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and a proper EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "The ones I’ve toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What you saying to a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm! Safe!\n"
	.string "I’ll register us right now!\l"
	.string "Let’s smash it, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "I hope you’ve made the right call\n"
	.string "there, mate…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hello, hello.\n"
	.string "I’m {STR_VAR_1}, and I’m an EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "I’ve raised my POKéMON thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they’re proper ready.\p"
	.string "Wouldn’t you like to team up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Good stuff.\n"
	.string "I’ll go sort the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Maybe we can form a team next time\n"
	.string "we’re in the area.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "I’m DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "The team I’ve been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Wanna be my partner, g?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Safe, I’ll give it my all!\n"
	.string "I’ll go register us now, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "You won’t find many partners\n"
	.string "tougher than me in these ends!$"

BattleFrontier_BirdKeeperIntro::
	.string "I’m BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BirdKeeperMon1::
	.string "Wagwan, check the birds.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BirdKeeperMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don’t you think we’d make a\n"
	.string "decent tag team?$"

BattleFrontier_BirdKeeperAccept::
	.string "Sick, nice one!\n"
	.string "I’ll look after the registration!$"

BattleFrontier_BirdKeeperReject::
	.string "Me and the birds are strong.\n"
	.string "What a letdown, fam.$"

BattleFrontier_NinjaBoyIntro::
	.string "I’m NINJA BOY {STR_VAR_1}!$"

BattleFrontier_NinjaBoyMon1::
	.string "My squad has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_NinjaBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let’s roll as a tag team, innit!$"

BattleFrontier_NinjaBoyAccept::
	.string "Get in!\n"
	.string "Let me go register!$"

BattleFrontier_NinjaBoyReject::
	.string "You’ll regret not having my\n"
	.string "team on your side!$"

BattleFrontier_ParasolLadyIntro::
	.string "Hiya!\n"
	.string "I’m PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_ParasolLadyMon1::
	.string "Escorting me today are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_ParasolLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren’t they lovely?\n"
	.string "Wanna join us for a tag team?$"

BattleFrontier_ParasolLadyAccept::
	.string "Thanks a bunch!\p"
	.string "I’ll go register at the counter.\n"
	.string "Let’s not mess this up!$"

BattleFrontier_ParasolLadyReject::
	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing, honestly…$"

BattleFrontier_BugManiacIntro::
	.string "Wagwan.\n"
	.string "I’m {STR_VAR_1}, and I’m a BUG MANIAC!$"

BattleFrontier_BugManiacMon1::
	.string "I’ve found my POKéMON, yeah.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BugManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "that’s the collection.\p"
	.string "Could I interest you in a\n"
	.string "tag team partnership?$"

BattleFrontier_BugManiacAccept::
	.string "Safe!\n"
	.string "Understood!\p"
	.string "I won’t be long with the registration!$"

BattleFrontier_BugManiacReject::
	.string "With the POKéMON I found, we\n"
	.string "wouldn’t have taken no Ls…$"

BattleFrontier_SailorIntro::
	.string "Ahoy there!\n"
	.string "I’m SAILOR {STR_VAR_1}!$"

BattleFrontier_SailorMon1::
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_SailorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Standard, you’re not gonna say no.\n"
	.string "We’re teaming up, right?$"

BattleFrontier_SailorAccept::
	.string "I knew you were smart!\n"
	.string "I’ll go register us now.$"

BattleFrontier_SailorReject::
	.string "We would’ve stormed through the\n"
	.string "opposition! Too bad, mate!$"

BattleFrontier_CollectorIntro::
	.string "Safe, I’m {STR_VAR_1}.\n"
	.string "I’m a COLLECTOR.$"

BattleFrontier_CollectorMon1::
	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_CollectorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, innit?\n"
	.string "We should be in a team together.$"

BattleFrontier_CollectorAccept::
	.string "Oh, yeah!\p"
	.string "Let’s not waste any time.\n"
	.string "I’ll go register the two of us.$"

BattleFrontier_CollectorReject::
	.string "Well, that’s upsetting.\n"
	.string "You don’t appreciate the collection.$"

BattleFrontier_PkmnRangerMIntro::
	.string "Safe, I’m {STR_VAR_1}.\n"
	.string "I’m a POKéMON RANGER.$"

BattleFrontier_PkmnRangerMMon1::
	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_PkmnRangerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don’t you think we’d make an\n"
	.string "impressive tag team?$"

BattleFrontier_PkmnRangerMAccept::
	.string "That’s super! Safe.\n"
	.string "I’ll deal with the registration now.$"

BattleFrontier_PkmnRangerMReject::
	.string "Next time, choose my POKéMON,\n"
	.string "yeah?$"

BattleFrontier_PkmnRangerFIntro::
	.string "My name’s {STR_VAR_1}.\n"
	.string "I’m a POKéMON RANGER!$"

BattleFrontier_PkmnRangerFMon1::
	.string "Let me tell you about my squad. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_PkmnRangerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"

BattleFrontier_PkmnRangerFAccept::
	.string "We’ll be our best!\n"
	.string "I’ll get the registration done quick!$"

BattleFrontier_PkmnRangerFReject::
	.string "I hope you’ll choose my POKéMON\n"
	.string "next time.$"

BattleFrontier_AromaLadyIntro::
	.string "Pleased to meet you. I’m {STR_VAR_1}.\n"
	.string "I’m an AROMA LADY, don't you know.$"

BattleFrontier_AromaLadyMon1::
	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_AromaLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they smell lovely. Care to\n"
	.string "be my partner?$"

BattleFrontier_AromaLadyAccept::
	.string "I’m honored! Safe.\n"
	.string "I will go register right this instant.$"

BattleFrontier_AromaLadyReject::
	.string "It would be wonderful if we could\n"
	.string "link up next time we meet.$"

BattleFrontier_RuinManiacIntro::
	.string "Want the drop on who I am?\n"
	.string "I’m {STR_VAR_1}, the RUIN MANIAC!$"

BattleFrontier_RuinManiacMon1::
	.string "The POKéMON I’ve got with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_RuinManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh? How about\n"
	.string "you and I partner up?$"

BattleFrontier_RuinManiacAccept::
	.string "That’s a sound decision!\n"
	.string "I’ll go do the paperwork.$"

BattleFrontier_RuinManiacReject::
	.string "Hmm…\n"
	.string "I think my POKéMON are proper tough…$"

BattleFrontier_CoolTrainerMIntro::
	.string "I’m COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_CoolTrainerMMon1::
	.string "The POKéMON I’ve got right now are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_CoolTrainerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Proper cool, innit?\p"
	.string "Don’t you think it’d be sick\n"
	.string "if we made a tag team?$"

BattleFrontier_CoolTrainerMAccept::
	.string "Sick!\n"
	.string "I’ll go do the registration in a flash!$"

BattleFrontier_CoolTrainerMReject::
	.string "I thought we’d make just the\n"
	.string "best team ever, man.$"

BattleFrontier_CoolTrainerFIntro::
	.string "I’m COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_CoolTrainerFMon1::
	.string "The team I’ve been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_CoolTrainerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound calm? How\n"
	.string "about we become tag partners?$"

BattleFrontier_CoolTrainerFAccept::
	.string "Sounds A-OK!\n"
	.string "I’d better do the registration.$"

BattleFrontier_CoolTrainerFReject::
	.string "I was thinking we would be one\n"
	.string "proper tough team…$"

BattleFrontier_PokemaniacIntro::
	.string "Safe!\n"
	.string "I’m {STR_VAR_1}, the POKéMANIAC!$"

BattleFrontier_PokemaniacMon1::
	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_PokemaniacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that’s what!\p"
	.string "Let’s do it! We’ll stomp around\n"
	.string "the ends as a tag team!$"

BattleFrontier_PokemaniacAccept::
	.string "Good call!\n"
	.string "I’ll register the both of us!$"

BattleFrontier_PokemaniacReject::
	.string "My POKéMON are brutal!\n"
	.string "Don't blame me if you regret this!$"

BattleFrontier_KindlerIntro::
	.string "Yo there!\n"
	.string "I’m KINDLER {STR_VAR_1}!$"

BattleFrontier_KindlerMon1::
	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_KindlerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what you saying?\n"
	.string "Wanna form a tag team?$"

BattleFrontier_KindlerAccept::
	.string "Safe!\n"
	.string "I’ll get on with the registration.$"

BattleFrontier_KindlerReject::
	.string "Promise you’ll link up with me next\n"
	.string "time we’re in the same place.$"

BattleFrontier_CamperIntro::
	.string "I’m {STR_VAR_1}, and I’m a CAMPER!$"

BattleFrontier_CamperMon1::
	.string "I’ve been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"

BattleFrontier_CamperMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it’d be jokes to team up?\n"
	.string "I bet it would be!$"

BattleFrontier_CamperAccept::
	.string "Yeah! Safe!\n"
	.string "Off I go to register!$"

BattleFrontier_CamperReject::
	.string "Next time, yeah?\n"
	.string "I wanna be on your team.$"

BattleFrontier_PicnickerIntro::
	.string "Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a PICNICKER!$"

BattleFrontier_PicnickerMon1::
	.string "The POKéMON I’ve been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_PicnickerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "You interested in joining me\n"
	.string "on a tag team?$"

BattleFrontier_PicnickerAccept::
	.string "Why, thank you!\n"
	.string "I will do the registration now.$"

BattleFrontier_PicnickerReject::
	.string "It’d be nice if I could roll with\n"
	.string "you some other time.$"

BattleFrontier_PsychicMIntro::
	.string "I’m PSYCHIC {STR_VAR_1}!$"

BattleFrontier_PsychicMMon1::
	.string "The twosome I’ve been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_PsychicMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Wanna form a tag team\n"
	.string "with me?$"

BattleFrontier_PsychicMAccept::
	.string "Safe thing!\n"
	.string "I’ll take care of the registration!$"

BattleFrontier_PsychicMReject::
	.string "If we meet again, that’s when I’d like\n"
	.string "to link up with you.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "I’m {STR_VAR_1}.\n"
	.string "I’m a PSYCHIC.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they’re my disciples.\p"
	.string "Doesn’t the idea of a tag-team\n"
	.string "partnership intrigue you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Safe for that.\n"
	.string "I’ll go sort the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "I hope there’s another chance for\n"
	.string "us to forge an alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "I’m SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
	.string "Please, may I be your partner for\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, nice one! Thank you!\n"
	.string "I’ll register at the counter right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Please?\n"
	.string "Can I join you next time?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hiya! The name’s {STR_VAR_1}!\n"
	.string "I’m a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "The POKéMON I’ve raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound like a bit of you?\n"
	.string "How about we form a tag team, then?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "All righty!\n"
	.string "Leave the registration stuff to me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "You’ve got to team up with me next\n"
	.string "time, all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "I’m {STR_VAR_1}, and I’m proud to say\n"
	.string "that I am a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "The darling POKéMON I’ve raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren’t they just the cutest?\n"
	.string "We really ought to make a team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Thank you, dear!\n"
	.string "I’ll be on my way to register us!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "My darlings are the best in London,\n"
	.string "I’ll have you know. How annoying!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hi, I’m SWIMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I’ve trained.\p"
	.string "You and me, let’s make a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "That’s cool! Safe.\n"
	.string "I’ll register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "If we meet again, you owe me\n"
	.string "a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Wagwan?\n"
	.string "I’m {STR_VAR_1}, and I’m a TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "I’ve got a couple decent POKéMON.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It’d be proper sick if we teamed up,\n"
	.string "so what you saying?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Safe one!\n"
	.string "Wait there while I register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "I expect you’ll let me join you\n"
	.string "next time, yeah?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "I’m the TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That’s my pair.\p"
	.string "What do you think?\n"
	.string "We’d make a proper good team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "I like that answer!\n"
	.string "I’ll get the registration done fast!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "You’ll give me another chance to\n"
	.string "link up later, won’t you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hi there! Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a SWIMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Check out what I’ve been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, innit?\n"
	.string "It’d be sweet to form a team, too!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Proper safe for that!\n"
	.string "I’ll go get the registration done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "If we meet again, you’ve got to team\n"
	.string "up with me. You’ll do that, right?$"

