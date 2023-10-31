#include "gbafe.h"
#include "unit/unit.h"
#include "random/hash.h"

void UnitInitRandomInventory(struct Unit* unit) {
	UnitClearInventory(unit);
	const struct ClassData* class = unit->pClassData;

	int slot = 0;

	for(int i = 0; i < ITYPE_DARK+1; i++){
		if (slot == UNIT_ITEM_COUNT){
			break;
		}

		if (class->baseRanks[i]){
			switch(i){
				case ITYPE_SWORD:
					unit->items[slot] = MakeNewItem(ITEM_SWORD_IRON);
					slot++;
					break;
				case ITYPE_LANCE:
					unit->items[slot] = MakeNewItem(ITEM_LANCE_IRON);
					slot++;
					break;
				case ITYPE_AXE:
					unit->items[slot] = MakeNewItem(ITEM_AXE_IRON);
					slot++;
					break;
				case ITYPE_BOW:
					unit->items[slot] = MakeNewItem(ITEM_BOW_IRON);
					slot++;
					break;
				case ITYPE_STAFF:
					unit->items[slot] = MakeNewItem(ITEM_STAFF_HEAL);
					slot++;
					break;
				case ITYPE_ANIMA:
					unit->items[slot] = MakeNewItem(ITEM_ANIMA_FIRE);
					slot++;
					break;
				case ITYPE_LIGHT:
					unit->items[slot] = MakeNewItem(ITEM_LIGHT_LIGHTNING);
					slot++;
					break;
				case ITYPE_DARK:
					unit->items[slot] = MakeNewItem(ITEM_DARK_FLUX);
					slot++;
					break;
			}
		}
	}
}

void UnitInitFromDefinition(struct Unit* unit, const struct UnitDefinition* uDef) {
	unit->pCharacterData = GetCharacterData(uDef->charIndex);

	if (uDef->classIndex)
		unit->pClassData = GetClassData(uDef->classIndex);
	else // such an overlooked feature
		unit->pClassData = GetClassData(unit->pCharacterData->defaultClass);

	unit->level = uDef->level;

	GenUnitDefinitionFinalPosition(uDef, (u8*)&unit->xPos, (u8*)&unit->yPos, FALSE);

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