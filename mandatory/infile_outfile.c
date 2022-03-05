/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:52:03 by merlich           #+#    #+#             */
/*   Updated: 2022/03/05 20:55:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_get_infile(t_data *head, char **argv)
{
	head->infile = open(argv[1], O_RDONLY);
	if (head->infile < 0)
		ft_error_parent("Error infile", head);
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
