#include "cards.h"
#include "colors.h"

// each card and an array of its associated colors per line
const char* FIBONACCI[CARD_LENGTH] = {
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
};

const char* C_FIBONACCI[CARD_LENGTH][MAX_COLORS] = {
    {WHITE, ESC},
    {WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
    {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
    {WHITE, ESC, C_FD5FF, ESC, C_009CFD, ESC, WHITE, ESC, C_009CFD, ESC, WHITE, ESC},
    {WHITE, ESC, C_FD5FF, ESC, C_009CFD, ESC,  WHITE, ESC, C_009CFD, ESC, WHITE, ESC}, 
    {WHITE, ESC, C_009CFD, ESC, WHITE, ESC, C_496E88, ESC, C_FD5FF, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC},
    {WHITE, ESC, C_496E88, ESC, WHITE, ESC, C_009CFD, ESC, C_FD5FF, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC}, //
    {WHITE, ESC, C_496E88, ESC, C_009CFD, ESC, WHITE, ESC, C_FD5FF, ESC, WHITE, ESC},
    {WHITE, ESC, C_496E88, ESC, C_009CFD, ESC, C_FD5FF, ESC, WHITE, ESC},
    {WHITE, ESC}
};

// DNA
const char* DNA[CARD_LENGTH] = {
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
};

const char* C_DNA[CARD_LENGTH][MAX_COLORS] = {
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
};

const char* FOUR_FINGERS[CARD_LENGTH] = {
    "%s╔═══════════╗%s",
    "%s║𝐉%s%s▒▒▒▒▒▒▒▒▒▒%s%s║%s",
    "%s║%s%s✦▓▓▓▓%s%s@%s%s▓▓▓▓▓%s%s║%s",
    "%s║%s%s████%s%s/▒␥%s%s█%s%s␥@%s%s█%s%s║%s",
    "%s║%s%s██%s%s@%s%s█%s%s»▓@␥█|%s%s█%s%s║%s",
    "%s║%s%s▓%s%s\\▓\\▓▓██«%s%s▓▓%s%s║%s", //
    "%s║%s%s▒▒%s%s\\▓▓▓▓█/%s%s▒▒%s%s║%s",
    "%s║%s%s▓▓▓%s%s⟍_▓█/%s%s▓▓✦%s%s║%s",
    "%s║%s%s██████████%s%s𝐉║%s",
    "%s╚═══════════╝%s" 
};

const char* C_FOUR_FINGERS[CARD_LENGTH][MAX_COLORS] = {
    {WHITE, ESC},
    {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
    {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
    {WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC, C_8C58C0, ESC, WHITE, ESC},
    {WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC}, //
    {WHITE, ESC, C_C47BCE, ESC, WHITE, ESC, C_C47BCE, ESC, WHITE, ESC},
    {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
    {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
    {WHITE, ESC, C_DD85B7, ESC, WHITE, ESC},
    {WHITE, ESC}
};

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