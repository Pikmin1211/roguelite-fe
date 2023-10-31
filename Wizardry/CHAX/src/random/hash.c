#include "gbafe.h"
#include "random/hash.h"

// credit circles
int HashByte_N(int number, int noise, int max){
    if (max == 0){ 
        return 0;
    }

    u32 hash = 5381;

    SetDebugTacticianName();
    char* TacticianName = GetTacticianName();
    for (int i = 0; i < 8; ++i){
        hash = (hash ^ TacticianName[i]) * 33;
    };

    hash = (hash ^ number) * 33;
    hash = (hash ^ noise) * 0x7FFFFFFF;
    return DivRem((u16)hash, max); // modulo
};

// debug
void SetDebugTacticianName(){
    char* TacticianName = GetTacticianName();

    if (TacticianName[0] != 0){
        return;
    }

    for (int i = 0; i < 8; ++i){
        TacticianName[i] = NextRN_N(0xFF);
    }
}

int HashByWeight(int number, int noise, const struct WeightedItem* itemList){
    int hash100 = HashByte_N(number, noise, 100);
    int index = 0;
    while (true){
        const struct WeightedItem weightedItem = itemList[index];
        hash100 -= weightedItem.weight;
        if (hash100 < 0){
            break;
        }
        index++;
    }
    return itemList[index].number;
}

int UnitHash(struct Unit* unit) {
    int hash = unit->xPos + unit->yPos + unit->index;
    hash += gPlaySt.chapterIndex;
    return hash;
}