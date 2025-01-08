#include "items.h"
#include "colors.h"

char* score_board[] = {
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▐            BIG BLIND            ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s/─────────────────────────────────\\%s",
    "%s│                                 │%s",
    "%s│ +───────────────+ description   │%s",
    "%s│ │Score at least │ description   │%s",
    "%s│ │❂ 4200         │ description   │%s",
    "%s│ │Reward: $$$$   │ description   │%s",
    "%s│ +───────────────+ description   │%s",
    "%s│                                 │%s",
    "%s\\─────────────────────────────────/%s",
    "%s░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▐                                 ▌%s",
    "%s▐ Round Score: ❂ 0                ▌%s",
    "%s▐                                 ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s/─────────────────────────────────\\%s",
    "%s│                                 │%s",
    "%s│       Type of hand lvl. 1       │%s",
    "%s│                                 │%s",
    "%s│          chips X multi          │%s",
    "%s│                                 │%s",
    "%s\\─────────────────────────────────/%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▌                                 ▌%s",
    "%s▌ Hands:                          ▌%s",
    "%s▌ Discards:                       ▌%s",
    "%s▌                                 ▌%s",
    "%s▌ ─────────────────────────────── ▌%s",
    "%s▌                                 ▌%s",
    "%s▌ Money:                          ▌%s",
    "%s▌ Ante:                           ▌%s",
    "%s▌ Round:                          ▌%s",
    "%s▌                                 ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░%s"
};

UI small_blind = {
    .art = {
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▐           %s%sSMALL BLIND%s%s           ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s/─────────────────────────────────\\%s",
    "%s│                                 │%s",
    "%s│ +─────────────────────────────+ │%s",
    "%s│ │%s%sScore at least%s%s               │ │%s",
    "%s│ │%s%s❂%s %s%s%s%s│ │%s",
    "%s│ │%s%sReward: %s%s%s%s%s│ │%s",
    "%s│ +─────────────────────────────+ │%s",
    "%s│                                 │%s",
    "%s\\─────────────────────────────────/%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▐                                 ▌%s",
    // "%s│ │❂         │ │%s",
    "%s▐%s%s Round Score: ❂ %s%s%s▌%s", // this is one space to small i think
    "%s▐                                 ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s/─────────────────────────────────\\%s",
    "%s│                                 │%s",
    "%s│%s%s%s lvl. %s%s%s│%s", // blue, white, insert, insert, blue - 35 characters total
    "%s│                                 │%s",
    "%s│%s %s%s%s %sX%s %s%s%s %s│%s",
    "%s│                                 │%s",
    "%s\\─────────────────────────────────/%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s",
    "%s▌                                 ▌%s",
    "%s▌%s %sHands:%s %s%s%s %s▌%s",
    "%s▌%s %sDiscards:%s %s%s%s %s▌%s",
    "%s▌                                 ▌%s",
    "%s▌ ─────────────────────────────── ▌%s",
    "%s▌                                 ▌%s",
    "%s▌%s %sMoney:%s %s%s%s %s▌%s",
    "%s▌%s %sAnte:%s %s%s%s %s▌%s",
    "%s▌%s %sRound:%s %s%s%s %s▌%s",
    "%s▌                                 ▌%s",
    "%s+▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬+%s"
    },
    // should probably change the numbers to %i or float later
    .color = {
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, RED_BOLD, "score", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, YELLOW_BOLD, "reward", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC}, 
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "current_points", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "type_of_hand", "current_lvl", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "chips", ESC, RED_BOLD, ESC, WHITE_BOLD, "mult", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, BLUE_BOLD, "hands", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, RED_BOLD, "discards", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, YELLOW_BOLD, "money", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, ORANGE_BOLD, "ante", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, ORANGE_BOLD, "round", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC}
    }
};
