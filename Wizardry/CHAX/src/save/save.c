#include "gbafe.h"
#include "save/save.h"

void SaveCurrentRunData(void* saveTarget){
	WriteAndVerifySramFast(&gCurrentRunData, saveTarget, sizeof(struct CurrentRunSaveData));
}

void LoadCurrentRunData(void* loadTarget){
	ReadSramFast(loadTarget, &gCurrentRunData, sizeof(struct CurrentRunSaveData));
}
