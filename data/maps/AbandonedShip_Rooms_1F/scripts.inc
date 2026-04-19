AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround::
	.string "You don't see builds like this often,\n"
	.string "so I'm just scoping it out.\p"
	.string "Hm... looks like there are more spots\n"
	.string "to check in the back.$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro::
	.string "What’s got you wandering into a place\n"
	.string "like this? You’re brave, I’ll give you that.$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat::
	.string "Not just brave, you're actually heavy\n"
	.string "with the battles...$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle::
	.string "That guy in the next room...\p"
	.string "He says he’s just a tourist, but\n"
	.string "he’s moving bare suspicious.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister::
	.string "You're a proper legend at this!\n"
	.string "I'm adding you to my contacts.$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro::
	.string "Back again? You must be looking for\n"
	.string "something specific in this wreck.$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat::
	.string "Your levels are too high, fam.$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch::
	.string "I’m telling you, that man is up to\n"
	.string "something dodgy. Look at him!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro::
	.string "Rhaaa!\n"
	.string "You caught me! ...Wait, who are you?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat::
	.string "Ah, safe. You're not my mum.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle::
	.string "I'm ducking my mum right now, so I'm\n"
	.string "staying low. Don't dry me out, yeah?$"

