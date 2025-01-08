mini-joker: main.c design/cards.c design/assets.c design/items.h design/colors.h tools/display_utils.c tools/display_utils.h
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o mini-joker main.c design/cards.c design/assets.c tools/display_utils.c -lutf8proc
