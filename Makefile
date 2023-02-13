# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2023/02/13 18:47:48 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all norm clean fclean re test

CC := c++
FLAGS := -std=c++98 -g3 -Wall -Wextra -Werror -MMD -MP -Isources/
#FLAGS += -fsanitize=address
SRC_DIR := sources/
OBJ_DIR := remove/
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

COMPIL = make all -C
REMOVE = make fclean -C
DEL = .delete

SRC0 = cpp00/ex00
SRC1 = cpp00/ex01
SRC2 = cpp00/ex02
SRC3 = cpp01/ex00
SRC4 = cpp01/ex01
SRC5 = cpp01/ex02
SRC6 = cpp01/ex03
SRC7 = cpp01/ex04
SRC8 = cpp01/ex05
SRC9 = cpp01/ex06
SRC10 = cpp02/ex00

SRCS =	$(SRC0) $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5) $(SRC6) $(SRC7) $(SRC8) $(SRC9) $(SRC10)

SOFT_NAME := MakeAll
OBJS = $(SRCS=%.tmp)
SRC := $(addprefix $(SRC_DIR),$(SRCS))
RSRC := $(addprefix $(OBJ_DIR),$(SRCS))
NORM := $(wildcard *.cpp) $(wildcard *.hpp)

all : ${SOFT_NAME}

$(SRC) :
	$(COMPIL) $(@:sources/%=%)

${SOFT_NAME} : $(SRC)

test : all
	$(VAL) ./${SOFT_NAME}

clean : 
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR} ${OBJF}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : $(DEL)

$(RSRC) :
	$(REMOVE) $(@:remove/%=%)

$(DEL) : $(RSRC)

re : fclean all

norm :
	${MAKE} norm -C libs/libft
	@norminette $(NORM) | grep -v OK! || true
