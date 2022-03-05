/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:48 by merlich           #+#    #+#             */
/*   Updated: 2022/03/05 20:32:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_data *head, char **envp)
{
	int	exitstat;
	int	x;
	int	y;

	exitstat = 0;
	x = dup2(head->infile, 0);
	close(head->fildes[0]);
	y = dup2(head->fildes[1], 1);
	if (x == -1 || y == -1)
	{
		ft_delete_list(&head);
		exit(EXIT_FAILURE);
	}
	exitstat = execve(head->next->path, head->next->flags, envp);
	// ft_delete_list(&head);
	perror("Error execve");
	// i = 0;
	// while (bin_path[i])
	// {
	// 	ft_printf("%s\n", bin_path[i]);
	// 	free(bin_path[i]);
	// 	i++;
	// }
	exit(exitstat);
}

void	second_child(t_data *head, char **envp)
{
	int	exitstat;
	int	x;
	int	y;

	exitstat = 0;
	x = dup2(head->fildes[0], 0);
	y = dup2(head->outfile, 1);
	if (x == -1 || y == -1)
	{
		ft_delete_list(&head);
		exit(EXIT_FAILURE);
	}
	if (!head->next->next->path)
	{
		perror("Error cmd");
		exit(EXIT_FAILURE);
	}
	exitstat = execve(head->next->next->path, head->next->next->flags, envp);
	// ft_delete_list(&head);
	perror("Error execve");
	exit(exitstat);
}
