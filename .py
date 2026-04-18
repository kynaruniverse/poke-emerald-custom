[1mdiff --git a/data/text/birch_speech.inc b/data/text/birch_speech.inc[m
[1mindex 7a9ea6a611..2ebf388b64 100644[m
[1m--- a/data/text/birch_speech.inc[m
[1m+++ b/data/text/birch_speech.inc[m
[36m@@ -1,13 +1,13 @@[m
 gText_Birch_Welcome::[m
 	.string "Hi! Sorry to keep you waiting!\p"[m
[31m-	.string "Welcome to the world of POKéMON!\p"[m
[31m-	.string "My name is BIRCH.\p"[m
[32m+[m	[32m.string "Welcome to the Hoenn Ecosystem™!\p"[m
[32m+[m	[32m.string "I am BIRCH, Founder and CEO of\nBIRCH-STARTUP.\p"[m
 	.string "But everyone calls me the POKéMON\n"[m
 	.string "PROFESSOR.\p"[m
 	.string "$"[m
 [m
 gText_Birch_Pokemon::[m
[31m-	.string "This is what we call a “POKéMON.”\p"[m
[32m+[m	[32m.string "This is a "High-Value Asset."\nWe call it a POKéMON for tax reasons.\p"[m
 	.string "\n"[m
 	.string "$"[m
 [m
[1mdiff --git a/src/strings.c b/src/strings.c[m
[1mindex 7d139586ab..2462e2d3ee 100644[m
[1m--- a/src/strings.c[m
[1m+++ b/src/strings.c[m
[36m@@ -301,7 +301,7 @@[m [mconst u8 gText_PkmnTransformed[] = _("{STR_VAR_1} transformed!{PAUSE_UNTIL_PRESS[m
 const u8 gText_ThrowAwayItem[] = _("Throw away this\n{STR_VAR_1}?");[m
 const u8 gText_ItemThrownAway[] = _("The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}");[m
 const u8 gText_TeachWhichPokemon2[] = _("Teach which POKéMON?"); // Unused[m
[31m-const u8 gText_ChoosePokemon[] = _("Choose a POKéMON.");[m
[32m+[m[32mconst u8 gText_ChoosePokemon[] = _("Select an Asset.");[m
 const u8 gText_MoveToWhere[] = _("Move to where?");[m
 const u8 gText_TeachWhichPokemon[] = _("Teach which POKéMON?");[m
 const u8 gText_UseOnWhichPokemon[] = _("Use on which POKéMON?");[m
[36m@@ -315,7 +315,7 @@[m [mconst u8 gText_RestoreWhichMove[] = _("Restore which move?");[m
 const u8 gText_BoostPp[] = _("Boost PP of which move?");[m
 const u8 gText_DoWhatWithItem[] = _("Do what with an item?");[m
 const u8 gText_NoPokemonForBattle[] = _("No POKéMON for battle!");[m
[31m-const u8 gText_ChoosePokemon2[] = _("Choose a POKéMON.");[m
[32m+[m[32mconst u8 gText_ChoosePokemon2[] = _("Select an Asset.");[m
 const u8 gText_NotEnoughHp[] = _("Not enough HP…");[m
 const u8 gText_PokemonAreNeeded[] = _("{STR_VAR_1} POKéMON are needed.");[m
 const u8 gText_PokemonCantBeSame[] = _("POKéMON can't be the same.");[m
