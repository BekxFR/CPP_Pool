# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2023/03/04 19:54:44 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all norm clean fclean re test

CC := c++
FLAGS := -std=c++98 -g3 -Wall -Wextra -Werror -MMD -MP -Isources/
# FLAGS += -fsanitize=address
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

SRCS =	$(wildcard cpp*/ex*)

SOFT_NAME := MakeAll
OBJS = $(SRCS=%.tmp)
SRC := $(addprefix $(SRC_DIR),$(SRCS))
RSR := $(addprefix $(OBJ_DIR),$(SRCS))
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

$(RSR) :
	$(REMOVE) $(@:remove/%=%)

$(DEL) : $(RSR)

re : fclean all

norm :
	${MAKE} norm -C libs/libft
	@norminette $(NORM) | grep -v OK! || true
