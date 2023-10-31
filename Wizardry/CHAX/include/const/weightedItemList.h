const struct WeightedItem ItemListSword[] = {
	{ITEM_SWORD_IRON, 70},
	{ITEM_SWORD_STEEL, 25},
	{ITEM_SWORD_SILVER, 5}
};

const struct WeightedItem ItemListLance[] = {
	{ITEM_LANCE_IRON, 70},
	{ITEM_LANCE_STEEL, 25},
	{ITEM_LANCE_SILVER, 5}
};

const struct WeightedItem ItemListAxe[] = {
	{ITEM_AXE_IRON, 70},
	{ITEM_AXE_STEEL, 25},
	{ITEM_AXE_SILVER, 5}
};

const struct WeightedItem ItemListBow[] = {
	{ITEM_BOW_IRON, 70},
	{ITEM_BOW_STEEL, 25},
	{ITEM_BOW_SILVER, 5}
};

const struct WeightedItem ItemListStaff[] = {
	{ITEM_STAFF_HEAL, 70},
	{ITEM_STAFF_MEND, 25},
	{ITEM_STAFF_PHYSIC, 5}
};

const struct WeightedItem ItemListAnima[] = {
	{ITEM_ANIMA_FIRE, 70},
	{ITEM_ANIMA_THUNDER, 25},
	{ITEM_ANIMA_ELFIRE, 5}
};

const struct WeightedItem ItemListLight[] = {
	{ITEM_LIGHT_LIGHTNING, 70},
	{ITEM_LIGHT_SHINE, 25},
	{ITEM_LIGHT_DIVINE, 5}
};

const struct WeightedItem ItemListDark[] = {
	{ITEM_DARK_FLUX, 70},
	{ITEM_DARK_NOSFERATU, 25},
	{ITEM_DARK_LUNA, 5}
};

const struct WeightedItem* const ItemListList[] = {
	ItemListSword,
	ItemListLance,
	ItemListAxe,
	ItemListBow,
	ItemListStaff,
	ItemListAnima,
	ItemListLight,
	ItemListDark	
};
