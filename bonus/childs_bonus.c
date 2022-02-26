/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:48 by merlich           #+#    #+#             */
/*   Updated: 2022/02/26 23:55:24 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_dup2(int	read, int write)
{
	dup2(read, 0);
	dup2(write, 1);
}

void	ft_child(t_data *head, t_data *cmd, char **envp)
{
	head->pid = fork();
	if (head->pid < 0)
		exit(EXIT_FAILURE);
	else if (head->pid == 0)
	{
		if (head->cmd_index == 0)
			ft_dup2(head->infile, head->pipe[1]);
		else if (head->cmd_index < head->cmd_num - 1)
			ft_dup2(head->pipe[2 * head->cmd_index - 2], head->pipe[2 * head->cmd_index + 1]);
		else
			ft_dup2(head->pipe[2 * head->cmd_index - 2], head->outfile);
		ft_close_pipes(head);
		execve(cmd->path, cmd->flags, envp);
		ft_close_fd(head);
		ft_error("Error execve", &head);
	}
}
