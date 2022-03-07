/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:28:50 by merlich           #+#    #+#             */
/*   Updated: 2022/03/07 22:13:53 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_fd(t_data *head)
{
	if (head->infile != -1 && close(head->infile) == -1)
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

void	ft_close_pipes_child(t_data *head)
{
	int	i;

	i = 0;
	while (i < head->pipe_num)
	{
		if (close(head->pipe[i]) == -1)
		{
			free(head->pipe);
			ft_error_child("Error while close pipe", head);
		}
		i++;
	}
	free(head->pipe);
}
