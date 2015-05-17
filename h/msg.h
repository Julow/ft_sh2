/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:59:27 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:11:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "ft_colors.h"

# define SH				"ft_msh2"
# define ENDL			C_RESET "\n"

# define E_EXEC			C_RED SH ": %s: Cannot exec" ENDL
# define E_FORK			C_RED SH ": Cannot create process" ENDL
# define E_DUP2			C_RED SH ": %d: Cannot dup" ENDL
# define E_FILE			C_RED SH ": %s: %s" ENDL

# define W_PATH_E		C_YELLOW SH ": Warning: %s: %s" ENDL
# define E_PATH_NO		C_LRED SH ": %s: Command not found" ENDL

# define E_PARSE		C_LRED SH ": Parse error: %s" ENDL
# define _E_PARSE_EXP	"Expect %s before %.*r" ENDL
# define E_PARSE_EXP	C_LRED SH ": Syntax error: " _E_PARSE_EXP

# define W_SIGNAL		C_LRED SH ": %s: "
# define W_SIGNAL_NO	"Kill by signal %d"
# define W_COREDUMP		" (core dump)"
# define W_SIGNAL_END	ENDL

# define M_RIGHT		"Permission denied"
# define M_ISDIR		"Is a directory"
# define M_NOEXISTS		"No such file or directory"
# define M_ERR			"Cannot open"

/*
** Builtins
*/
# define E_CD_HOME		C_LRED "%s: Cannot find $HOME variable." ENDL
# define E_CD_OLDPWD	C_LRED "%s: Cannot find $OLDPWD variable." ENDL
# define E_CD_FAIL		C_LRED "%s: No such file or directory: %s" ENDL
# define E_CD_ERR		C_LRED "%s: Unexpected error" ENDL

# define E_ARG_INT		C_LRED "%s: '%s' is not a valid int" ENDL
# define E_ARG_NOT		C_LRED "%s: Not enougth argument" ENDL

#endif
