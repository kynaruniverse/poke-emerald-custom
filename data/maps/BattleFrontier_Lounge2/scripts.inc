BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Wagwan! When it comes to the latest\n"
	.string "word on the FRONTIER, I’m no. 1.\p"
	.string "Call me the FRONTIER MANIAC, yeah?\p"
	.string "Just checking, but you’re a TRAINER,\n"
	.string "innit? Safe.\p"
	.string "I’ll drop the hottest news I’ve\n"
	.string "gathered about the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Wagwan! You back again to grill me\n"
	.string "about the latest? Say no more!$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Let’s see now…\p"
	.string "Word on the street is the\n"
	.string "{STR_VAR_1} is proper popping off.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Let’s see now…\p"
	.string "Sounds like the BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest spot.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Bet you didn't know this one!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Mysterious lady called the SALON\n"
	.string "MAIDEN is the one running the shop.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "You clashed with the SALON MAIDEN yet?\p"
	.string "When she’s just testing the waters,\n"
	.string "she brings these ones to the scrap:\p"
	.string "A PSYCHIC-type PSI POKéMON,\n"
	.string "a FIRE-type VOLCANO POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "You fought the SALON MAIDEN when\n"
	.string "she’s actually serious?\p"
	.string "When she’s going all out, no cap,\n"
	.string "she’s using these POKéMON:\p"
	.string "A DRAGON & PSYCHIC EON POKéMON,\n"
	.string "an ELECTRIC-type THUNDER POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Flamboyant fella called the DOME ACE\n"
	.string "is the one running the place.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "You clashed with the DOME ACE yet?\p"
	.string "When he’s taking it easy on you,\n"
	.string "he’s using these three POKéMON:\p"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a FIRE & FLYING FLAME POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "You fought the DOME ACE when\n"
	.string "he’s actually serious?\p"
	.string "When he’s showing off his tactics,\n"
	.string "he’s using these three POKéMON:\p"
	.string "A DRAGON & FLYING EON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a STEEL- & PSYCHIC-type IRON LEG\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Freaky fella called the FACTORY HEAD\n"
	.string "is the one running the shop.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "You clashed with the FACTORY HEAD\n"
	.string "yet, or what?\p"
	.string "Let me think… When he scraps, he\n"
	.string "just grabs three rental POKéMON.\p"
	.string "He’s fighting under the same\n"
	.string "vibes as you, basically.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "You fought the FACTORY HEAD when\n"
	.string "he’s actually serious?\p"
	.string "Even when he’s going in hard, he\n"
	.string "still just uses rental POKéMON.\p"
	.string "He’s fighting under virtually the\n"
	.string "same conditions as you.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Scary lady called the PIKE QUEEN\n"
	.string "is the one running the place.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "You clashed with the PIKE QUEEN\n"
	.string "before?\p"
	.string "When she’s in a good mood, word is\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a BUG & ROCK MOLD POKéMON,\l"
	.string "and a WATER-type TENDER POKéMON.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "You fought the PIKE QUEEN when\n"
	.string "she’s actually serious?\p"
	.string "When she’s proper annoyed, they say\n"
	.string "she brings these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a STEEL & GROUND IRON SNAKE POKéMON,\l"
	.string "and a WATER- & FLYING-type ATROCIOUS\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Cute lady called the ARENA TYCOON\n"
	.string "is the one running the place.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "You clashed with the ARENA TYCOON\n"
	.string "before?\p"
	.string "When she’s just checking your game,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A BUG & FIGHTING SINGLE HORN POKéMON,\n"
	.string "a DARK-type MOONLIGHT POKéMON,\l"
	.string "and a BUG & GHOST SHED POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "You fought the ARENA TYCOON when\n"
	.string "she’s actually serious?\p"
	.string "When she’s battling for keeps,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A DARK-type MOONLIGHT POKéMON,\n"
	.string "a GHOST & POISON SHADOW POKéMON\l"
	.string "and a GRASS- & FIGHTING-type\l"
	.string "MUSHROOM POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Sinister fella called the PALACE\n"
	.string "MAVEN is the one running the shop.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "You clashed with the PALACE MAVEN\n"
	.string "before?\p"
	.string "When he’s testing your spirit, he’s\n"
	.string "said to use these three POKéMON:\p"
	.string "A POISON & FLYING-type BAT POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON, and a\l"
	.string "WATER- & ICE-type TRANSPORT POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "You fought the PALACE MAVEN when\n"
	.string "he’s actually serious?\p"
	.string "When he puts his whole weight into it,\n"
	.string "he’s said to use these POKéMON:\p"
	.string "A FIRE-type LEGENDARY POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON,\l"
	.string "and a WATER-type AURORA POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those elite TRAINERS SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "Fiery-hot fella called the PYRAMID\n"
	.string "KING is the one running the place.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "You clashed with the PYRAMID KING\n"
	.string "before?\p"
	.string "When he’s checking your power, he\n"
	.string "apparently uses these three POKéMON:\p"
	.string "A ROCK-type ROCK PEAK POKéMON,\n"
	.string "an ICE-type ICEBERG POKéMON,\l"
	.string "and a STEEL-type IRON POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "You fought the PYRAMID KING when\n"
	.string "he’s actually serious?\p"
	.string "When he’s pumped and ready to scrap,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "An ICE & FLYING FREEZE POKéMON, an\n"
	.string "ELECTRIC & FLYING ELECTRIC POKéMON,\l"
	.string "and a FIRE- & FLYING-type FLAME\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Yeah, there’s plenty of spots where\n"
	.string "you can jump into DOUBLE BATTLES.\p"
	.string "But the DOUBLE BATTLE ROOMS in\n"
	.string "the BATTLE TOWER are, like, basic!\p"
	.string "Start there to learn how DOUBLE\n"
	.string "BATTLES are played here in the\l"
	.string "BATTLE FRONTIER, innit.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Watch your back in the scrap here.\p"
	.string "I hear there are TRAINERS that have\n"
	.string "tactics they’ve built just for\l"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Once you’re feeling confident with\n"
	.string "the DOUBLE BATTLES here, you should\l"
	.string "look at challenging the other spots\l"
	.string "offering doubles.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "All sorts of TRAINERS link up in\n"
	.string "the BATTLE SALON.\p"
	.string "Just think--you might run into your\n"
	.string "mates or followers!\l"
	.string "Keep your eyes peeled, yeah?$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "If you’re with a mate, head for the\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "If you scrap with a strong friend,\n"
	.string "expect to see some proper tough foes!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Swear down, his news-gathering!\n"
	.string "My mentor’s built different!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Look at those powers of observation!\n"
	.string "My mentor’s like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Look at that power of persuasion!\n"
	.string "My mentor’s the realest!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…What even is this place?\n"
	.string "It’s proper scaring me…$"

