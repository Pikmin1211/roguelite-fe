#define EXTERN_ID(externUnit) ((externUnit) & 0xFF)
#define EXTERN_TABLE(externUnit) ((externUnit) >> 8)

extern struct CharacterData const * ExternUnitTables[];

void UnitLoadSupports(struct Unit* unit);
void ProcessTurnSupportExp(void);

const struct CharacterData* GetExternUnitFromUnit(struct Unit* unit);
int GetNameTextIdForExternUnit(struct Unit* unit);
inline int GetUnitPortraitId(struct Unit* unit);
inline int GetUnitMiniPortraitId(struct Unit* unit);