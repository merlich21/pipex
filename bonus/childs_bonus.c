/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:48 by merlich           #+#    #+#             */
/*   Updated: 2022/03/05 21:20:54 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*ft_get_cmd(char **path, char *bin)
{
	char	*tmp;
	char	*full_path;

	if (bin[0] == '/' && access(bin, X_OK))
		return (NULL);
	else if (!access(bin, X_OK))
		return (ft_strdup(bin));
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		full_path = ft_strjoin(tmp, bin);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		path++;
	}
	return (NULL);
}

static void	ft_dup2(int read, int write)
{
	int	x;
	int	y;

	x = dup2(read, 0);
	y = dup2(write, 1);
	if (x == -1 || y == -1)
	{
		exit(EXIT_FAILURE);
	}
}

void	ft_child(t_data head, char **argv, char **envp)
{
	head.pid = fork();
	if (head.pid < 0)
		exit(EXIT_FAILURE);
	else if (head.pid == 0)
	{
		if (head.cmd_index == 0)
			ft_dup2(head.infile, head.pipe[1]);
		else if (head.cmd_index < head.cmd_num - 1)
			ft_dup2(head.pipe[2 * head.cmd_index - 2], \
					head.pipe[2 * head.cmd_index + 1]);
		else
			ft_dup2(head.pipe[2 * head.cmd_index - 2], head.outfile);
		ft_close_pipes_child(&head);
		head.argv = ft_split(argv[head.cmd_index + 2 + head.here_doc], ' ');
		head.cmd = ft_get_cmd(head.cmd_paths, head.argv[0]);
		if (NULL == head.cmd)
		{
			perror("Error cmd");
			exit(EXIT_FAILURE);
		}
		execve(head.cmd, head.argv, envp);
		ft_free_child(&head);
		ft_error_parent("Error execve", &head);
		exit(EXIT_FAILURE);
	}
}
