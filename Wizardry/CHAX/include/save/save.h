struct CurrentRunSaveData {
	u8 usedUnitIds[62];
};

extern struct CurrentRunSaveData gCurrentRunData;

void SaveCurrentRunData(void* saveTarget);
void LoadCurrentRunData(void* loadTarget);