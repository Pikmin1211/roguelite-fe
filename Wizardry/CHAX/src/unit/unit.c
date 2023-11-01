#include "gbafe.h"
#include "random/hash.h"
#include "const/weightedItemList.h"
#include "unit/unit.h"
#include "externunit/externunit.h"

void SetUnitRandomExternUnit(struct Unit* unit){
	switch(UNIT_FACTION(unit)){
		case FACTION_BLUE:
			int number = HashByte_N(UnitHash(unit), NOISE_UNIT, sizeof(FE8CharacterList));
			unit->externUnit = FE8CharacterList[number] | (GAME_FE8 << 8);
			break;
		default:
			break;
	}
}

void RandomItemForSlot(struct Unit* unit, int slot, int noise, const struct WeightedItem* itemList){
	int item = HashByWeight(UnitHash(unit), noise, itemList);
	unit->items[slot] = MakeNewItem(item);
}

void UnitInitRandomInventory(struct Unit* unit) {
	UnitClearInventory(unit);
	const struct ClassData* class = unit->pClassData;

	int slot = 0;
	int noise = NOISE_ITEM_0;

	for(int i = 0; i < ITYPE_DARK+1; i++){
		if (slot == UNIT_ITEM_COUNT){
			break;
		}
		if (class->baseRanks[i]){
			RandomItemForSlot(unit, slot, noise, ItemListList[i]);
			slot++;
			noise++;
		}
	}
}

void UnitInitFromDefinition(struct Unit* unit, const struct UnitDefinition* uDef) {
	unit->pCharacterData = GetCharacterData(uDef->charIndex);
	
	GenUnitDefinitionFinalPosition(uDef, (u8*)&unit->xPos, (u8*)&unit->yPos, FALSE);
	SetUnitRandomExternUnit(unit);

	if (uDef->classIndex)
		unit->pClassData = GetClassData(uDef->classIndex);
	else // such an overlooked feature
		unit->pClassData = GetClassData(unit->pCharacterData->defaultClass);

	unit->level = uDef->level;

	//GenUnitDefinitionFinalPosition(uDef, (u8*)&unit->xPos, (u8*)&unit->yPos, FALSE);

	if (UNIT_IS_GORGON_EGG(unit)) {
		int i;

		// For gorgon eggs, set first item to zero
		// And store the other item ids in slots 1 through 4 for later initialization

		unit->items[0] = 0;

		for (i = 0; i < UNIT_DEFINITION_ITEM_COUNT; ++i)
			unit->items[i + 1] = uDef->items[i];
	} else {
		/*
		int i;

		for (i = 0; (i < UNIT_DEFINITION_ITEM_COUNT) && (uDef->items[i]); ++i)
			UnitAddItem(unit, MakeNewItem(uDef->items[i]));
		*/
		UnitInitRandomInventory(unit);
	}

	CharStoreAI(unit, uDef);
}