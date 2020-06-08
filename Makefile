# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by bleplat           #+#    #+#              #
#    Updated: 2020/06/07 19:45:31 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME	= corewar

###########################
###   B I N A R I E S   ###
###########################

NAME_ASM        = asm
NAME_CW         = corewar


###########################
###  L I B R A R I E S  ###
###########################

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFTMO     = $(LIBFT_DIR)/libftmo.a


###########################
###    S O U R C E S    ###
###########################

SRC_FILES_COMMON	=	common/ft_printerr.c \
						common/cw_champion.c \
						common/cw_op_list.c \
						common/cw_op_get_arg_type.c \
						common/cw_op_get_arg_types.c \
						common/cw_op_get_coding_code.c \
						common/cw_op_get_coding_byte.c \

SRC_FILES_ASM		=#	asm/cw_asm_main.c \

SRC_FILES_CW		=	vm/cw_vm_main.c \
						vm/cw_vm_parsing.c \
						vm/cw_vm_usage.c \
						vm/cw_parsing_number_player.c \
						vm/cw_vm_read_player.c \
						vm/cw_vm_valid_player.c \
						vm/cw_vm_read_file_struct.c \
						vm/cw_vm_read_magic_number.c \
						vm/cw_vm_ini_arena.c \
						vm/cw_vm_arena_dump.c \
						vm/cw_vm_intro_players.c \
						vm/cw_vm_battle.c \
						vm/cw_vm_ini_battle.c \
						vm/cw_vm_start_game.c \

SRC_FILES = $(SRC_FILES_COMMON) $(SRC_FILES_ASM) $(SRC_FILES_CW)


###########################
###    F O L D E R S    ###
###########################

INCLUDES = includes
SRC_DIR  = srcs
OBJ_DIR  = .obj
DEP_DIR  = $(OBJ_DIR)

SRC_COMMON	= $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES_COMMON))
SRC_ASM		= $(SRC_COMMON) $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES_ASM))
SRC_CW		= $(SRC_COMMON) $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES_CW))
SRC = $(SRC_COMMON) $(SRC_ASM) $(SRC_CW)

OBJ_COMMON	= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_FILES_COMMON))
OBJ_ASM = $(OBJ_COMMON) $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_FILES_ASM))
OBJ_CW = $(OBJ_COMMON) $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_FILES_CW))
OBJ = $(OBJ_ASM) $(OBJ_CW)

DEP = $(patsubst %, $(DEP_DIR)/%.d, $(SRC_FILES))


###########################
###   C O M P I L E R   ###
###########################

CC = gcc

DEFINES = _DARWIN_USE_64_BIT_INODE
CDEFINES = $(patsubst %, -D%, $(DEFINES))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(CDEFINES)
CFLAGS += -I $(INCLUDES)
CFLAGS += -I $(LIBFT_DIR)/includes

LDFLAGS += -L $(LIBFT_DIR) -lft


###########################
###     E X T R A       ###
###########################
CR          = "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC         = "\033[0;0m"
BLACK		= '\033[0;30m'
RED			= '\033[0;31m'
GREEN		= '\033[0;32m'
YELLOW		= '\033[0;33m'
BLUE		= '\033[0;34m'
PURPLE		= '\033[0;35m'
CYAN		= '\033[0;36m'
WHITE		= '\033[0;37m'


###########################
### M A I N   R U L E S ###
###########################

.SILENT:
.PHONY: all
all: $(NAME_CW) #$(NAME_ASM)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_ASM) $(LDFLAGS)
	@printf $(CR)$(GREEN)"✓ $@ is created\n"$(EOC)

$(NAME_CW): $(LIBFT) $(OBJ_CW)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_CW) $(LDFLAGS)
	@printf $(CR)$(GREEN)"✓ $@ is created\n"$(EOC)

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/common
	mkdir -p $@/asm
	mkdir -p $@/vm

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf $(CR)$(WHITE)"[ $(PROJECT_NAME): %s ]"$(EOC) $@

$(LIBFT):
	@make -sC $(LIBFT_DIR) libft.a

.PHONY: clean
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR) \
		&& printf $(CR)$(RED)"✗ Object files of $(PROJECT_NAME) are cleaned\n"$(EOC); \
	fi
	@if [ -d $(LIBFT_DIR) ]; then \
		make -sC $(LIBFT_DIR) $@; \
	fi

.PHONY: fclean
fclean: clean
	@if [ -f $(NAME_CW) ]; then \
		rm -f $(NAME_CW) \
		&& rm -f $(NAME_ASM) \
		&& printf $(CR)$(RED)"✗ Executable files of $(PROJECT_NAME) are cleaned\n"$(EOC); \
	fi
	@if [ -d $(LIBFT_DIR) ]; then \
		make -sC $(LIBFT_DIR) $@; \
	fi

.PHONY: re
re: fclean all
	@printf "\e[0m" || true


###########################
### M O R E   R U L E S ###
###########################

.PHONY: update
update:
	@printf "\e[95m" || true
	@git remote update
	@git status -uno
	@printf "\e[0m" || true

.PHONY: upgrade
upgrade:
	@printf "\e[95m" || true
	@git pull
	@printf "\e[0m" || true

.PHONY: debug
debug: LDFLAGS += -L. -lftmo -rdynamic -ldl
debug: $(LIBFTMO) all

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

$(LIBFTMO):
	@printf "\e[35m" || true
	@make -sC $(LIBFT_DIR) libftmo.a
	@printf "\e[35m" || true
	@#cp $(LIBFT_DIR)/libftmo.so $@
	@printf "\e[0m" || true


###########################
###  D O C   R U L E S  ###
###########################

.PHONY: geterror
geterror:
	@echo $?
	grep _ERROR_ includes/cw_errors.h

.PHONY: help
help:
	@printf "\e[0m" || true
	@printf "USAGE:\n" || true
	@printf "\t./asm CHAMPION.s\n" || true
	@printf "\t./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n" || true
	@printf "\e[91m" || true

