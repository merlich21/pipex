/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:09:50 by merlich           #+#    #+#             */
/*   Updated: 2022/02/23 23:14:22 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_delete_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static void	ft_get_flags(t_data *elem, char **bin)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tab;

	i = 0;
	j = 0;
	tmp = NULL;
	while (bin[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * i);
	while (bin[j] && bin[j + 1])
	{
		tab[j] = ft_strdup(bin[j + 1]);
		j++;
	}
	tab[j] = NULL;
	elem->flags = tab;
}

static void	ft_build_n_check_path(t_data *head, char **bin_path, char *bin)
{
	int		i;
	char	*tmp;
	char	*full_path;

	i = 0;
	while (bin_path[i] && bin_path[i + 1])
	{
		tmp = ft_strjoin(bin_path[i], "/");
		full_path = ft_strjoin(tmp, bin);
		free(tmp);
		if (!access(full_path, X_OK))
		{
			head->path = full_path;
			return ;
		}
		free(full_path);
		i++;
	}
	perror("Error cmd");
	exit(EXIT_FAILURE);
}

void	ft_fill_list(t_data *head, char **envp)
{
	int		i;
	t_data	*elem;
	char	*tmp;
	char	**bin;
	char	**bin_path;

	elem = head->next;
	tmp = NULL;
	bin = NULL;
	bin_path = NULL;
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	tmp = ft_strtrim(envp[i], "PATH=");
	bin_path = ft_split(tmp, ':');
	free(tmp);
	while (elem->next)
	{
		bin = ft_split(elem->path, ' ');
		ft_build_n_check_path(elem, bin_path, bin[0]);
		ft_get_flags(elem, bin);
		ft_delete_tab(bin);
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
