/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/03/07 22:00:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_create_pipes(t_data *head)
{
	int	i;

	i = 0;
	head->pipe = malloc(sizeof(int) * head->pipe_num);
	if (NULL == head->pipe)
		ft_error_parent("Error malloc", head);
	while (i < head->cmd_num - 1)
	{
		if (pipe(head->pipe + 2 * i))
			ft_error_parent("Error pipe", head);
		i++;
	}
}

void	ft_get_cmd_paths(t_data *head, char **envp)
{
	head->cmd_paths = NULL;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (NULL == *envp)
		return ;
	head->cmd_paths = ft_split((*envp + 5), ':');
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_data	head;

	i = 1;
	if (argc < 5)
		ft_error_input();
	ft_get_cmd_paths(&head, envp);
	ft_init_fildes(&head, argc, argv);
	head.cmd_num = argc - 3 - head.here_doc;
	head.pipe_num = 2 * (head.cmd_num - 1);
	ft_create_pipes(&head);
	head.cmd_index = -1;
	while (++head.cmd_index < head.cmd_num)
		ft_child(head, argv, envp);
	ft_close_fd(&head);
	ft_close_pipes(&head);
	while (head.cmd_index)
	{
		wait(NULL);
		head.cmd_index--;
	}
	ft_free_parent(&head);
	return (0);
}
