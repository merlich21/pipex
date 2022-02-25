/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:09:50 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 23:08:49 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_build_n_check_path(t_data *head, char **bin_path, char *bin)
{
	char	*tmp;
	char	*full_path;

	while (*bin_path)
	{
		tmp = ft_strjoin(*bin_path, "/");
		full_path = ft_strjoin(tmp, bin);
		free(tmp);
		if (!access(full_path, X_OK))
		{
			head->path = full_path;
			return ;
		}
		free(full_path);
		bin_path++;
	}
	perror("Error cmd");
	exit(EXIT_FAILURE);
}

void	ft_fill_list(t_data *head, char **envp)
{
	t_data	*elem;
	char	*tmp;
	char	**bin;
	char	**bin_path;

	elem = head->next;
	tmp = NULL;
	bin = NULL;
	bin_path = NULL;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	tmp = ft_strtrim(*envp, "PATH=");
	bin_path = ft_split(tmp, ':');
	free(tmp);
	while (elem->next)
	{
		bin = ft_split(elem->path, ' ');
		ft_build_n_check_path(elem, bin_path, bin[0]);
		elem->flags = bin;
		elem = elem->next;
	}
	ft_delete_tab(bin_path);
}

void	ft_check_files(char **argv)
{
	if (access(argv[1], R_OK) || access(argv[4], W_OK))
	{
		perror("Error infile/outfile");
		exit(EXIT_FAILURE);
	}
}
