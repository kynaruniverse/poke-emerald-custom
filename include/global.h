# Updated global.h file

// Existing Includes
#include "config/save.h"
#include "wardrobe.h"
#include "quest_log_custom.h"

// Other contents of global.h...

struct SaveBlock2 {
    // Existing fields...
    // Adding wardrobe state fields
    // (Specify the types and sizes for these fields)
    int wardrobeState;
};

struct SaveBlock1 {
    // Existing fields...
    // Adding questLog field after waldaPhrase
    // (Specify the types and sizes for these fields)
    int waldaPhrase;
    int questLog;
};