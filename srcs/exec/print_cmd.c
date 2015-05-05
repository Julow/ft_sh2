/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:57:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 15:58:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		print_redir(t_redir *redir)
{
	PC(' ');
	PI(redir->fd[0]);
	if (redir->redir_t == REDIR_LEFT)
		PS("<");
	else if (redir->redir_t == REDIR_HEREDOC)
		PS("<<");
	else if (redir->redir_t == REDIR_RIGHT)
		PS(">");
	else if (redir->redir_t == REDIR_APPEND)
		PS(">>");
	if (redir->data == NULL)
		PI(redir->fd[1]);
	else
		PS(redir->data);
	PC(' ');
}

void			print_cmd(t_cmd *cmd)
{
	int				i;

	i = -1;
	while (++i < cmd->argv.length)
	{
		if (i > 0)
			PC(' ');
		PC('"');
		PS(AG(char*, &(cmd->argv), i));
		PC('"');
	}
	i = -1;
	while (++i < cmd->redirs.length)
		print_redir(TG(t_redir, cmd->redirs, i));
	if (cmd->next == NULL)
		return (NL, (void)0);
	if (cmd->next_t == NEXT_PIPE)
		PS(" | ");
	else if (cmd->next_t == NEXT_AND)
		PS(" && ");
	else if (cmd->next_t == NEXT_OR)
		PS(" || ");
	else if (cmd->next_t == NEXT_COLON)
		PS(" ; ");
	else
		PS(" ?? ");
	print_cmd(cmd->next);
}
