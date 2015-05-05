#
# ft_minishell2
#
# Makefile
#

#
# Config
#

# Project name
NAME := ft_minishell2

# Project directories
DIRS := srcs h

# Obj directory
O_DIR := o

# Makefiles to call
LIBS := libft

# Number of threads
THREADS := 1

# C compiler
C_CC := clang

# Linking compiler
LD_CC := clang

# Clang flags
C_FLAGS := -Wall -Wextra -Werror -O2

# Linking flags
LD_FLAGS := -Llibft -lft

# Clang include flags
C_HEADS := -Ih -Ilibft

#
# Internal
#

O_FILES := o/srcs/parser/parse_arg_numeric.o \
	o/srcs/parser/parse_cmd.o \
	o/srcs/parser/parse_next_cmd.o \
	o/srcs/parser/parse_string.o \
	o/srcs/main.o \
	o/srcs/parser/parse_redir.o \
	o/srcs/parser/parse_heredoc.o \
	o/srcs/parser/ft_parsesubn.o \
	o/srcs/parser/parse_string_newline.o \
	o/srcs/parser/utils.o \
	o/srcs/env.o \
	o/srcs/exec/exec_cmd.o \
	o/srcs/parser/parse_string_var.o \
	o/srcs/parser/parse_arg.o \
	o/srcs/exec/cmd.o \
	o/srcs/parser/parse_error.o \
	o/srcs/parser/parse_string_escape.o \
	o/srcs/exec/exec_line.o \
	o/srcs/exec/print_cmd.o

MSG_0 := printf '\033[0;32m%-36.36s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-36.36s\033[0;0m\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && echo || $(MSG_1) $@

o/srcs/parser/parse_arg_numeric.o: srcs/parser/parse_arg_numeric.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_cmd.o: srcs/parser/parse_cmd.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_next_cmd.o: srcs/parser/parse_next_cmd.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string.o: srcs/parser/parse_string.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c h/minish.h h/exec.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_redir.o: srcs/parser/parse_redir.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_heredoc.o: srcs/parser/parse_heredoc.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/ft_parsesubn.o: srcs/parser/ft_parsesubn.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_newline.o: srcs/parser/parse_string_newline.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/utils.o: srcs/parser/utils.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/env.o: srcs/env.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_cmd.o: srcs/exec/exec_cmd.c h/exec.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_var.o: srcs/parser/parse_string_var.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_arg.o: srcs/parser/parse_arg.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/cmd.o: srcs/exec/cmd.c h/exec.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_error.o: srcs/parser/parse_error.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_escape.o: srcs/parser/parse_string_escape.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_line.o: srcs/exec/exec_line.c h/parser.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/print_cmd.o: srcs/exec/print_cmd.c h/exec.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

h/exec.h: h/minish.h

h/parser.h: h/exec.h

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs/parser o/srcs/exec o/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

make: fclean
	@python makemake.py
.PHONY: make
