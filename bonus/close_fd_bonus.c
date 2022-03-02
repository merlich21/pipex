/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:28:50 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 21:59:41 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close_fd(t_data *head)
{
	if (close(head->infile) == -1)
		ft_error_parent("Error closing infile", head);
	if (close(head->outfile) == -1)
		ft_error_parent("Error closing outfile", head);
}

void	ft_close_pipes(t_data *head)
{
	int	i;

	i = 0;
	while (i < head->pipe_num)
	{
		if (close(head->pipe[i]) == -1)
		{
			free(head->pipe);
			ft_error_parent("Error while close pipe", head);
		}
		i++;
	}
	free(head->pipe);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_parent(t_data *head)
{
	if (head->here_doc)
		unlink(".here_doc");
	ft_free_tab(head->cmd_paths);
}

void	ft_free_child(t_data *head)
{
	free(head->cmd);
	ft_free_tab(head->cmd_paths);
	ft_free_tab(head->argv);
}
