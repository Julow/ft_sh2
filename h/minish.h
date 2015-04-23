/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/24 01:06:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

/*
** ========================================================================== **
** TODO
** ----
** |
** < file
** <<
** > file
** >> file
** ;
** &&
** ||
** 0< file
** <&1
** 0<&1
** 0<<
** 0> file
** &> file
** >&0
** 1>&0
** 0>> file
** &>> file
** ----
** ""
** ''
** ""''
** ----
*/

typedef char	t_bp[65];

typedef struct	s_msh
{
	t_array			env;
	int				last_status;
}				t_msh;

# define SH				"ft_msh2"

# define DEF_REDIR_FD	0

#endif
