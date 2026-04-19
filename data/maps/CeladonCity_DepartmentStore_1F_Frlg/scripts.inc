CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "Whats good!\n"
	.string "Your at the CELADON DEPT. STORE.\p"
	.string "That board on the right Shows\n"
	.string "the store layout.$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "1F: SERVICE COUNTER\p"
	.string "2F: TRAINER'S MARKET\p"
	.string "3F: TV GAME SHOP\p"
	.string "4F: WISE MAN GIFTS\p"
	.string "5F: DRUGSTORE\p"
	.string "ROOFTOP SQUARE: VENDING MACHINES$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "1F: SERVICE COUNTER$"

