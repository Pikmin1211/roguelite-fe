#pragma once

#include "global.h"
#include "agb_sram.h"
#include "bmsave.h"
#include "bmdifficulty.h"
#include "bmtrick.h"
#include "uimenu.h"

enum game_save_blocks {
    GAMESAVE_SIZE_PLAYST         = sizeof(struct PlaySt),
    GAMESAVE_SIZE_UNITS          = UNIT_SAVE_AMOUNT_BLUE * sizeof(struct GameSavePackedUnit),
    GAMESAVE_SIZE_GMMONSTER      = sizeof(struct GameSavePackedUnit),
    GAMESAVE_SIZE_SUPPLY         = 0xB0,
    GAMESAVE_SIZE_PIDSTATS       = sizeof(gPidStatsData),
    GAMESAVE_SIZE_CHAPTERSTATS   = sizeof(gChapterStats),
    GAMESAVE_SIZE_PERMANENTFLAGS = 0x19 + (0x1C - 0x19), /* align 2 */
    GAMESAVE_SIZE_BONUSCLAIM     = sizeof(u32),
    GAMESAVE_SIZE_GMINFO         = sizeof(struct GMapSaveInfo),
    GAMESAVE_SIZE_DUNGEON        = 2 * sizeof(struct Dungeon),
};

enum game_save_memory_map {
    GAMESAVE_OFFSET_START = 0,

    GAMESAVE_OFFSET_PLAYST         = GAMESAVE_OFFSET_START,
    GAMESAVE_OFFSET_UNITS          = GAMESAVE_OFFSET_PLAYST         + GAMESAVE_SIZE_PLAYST,
    GAMESAVE_OFFSET_GMMONSTER      = GAMESAVE_OFFSET_UNITS          + GAMESAVE_SIZE_UNITS,
    GAMESAVE_OFFSET_SUPPLY         = GAMESAVE_OFFSET_GMMONSTER      + GAMESAVE_SIZE_GMMONSTER,
    GAMESAVE_OFFSET_PIDSTATS       = GAMESAVE_OFFSET_SUPPLY         + GAMESAVE_SIZE_SUPPLY,
    GAMESAVE_OFFSET_CHAPTERSTATS   = GAMESAVE_OFFSET_PIDSTATS       + GAMESAVE_SIZE_PIDSTATS,
    GAMESAVE_OFFSET_PERMANENTFLAGS = GAMESAVE_OFFSET_CHAPTERSTATS   + GAMESAVE_SIZE_CHAPTERSTATS,
    GAMESAVE_OFFSET_BONUSCLAIM     = GAMESAVE_OFFSET_PERMANENTFLAGS + GAMESAVE_SIZE_PERMANENTFLAGS,
    GAMESAVE_OFFSET_GMINFO         = GAMESAVE_OFFSET_BONUSCLAIM     + GAMESAVE_SIZE_BONUSCLAIM,
    GAMESAVE_OFFSET_DUNGEON        = GAMESAVE_OFFSET_GMINFO         + GAMESAVE_SIZE_GMINFO,

    GAMESAVE_OFFSET_MAX            = GAMESAVE_OFFSET_DUNGEON        + GAMESAVE_SIZE_DUNGEON
};

enum suspend_save_blocks {
    SUSPENDSAVE_SIZE_PLAYST         = sizeof(struct PlaySt),
    SUSPENDSAVE_SIZE_ACTION         = sizeof(struct ActionData),
    SUSPENDSAVE_SIZE_UNITS_BLUE     = UNIT_SAVE_AMOUNT_BLUE * sizeof(struct SuspendSavePackedUnit),
    SUSPENDSAVE_SIZE_GMMONSTER      = sizeof(struct SuspendSavePackedUnit),
    SUSPENDSAVE_SIZE_UNITS_RED      = UNIT_SAVE_AMOUNT_RED * sizeof(struct SuspendSavePackedUnit),
    SUSPENDSAVE_SIZE_UNITS_GREEN    = UNIT_SAVE_AMOUNT_GREEN * sizeof(struct SuspendSavePackedUnit),
    SUSPENDSAVE_SIZE_TRAPS          = TRAP_MAX_COUNT * sizeof(struct Trap),
    SUSPENDSAVE_SIZE_SUPPLY         = 0xB0,
    SUSPENDSAVE_SIZE_PIDSTATS       = sizeof(gPidStatsData),
    SUSPENDSAVE_SIZE_CHAPTERSTATS   = sizeof(gChapterStats),
    SUSPENDSAVE_SIZE_FORCENMENU     = MENU_OVERRIDE_MAX * sizeof(u8),
    SUSPENDSAVE_SIZE_PERMANENTFLAGS = 0x19,
    SUSPENDSAVE_SIZE_CHAPTERFLAGS   = 0x05 + 2,  /* align 1 */
    SUSPENDSAVE_SIZE_GMINFO         = sizeof(struct GMapSaveInfo),
    SUSPENDSAVE_SIZE_DUNGEON        = sizeof(struct Dungeon),
    SUSPENDSAVE_SIZE_EVENTSLOTCNT   = sizeof(int),
};

enum suspend_save_memory_map {
    SUSPENDSAVE_OFFSET_START = 0,

    SUSPENDSAVE_OFFSET_PLAYST         = SUSPENDSAVE_OFFSET_START,
    SUSPENDSAVE_OFFSET_ACTION         = SUSPENDSAVE_OFFSET_PLAYST         + SUSPENDSAVE_SIZE_PLAYST,
    SUSPENDSAVE_OFFSET_UNITS_BLUE     = SUSPENDSAVE_OFFSET_ACTION         + SUSPENDSAVE_SIZE_ACTION,
    SUSPENDSAVE_OFFSET_GMMONSTER      = SUSPENDSAVE_OFFSET_UNITS_BLUE     + SUSPENDSAVE_SIZE_UNITS_BLUE,
    SUSPENDSAVE_OFFSET_UNITS_RED      = SUSPENDSAVE_OFFSET_GMMONSTER      + SUSPENDSAVE_SIZE_GMMONSTER,
    SUSPENDSAVE_OFFSET_UNITS_GREEN    = SUSPENDSAVE_OFFSET_UNITS_RED      + SUSPENDSAVE_SIZE_UNITS_RED,
    SUSPENDSAVE_OFFSET_TRAPS          = SUSPENDSAVE_OFFSET_UNITS_GREEN    + SUSPENDSAVE_SIZE_UNITS_GREEN,
    SUSPENDSAVE_OFFSET_SUPPLY         = SUSPENDSAVE_OFFSET_TRAPS          + SUSPENDSAVE_SIZE_TRAPS,
    SUSPENDSAVE_OFFSET_PIDSTATS       = SUSPENDSAVE_OFFSET_SUPPLY         + SUSPENDSAVE_SIZE_SUPPLY,
    SUSPENDSAVE_OFFSET_CHAPTERSTATS   = SUSPENDSAVE_OFFSET_PIDSTATS       + SUSPENDSAVE_SIZE_PIDSTATS,
    SUSPENDSAVE_OFFSET_FORCENMENU     = SUSPENDSAVE_OFFSET_CHAPTERSTATS   + SUSPENDSAVE_SIZE_CHAPTERSTATS,
    SUSPENDSAVE_OFFSET_PERMANENTFLAGS = SUSPENDSAVE_OFFSET_FORCENMENU     + SUSPENDSAVE_SIZE_FORCENMENU,
    SUSPENDSAVE_OFFSET_CHAPTERFLAGS   = SUSPENDSAVE_OFFSET_PERMANENTFLAGS + SUSPENDSAVE_SIZE_PERMANENTFLAGS,
    SUSPENDSAVE_OFFSET_GMINFO         = SUSPENDSAVE_OFFSET_CHAPTERFLAGS   + SUSPENDSAVE_SIZE_CHAPTERFLAGS,
    SUSPENDSAVE_OFFSET_DUNGEON        = SUSPENDSAVE_OFFSET_GMINFO         + SUSPENDSAVE_SIZE_GMINFO,
    SUSPENDSAVE_OFFSET_EVENTSLOTCNT   = SUSPENDSAVE_OFFSET_DUNGEON        + SUSPENDSAVE_SIZE_DUNGEON,

    SUSPENDSAVE_OFFSET_MAX            = SUSPENDSAVE_OFFSET_EVENTSLOTCNT   + SUSPENDSAVE_SIZE_EVENTSLOTCNT
};

enum global_sram_blocks {
    SRAM_SIZE_HEADER    = sizeof(struct GlobalSaveInfo),
    SRAM_SIZE_BLOCKINFO = SAVE_ID_MAX * sizeof(struct SaveBlockInfo),
    SRAM_SIZE_SUSPEND   = SUSPENDSAVE_OFFSET_MAX,
    SRAM_SIZE_GAMESAVE  = GAMESAVE_OFFSET_MAX,
    SRAM_SIZE_MARENA    = sizeof(struct MultiArenaSaveBlock),
    SRAM_SIZE_XMAP      = 0xC00,
};

enum global_sram_memory_map {
    SRAM_OFFSET_START = 0,

    SRAM_OFFSET_HEADER    = SRAM_OFFSET_START,
    SRAM_OFFSET_BLOCKINFO = SRAM_OFFSET_HEADER    + SRAM_SIZE_HEADER,
    SRAM_OFFSET_SUS0      = SRAM_OFFSET_BLOCKINFO + SRAM_SIZE_BLOCKINFO,
    SRAM_OFFSET_SUS1      = SRAM_OFFSET_SUS0      + SRAM_SIZE_SUSPEND,
    SRAM_OFFSET_SAV0      = SRAM_OFFSET_SUS1      + SRAM_SIZE_SUSPEND,
    SRAM_OFFSET_SAV1      = SRAM_OFFSET_SAV0      + SRAM_SIZE_GAMESAVE,
    SRAM_OFFSET_SAV2      = SRAM_OFFSET_SAV1      + SRAM_SIZE_GAMESAVE,
    SRAM_OFFSET_MARENA    = SRAM_OFFSET_SAV2      + SRAM_SIZE_GAMESAVE,

    SRAM_OFFSET_END       = SRAM_OFFSET_MARENA    + SRAM_SIZE_MARENA,

    SRAM_OFFSET_XMAP      = CART_SRAM_SIZE - SRAM_SIZE_XMAP,
};
