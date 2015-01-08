/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 14:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 14:47:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** ft_strcase
** =============
** Compare 's1' and 's2' case insensitive
*/
t_bool			ft_strcase(const char *s1, const char *s2)
{
	t_uint			i;

	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? TRUE : FALSE);
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0')
		i++;
	return ((ft_tolower(s1[i]) == ft_tolower(s2[i])) ? TRUE : FALSE);
}

/*
** ft_strncase
** =============
** Compare 's1' and 's2' case insensitive
** Compare 'n' characters
*/
t_bool			ft_strncase(const char *s1, const char *s2, t_uint n)
{
	t_uint			i;

	if (n == 0)
		return (TRUE);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? TRUE : FALSE);
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0' &&i < n)
		i++;
	return ((ft_tolower(s1[i]) == ft_tolower(s2[i])) ? TRUE : FALSE);
}

t_array			*ft_arraydup(const t_array *array)
{
	t_array			*dup;

	dup = ft_arraynew();
	ft_arrayext(dup, array->length);
	ft_memcpy(dup->data, array->data, array->length * sizeof(void*));
	dup->length = array->length;
	return (dup);
}
