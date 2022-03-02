/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:48:29 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 21:47:06 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_fill_here_doc(t_data *head, char **argv)
{
	int		fd;
	char	*buff;

	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 000777);
	if (head->infile < 0)
		ft_error_parent("Error infile", head);
	write(1, "pipe here_doc> ", 15);
	buff = get_next_line(0);
	while (buff && ft_strncmp(buff, argv[2], ft_strlen(argv[2])))
	{
		write(1, "pipe here_doc> ", 15);
		write(fd, buff, ft_strlen(buff));
		free(buff);
		buff = get_next_line(0);
	}
	free(buff);
	close(fd);
}
