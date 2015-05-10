/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:59:27 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 17:58:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define SH				"ft_msh2"
# define ENDL			"\n"

# define E_EXEC			SH ": %s: Cannot exec" ENDL
# define E_FORK			SH ": Cannot create process" ENDL
# define E_DUP2			SH ": %d: Cannot dup" ENDL
# define E_FILE			SH ": %s: Cannot open file" ENDL

# define E_PARSE		SH ": Parse error: %s" ENDL
# define E_PARSE_EXP	SH ": Syntax error: Expect %s before %.*r" ENDL

# define W_SIGNAL		SH ": %s: "
# define W_SIGNAL_NO	"Kill by signal %d"
# define W_COREDUMP		" (core dump)"

#endif
