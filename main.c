/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:36 by merlich           #+#    #+#             */
/*   Updated: 2022/02/22 22:43:48 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_delete(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_check_bin(char **path, char *bin)
{
	int		i;
	char	*tmp;
	char	*full_path;

	i = 0;
	tmp = NULL;
	full_path = NULL;
	while (path[i + 1])
	{
		tmp = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(tmp, bin);
		// ft_printf("%s\n", full_path);
		if (!access(full_path, X_OK))
		{
			// perror("Error");
			free(tmp);
			free(full_path);
			return (0);
		}
		i++;
	}
	free(tmp);
	free(full_path);
	return (-1);
}

void	ft_error_management(char **argv, char **envp)
{
	int		i;
	char	**bin_1;
	char	**bin_2;
	char	*tmp;
	char	**path;

	i = 0;
	bin_1 = ft_split(argv[2], ' ');
	bin_2 = ft_split(argv[3], ' ');
	tmp = ft_strtrim(envp[7], "PATH=");
	path = ft_split(tmp, ':');
	if (access(argv[1], R_OK) || access(argv[4], W_OK) || \
		ft_check_bin(path, bin_1[0]) || ft_check_bin(path, bin_2[0]))
	{
		perror("Error");
		// ft_delete(bin_1);
		// ft_delete(bin_2);
		// ft_delete(path);
		exit(EXIT_FAILURE);
	}
	// ft_delete(bin_1);
	// ft_delete(bin_2);
	// ft_delete(path);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	char	**tab;
	int		i;
	
	tab = NULL;
	i = 0;
	if (argc == 5)
	{
		ft_error_management(argv, envp);
	}
	else{
		ft_printf("Error : The program takes 4 arguments.\n");
		ft_printf("Example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
	}
	return (0);
}
