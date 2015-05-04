#
# Makemake
#

# Executable name
NAME := ft_minishell2
# Sources directory
C_DIR := srcs
# Includes directories
H_DIRS := h
# Obj directory
O_DIR := o
# Makefiles to call
LIBS := libft
# Number of threads
THREADS := 1
# C compiler
C_CC := clang
# Clang flags
C_FLAGS := -Wall -Wextra -Werror -g
# Linking flags
LD_FLAGS := -Llibft -lft
# Clang include flags
C_HEADS := -Ih -Ilibft

all: $(NAME)

LD_CC := clang

srcs/exec/cmd.o: srcs/exec/cmd.c o/exec h/exec.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/exec/exec_cmd.o: srcs/exec/exec_cmd.c o/exec h/exec.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/exec/exec_line.o: srcs/exec/exec_line.c o/exec h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/main.o: srcs/main.c o/ h/minish.h h/exec.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_arg.o: srcs/parser/parse_arg.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_arg_numeric.o: srcs/parser/parse_arg_numeric.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_cmd.o: srcs/parser/parse_cmd.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_error.o: srcs/parser/parse_error.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_heredoc.o: srcs/parser/parse_heredoc.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_next_cmd.o: srcs/parser/parse_next_cmd.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/parse_redir.o: srcs/parser/parse_redir.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

srcs/parser/utils.o: srcs/parser/utils.c o/parser h/parser.h
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

libft:
	@make -C libft
.PHONY: libft

MSG_0 := printf '\033[0;32m%-31.31s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-31.31s\033[0;0m\n'

O_FILES :=	srcs/exec/cmd.o \
			srcs/exec/exec_cmd.o \
			srcs/exec/exec_line.o \
			srcs/main.o \
			srcs/parser/parse_arg.o \
			srcs/parser/parse_arg_numeric.o \
			srcs/parser/parse_cmd.o \
			srcs/parser/parse_error.o \
			srcs/parser/parse_heredoc.o \
			srcs/parser/parse_next_cmd.o \
			srcs/parser/parse_redir.o \
			srcs/parser/utils.o

$(NAME): $(LIBS) $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && echo || $(MSG_1) $@

$(O_DIR)/:
	@mkdir -p $@ 2> /dev/null || true

$(O_DIR)/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p $(O_DIR) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME) 2> /dev/null || true

re: fclean all

make:
	@python ./makemake.py

.PHONY: all clean fclean re make
