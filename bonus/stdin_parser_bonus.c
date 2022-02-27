/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:09:50 by merlich           #+#    #+#             */
/*   Updated: 2022/02/27 20:27:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_get_cmd_paths(t_data *head, char **envp)
{
	// char	*tmp;

	// tmp = NULL;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	// tmp = ft_strtrim(*envp, "PATH=");
	head->cmd_paths = ft_split((*envp + 5), ':');
	// free(tmp);
}

void	ft_check_files(int argc, char **argv, t_data *head)
{
	if (access(argv[1], R_OK) || access(argv[argc - 1], W_OK))
		ft_error_parent("Error infile/outfile", head);
}
