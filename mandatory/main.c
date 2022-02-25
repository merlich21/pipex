/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 19:37:13 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_init_fildes(t_data *head)
{
	head->infile = open(head->path, O_RDONLY);
	if (head->infile < 0)
		ft_error("Error infile", &head);
	head->outfile = open(ft_list_last(head)->path, \
						O_WRONLY | O_TRUNC | O_CREAT, 777);
	if (head->outfile < 0)
		ft_error("Error outfile", &head);
	if (pipe(head->fildes) < 0)
		ft_error("Error pipe", &head);
}

static void	ft_child_1(t_data *head, pid_t pid, char **envp)
{
	pid = fork();
	if (pid == 0)
		first_child(head, envp);
	waitpid(pid, NULL, 0);
}

static void	ft_child_2(t_data *head, pid_t pid, char **envp)
{
	pid = fork();
	if (pid == 0)
		second_child(head, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_data	*head;

	i = 1;
	head = NULL;
	if (argc != 5)
		ft_error_input();
	while (i < argc)
	{
		ft_push(&head, argv[argc - i]);
		i++;
	}
	ft_fill_list(head, envp);
	ft_check_files(argv);
	ft_init_fildes(head);
	ft_child_1(head, head->next->pid, envp);
	ft_child_2(head, head->next->next->pid, envp);
	ft_close_fd(head);
	ft_delete_list(&head);
	return (0);
}
