/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/23 23:12:11 by merlich          ###   ########.fr       */
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
	if (argc == 5)
	{
		while (i < argc)
		{
			ft_push(&head, argv[argc - i]);
			i++;
		}
		ft_fill_list(head, envp);
		ft_check_files(argv);
		ft_delete_list(&head);
	}
	else
	{
		ft_printf("Error : The program takes 4 arguments.\n");
		ft_printf("Example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
	}
	return (0);
}
