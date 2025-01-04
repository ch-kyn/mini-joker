mini-joker: main.c design/jokers.c design/cards.c design/ui.c design/items.h design/colors.h
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o mini-joker main.c design/jokers.c design/cards.c design/ui.c -lncurses
