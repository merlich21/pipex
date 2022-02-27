/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/27 20:53:35 by merlich          ###   ########.fr       */
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

void	ft_close_pipes(t_data *head)
{
	int	i;

	i = 0;
	while (i < head->pipe_num)
	{
		if (close(head->pipe[i]) == -1)
			ft_error_parent("Error while close pipe", head);
		i++;
	}
}

static void	ft_init_fildes(t_data *head, int argc, char **argv)
{
	head->infile = open(argv[1], O_RDONLY);
	if (head->infile < 0)
		ft_error_parent("Error infile", head);
	head->outfile = open(argv[argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT, 777);
	if (head->outfile < 0)
		ft_error_parent("Error outfile", head);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_data	head;

	i = 1;
	if (argc < 5)
		ft_error_input();
	ft_get_cmd_paths(&head, envp);
	ft_check_files(argc, argv, &head);
	ft_init_fildes(&head, argc, argv);
	head.cmd_num = argc - 3;
	head.pipe_num = 2 * (head.cmd_num - 1);
	ft_create_pipes(&head);
	head.cmd_index = 0;
	while (head.cmd_index < head.cmd_num)
	{
		ft_child(head, argv, envp);
		head.cmd_index++;
	}
	ft_close_fd(&head);
	ft_close_pipes(&head);
	waitpid(-1, NULL, 0);
	ft_free_parent(&head);
	return (0);
}
