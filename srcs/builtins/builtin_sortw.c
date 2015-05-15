/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_sortw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 00:26:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <fcntl.h>

static int		alphlong_cmp(t_sub *s1, t_sub *s2)
{
	int				i;
	char			c1;
	char			c2;

	if (s1->length != s2->length)
		return (s1->length - s2->length);
	i = 0;
	while (i < s1->length)
	{
		c1 = LOWER(s1->str[i]);
		c2 = LOWER(s2->str[i]);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

static void		sortw(t_sub line, int word_count)
{
	t_sub			words[word_count];
	t_sub			*words_ptr[word_count];
	int				i;

	i = -1;
	line.length = 0;
	while (++i < word_count)
	{
		ft_subnextf(&line, &ft_iswhite);
		words[i] = line;
		words_ptr[i] = words + i;
	}
	ft_quicksort((void**)words_ptr, word_count, &alphlong_cmp);
	i = -1;
	while (++i < word_count)
	{
		if (i > 0)
			PC(' ');
		P("%.*s", words_ptr[i]->length, words_ptr[i]->str);
	}
	NL;
}

static t_bool	sortw_file(char const *file)
{
	int				fd;
	t_sub			line;

	if (ft_strequ(file, "-"))
		fd = 0;
	else if ((fd = exec_open(file, READ_O)) < 0)
		return (false);
	while (get_next_line(fd, &line) > 0)
		sortw(line, ft_countwords(line.str));
	return (true);
}

int				builtin_sortw(t_msh *sh, int argc, char **argv)
{
	int				i;

	if (argc == 1)
	{
		sortw_file("-");
		return (0);
	}
	i = 0;
	while (++i < argc)
		if (!sortw_file(argv[i]))
			return (1);
	return (0);
	(void)sh;
}
