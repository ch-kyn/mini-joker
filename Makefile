mini-joker: main.c \
	game/render/screen.c game/render/screen.h \
	game/render/board.c game/render/board.h \
	game/render/round.c game/render/round.h \
	game/logic/inventory.c game/logic/inventory.h \
	game/logic/input.c game/logic/input.h \
	design/cards.c design/assets.c design/items.h design/colors.h \
	tools/display_utils.c tools/display_utils.h \
	tools/linked_list.c tools/linked_list.h
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra \
		-Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable \
		-Wshadow -I. -Igame/render -Igame/logic \
		-o mini-joker main.c \
		game/render/screen.c game/render/board.c game/render/round.c \
		game/logic/inventory.c game/logic/input.c \
		design/cards.c design/assets.c tools/display_utils.c tools/linked_list.c \
		-lutf8proc