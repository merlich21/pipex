/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:09:50 by merlich           #+#    #+#             */
/*   Updated: 2022/03/05 20:30:19 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*ft_build_path(char **bin_path, char *cmd)
{
	char	*tmp;
	char	*full_path;

	if (cmd[0] == '/' && access(cmd, X_OK))
		return (NULL);
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	while (*bin_path)
	{
		tmp = ft_strjoin(*bin_path, "/");
		full_path = ft_strjoin(tmp, cmd);
		if (tmp)
			free(tmp);
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
		bin_path++;
	}
	return (NULL);
}

static void	ft_get_cmd(t_data *head, char **envp)
{
	char	*tmp;

	tmp = NULL;
	head->bin_path = NULL;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	tmp = ft_strtrim(*envp, "PATH=");
	head->bin_path = ft_split(tmp, ':');
	if (tmp)
		free(tmp);
	return ;
}

void	ft_fill_list(t_data *head, char **envp)
{
	t_data	*elem;
	char	**bin;

	bin = NULL;
	ft_get_cmd(head, envp);
	elem = head->next;
	while (elem->next)
	{
		bin = ft_split(elem->path, ' ');
		head->path = ft_build_path(head->bin_path, bin[0]);
		///////
		elem->flags = bin;
		elem = elem->next;
	}
	if (head->bin_path)
		ft_free_tab(head->bin_path);
}
