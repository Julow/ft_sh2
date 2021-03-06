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

O_FILES := o/srcs/prompt.o \
	o/srcs/builtins/builtin_export.o \
	o/srcs/builtins/builtin_setenv.o \
	o/srcs/builtins/builtin_env.o \
	o/srcs/builtins/builtin_builtin.o \
	o/srcs/ft_tabiter.o \
	o/srcs/parser/parse_string_var.o \
	o/srcs/exec/cmd.o \
	o/srcs/builtins/builtin_printenv.o \
	o/srcs/parser/parse_arg.o \
	o/srcs/parser/parse_next_cmd.o \
	o/srcs/ft_access.o \
	o/srcs/parser/utils.o \
	o/srcs/exec/print_cmd.o \
	o/srcs/parser/parse_redir.o \
	o/srcs/ft_argvarg.o \
	o/srcs/main.o \
	o/srcs/exec/exec_builtin_nofork.o \
	o/srcs/exec/exec_cmd.o \
	o/srcs/parser/parse_string_newline.o \
	o/srcs/ft_subnextf.o \
	o/srcs/builtins/builtin_cd.o \
	o/srcs/builtins/builtin_pwd.o \
	o/srcs/parser/parse_heredoc.o \
	o/srcs/parser/parse_cmd.o \
	o/srcs/builtins/builtin_rand.o \
	o/srcs/exec/exec_builtin.o \
	o/srcs/parser/parse_arg_numeric.o \
	o/srcs/builtins/builtin_exit.o \
	o/srcs/builtins/builtin_sleep.o \
	o/srcs/ft_countwords.o \
	o/srcs/parser/parse_string_escape.o \
	o/srcs/exec/search_cmd.o \
	o/srcs/exec/exec_status_signal.o \
	o/srcs/builtins/builtin_true.o \
	o/srcs/ft_subnext.o \
	o/srcs/env.o \
	o/srcs/parser/ft_parsesubn.o \
	o/srcs/builtins/builtin_raise.o \
	o/srcs/builtins/builtin_sortw.o \
	o/srcs/builtins/builtin_eval.o \
	o/srcs/builtins/builtin_unsetenv.o \
	o/srcs/parser/parse_string.o \
	o/srcs/ft_argvopt.o \
	o/srcs/builtins/builtin_help.o \
	o/srcs/builtins/builtin_return.o \
	o/srcs/exec/exec_redirs.o \
	o/srcs/builtins/builtin_false.o \
	o/srcs/exec/exec_open.o \
	o/srcs/parser/parse_error.o \
	o/srcs/builtins/builtin_echo.o \
	o/srcs/exec/exec_line.o

MSG_0 := printf '\033[0;32m%-36.36s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-36.36s\033[0;0m\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && echo || $(MSG_1) $@

o/srcs/prompt.o: srcs/prompt.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_export.o: srcs/builtins/builtin_export.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_setenv.o: srcs/builtins/builtin_setenv.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_env.o: srcs/builtins/builtin_env.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_builtin.o: srcs/builtins/builtin_builtin.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_tabiter.o: srcs/ft_tabiter.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_var.o: srcs/parser/parse_string_var.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/cmd.o: srcs/exec/cmd.c h/exec.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_printenv.o: srcs/builtins/builtin_printenv.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_arg.o: srcs/parser/parse_arg.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_next_cmd.o: srcs/parser/parse_next_cmd.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_access.o: srcs/ft_access.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/utils.o: srcs/parser/utils.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/print_cmd.o: srcs/exec/print_cmd.c h/exec.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_redir.o: srcs/parser/parse_redir.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_argvarg.o: srcs/ft_argvarg.c h/ft_argv.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c h/minish.h h/exec.h h/msg.h h/ft_argv.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_builtin_nofork.o: srcs/exec/exec_builtin_nofork.c h/builtin.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_cmd.o: srcs/exec/exec_cmd.c h/exec.h h/builtin.h h/msg.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_newline.o: srcs/parser/parse_string_newline.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_subnextf.o: srcs/ft_subnextf.c h/exec.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_cd.o: srcs/builtins/builtin_cd.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_pwd.o: srcs/builtins/builtin_pwd.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_heredoc.o: srcs/parser/parse_heredoc.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_cmd.o: srcs/parser/parse_cmd.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_rand.o: srcs/builtins/builtin_rand.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_builtin.o: srcs/exec/exec_builtin.c h/builtin.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_arg_numeric.o: srcs/parser/parse_arg_numeric.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_exit.o: srcs/builtins/builtin_exit.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_sleep.o: srcs/builtins/builtin_sleep.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_countwords.o: srcs/ft_countwords.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string_escape.o: srcs/parser/parse_string_escape.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/search_cmd.o: srcs/exec/search_cmd.c h/exec.h h/msg.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_status_signal.o: srcs/exec/exec_status_signal.c h/exec.h h/msg.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_true.o: srcs/builtins/builtin_true.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_subnext.o: srcs/ft_subnext.c h/exec.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/env.o: srcs/env.c h/minish.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/ft_parsesubn.o: srcs/parser/ft_parsesubn.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_raise.o: srcs/builtins/builtin_raise.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_sortw.o: srcs/builtins/builtin_sortw.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_eval.o: srcs/builtins/builtin_eval.c h/exec.h h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_unsetenv.o: srcs/builtins/builtin_unsetenv.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_string.o: srcs/parser/parse_string.c h/parser.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_argvopt.o: srcs/ft_argvopt.c h/ft_argv.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_help.o: srcs/builtins/builtin_help.c h/builtin.h h/msg.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_return.o: srcs/builtins/builtin_return.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_redirs.o: srcs/exec/exec_redirs.c h/exec.h h/msg.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_false.o: srcs/builtins/builtin_false.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_open.o: srcs/exec/exec_open.c h/exec.h h/msg.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/parser/parse_error.o: srcs/parser/parse_error.c h/parser.h h/msg.h
	@mkdir -p o/srcs/parser 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/builtins/builtin_echo.o: srcs/builtins/builtin_echo.c h/builtin.h
	@mkdir -p o/srcs/builtins 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/exec/exec_line.o: srcs/exec/exec_line.c h/parser.h
	@mkdir -p o/srcs/exec 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

h/parser.h: h/exec.h

h/builtin.h: h/exec.h

h/exec.h: h/minish.h

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs/parser o/srcs/exec o/srcs/builtins o/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

make: fclean
	@python makemake.py
.PHONY: make
