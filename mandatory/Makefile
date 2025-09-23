# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:47:43 by mivogel           #+#    #+#              #
#    Updated: 2025/09/23 11:18:57 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/make/srcs.mk
include libft/make/colors.mk

TERM_WIDTH := $(shell tput cols)
SHELL = /bin/bash

vpath %.c ${SRCS_PATH}

# Header management
INC_CORE := includes libft/includes mlx
INC := $(addprefix -I, $(INC_CORE))


LIBS = -L libft -lft

MLX = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm -lGL

OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = cc
CFLAGS += -g3 -O2
#CFLAGS += -flto -ffast-math -march=native -pipe -fno-pie -no-pie
CFLAGS += -Wall -Wextra -Werror

NAME = cub3D

default:	help
	@	${MAKE} --no-print-directory ${NAME}

ifeq ($(shell test $(TERM_WIDTH) -gt 50; echo $$?), 0)
help:
	@	echo -ne "\r\033[2K" $(WHITE) "----------------------------------------------"${NC}"\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "all        →  "${NC}"Compile the program.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "game       →  "${NC}"Run the game.\n"
	@   echo -ne "\r\033[2K" $(LIGHTPURPLE) "assets     →  "${NC}"Download game assets.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "valgrind   →  "${NC}"Check for memory leaks.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "libft      →  "${NC}"Rebuilds libft.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "mlx        →  "${NC}"Rebuilds libmlx.a.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "submodules →  "${NC}"Updates git submodules.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "clean      →  "${NC}"Removes temporary files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "fclean     →  "${NC}"Deletes all generated files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "re         →  "${NC}"Rebuilds the project.\n"
	@	echo -ne "\r\033[2K" $(WHITE) "----------------------------------------------"${NC}"\n"
else
help:
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"all\n"${NC}" Compile the program.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"game\n"${NC}" Run the game.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"assets\n"${NC}" Download game assets.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"valgrind\n"${NC}" Check for memory leaks.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"libft\n"${NC}" Rebuilds libft.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"mlx\n"${NC}" Rebuilds libmlx.a.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"submodules\n"${NC}" Updates git submodules.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"clean\n"${NC}" Removes temporary files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"fclean\n"${NC}" Deletes all generated files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"re\n"${NC}" Rebuilds the project.\n"
endif

all: ${NAME}

game: ${NAME}
	@	echo -ne "\r\033[2K" $(LIGHTBLUE) "→ Running a test map\n"$(NC)
	@	./${NAME} maps/church.cub

assets:
	@	echo -ne "\r\033[2K" $(LIGHTBLUE) "→ Downloading assets...\n"$(NC)
	@	cd assets && ./bash.sh && cd ..
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ Assets downloaded!\n"$(NC)

valgrind:	${NAME}
	@		echo -ne "\r\033[2K"$(LIGHTBLUE)"Valgrind ./${NAME} maps/church.cub : \n--track-fds=yes \n--leak-check=full --show-leak-kinds=all --track-origins=yes"$(NC)"\n"
	@		-valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/church.cub

libft:
	@	+$(MAKE) --no-print-directory -s -C libft re CFLAGS="-fno-pie"

mlx:
	@	+$(MAKE) --no-print-directory -s -C mlx re

submodules:
	@	echo -ne "\r\033[2K" $(LIGHTBLUE) "→ Updating submodules...\n"$(NC)
	@	git submodule update --init --recursive
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ Submodules updated!\n"$(NC)

clean:	
	@	+$(MAKE) --no-print-directory -s -C mlx clean > /dev/null 2>&1
	@ 	echo -ne "\r\033[2K" $(LIGHTRED) "→ objs cleaned\n"$(NC)
	@	rm -rf ${OBJS_PATH}

fclean:	clean
	@	+$(MAKE) --no-print-directory -s -C libft fclean
	@	echo -ne "\r\033[2K" $(LIGHTRED) "→ ${NAME} cleaned\n"$(NC)
	@	rm -f ${NAME}

re:	fclean ${NAME}

${NAME}: ${MLX} ${OBJS}
	@	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${MLX_FLAGS}
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ $(NAME) OK!\n"$(NC)

${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile includes/cub3d.h
	@	$(MAKE) --no-print-directory -s -C libft CFLAGS="-fno-pie"
	@	mkdir -p ${OBJS_PATH}
	@	$(COLORCOMPIL)
	@	${CC} ${CFLAGS} -c $< -o $@ ${INC}

${MLX}: 
	@	echo -ne "\r\033[2K" $(YELLOW) "→ Checking MLX submodule..."$(NC)
	@	if [ ! -f mlx/Makefile ]; then \
			echo -ne "\r\033[2K" $(YELLOW) "→ Initializing MLX submodule..."$(NC); \
			git submodule update --init --recursive; \
		fi
	@	echo -ne "\r\033[2K" $(YELLOW) "→ Compiling libmlx.a..."$(NC)
	@	$(MAKE) --no-print-directory -s -C mlx >/dev/null 2>&1
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ libmlx.a OK!"$(NC)"\n"

include libft/make/colorcompil.mk

.PHONY: default all clean fclean re valgrind libft mlx submodules debug game assets