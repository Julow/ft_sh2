# LOL

NAME := ft_minishell2
C_DIR := srcs
H_DIRS := h
O_DIR := o
LIBS := libft
CC := clang
FLAGS := -Wall -Wextra -Werror -O2
LINKS := -Llibft -lft
HEADS := -Ilibft -Ih 

all: $(NAME)

o/exec/cmd.c.o: srcs/exec/cmd.c h/exec.h
	@$(COMPILE)
o/exec/exec_cmd.c.o: srcs/exec/exec_cmd.c h/exec.h
	@$(COMPILE)
o/exec/exec_line.c.o: srcs/exec/exec_line.c h/parser.h
	@$(COMPILE)
o/main.c.o: srcs/main.c h/minish.h h/exec.h
	@$(COMPILE)
o/parser/parse_arg.c.o: srcs/parser/parse_arg.c h/parser.h
	@$(COMPILE)
o/parser/parse_arg_numeric.c.o: srcs/parser/parse_arg_numeric.c h/parser.h
	@$(COMPILE)
o/parser/parse_cmd.c.o: srcs/parser/parse_cmd.c h/parser.h
	@$(COMPILE)
o/parser/parse_next_cmd.c.o: srcs/parser/parse_next_cmd.c h/parser.h
	@$(COMPILE)
o/parser/parse_redir.c.o: srcs/parser/parse_redir.c h/parser.h
	@$(COMPILE)
o/parser/utils.c.o: srcs/parser/utils.c h/parser.h
	@$(COMPILE)
libft:
	@make -C libft


MSG_0 := printf '\033[0;32m%-31.31s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-31.31s\033[0;0m\n'

COMPILE = $(MSG_0) $< ; $(CC) $(FLAGS) $(HEADS) -c -o $@ $< || $(MSG_1) $<

O_FILES := o/exec/cmd.c.o \
		o/exec/exec_cmd.c.o \
		o/exec/exec_line.c.o \
		o/main.c.o \
		o/parser/parse_arg.c.o \
		o/parser/parse_arg_numeric.c.o \
		o/parser/parse_cmd.c.o \
		o/parser/parse_next_cmd.c.o \
		o/parser/parse_redir.c.o \
		o/parser/utils.c.o

$(NAME): o/ o/exec/ o/parser/ $(LIBS) $(O_FILES)
	@$(MSG_0) $@ ; $(CC) $(FLAGS) -o $@ $(O_FILES) $(LINKS) && echo || $(MSG_1) $@

o/:
	@mkdir -p $@ 2> /dev/null || true

o/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o 2> /dev/null || true

fclean: clean
	@rm -f ft_minishell2 2> /dev/null || true

re: fclean all

make:
	@bash './makemake.sh' re

.PHONY: all clean fclean re make libft
