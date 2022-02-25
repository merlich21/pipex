/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:48 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 23:08:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	first_child(t_data *head, char **envp)
{
	int	exitstat;

	exitstat = 0;
	dup2(head->infile, 0);
	close(head->fildes[0]);
	dup2(head->fildes[1], 1);
	exitstat = execve(head->next->path, head->next->flags, envp);
	ft_delete_list(&head);
	exit(exitstat);
}

void	second_child(t_data *head, char **envp)
{
	int	exitstat;

	exitstat = 0;
	dup2(head->fildes[0], 0);
	dup2(head->outfile, 1);
	exitstat = execve(head->next->next->path, head->next->next->flags, envp);
	ft_delete_list(&head);
	exit(exitstat);
}
