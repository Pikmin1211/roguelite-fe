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

    if (TacticianName[0]){
        return;
    }

    for (int i = 0; i < 8; ++i){
        TacticianName[i] = NextRN_N(0xFF);
    };
}