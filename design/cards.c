#include "items.h"
#include "colors.h"
// #include <stdbool.h>

Card fibonacci = {
    .name = "Fibonacci",
    .art = {
        "%s╔═══════════╗%s", 
        "%s║𝐉──\\%s%s███████%s%s║%s",
        "%s║%s%s✦█▓▓%s%s──\\%s%s▓▓▓▓%s%s║%s",
        "%s║%s%s▓%s%s█▓▓▓▓%s%s──\\%s%s▓▓%s%s║%s",
        "%s║%s%s▓%s%s█▓▓▓▓▓▓▓%s%s│%s%s▓%s%s║%s", //
        "%s║%s%s▓%s%s/ට%s%s▓%s%s████▓%s%s/%s%s▓%s%s║%s",
        "%s║%s%s▓%s%s|%s%s▓▓%s%s█▓▓▓%s%s/%s%s▓▓%s%s║%s",
        "%s║%s%s▓%s%s▓%s%s\\⌡⌡⌡⌡/%s%s▓▓✦%s%s║%s",
        "%s║%s%s▓%s%s▓▓▓%s%s▓▓▓▓▓▓%s%s𝐉║%s",
        "%s╚═══════════╝%s"
    },
    .color = {
        {WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_FD5FF, ESC, C_009CFD, ESC, WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_FD5FF, ESC, C_009CFD, ESC,  WHITE, ESC, C_009CFD, ESC, WHITE, ESC}, 
        {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_496E88, ESC, C_FD5FF, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC},
        {WHITE, ESC, C_496E88, ESC, WHITE, ESC, C_009CFD, ESC, C_FD5FF, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC},
        {WHITE, ESC, C_496E88, ESC, C_009CFD, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC},
        {WHITE, ESC, C_496E88, ESC, C_009CFD, ESC, C_FD5FF, ESC, WHITE, ESC},
        {WHITE, ESC}
    },
    .buy_price = 8,
    .sell_price = 4,
    .owned = 0  
};

Card dna = {
    .name = "DNA",
    .art = {
        "%s╔═══════════╗%s",
        "%s║𝐉█%s%s⑊%s%s████▓%s%s⫽%s%s▓▓║%s",
        "%s║✦█%s%s𝕏▓%s%s━%s%s━━%s%s░𝕏%s%s▓▓║%s",
        "%s║███%s%s⑊𝕏▓%s%s▓⫽%s%s▓▓▓║%s",
        "%s║██%s%s║▓𝕏%s%s═%s%s═%s%s▓║%s%s▓▓║%s",
        "%s║██%s%s🮍▓%s%s══%s%s═%s%s█🮌%s%s▓▓║%s",
        "%s║███%s%s⫽█%s%s▓𝕏⑊%s%s▓▓▓║%s",
        "%s║██%s%s𝕏█%s%s━%s%s━━%s%s█𝕏%s%s▓✦║%s",
        "%s║██%s%s⫽%s%s███▓▓%s%s⑊%s%s▓𝐉║%s",
        "%s╚═══════════╝%s"
    },
    .color = {
        {WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_DD463C, ESC, WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, C_56A786, ESC, C_DD463C, ESC, C_DD463C, ESC, WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, C_DD463C, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD463C, ESC, C_56A786, ESC, C_DD463C, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD463C, ESC, C_FDA200, ESC, C_009CFD, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD463C, ESC, C_009CFD, ESC, WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, C_FDA200, ESC, C_009CFD, ESC, C_DD463C, ESC, WHITE, ESC},
        {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_DD463C, ESC, WHITE, ESC},
        {WHITE, ESC}
    },
    .buy_price = 8,
    .sell_price = 4,
    .owned = 0  
};

Card four_fingers = {
    .name = "Four Fingers",
    .art = {
        "%s╔═══════════╗%s",
        "%s║𝐉%s%s▒▒▒▒▒▒▒▒▒▒%s%s║%s",
        "%s║%s%s✦▓▓▓▓%s%s@%s%s▓▓▓▓▓%s%s║%s",
        "%s║%s%s████%s%s/▒␥%s%s█%s%s␥@%s%s█%s%s║%s",
        "%s║%s%s██%s%s@%s%s█%s%s»▓@␥█|%s%s█%s%s║%s",
        "%s║%s%s▓%s%s\\▓\\▓▓██«%s%s▓▓%s%s║%s", 
        "%s║%s%s▒▒%s%s\\▓▓▓▓█/%s%s▒▒%s%s║%s",
        "%s║%s%s▓▓▓%s%s⟍_▓█/%s%s▓▓✦%s%s║%s",
        "%s║%s%s██████████%s%s𝐉║%s",
        "%s╚═══════════╝%s"
    },
    .color = {
        {WHITE, ESC},
        {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
        {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
        {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
        {WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC},
        {WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
        {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
        {WHITE, ESC}
    },
    .buy_price = 7,
    .sell_price = 3,
    .owned = 0
};

/*
const char* TEMP[CARD_LENGTH] = {
};

const char* C_TEMP[CARD_LENGTH][MAX_COLORS] = {
    {WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC, WHITE, ESC},
    {WHITE, ESC}
};
*/