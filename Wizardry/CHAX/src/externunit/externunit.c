#include "gbafe.h"
#include "externunit/externunit.h"

void UnitLoadSupports(struct Unit* unit) {
    return;
}

void ProcessTurnSupportExp(void){
    return;
}

const struct CharacterData* GetExternUnitFromUnit(struct Unit* unit){
    return &ExternUnitTables[EXTERN_TABLE(unit->externUnit)][EXTERN_ID(unit->externUnit)];
} 

int GetNameTextIdForExternUnit(struct Unit* unit) {
    return GetExternUnitFromUnit(unit)->nameTextId;
}

inline int GetUnitPortraitId(struct Unit* unit) {
    if (unit->pCharacterData->portraitId) {
        // TODO: PORTRAIT_LYON?, CHAPTER definitions
        /*
        if (gPlaySt.chapterIndex == 0x22 && unit->pCharacterData->portraitId == 0x4A)
            return 0x46;
        */

        //return unit->pCharacterData->portraitId;
        return GetExternUnitFromUnit(unit)->portraitId;
    }

    if (unit->pClassData->defaultPortraitId)
        return unit->pClassData->defaultPortraitId;

    return 0;
}

// this is unchanged but needs to be here to work
inline int GetUnitMiniPortraitId(struct Unit* unit) {
    if (unit->pCharacterData->miniPortrait)
        return 0x7F00 + unit->pCharacterData->miniPortrait;

    return GetUnitPortraitId(unit);
}