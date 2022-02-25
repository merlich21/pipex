/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:48 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 21:09:38 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_data *head, char **envp)
{
	dup2(head->infile, 0);
	close(head->fildes[0]);
	dup2(head->fildes[1], 1);
	if (execve(head->next->path, head->next->flags, envp) == -1)	
	{
		ft_delete_list(&head);
		exit(EXIT_FAILURE);
	}
}

void	second_child(t_data *head, char **envp)
{
	dup2(head->fildes[0], 0);
	close(head->fildes[1]);
	dup2(head->outfile, 1);
	if (execve(head->next->next->path, head->next->next->flags, envp) == -1)
	{
		ft_delete_list(&head);
		exit(EXIT_FAILURE);
	}
}
