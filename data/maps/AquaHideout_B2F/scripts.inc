AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro::
	.string "Haha... so you actually made it down\n"
	.string "to the depths? Mad.\p"
	.string "We definitely didn't think you had\n"
	.string "the minerals for this.\p"
	.string "But the games stop here.\p"
	.string "I’m in a different league than those\n"
	.string "low-level grunts.\p"
	.string "I ain’t just stalling you, fam.\n"
	.string "I’m gonna actually end your run.$"

AquaHideout_B2F_Text_MattDefeat::
	.string "Haha... so I really got smoked,\n"
	.string "didn't I?$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations::
	.string "Big laughs!\p"
	.string "While I was busy running your hands,\n"
	.string "the BIG MAN finished the prep!$"

AquaHideout_B2F_Text_MattPostBattle::
	.string "Safe... the BOSS is already on route\n"
	.string "to some deep-sea trench!\p"
	.string "If you’re still trying to chase the\n"
	.string "squad, you better get searching the\l"
	.string "waves past LILYCOVE.\p"
	.string "But you’re looking for a needle in a\n"
	.string "stack of needles, fam. Good luck.$"

AquaHideout_B2F_Text_Grunt4Intro::
	.string "Rah, I was getting bored of waiting!\n"
	.string "Finally, someone I can actually test!$"

AquaHideout_B2F_Text_Grunt4Defeat::
	.string "Tired of waiting... now I’m just\n"
	.string "tired of losing.$"

AquaHideout_B2F_Text_Grunt4PostBattle::
	.string "BOSS... I did what I could.\n"
	.string "Is it enough?$"

AquaHideout_B2F_Text_Grunt6Intro::
	.string "Warp panels, man. The pride of the\n"
	.string "whole hideout!\p"
	.string "You’re proper lost in the sauce right\n"
	.string "now, aren't you?\p"
	.string "Confuse the enemy, wear 'em out, then\n"
	.string "drop 'em. That’s the motive!$"

AquaHideout_B2F_Text_Grunt6Defeat::
	.string "What’s the deal? You aren't even\n"
	.string "sweating!$"

AquaHideout_B2F_Text_Grunt6PostBattle::
	.string "Wait... where did I even put that\n"
	.string "MASTER BALL?\p"
	.string "If I've lost the crew's best tech,\n"
	.string "the BOSS is gonna have my head...$"

AquaHideout_B2F_Text_Grunt8Intro::
	.string "When I first joined the gang, I had to\n"
	.string "learn how these warps work before I\l"
	.string "was even allowed to carry a POKé BALL.$"

AquaHideout_B2F_Text_Grunt8Defeat::
	.string "I was too focused on the tiles and\n"
	.string "not the battle!$"

AquaHideout_B2F_Text_Grunt8PostBattle::
	.string "I need to stop worrying about the floor\n"
	.string "and start worrying about my levels.$"

