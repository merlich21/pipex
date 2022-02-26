/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:28:50 by merlich           #+#    #+#             */
/*   Updated: 2022/02/26 22:28:01 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close_pipes(t_data *head)
{
	int	i;

	i = 0;
	while (i < head->pipe_num)
	{
		if (close(head->pipe[i]) == -1)
			ft_error("Error while close pipe", &head);
		i++;
	}
}

void	ft_close_fd(t_data *head)
{
	if (close(head->infile) == -1)
		ft_error("Error while close infile", &head);
	if (close(head->outfile) == -1)
		ft_error("Error while close outfile", &head);
	ft_close_pipes(head);
}

void	ft_delete_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
