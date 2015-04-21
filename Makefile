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

o/main.c.o: srcs/main.c h/minish.h
	@$(COMPILE)
libft:
	@make -C libft


MSG_0 := printf '\033[0;32m%-13.13s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-13.13s\033[0;0m\n'

COMPILE = $(MSG_0) $< ; $(CC) $(FLAGS) $(HEADS) -c -o $@ $< || $(MSG_1) $<

O_FILES := o/main.c.o

$(NAME): o/ $(LIBS) $(O_FILES)
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
