#include "items.h"
#include "colors.h"

Board small_blind = {
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
    .color = {
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, RED_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, YELLOW_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC}, 
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "n/a", "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, "0", ESC, RED_BOLD, ESC, WHITE_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, BLUE_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, RED_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, YELLOW_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, ORANGE_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC, WHITE_BOLD, ESC, ORANGE_BOLD, "0", ESC, C_0064AB, ESC},
        {C_0064AB, ESC},
        {C_0064AB, ESC}
    }
};