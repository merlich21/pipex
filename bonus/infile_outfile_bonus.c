/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:52:03 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 22:07:44 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_get_infile(t_data *head, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		head->here_doc = 1;
		ft_fill_here_doc(head, argv);
		head->infile = open(".here_doc", O_RDONLY);
		if (head->infile < 0)
			ft_error_parent("Error here_doc", head);
	}
	else
	{
		head->here_doc = 0;
		head->infile = open(argv[1], O_RDONLY);
		if (head->infile < 0)
			ft_error_parent("Error infile", head);
	}
}

static void	ft_get_outfile(t_data *head, int argc, char **argv)
{
	head->outfile = open(argv[argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT, 000777);
	if (head->outfile < 0)
		ft_error_parent("Error outfile", head);
}

void	ft_init_fildes(t_data *head, int argc, char **argv)
{
	ft_get_infile(head, argv);
	ft_get_outfile(head, argc, argv);
}
