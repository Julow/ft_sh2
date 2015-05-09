/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:59:27 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 01:04:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define SH				"ft_msh2"
# define ENDL			"\n"

# define E_EXEC			SH ": %s: Cannot exec" ENDL
# define E_FORK			SH ": Cannot create process" ENDL

# define E_PARSE		SH ": Parse error: %s" ENDL
# define E_PARSE_EXP	SH ": Syntax error: Expect %s before %.*r" ENDL

#endif
