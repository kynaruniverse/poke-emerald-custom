// ============================================================
// Pokémon Daydream Version — Quest Log Implementation
// src/daydream/quest_log_custom.c
// ============================================================

#include "global.h"
#include "quest_log_custom.h"
#include "task.h"
#include "menu.h"
#include "window.h"
#include "text.h"
#include "main.h"
#include "strings.h"

// ---- State accessors ----
// State is stored in gSaveBlock1Ptr->questLog.packed[].
// 4 bits per quest: byte = questId / 2, nibble = questId % 2.

u8 QuestLog_GetState(u8 questId)
{
    u8 byteIndex, nibble;
    if (questId == QUEST_NONE || questId >= QUEST_COUNT)
        return QSTATE_NOT_STARTED;
    byteIndex = questId / 2;
    nibble    = questId % 2;
    if (nibble == 0)
        return gSaveBlock1Ptr->questLog.packed[byteIndex] & 0x0F;
    else
        return (gSaveBlock1Ptr->questLog.packed[byteIndex] >> 4) & 0x0F;
}

void QuestLog_SetState(u8 questId, u8 state)
{
    u8 byteIndex, nibble, byte;
    if (questId == QUEST_NONE || questId >= QUEST_COUNT)
        return;
    if (state > 15)
        state = 15;
    byteIndex = questId / 2;
    nibble    = questId % 2;
    byte      = gSaveBlock1Ptr->questLog.packed[byteIndex];
    if (nibble == 0)
        gSaveBlock1Ptr->questLog.packed[byteIndex] = (byte & 0xF0) | (state & 0x0F);
    else
        gSaveBlock1Ptr->questLog.packed[byteIndex] = (byte & 0x0F) | ((state & 0x0F) << 4);
}

void QuestLog_Start(u8 questId)
{
    if (QuestLog_GetState(questId) == QSTATE_NOT_STARTED)
        QuestLog_SetState(questId, QSTATE_STEP_1);
}

void QuestLog_Advance(u8 questId)
{
    u8 current = QuestLog_GetState(questId);
    if (current == QSTATE_NOT_STARTED || current == QSTATE_COMPLETE)
        return;
    if (current >= QSTATE_STEP_8)
        QuestLog_SetState(questId, QSTATE_COMPLETE);
    else
        QuestLog_SetState(questId, current + 1);
}

void QuestLog_Complete(u8 questId)
{
    QuestLog_SetState(questId, QSTATE_COMPLETE);
}

bool8 QuestLog_IsComplete(u8 questId)
{
    return QuestLog_GetState(questId) == QSTATE_COMPLETE;
}

bool8 QuestLog_IsStarted(u8 questId)
{
    return QuestLog_GetState(questId) > QSTATE_NOT_STARTED;
}

// ---- Journal UI stub ----
// Full list + step-detail UI requires custom window work (see TASKS.md).

static void Task_JournalMenuClose(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

void Task_OpenJournalFromStartMenu(u8 taskId)
{
    // TODO: Replace with full quest-list UI (see TASKS.md §4.6).
    u8 i, activeCount = 0;
    for (i = 1; i < QUEST_COUNT; i++)
    {
        if (QuestLog_IsStarted(i) && !QuestLog_IsComplete(i))
            activeCount++;
    }
    // Display a simple summary message for now.
    ConvertIntToDecimalStringN(gStringVar1, activeCount, STR_CONV_MODE_LEFT_ALIGN, 2);
    ShowFieldMessage(COMPOUND_STRING("JOURNAL\nActive quests: {STR_VAR_1}\n(Full UI pending — see TASKS.md)"));
    gTasks[taskId].func = Task_JournalMenuClose;
}

bool8 StartMenuJournalCallback(void)
{
    CreateTask(Task_OpenJournalFromStartMenu, 0);
    return TRUE;
}
