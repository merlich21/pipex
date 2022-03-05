/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:00:34 by merlich           #+#    #+#             */
/*   Updated: 2022/03/05 21:20:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_parent(t_data *head)
{
	if (head->here_doc)
		unlink(".here_doc");
	if (head->cmd_paths)
		ft_free_tab(head->cmd_paths);
}

void	ft_free_child(t_data *head)
{
	if (head->cmd)
		free(head->cmd);
	if (head->argv)
		ft_free_tab(head->argv);
}
