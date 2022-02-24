/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/24 23:55:46 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**tab;
	t_data	*head;

	i = 1;
	tab = NULL;
	head = NULL;
	if (argc != 5)
	{
		ft_printf("Error : The program takes 4 arguments.\n");
		ft_printf("Example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
	}
	else
	{
		while (i < argc)
		{
			ft_push(&head, argv[argc - i]);
			i++;
		}
		ft_fill_list(head, envp);
		// while (head)
		// {
		// 	ft_printf("%s\n", head->path);
		// 	head = head->next;
		// }
		ft_check_files(argv);
		head->infile = open(head->path, O_RDONLY);
		if (head->infile < 0)
			ft_error("Error infile", &head);
		head->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 777);
		if (head->outfile < 0)
			ft_error("Error outfile", &head);
		if (pipe(head->fildes) < 0)
			ft_error("Error pipe", &head);
		head->next->pid = fork();
		if (head->next->pid == 0)
			first_child(head, envp);
		head->next->next->pid = fork();
		if (head->next->next->pid == 0)
			second_child(head, envp);
		waitpid(head->pid, NULL, 0);
		waitpid(head->pid, NULL, 0);
		ft_close_fd(head);
		ft_delete_list(&head);
	}
	return (0);
}
