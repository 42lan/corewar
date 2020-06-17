# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by bleplat           #+#    #+#              #
#    Updated: 2020/06/17 19:25:34 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRC_FILES_COMMON	=	common/cw_champion.c \
						common/cw_op_list.c \
						common/cw_op_get.c \
						common/cw_op_get_arg_type.c \
						common/cw_op_get_arg_types.c \
						common/cw_op_get_coding_code.c \
						common/cw_op_get_coding_byte.c \
						common/cw_op_get_full_coding_byte.c \
						common/cw_champion_save_to_file.c \
						common/cw_inst.c \
						common/cw_inst_write.c \
						common/cw_inst_size.c \

SRC_FILES_ASM		=	asm/cw_asm_main.c \
						asm/cw_asm_error.c \
						asm/cw_asm_options.c \
						asm/cw_asm_default_out_file.c \
						asm/cw_linst.c \
						asm/cw_literal.c \
						asm/cw_asm.c \
						asm/cw_asm_get_label.c \
						asm/cw_asm_run.c \
						asm/cw_asm_input.c \
						asm/cw_asm_translate.c \
						asm/cw_asm_translate_labels.c \
						asm/cw_asm_translate_insts.c \
						asm/cw_asm_translate_insts_labels.c \
						asm/cw_asm_assemble.c \
						asm/cw_asm_output.c \
						asm/cw_asm_nothing_at_end.c \
						asm/cw_asm_skip_label_index.c \
						asm/cw_asm_skip_spaces_index.c \
						asm/cw_asm_spaces_index.c \
						asm/cw_asm_skip_alnums_index.c \
						asm/cw_asm_argend_index.c \
						asm/cw_asm_nextarg_index.c \
						asm/cw_asm_dismember_string.c \
						asm/cw_asm_translate_literal.c \
						asm/cw_asm_translate_inst.c \
						asm/cw_asmr.c \
						asm/cw_asmr_msg.c \

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
						vm/cw_vm_game.c \
						vm/cw_vm_ini_game.c \
						vm/cw_vm_start_game.c \
						vm/cw_vm_read_execute.c \
						vm/cw_vm_predicaters.c \
						vm/cw_vm_debug.c \
						vm/cw_vm_is_valid_extension.c \
						vm/cw_vm_set_dump.c \
						vm/cw_vm_set_player.c \
						vm/cw_vm_proc.c \
						vm/cw_vm_rw_bigendian.c \
						$(SRC_FILES_CW_OP)

SRC_FILES_CW_OP		=	vm/ops/cw_vm_live.c \
						vm/ops/cw_vm_ld.c \
						vm/ops/cw_vm_st.c \
						vm/ops/cw_vm_add.c \
						vm/ops/cw_vm_sub.c \
						vm/ops/cw_vm_and.c \
						vm/ops/cw_vm_or.c \
						vm/ops/cw_vm_xor.c \
						vm/ops/cw_vm_zjmp.c \
						vm/ops/cw_vm_ldi.c \
						vm/ops/cw_vm_sti.c \
						vm/ops/cw_vm_fork.c \
						vm/ops/cw_vm_lld.c \
						vm/ops/cw_vm_lldi.c \
						vm/ops/cw_vm_lfork.c \
						vm/ops/cw_vm_aff.c \
						vm/ops/cw_vm_add_pos.c \

SRC_FILES = $(SRC_FILES_COMMON) $(SRC_FILES_ASM) $(SRC_FILES_CW)



###########################
###    F O L D E R S    ###
###########################

INCLUDES = includes
SRC_DIR  = srcs
OBJ_DIR  = .obj
OBJ_SUBDIRS = $(OBJ_DIR)/common $(OBJ_DIR)/asm $(OBJ_DIR)/vm/ops $(OBJ_DIR)/vm
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

CC = gcc -g3

DEFINES = _DARWIN_USE_64_BIT_INODE
CDEFINES = $(patsubst %, -D%, $(DEFINES))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(CDEFINES)
CFLAGS += -I $(INCLUDES)
CFLAGS += -I $(LIBFT_DIR)/includes

LDFLAGS += -L $(LIBFT_DIR) -lft


###########################
### M A I N   R U L E S ###
###########################

.PHONY: all
all: $(NAME_CW) $(NAME_ASM)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	@printf "\e[92m" || true
	$(CC) $(CFLAGS) -o $@ $(OBJ_ASM) $(LDFLAGS)
	@printf "\e[0m" || true

$(NAME_CW): $(LIBFT) $(OBJ_CW)
	@printf "\e[92m" || true
	$(CC) $(CFLAGS) -o $@ $(OBJ_CW) $(LDFLAGS)
	@printf "\e[0m" || true

$(OBJ_DIR):
	@printf "\e[96m" || true
	@mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "\e[96m" || true
	$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\e[0m" || true

$(LIBFT):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libft.a
	@printf "\e[0m" || true

.PHONY: clean
clean:
	@printf "\e[93m" || true
	rm -f $(OBJ)
	rmdir $(OBJ_SUBDIRS) || true
	rmdir $(OBJ_DIR) || true
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: fclean
fclean: clean
	@printf "\e[91m" || true
	rm -f $(NAME)
	rm -f $(LIBFTMO)
	rm -f $(NAME_ASM)
	rm -f $(NAME_CW)
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: re
re: fclean all
	@printf "\e[0m" || true


###########################
### M O R E   R U L E S ###
###########################

.PHONY: update
update:
	@printf "\e[95m" || true
	git remote update
	git status -uno
	@printf "\e[0m" || true

.PHONY: upgrade
upgrade:
	@printf "\e[95m" || true
	git pull
	@printf "\e[0m" || true

.PHONY: debug
debug: LDFLAGS += -L. -lftmo -rdynamic -ldl
debug: $(LIBFTMO) all

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

$(LIBFTMO):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libftmo.a
	@printf "\e[35m" || true
	#cp $(LIBFT_DIR)/libftmo.so $@
	@printf "\e[0m" || true


###########################
###  D O C   R U L E S  ###
###########################

.PHONY: geterror
geterror:
	@echo $?
	grep -E "_ERROR_|_WARNING_" includes/cw_errors.h

.PHONY: help
help:
	@printf "\e[0m" || true
	@printf "USAGE:\n" || true
	@printf "\t./asm CHAMPION.s\n" || true
	@printf "\t./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n" || true
	@printf "\e[91m" || true
