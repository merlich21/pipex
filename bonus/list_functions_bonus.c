/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:30:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/26 21:49:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_push(t_data **head, char *path)
{
	t_data	*tmp;

	tmp = malloc(sizeof(t_data));
	if (NULL == tmp)
		exit(EXIT_FAILURE);
	tmp->path = path;
	tmp->next = *head;
	*head = tmp;
}

void	ft_delete_list_bonus(t_data **head)
{
	t_data	*tmp;

	tmp = *head;
	*head = tmp->next;
	free(tmp->pipe);
	free(tmp);
	while ((*head)->next)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp->path);
		ft_delete_tab(tmp->flags);
		free(tmp);
	}
	free(*head);
}
