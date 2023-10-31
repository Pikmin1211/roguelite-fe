enum noises{
    NOISE_NONE,
    NOISE_CLASS,
    NOISE_MAXHP,
    NOISE_POW,
    NOISE_SKL,
    NOISE_SPD,
    NOISE_DEF,
    NOISE_RES,
    NOISE_LCK,
    NOISE_CHEST,
    NOISE_ITEM_0,
    NOISE_ITEM_1,
    NOISE_ITEM_2,
    NOISE_ITEM_3,
    NOISE_ITEM_4
};

int HashByte_N(int number, int noise, int max);
void SetDebugTacticianName();