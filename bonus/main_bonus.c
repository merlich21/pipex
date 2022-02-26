/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/26 22:58:36 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_create_pipes(t_data *head)
{
	int	i;

	i = 0;
	head->pipe_num = (2 * (head->cmd_num - 1));
	head->pipe = malloc(sizeof(int) * 2 * head->cmd_num);
	if (NULL == head->pipe)
		ft_error("Error malloc", &head);
	while (i < head->cmd_num - 1)
	{
		if(pipe(head->pipe + 2 * i))
			ft_error("Error pipe", &head);
		i++;
	}
}

static void	ft_init_fildes(t_data *head, int argc, char **argv)
{
	head->infile = open(argv[1], O_RDONLY);
	if (head->infile < 0)
		ft_error("Error infile", &head);
	head->outfile = open(argv[argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT, 777);
	if (head->outfile < 0)
		ft_error("Error outfile", &head);
	head->cmd_num = argc - 3;
	ft_create_pipes(head);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_data	*head;
	t_data	*cmd;

	i = 1;
	head = NULL;
	cmd = NULL;
	if (argc < 5)
		ft_error_input();
	while (i < argc)
	{
		ft_push(&head, argv[argc - i]);
		i++;
	}
	ft_fill_list(head, envp);
	cmd = head->next;
	ft_check_files(argc, argv);
	ft_init_fildes(head, argc, argv);
	head->cmd_index = 0;
	while (cmd->next)
	{
		ft_child(head, cmd, envp);
		cmd = cmd->next;
		head->cmd_index++;
	}
	ft_close_fd(head);
	waitpid(-1, NULL, 0);
	ft_delete_list_bonus(&head);
	return (0);
}
