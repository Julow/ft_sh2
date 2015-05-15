/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnextf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:59:25 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 00:03:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ft_subnextf(t_sub *sub, t_bool (*f)(int c))
{
	sub->str += sub->length;
	sub->length = 0;
	while (f(*(sub->str)))
		sub->str++;
	while (!f(sub->str[sub->length]) && sub->str[sub->length] != '\0')
		sub->length++;
	return (sub->length);
}
